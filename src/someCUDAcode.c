#include <R.h>

#define CUDA_CALL(x) {if((x) != cudaSuccess){ \
  REprintf("CUDA error at %s:%d\n",__FILE__,__LINE__); \
  REprintf("  %s\n", cudaGetErrorString(cudaGetLastError()));}}

__global__ void mykernel(int a){
  int id = threadIdx.x;
  int b = a;
  b++;
  id++;
}

extern "C" void someCUDAcode() {
  int a;
  CUDA_CALL(cudaMalloc((void**) &a, sizeof(int)));
  mykernel<<<1, 1>>>(1);
}
