#include "..\include\vector_simd_delphi.h"

VECTOR_SIMD_DELPHI_API void vadd_double(const double *a, const double *b, double *c, int length)
{
    VDouble vecA, vecB, vecC;
    int i = 0;

    for (i = 0; i <= length - VDOUBLE_LEN; i += VDOUBLE_LEN)
    {
#if defined(__AVX__)
        vecA = _mm256_loadu_pd(&a[i]);
        vecB = _mm256_loadu_pd(&b[i]);
        vecC = _mm256_add_pd(vecA, vecB);
        _mm256_storeu_pd(&c[i], vecC);
#elif defined(__SSE2__)
        vecA = _mm_loadu_pd(&a[i]);
        vecB = _mm_loadu_pd(&b[i]);
        vecC = _mm_add_pd(vecA, vecB);
        _mm_storeu_pd(&c[i], vecC);
#else
        for (int j = 0; j < VDOUBLE_LEN; j++)
            c[i + j] = a[i + j] + b[i + j];
#endif
    }

    for (; i < length; i++)
        c[i] = a[i] + b[i];
}

VECTOR_SIMD_DELPHI_API void vmul_double(const double *a, const double *b, double *c, int length)
{
    VDouble vecA, vecB, vecC;
    int i = 0;

    for (i = 0; i <= length - VDOUBLE_LEN; i += VDOUBLE_LEN)
    {
#if defined(__AVX__)
        vecA = _mm256_loadu_pd(&a[i]);
        vecB = _mm256_loadu_pd(&b[i]);
        vecC = _mm256_mul_pd(vecA, vecB);
        _mm256_storeu_pd(&c[i], vecC);
#elif defined(__SSE2__)
        vecA = _mm_loadu_pd(&a[i]);
        vecB = _mm_loadu_pd(&b[i]);
        vecC = _mm_mul_pd(vecA, vecB);
        _mm_storeu_pd(&c[i], vecC);
#else
        for (int j = 0; j < VDOUBLE_LEN; j++)
            c[i + j] = a[i + j] * b[i + j];
#endif
    }

    for (; i < length; i++)
        c[i] = a[i] * b[i];
}

VECTOR_SIMD_DELPHI_API void vfma_double(const double *a, const double *b, double *c, int length)
{
    VDouble vecA, vecB, vecC;
    int i = 0;

    for (i = 0; i <= length - VDOUBLE_LEN; i += VDOUBLE_LEN)
    {
#if defined(__AVX__)
        vecA = _mm256_loadu_pd(&a[i]);
        vecB = _mm256_loadu_pd(&b[i]);
        vecC = _mm256_loadu_pd(&c[i]);
        vecC = _mm256_fmadd_pd(vecA, vecB, vecC);
        _mm256_storeu_pd(&c[i], vecC);
#elif defined(__SSE2__)
        vecA = _mm_loadu_pd(&a[i]);
        vecB = _mm_loadu_pd(&b[i]);
        vecC = _mm_loadu_pd(&c[i]);
        vecC = _mm_add_pd(vecC, _mm_mul_pd(vecA, vecB));
        _mm_storeu_pd(&c[i], vecC);
#else
        c[i] = a[i] * b[i] + c[i];
#endif
    }

    for (; i < length; i++)
        c[i] = a[i] * b[i] + c[i];
}

VECTOR_SIMD_DELPHI_API void vreduce_double(const double *a, double *out, int length)
{
    VDouble vecA;
    double sum = 0.0;
    int i = 0;

    for (i = 0; i <= length - VDOUBLE_LEN; i += VDOUBLE_LEN)
    {
#if defined(__AVX__)
        vecA = _mm256_loadu_pd(&a[i]);
        __m256d t1 = _mm256_hadd_pd(vecA, vecA);

        __m128d hi = _mm256_extractf128_pd(t1, 1);
        __m128d lo = _mm256_castpd256_pd128(t1);

        __m128d sum128 = _mm_add_pd(lo, hi);

        sum += _mm_cvtsd_f64(sum128);
#elif defined(__SSE2__)
        for (int j = 0; j < VDOUBLE_LEN; j++)
            sum += a[i + j];
#else
        for (int j = 0; j < VDOUBLE_LEN; j++)
            sum += a[i + j];
#endif
    }

    for (; i < length; i++)
        sum += a[i];

    *out = sum;
}