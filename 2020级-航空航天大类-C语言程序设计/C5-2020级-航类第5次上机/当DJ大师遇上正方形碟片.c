#include <stdio.h>

int del[3] = {0, 0}, rev[3] = {0, 1};

int arr[150][150];

int main()
{
    int n, i, j, q, m, k, tmp;
    int tar[2]={0,0};

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &q);

    while (q--)
    {
        scanf("%d", &m);
        if (m == 2 || m == 3)
        {
            scanf("%d", &k);
            k %= n;
        }

        switch (m)
        {
        case 1:
            tmp = rev[0];
            rev[0] = rev[1];
            rev[1] = tmp;
            break;
        case 2:
            del[rev[0]] += k;
            del[rev[0]] %= n;
            break;
        case 3:
            del[rev[1]] += k;
            del[rev[1]] %= n;
            break;
        }
    }

    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            tar[rev[0]]=(n+i-del[rev[0]])%n;
            tar[rev[1]]=(n+j-del[rev[1]])%n;
            printf("%d ",arr[tar[0]][tar[1]]);
        }
        printf("\n");
    }
}