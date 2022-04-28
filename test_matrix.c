#include <stdio.h>
#include <sys/time.h>
#ifndef N
#define N 4096
#endif

int a[N][N];
int b[N][N];
int c[N][N];

void init(int a[N][N], int b[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = i * 2 + j;
            b[i][j] = i + j * 2;
        }
    }
}

extern void run(int a[N][N], int b[N][N], int c[N][N]);

void print_result()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    init(a, b);
    struct timeval begin, end;
    gettimeofday(&begin, NULL);
    run(a, b, c);
    gettimeofday(&end, NULL);
    printf("time: %lfs\n", (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec) / 1000000.0);
    /* print_result(); */
    return 0;
}

