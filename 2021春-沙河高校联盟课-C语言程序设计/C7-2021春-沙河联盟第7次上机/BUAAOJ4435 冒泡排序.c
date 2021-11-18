#include <stdio.h>
#include <stdlib.h>
typedef struct _line
{
    int l, r;
} LINE;
LINE arr[1005];
int n;
int main(void)
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d%d", &arr[i].l, &arr[i].r);
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].l > arr[j + 1].l || (arr[j].l == arr[j + 1].l &&
                                            arr[j].r > arr[j + 1].r)) //注意交换条件
            {
                LINE temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag)
            break;
    }
    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].l, arr[i].r);
    return 0;
}