CC        := gcc
CFLAGS    := -Wall -shared -O3 -mavx -mavx2 -mfma -march=native -mtune=native

SRC_DIR   := src
OBJ_DIR   := build
INC_DIR   := include

TARGET    := $(OBJ_DIR)\intel_simd_delphi.dll
SRC   := $(SRC_DIR)\intel_simd_delphi.c
OBJ   := $(OBJ_DIR)\intel_simd_delphi.o
HEADERS   := $(INC_DIR)\intel_simd_delphi.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): $(SRC) $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	rmdir /s /Q $(OBJ_DIR)
