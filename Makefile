CC        := gcc
CFLAGS    := -Wall -shared -O3 -mavx -mavx2 -mfma -march=native -mtune=native

SRC_DIR   := src
OBJ_DIR   := build
INC_DIR   := include

TARGET    := $(OBJ_DIR)\vector_simd_delphi.dll
SRC   := $(SRC_DIR)\vector_simd_delphi.c
OBJ   := $(OBJ_DIR)\vector_simd_delphi.o
INC   := $(INC_DIR)\vector_simd_delphi.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): $(SRC) $(INC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	rmdir /s /Q $(OBJ_DIR)
