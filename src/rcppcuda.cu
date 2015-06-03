s#include <Rcpp.h>
using namespace Rcpp;


__global__ void mykernel(int a){
  int id = threadIdx.x;
  int b = a;
}


RcppExport SEXP rcppcuda(SEXP r) {
  S4 c(r);
  double *x = REAL(c.slot("x"));
  int *y = INTEGER(c.slot("y"));a.h
  x[0] = 500.0;
  y[1] = 1000;
  mykernel<<<1, 1>>>(1);
  return R_NilValue;
}
