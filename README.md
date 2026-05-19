# vector_simd_delphi - SIMD Operations Library for Delphi Integration

[![Platform: Windows](https://img.shields.io/badge/Platform-Windows%2011-blue)](https://www.microsoft.com/en-us/windows/windows-11)
[![GCC](https://img.shields.io/badge/GCC-15.1.0-brightgreen)](https://winlibs.com/)

`vector_simd_delphi` is a dynamic library written in C, providing vectorized operations on double-precision floating-point arrays for Delphi applications. This module is designed to accelerate mathematical and algebraic computations in High-Performance Computing (HPC) scenarios, serving as a core dependency for optimized matrix processing.

## Features

- **SIMD Vectorization**: Implements dynamic instruction set dispatching (AVX, SSE2, or scalar fallback) depending on the compilation flags and target architecture.
- **Core Mathematical Functions**: Exposes highly optimized routines for array addition (`vadd`), multiplication (`vmul`), Fused Multiply-Add (`vfma`), and array reduction/summation (`vreduce`).
- **Delphi Wrapper**: Includes a Delphi wrapper for seamless integration.
- **High-Performance Computing**: Enables vectorized/optimized computations for improved performance.
- **Cross-Language Compatibility**: Distributed as a DLL, accessible from various programming environments.
- **Modern Toolchain Support**: Built and tested with the latest GCC toolchain for Windows 11.

## Requirements & Development Environment

The library is developed, tested, and intended to be used in the following environment:

- **Operating System**: Windows 11 (64-bit)
- **Compiler**: GCC 15.1.0
- **Toolchain**: MinGW-w64 12.0.0 UCRT (release 1) from [winlibs.com](https://winlibs.com/)
- **Dependencies**: No external third-party libraries required. Uses standard Intel intrinsic headers (`immintrin.h`, `emmintrin.h`).
- **Build System**: `mingw32-make`
- **Delphi Integration**: RAD Studio (Delphi 12.1 Community Edition)

## Project Structure

```text
vector_simd_delphi/
│
├── build/                  # Compiled binaries and intermediate files
├── include/                # Public API headers (C)
│   └── vector_simd_delphi.h
├── src/                    # C source code
│   └── vector_simd_delphi.c
├── wrappers/               # Delphi language wrapper
│   └── VectorSIMD.pas
├── LICENSE                 # License information
├── Makefile                # Build script for DLL
└── README.md               # Project documentation
```

## Compilation Instructions

To build the library as a DLL:

1. Ensure the GCC toolchain is available in your system's PATH. The provided Makefile already configures the necessary SIMD flags (`-mavx -mavx2 -mfma`).
2. Open a Command Prompt or PowerShell window.
3. Navigate to the project root directory (`vector_simd_delphi`).
4. Run:

   ```sh
   mingw32-make
   ```

This will generate `vector_simd_delphi.dll` in the `build/` directory.

## Using the Library in Delphi

### 1. Setup
- Place `vector_simd_delphi.dll` in the directory where the executable is created upon compiling your Delphi project, or ensure it is in a directory included in your system's PATH.

### 2. Using the Wrapper in a Delphi Project
- Add the path to `VectorSIMD.pas` in the "Search Path" under Project Options in your Delphi project.
- Use the functions declared in the wrapper to perform operations.

**Example Usage:**
```pascal
uses VectorSIMD;

// Perform vectorized Fused Multiply-Add (C = A * B + C)
VectorFMA(@ArrayA[0], @ArrayB[0], @ArrayC[0], Length);

// Reduce array elements to a single sum
VectorReduce(@ArrayA[0], @SumResult, Length);
```

## Academic Citation

If you use this software in your research, please cite it using the metadata provided in the `CITATION.cff` file located in the root of this repository.

## License

This project is licensed under the MIT License - see the LICENSE file for details.