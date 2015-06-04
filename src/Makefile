CUDA_HOME = /usr/local/cuda
R_HOME = /apps/R-3.2.0
CPPC = /usr/bin/g++

#########################################

NVCC = $(CUDA_HOME)/bin/nvcc
CUDA_INC = $(CUDA_HOME)/include 
CUDA_LIB = $(CUDA_HOME)/lib64

R_CC = R CMD SHLIB
R_INC = $(R_HOME)/include
RCPP_INC = $(R_HOME)/library/Rcpp/include

LIBS = -lcudart -d
NVCC_FLAGS = --shared -Xcompiler "-fPIC" -gencode arch=compute_20,code=sm_20 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=sm_35 -I$(R_INC)

all: someCUDAcode.o someCPPcode.o
	$(R_CC) $< -o rcppcuda.so $(LIBS) -L$(CUDA_LIB)
	
someCUDAcode.o: someCUDAcode.cu 
	$(NVCC) -c someCUDAcode.cu -o someCUDAcode.o $(NVCC_FLAGS) -I$(CUDA_INC)

someCPPcode.o: someCPPcode.cpp 
	$(CPPC) -c someCPPcode.cpp -o someCPPcode.o -I$(R_INC) -I$(RCPP_INC)
