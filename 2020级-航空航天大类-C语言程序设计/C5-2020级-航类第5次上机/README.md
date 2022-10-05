# C5-2020级-航类第五次上机

## 题目列表

- A 4333 阿水给大家排排坐
- B 4334 超级泡泡排序
- C 4228 Wink矩阵运算
- D 4328 Ning的汉明距离
- E 4335 惹Shy的二分查找
- F 4337 dch做不出毕业设计
- G 4330 PlayFair
- H 4323 当DJ大师遇上正方形碟片

### `A` 4333 阿水给大家排排坐

签到题

冒泡排序和选择排序都可以过

```C
#include<stdio.h>
int main()
{
	int n,i,j;
	double a[1100],temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
	for(i=0; i<n; i++)
		for(j=0; j<n-1-i; j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	for(i=0; i<n; i++)
	{
		if(a[i]==0)
		{
			printf("0.00000\n");
			continue;
		}
		printf("%.5f\n",a[i]);

	}
	return 0;
}
```



### `B` 4334 超级泡泡排序

本题是冒泡排序的改编（如果你还不懂冒泡排序的原理和算法，请仔细看课件，本分析基于你已经了解冒泡排序的基础），冒泡排序的排序关键字数**两个数之间的大小**，本题的解法大体仍然是冒泡排序框架，判断两个数是否交换时，第一关键字是数到m的距离，第二关键字是两个数的大小，伪代码如下：

```
for(int i=0;i<n-1;i++)

{
  int flag=0;
  for(int j=0;j<n-i-1;j++)
  {
    if((|a[j]-m|>|a[j+1]-m|)或者距离相等并且(a[j]>a[j+1]))
    {
      flag=1;
			两数交换
    }
  }
  if(!flag)break;
}
```

需要注意的一点是，虽然输入的数都在int范围内，但是a[j]和m之间的距离是可能超过int的，所以需要定义一个long long型变量来储存距离，进行比较。如果需要用到long long型的绝对值函数，自己定义即可。

示例代码

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ll long long
ll n, m;
ll arr[1005];

ll l_abs(ll num)//long long型绝对值函数
{
    if (num < 0)num = -num;
    return num;
}

int main(void) {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    for (int i = 0; i < n - 1; i++)//冒泡排序
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            ll dis1 = l_abs(arr[j] - m);
            ll dis2 = l_abs(arr[j + 1] - m);
            if ((dis1 > dis2) || (dis1 == dis2 && arr[j] > arr[j + 1]))//交换条件
            {
                flag = 1;
                ll temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!flag)break;
    }
    for (int i = 0; i < n; i++)printf("%lld\n", arr[i]);//输出

    return 0;
}
```



### `C` 4228 Wink矩阵运算

本题没有什么坑，只要按照矩阵运算的规则对于数据进行运算就可以了。主要考察大家对于一维和二维数组之间思维的转换。

理论上，二维数组能够完成的工作，一维数组都能够完成，只不过二维数组在很多时候都要更方便、更直观好理解一些。

不过注意数据范围，需要使用$long$  $long$类型。

```c
#include<stdio.h>

typedef long long ll;
ll A[100][100], B[100][100], C[100][100];

int main(void) {
    int M, N, P, Q;
    int i, j, k;
    ////input
    scanf("%d%d", &M, &N);
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            scanf("%lld", &A[i][j]);
    scanf("%d%d", &P, &Q);
    for (i = 0; i < P; i++)
        for (j = 0; j < Q; j++)
            scanf("%lld", &B[i][j]);
    ////input

    ////compute
    for (i = 0; i < M; i++) {
        for (j = 0; j < Q; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    ////compute

    ////output
    for (i = 0; i < M; i++) {
        for (j = 0; j < Q; j++) {
            printf("%lld ", C[i][j]);
        }
        printf("\n");
    }
    ////output

    return 0;
}
```



### `D` 4328 Ning的汉明距离

本题是字符串的简单处理加上循环。两个编码的汉明距离其实就是相对应的编码位上不同的个数，我们可以用二维字符数组，实现字符串的读入，然后二重循环遍历每一对编码，计算其汉明距离，更新最小值，注意最小值的初始值不能比n小。

示例代码

```c
#include <stdio.h>
#include <stdlib.h>

char code[102][1005];//储存字符串
int n, m;
int ans = 1005, distance;//ans为最后的最小值，初始值为1005
int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%s", code[i]);

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            distance = 0;//注意变量的重新赋值
            for (int k = 0; k < n; k++)
                distance += (code[i][k] != code[j][k]);

            if (distance < ans)ans = distance;//更新最小值
        }
    }
    printf("%d\n", ans);

    return 0;
}
```



### `E` 4335 惹Shy的二分查找

本题是一个很基础的查找题。可以找到很多可参考的板子代码。

考察二分查找，使用其他的方法应该都是过不去哒（老老实实的写二分吧~~）

```c
#include<stdio.h>

int a[1000002];

int find(int num, int length) {
    int left = 1, right = length;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= num) right = mid;
        else left = mid + 1;
    }
    if (a[left] == num) return left;
    else return -1;
}

int main() {
    int n, m, q;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        scanf("%d", &q);
        int des = find(q, n);
        printf("%d\n", des);
    }
    return 0;
}
```



### `F` 4337 dch做不出毕业设计

这是一个很规范的二分法求根模版。由于题目中函数是单调递减的，所以当`f(mid)>y`，令`L=mid`；反之亦然。

题目的输出要求6位小数的精度，所以程序结束时的区间长度应该小于`1e-6`，选用`1e-8`即可。

由于本题中的函数很特殊，牛顿法、弦截法均不能AC，而二分法则是工程上最简单，最稳定的一种算法，其缺点是速度较慢。

```c
#include<stdio.h>
#include<math.h>

double pi;
double eps = 1e-8;

double fun(double x) {
    return (pi - 2 * x) / 2 / sin(x) / sin(x) - 1 / tan(x);
}

int main() {
    double y, L, R, mid;
    pi = acos(-1);
    scanf("%lf", &y);
    L = 0, R = pi / 2;
    while ((R - L) > eps) {
        mid = (R + L) / 2;
        if (fun(mid) > y) {
            L = mid;
        } else {
            R = mid;
        }
    }
    mid = (R + L) / 2;
    printf("%0.6f", mid);
    printf("\n%0.10f", mid);
    return 0;
}
```



### `G` 4330 PlayFair

本题按照题目要求，首先需要定义一个 $5\times5$ 的矩阵作为密码表，并将密钥填充进去。同时需要一个数组统计哪些字母未出现过，将其按顺序编入密码表。对于多次重复使用的功能 `在密码表中找到X坐标` 、`在密码表中找到Y坐标` 和 `加密明文` 可以通过自定义函数的方式实现，以减少重复代码。

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

char c1, c2;
char mima[5][5];

int findX(char p)//在密码表中找到该字母的X坐标
{
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (mima[i][j] == p) return i;
        }
    }
}

int findY(char p)//在密码表中找到该字母的Y坐标
{
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (mima[i][j] == p) return j;
        }
    }
}

void jiami(char p1, char p2) {
    if (findX(p1) == findX(p2))//p1 p2在同一行的情况
    {
        if (findY(p1) == 4) printf("%c", mima[findX(p1)][0]);//针对最后一行单独讨论
        else printf("%c", mima[findX(p1)][findY(p1) + 1]);
        if (findY(p2) == 4) printf("%c", mima[findX(p2)][0]);//针对最后一行单独讨论
        else printf("%c", mima[findX(p2)][findY(p2) + 1]);
    } else if (findY(p1) == findY(p2))//p1 p2在同一列的情况
    {
        if (findX(p1) == 4) printf("%c", mima[0][findY(p1)]);//针对最右一列单独讨论
        else printf("%c", mima[findX(p1) + 1][findY(p1)]);
        if (findX(p2) == 4) printf("%c", mima[0][findY(p2)]);//针对最右一列单独讨论
        else printf("%c", mima[findX(p2) + 1][findY(p2)]);
    } else printf("%c%c", mima[findX(p2)][findY(p1)], mima[findX(p1)][findY(p2)]);
}

int main() {
#ifdef DEBUG
    freopen("in2.txt","r",stdin);
    freopen("out2.txt","w",stdout);
#endif
    char s[20], in[300];
    int zimu[25] = {0};
    int i, j = 0, k = 0;
    scanf("%s", s);
    scanf("%s", in);
    for (i = 0; i < strlen(s); i++)//将密钥编入密码表
    {
        if (!zimu[tolower(s[i]) - 'a'])//确认密钥中的字母没有出现过
        {
            zimu[tolower(s[i]) - 'a']++;
            mima[j][k] = tolower(s[i]);
            j++;
            if (j == 5) {
                j = 0;
                k++;
            }
        }
    }
    for (i = 0; i < 25; i++)//将密钥中未出现的字母编入密码表
    {
        if (!zimu[i]) {
            mima[j][k] = i + 'a';
            j++;
            if (j == 5) {
                j = 0;
                k++;
            }
        }
    }
    for (i = 0; i < strlen(in);)//对明文进行加密
    {
        if (i == strlen(in) - 1)//明文仅剩一个字母，需要补字母x
        {
            jiami(tolower(in[i]), 'x');
            break;
        } else if (tolower(in[i]) == tolower(in[i + 1]))//明文字母相同，需要插入字母x
        {
            jiami(tolower(in[i]), 'x');
            i++;
        } else //一般情况
        {
            jiami(tolower(in[i]), tolower(in[i + 1]));
            i += 2;
        }
    }
    return 0;
}
```



### `H` 4323 当DJ大师遇上正方形碟片

本题考察的是二维数组的循环移动问题，如果有人对很久之前的"循环位移转圈圈"有印象的话，可以发现，那道题不采用位运算的性质，直接用数组来做也是可以的。

题目的数据强度并不大， 只要能学会每行循环位移即可。但是需要知道 $k$ 可以非常大，而且循环位移 $n$ 次之后没有任何变化，所以直接循环位移 $k % n$ 即可。

#### 空间复杂度 $O(n)$ 的做法

每一行或者每一列进行位移的时候，都采用一个临时数组先表示位移之后的结果，然后再填完了临时数组之后，再从临时数组全部复制回数组当中即可。

```c
#include<stdio.h>

int a[110][110];
int tmp[110];
int n, q;
int op, k;

void shift_single_row(int row_num, int k)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		int target_place = i + k;//挪动k个单位
		if (target_place > n)
		{
			target_place -= n;//循环挪动k个
		}
		tmp[target_place] = a[i][row_num];
	}
	for (i = 1; i <= n; ++i)
	{
		a[i][row_num] = tmp[i];
	}
}

void shift_single_col(int col_num, int k)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		int target_place = i + k;//挪动k个单位
		if (target_place > n)
		{
			target_place -= n;//循环挪动k个
		}
		tmp[target_place] = a[col_num][i];
	}
	for (i = 1; i <= n; ++i)
	{
		a[col_num][i] = tmp[i];
	}
}

void transpose()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = i; j <= n; ++j)
		{
			if (i != j)
			{
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
	}
}

void shift_row(int k)
{
	int move_down = k % n;
	int i;
	for (i = 1; i <= n; ++i)
	{
		shift_single_row(i, move_down);
	}
}

void shift_col(int k)
{
	int move_right = k % n;
	int i;
	for (i = 1; i <= n; ++i)
	{
		shift_single_col(i, move_right);
	}
}

void input_matrix()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

void print_matrix()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	scanf("%d", &n);
	input_matrix();
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				transpose();
				break;
			case 2:
				scanf("%d", &k);
				shift_row(k);
				break;
			case 3:
				scanf("%d", &k);
				shift_col(k);
				break;
			default:
				break;
		}
	}
	print_matrix();
}
```

#### 空间复杂度 $ O(1) $ 的做法

可以得到，如果想让一行循环右移 $k$ 位的话，先对数组整个颠倒，再将前面 $k$ 个数字颠倒，再将后面 $n-k$ 个数字颠倒，就是答案。感兴趣的同学可以回去试一下。

```c
#include<stdio.h>

int a[110][110];
int n, q;
int op, k;

void reverse_single_col(int col_num, int lo, int hi)
{
	while (lo < hi)
	{
		int temp = a[lo][col_num];
		a[lo][col_num] = a[hi][col_num];
		a[hi][col_num] = temp;
		lo++;
		hi--;
	}
}

void reverse_single_row(int row_num, int lo, int hi)
{
	while (lo < hi)
	{
		int temp = a[row_num][lo];
		a[row_num][lo] = a[row_num][hi];
		a[row_num][hi] = temp;
		lo++;
		hi--;
	}
}

void transpose()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = i; j <= n; ++j)
		{
			if (i != j)
			{
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
	}
}

void shift_col(int k)
{
	int move_down = k % n;
	int i;
	for (i = 1; i <= n; ++i)
	{
		reverse_single_col(i, 1, n);
		reverse_single_col(i, 1, move_down);
		reverse_single_col(i, move_down + 1, n);
	}
}

void shift_row(int k)
{
	int move_right = k % n;
	int i;
	for (i = 1; i <= n; ++i)
	{
		reverse_single_row(i, 1, n);
		reverse_single_row(i, 1, move_right);
		reverse_single_row(i, move_right + 1, n);
	}
}

void input_matrix()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

void print_matrix()
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	scanf("%d", &n);
	input_matrix();
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				transpose();
				break;
			case 2:
				scanf("%d", &k);
				shift_col(k);
				break;
			case 3:
				scanf("%d", &k);
				shift_row(k);
				break;
			default:
				break;
		}
	}
	print_matrix();
}
```