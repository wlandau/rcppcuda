CUDA_HOME = /usr/local/cuda
R_HOME = /apps/R-3.2.0

#########################################

NVCC = $(CUDA_HOME)/bin/nvcc
CUDA_INC_PATH = $(CUDA_HOME)/include 
CUDA_LIB_PATH = $(CUDA_HOME)/lib64

R_CC = R CMD SHLIB
R_INC_PATH = $(R_HOME)/include

NAME = rcppcuda
SRC = $(NAME).cu
OUT_OBJ = $(NAME).o
OUT_SO = $(NAME).so

LIBS = -lcudart -d
NVCC_FLAGS = --shared -Xcompiler "-fPIC" -gencode arch=compute_20,code=sm_20 -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=sm_35 -I$(R_INC_PATH)

all: $(OUT_OBJ)
	$(R_CC) $(OUT_OBJ) -o $(OUT_SO) $(LIBS) -L$(CUDA_LIB_PATH)
	
$(OUT_OBJ): $(SRC)
	$(NVCC) -c $(SRC) -o $(OUT_OBJ) $(NVCC_FLAGS) -I$(CUDA_INC_PATH)
