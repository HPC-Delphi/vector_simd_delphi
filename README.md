# intel_simd_delphi - SIMD Library for Delphi Integration

[![Platform: Windows](https://img.shields.io/badge/Platform-Windows%2011-blue)](https://www.microsoft.com/en-us/windows/windows-11)
[![GCC](https://img.shields.io/badge/GCC-15.1.0-brightgreen)](https://winlibs.com/)

`intel_simd_delphi` is a dynamic library written in C, providing SIMD (Single Instruction, Multiple Data) functionality for Delphi applications. It enables high-performance vectorized computations using Intel SIMD instructions.

---

## Features

- **SIMD Integration**: Provides bindings for Intel SIMD instructions to be used in Delphi projects.
- **Delphi Wrapper**: Includes a Delphi wrapper for seamless integration.
- **High-Performance Computing**: Enables vectorized computations for improved performance.
- **Cross-Language Compatibility**: Distributed as a DLL, accessible from various programming environments.
- **Modern Toolchain Support**: Built and tested with the latest GCC and Intel SIMD libraries for Windows 11.

---

## Requirements & Development Environment

The library is developed, tested, and intended to be used in the following environment:

- **Operating System**: Windows 11 (64-bit)
- **Compiler**: GCC 15.1.0
- **Toolchain**: MinGW-w64 12.0.0 UCRT (release 1) from [winlibs.com](https://winlibs.com/)
- **Intel SIMD Libraries**: Required for SIMD functionality.
- **Build System**: `mingw32-make`
- **Delphi Integration**: RAD Studio (Delphi 12.1 Community Edition)

---

## Project Structure

```
intel_simd_delphi/
│
├── build/                  # Compiled binaries and intermediate files
├── include/                # Public API headers (C)
│   └── intel_simd_delphi.h
├── src/                    # C source code
│   └── intel_simd_delphi.c
├── wrappers/               # Delphi language wrapper
│   └── SIMD.pas
├── LICENSE                 # License information (MIT)
├── Makefile                # Build script for DLL
└── README.md               # Project documentation
```

---

## Compilation Instructions

To build the library as a DLL:

1. Install the Intel SIMD libraries (ensure the paths are set in your environment variables).
2. Open a Command Prompt or PowerShell window.
3. Navigate to the project root directory (`intel_simd_delphi`).
4. Run:

   ```sh
   mingw32-make
   ```

This will generate `intel_simd_delphi.dll` in the `build/` directory.

---

## Using the Library in Delphi

### 1. Setup
- Place `intel_simd_delphi.dll` in the directory where the executable is created upon compiling your Delphi project, or ensure it is in a directory included in your system's PATH.

### 2. Using the Wrapper in a Delphi Project
- Add the path to `SIMD.pas` in the "Search Path" under Project Options in your Delphi project.
- Use the functions declared in the wrapper to perform SIMD operations.