#include <cuda.h>
#include <cuda_runtime.h>
#include <R.h>

#define CUDA_CALL(x) {if((x) != cudaSuccess){ \
  REprintf("CUDA error at %s:%d\n",__FILE__,__LINE__); \
  REprintf("  %s\n", cudaGetErrorString(cudaGetLastError()));}}

#define checkCudaErrors(err)  __checkCudaErrors (err, __FILE__, __LINE__)

inline void __checkCudaErrors( CUresult err, const char *file, const int line )
{
    if( CUDA_SUCCESS != err) {
        fprintf(stderr,
                "CUDA Driver API error = %s from file <%s>, line %i.\n",
                err, file, line );
        exit(-1);
    }
}

#define KERNEL_CHECK { \
  cudaError err = cudaGetLastError(); \
  if (cudaSuccess != err) \
    REprintf("cudaCheckError() failed at %s:%i : %s\n", \
            __FILE__, __LINE__, cudaGetErrorString(err)); \
  err = cudaDeviceSynchronize(); \
  if(cudaSuccess != err) \
    REprintf("cudaCheckError() with sync failed at %s:%i : %s\n", \
            __FILE__, __LINE__, cudaGetErrorString(err)); \
}

__global__ void mykernel(int a){
  int id = threadIdx.x;
  int b = a;
  b++;
  id++;
}

extern "C" void someCUDAcode(int device) {
  int *a;
  CUcontext context;
  checkCudaErrors(cuInit(0));
  CUDA_CALL(cudaSetDevice(device));
  checkCudaErrors(cuCtxCreate(&context, 0, device));

  CUDA_CALL(cudaMalloc((void**) &a, sizeof(int)));
  mykernel<<<1, 1>>>(1);
  KERNEL_CHECK;
  CUDA_CALL(cudaFree(a));

  CUDA_CALL(cudaDeviceReset());
  checkCudaErrors(cuCtxPopCurrent(&context));
  checkCudaErrors(cuCtxDestroy(context));
}
