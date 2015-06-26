#include <cuda.h>
#include <cuda_runtime.h>
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

extern "C" void someCUDAcode(int device) {
  int *a, dev2;
  CUcontext context;

  cuInit(0);
  CUresult res = cuCtxCreate(&context, 0, device);

  cudaGetDevice(&dev2);
  Rprintf("Really running on device %d\n", dev2);

  CUDA_CALL(cudaMalloc((void**) &a, sizeof(int)));
  mykernel<<<1, 1>>>(1);
  CUDA_CALL(cudaFree(a));

  res = cuCtxPopCurrent(&context);
  cudaDeviceReset();
}
