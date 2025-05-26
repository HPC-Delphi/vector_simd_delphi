#include "..\include\vector_delphi.h"

VECTOR_DELPHI_API int vlength_double() { return VDOUBLE_LEN; }

VECTOR_DELPHI_API void vfma_double(const double *a, const double *b, double *c)
{
#if defined(__AVX__)
    VDouble vecA = _mm256_loadu_pd(a);
    VDouble vecB = _mm256_loadu_pd(b);
    VDouble vecC = _mm256_loadu_pd(c);
    vecC = _mm256_fmadd_pd(vecA, vecB, vecC);
    _mm256_storeu_pd(c, vecC);
#elif defined(__SSE2__)
    VDouble vecA = _mm_loadu_pd(a);
    VDouble vecB = _mm_loadu_pd(b);
    VDouble vecC = _mm_loadu_pd(c);
    vecC = _mm_add_pd(vecC, _mm_mul_pd(vecA, vecB));
    _mm_storeu_pd(c, vecC);
#else
    *c = (*a + *b) * *c;
#endif
}

VECTOR_DELPHI_API void vadd_double(const double *a, const double *b, double *out)
{
#if defined(__AVX__)
    VDouble vecA = _mm256_loadu_pd(a);
    VDouble vecB = _mm256_loadu_pd(b);
    VDouble vecOut = _mm256_add_pd(vecA, vecB);
    _mm256_storeu_pd(out, vecOut);
#elif defined(__SSE2__)
    VDouble vecA = _mm_loadu_pd(a);
    VDouble vecB = _mm_loadu_pd(b);
    VDouble vecOut = _mm_add_pd(vecA, vecB);
    _mm_storeu_pd(out, vecOut);
#else
    *out = *a + *b;
#endif
}

VECTOR_DELPHI_API void vmul_double(const double *a, const double *b, double *out)
{
#if defined(__AVX__)
    VDouble vecA = _mm256_loadu_pd(a);
    VDouble vecB = _mm256_loadu_pd(b);
    VDouble vecOut = _mm256_mul_pd(vecA, vecB);
    _mm256_storeu_pd(out, vecOut);
#elif defined(__SSE2__)
    VDouble vecA = _mm_loadu_pd(a);
    VDouble vecB = _mm_loadu_pd(b);
    VDouble vecOut = _mm_mul_pd(vecA, vecB);
    _mm_storeu_pd(out, vecOut);
#else
    *out = *a * *b;
#endif
}