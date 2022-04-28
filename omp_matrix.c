#ifndef N
#define N 4096
#endif

#include <omp.h>
void run(int a[N][N], int b[N][N], int c[N][N])
{
#pragma omp parallel for
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }       
}
