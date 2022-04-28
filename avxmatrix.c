#include <immintrin.h>
#include <xmmintrin.h>
#ifndef N
#define N 4096
#endif

void run(int a[N][N], int b[N][N], int c[N][N])
{
    __m512i t1, t2, sum;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; j += 16) {
            sum = _mm512_setzero_si512();
            for (int k = 0; k < N; k++) {
                t1 = _mm512_set1_epi32(a[i][k]);
                t2 = _mm512_load_epi32(b[k] + j);
                t2 = _mm512_mullo_epi32(t2, t1);
                sum = _mm512_add_epi32(sum, t2);
            }
            _mm512_store_epi32(c[i] + j, sum);
        }
    }       
}

