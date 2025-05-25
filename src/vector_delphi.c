#include "..\include\vector_delphi.h"

VECTOR_DELPHI_API int vlength_double(){ return VDOUBLE_LEN;}

VECTOR_DELPHI_API VDouble vload_double(double* A)
{
#if defined(__AVX__)
    VDouble vecA = _mm256_loadu_pd(A);
#elif defined(__SSE2__)
    VDouble vecA = _mm_loadu_pd(A);
#else
    VDouble *vecA = *A;
#endif

    return vecA;
}

VECTOR_DELPHI_API void vstore_double(double *A, VDouble vecA)
{
#if defined(__AVX__)
    _mm256_store_pd(A, vecA);
#elif defined(__SSE2__)
    _mm_store_pd(A, vecA);
#else
    *A = vecA;
#endif
}

VECTOR_DELPHI_API VDouble vadd_double(VDouble A, VDouble B)
{
#if defined(__AVX__)
    return _mm256_add_pd(A, B);
#elif defined(__SSE2__)
    return _mm_add_pd(A, B);
#else
    return A + B;
#endif
}

VECTOR_DELPHI_API VDouble vmul_double(VDouble A, VDouble B)
{
#if defined(__AVX__)
    return _mm256_mul_pd(A, B);
#elif defined(__SSE2__)
    return _mm_mul_pd(A, B);
#else
    return A * B;
#endif
}