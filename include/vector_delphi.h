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
VECTOR_DELPHI_API void vfma_double(const double *a, const double *b, double *c);
VECTOR_DELPHI_API void vadd_double(const double *a, const double *b, double *out);
VECTOR_DELPHI_API void vmul_double(const double *a, const double *b, double *out);