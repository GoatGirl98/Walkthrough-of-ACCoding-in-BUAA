#include <stdio.h>

long long A[150][150] = {0}, B[150][150] = {0}, C[150][150] = {0};

int main()
{
    int m, n;
    int p, q, i, j, k;

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%lld", &A[i][j]);
        }
    }
    scanf("%d %d", &p, &q);
    for (i = 0; i < p; ++i)
    {
        for (j = 0; j < q; ++j)
        {
            scanf("%lld", &B[i][j]);
        }
    }

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < q; ++j)
        {
            for (k = 0; k < n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for(i=0;i<m;++i){
        for(j=0;j<q;++j){
            printf("%lld ",C[i][j]);
        }
        printf("\n");
    }
}