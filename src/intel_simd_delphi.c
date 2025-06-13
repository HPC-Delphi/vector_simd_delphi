#include "..\include\intel_simd_delphi.h"

INTEL_SIMD_DELPHI_API int vlength_double() { return VDOUBLE_LEN; }

INTEL_SIMD_DELPHI_API void vfma_double(const double *a, const double *b, double *c)
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

INTEL_SIMD_DELPHI_API void vadd_double(const double *a, const double *b, double *out)
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

INTEL_SIMD_DELPHI_API void vmul_double(const double *a, const double *b, double *out)
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

INTEL_SIMD_DELPHI_API void vreduce_double(const double *a, double *out)
{
    *out = 0.0;
#if defined(__AVX__)
    VDouble vecA = _mm256_loadu_pd(a);
    __m256d t1 = _mm256_hadd_pd(vecA, vecA);

    __m128d hi = _mm256_extractf128_pd(t1, 1);
    __m128d lo = _mm256_castpd256_pd128(t1);

    __m128d sum128 = _mm_add_pd(lo, hi);

    *out = _mm_cvtsd_f64(sum128);
#elif defined(__SSE2__)
    for (int i = 0; i < VDOUBLE_LEN; i++)
        *out += a[i];
#else
    for (int i = 0; i < VDOUBLE_LEN; i++)
        *out += a[i];
#endif
}