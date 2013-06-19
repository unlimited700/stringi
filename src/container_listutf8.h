/* This file is part of the 'stringi' library.
 * 
 * Copyright 2013 Marek Gagolewski, Bartek Tartanus, Marcin Bujarski
 * 
 * 'stringi' is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 'stringi' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with 'stringi'. If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef __container_listutf8_h
#define __container_listutf8_h





/**
 * A class to handle conversion between R lists of character vectors and lists of UTF-8 string vectors
 * @version 0.1 (Marek Gagolewski, 2013-06-16)
 */
class StriContainerListUTF8 : public StriContainerBase {

   private:
   
      StriContainerUTF8 **data;
      
      
   public:
      
      StriContainerListUTF8();
      StriContainerListUTF8(SEXP rlist, R_len_t nrecycle, bool shallowrecycle=true);
      StriContainerListUTF8(StriContainerListUTF8& container);
      ~StriContainerListUTF8();
      StriContainerListUTF8& operator=(StriContainerListUTF8& container);
      SEXP toR(R_len_t i) const;
      SEXP toR() const;


      /** check if the vectorized ith element is NA
       * @param i index
       * @return true if is NA
       */
      inline bool isNA(R_len_t i) const {
#ifndef NDEBUG
         if (i < 0 || i >= nrecycle)
            error("StriContainerListUTF8::isNA(): INDEX OUT OF BOUNDS"); // TO DO: throw StriException
#endif
         return (data[i%n] == NULL);
      }
      
      
      /** get the vectorized ith element
       * @param i index
       * @return string, read only
       */
      const StriContainerUTF8& get(R_len_t i) const {
#ifndef NDEBUG
         if (i < 0 || i >= nrecycle)
            error("StriContainerListUTF8::get(): INDEX OUT OF BOUNDS"); // TO DO: throw StriException
         if (data[i%n] == NULL)
            error("StriContainerListUTF8::get(): isNA"); // TO DO: throw StriException
#endif
         return (*(data[i%n]));
      }
};

#endif
