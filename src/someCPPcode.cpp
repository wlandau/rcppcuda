#include <Rcpp.h>
using namespace Rcpp;

extern "C"
void someCUDAcode(int device);

//[[Rcpp::export]]
SEXP someCPPcode(SEXP r, SEXP device) {
  S4 c(r);
  double *x = REAL(c.slot("x"));
  int *y = INTEGER(c.slot("y"));

  x[0] = 500.0;
  y[1] = 1000;
  someCUDAcode(INTEGER(device)[0]);
  return r;
}
