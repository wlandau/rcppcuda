#include <Rcpp.h>
using namespace Rcpp;

 void someCUDAcode();

RcppExport SEXP someCPPcode(SEXP r) {
  S4 c(r);
  double *x = REAL(c.slot("x"));
  int *y = INTEGER(c.slot("y"));
  x[0] = 500.0;
  y[1] = 1000;
  someCUDAcode();
  return R_NilValue;
}
