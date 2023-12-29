/*********************************************************************/
/* File:   h1hofe.cpp                                                */
/* Author: Start                                                      */
/* Date:   6. Feb. 2003                                              */
/*********************************************************************/
 
#include <h1hofe_impl.hpp>
#include <tscalarfe_impl.hpp>

namespace ngfem
{
  template class H1HighOrderFE<ET_HEX>;
  template class T_ScalarFiniteElement<H1HighOrderFE_Shape<ET_HEX>, ET_HEX>;  
}
