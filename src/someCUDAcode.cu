__global__ void mykernel(int a){
  int id = threadIdx.x;
  int b = a;
  b++;
  id++;
}

void someCUDAcode() {
  mykernel<<<1, 1>>>(1);
}
