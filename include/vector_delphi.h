#pragma once

#ifdef VECTOR_DELPHI_EXPORTS
#define VECTOR_DELPHI_API __declspec(dllexport)
#else
#define VECTOR_DELPHI_API __declspec(dllimport)
#endif

#ifdef __AVX__
  #include <immintrin.h>
  typedef __m256d VDouble;
  #define VDOUBLE_LEN 4
#elif defined(__SSE2__)
  #include <emmintrin.h>
  typedef __m128d VDouble;
  #define VDOUBLE_LEN 2
#else
  typedef double VDouble;
  #define VDOUBLE_LEN 1
#endif

VECTOR_DELPHI_API int vlength_double();
VECTOR_DELPHI_API VDouble vload_double(double* A);
VECTOR_DELPHI_API void vstore_double(double *A, VDouble vecA);
VECTOR_DELPHI_API VDouble vadd_double(VDouble A, VDouble B);
VECTOR_DELPHI_API VDouble vmul_double(VDouble A, VDouble B);