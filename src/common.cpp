/* This file is part of the 'stringi' library.
 * 
 * Copyright 2013 Marek Gagolewski, Bartek Tartanus
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


#include "stringi.h"




/** 
 *  Create a character vector filled with NA_character_
 * 
 *  Useful when something goes wrong
 * 
 *  @param how_many length of the vector
 *  @return a character vector of length how_many
*/
SEXP stri__mkStringNA(R_len_t howmany)
{
   if (howmany <= 0) return R_NilValue;
   
   SEXP ret;
   PROTECT(ret = allocVector(STRSXP, howmany));
   for (R_len_t i=0; i<howmany; ++i)
      SET_STRING_ELT(ret, i, NA_STRING);
   UNPROTECT(1);
   return ret;   
}


/** 
 *  Create a character vector filled with empty strings
 * 
 *  @param how_many length of the vector
 *  @return a character vector of length how_many
*/
SEXP stri__mkStringEmpty(R_len_t howmany)
{
   if (howmany <= 0) return R_NilValue;
   
   SEXP ret;
   PROTECT(ret = allocVector(STRSXP, howmany));
   for (R_len_t i=0; i<howmany; ++i)
      SET_STRING_ELT(ret, i, mkCharLen(NULL, 0));
   UNPROTECT(1);
   return ret;   
}
