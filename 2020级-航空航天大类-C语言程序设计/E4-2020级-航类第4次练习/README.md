# E4-2020级-航类第4次练习

## 题目列表

- A 4313 简单的递归函数~
- B 4272 逆 序 对
- C 4233 网抑人
- D 4262 二荷学姐买基金（续）
- E 4291 ssd学不会理力
- F 4260 大兔子乖乖拔大萝卜
- G 4300 汉诺塔防住了荷家军
- H 4299 小雷枚举排列数 
- I   4257 小迷弟积不出分
- J   4324 多项式相加2021
- K  4317 阿水记不住日期
- L   4281递归括号匹配

### `A`  4313 简单的递归函数~

本题给出了递归函数的公式，类似于阿克曼函数，直接代入公式调用就好了；hint中所说的在计算过程中取模的意思是，当你直接调用递归函数，函数在计算中可能已经超过int范围了，所以最后的返回值也是溢出的结果，这时候再对结果取模也是错误的。注意到函数在计算过程中只有有乘法，利用取模的运算性质可以在函数return时，对return的结果取模，这样得出的结果就可以不会溢出

示例代码

```C
#include <stdio.h>
#define MOD 1000007
#define MAX 11
int a,b;
int fun(int a,int b)
{
    if(b==0)return 1;
    else if(b%2==0)return fun(a*a,b/2)%MOD;
    else return fun(a*a,b/2)*a%MOD;//所谓的计算过程中取模
}
int main(void)
{

    while(scanf("%d%d",&a,&b)!=EOF)
    printf("%d\n",fun(a,b)%MOD);

    return 0;
}
```

题外分析：

通过简单的观察，题目给出的函数 $fun(a,b)$ 其实计算的就是 $a^b$ 。推导过程如下：
$$
a^b=\begin{cases}
1,\ &\text{if}\ \ b=0;\\\\
a^{2\times \frac{b}{2}}=(a^2)^{\frac{b}{2}},\ &\text{else if}\ \ b\%2=0;\\\\
(a^2)^{\frac{b}{2}}\times a,\ &\text{else}.
\end{cases}
$$
这和递归函数给出的公式是一样的，注意 $\frac{b}{2}$ 是整型相除即可。

所以我们的代码也可以写成下面这样

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000007
#define ll long long
ll a,b;
ll pow1(ll m,ll n)
{
    if(n==0)return 1;
    long long ans=1;
    for(int i=0;i<n;i++)
    ans=(ans*m)%MOD;
    return ans;
}
int main(void)
{
    while(scanf("%lld%lld",&a,&b)!=EOF)
    printf("%lld\n",pow1(a,b)%MOD);
    
    return 0;
}
```



给出一个简单的递归函数如下


$$
fun(a,b)=\begin{cases}
1,\ &\text{if}\ \ b=0;\\\\
fun(a*a,b/2),\ &\text{else if}\ \ b\%2=0;\\\\
fun(a*a,b/2)*a,\ &\text{else}.
\end{cases}
$$

现给出 $a,b$，请你计算 $\mathcal{fun(a,b)}$ 的值；答案可能很大，请对 $1,000,007$ 取模；



### `B`  4272 逆 序 对

本题主要考察了逆序对的概念，了解概念之后，只需要循环就可以找到逆序个数了。

```c
#include <stdio.h>

int main() {
    int n, i, j, cnt = 0;
    int num[10000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (num[j] < num[i]) {
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}
```



### `C` 4233 网抑人

我们把歌曲从$1$ ~ $n$编号，设$n$在二进制下有$bit$位，那么所有歌曲编号最多只有$bit$位。

举个例子$n=11$，二进制为$1011$， $bit=4$。（从右往左是第$1、2、3、4$位）

我们求解的思路是确定那首网抑歌曲的编号，即确定它的二进制每一位是多少。

我们第$1$次听第一位为$1$的所有歌，如果抑了则第一位为$1$，否则为$0$.

第$2$次听第二位为$1$的所有歌，如果抑了则第二位为$1$，否则为$0$.

第$3$次听第三位为$1$的所有歌，如果抑了则第三位为$1$，否则为$0$.

$......$

第$bit$次听第$bit$位为$1$的所有歌，如果抑了则第$bit$位为$1$，否则为$0$.

答案是$bit$次。

但是有一个情况要特判，当$n$巧好是$2$的整数幂时（如$n=8$，二进制为$1000$），我们并不用听第$bit$位为$1$的歌，因为它只有一首且就是第$n$首。如果前$bit-1$次听完后都没有抑，那么那首歌就是第$n$首；如果前$bit-1$次抑了，那么便不可能是第$bit$位为$1$的歌。所以此时答案是$bit-1$.

```
要想不特判，可以在一开始让n--，答案就是n现在的二进制位数。
```

```c
#include<stdio.h>

int n, Ans;

int main() {
    scanf("%d", &n);
    n--;
    while (n) {
        ++Ans;
        n >>= 1;
    }
    printf("%d", Ans);
    return 0;
}
```



### `D`  4262 二荷学姐买基金（续）

本题可以直接枚举所有方案，下面是枚举的做法，时间复杂度$O(n^2)$

```c
#include<stdio.h>

long long value[10005];

int main()
{
	int n, i, j, L, R;
	long long cur, ans;
	while (scanf("%d", &n) != EOF)
	{
		ans = -1;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &value[i]);
		}
		for (i = 1; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				cur = value[j] - value[i - 1];
				if (cur < 0)
				{
					continue;
				}
				if (cur > ans)
				{
					ans = cur;
					L = i - 1;
					R = j;
				}
			}
		}
		if (ans <= 0)
		{
			printf("No profit!\n");
		}
		else
		{
			printf("%lld %d %d\n", ans, L + 1, R + 1);
		}
	}
}
```

提供一个$O(n)$的做法，可供参考。

```c
#include<stdio.h>
#include<string.h>

typedef long long ll;
ll stock[10010];
int skip[10010];
ll res, cur, start, finish;
int n;

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) scanf("%lld", stock + i);
        memset(skip, 0, sizeof(skip));
        res = cur = start = finish = 0;

        for (int i = 1; i <= n; ++i) {
            if (skip[i]) continue;
            for (int j = i + 1; j <= n; ++j) {
                if (stock[j] <= stock[i]) {
                    i = j;
                    continue;
                }
                skip[j] = 1;
                if (stock[i] > stock[j]) continue;
                cur = stock[j] - stock[i];
                if (cur > res)
                    res = cur, start = i, finish = j;
            }
        }
        if (res > 0) printf("%lld %lld %lld\n", res, start, finish);
        else puts("No profit!");
    }
}
```



### `E`  4291 ssd学不会理力

本题只是一个简单的循环计算题，提供了通过传递数组参数来使自定义函数返回数组内容的代码供同学们学习使用，如果不用这一代码也可以自己写叉积部分的内容。

```c
#include<stdio.h>
#include<stdlib.h>

void CrossProduct(long long Result[], long long V1[], long long V2[]) {
    Result[0] = V1[1] * V2[2] - V1[2] * V2[1];
    Result[1] = V1[2] * V2[0] - V1[0] * V2[2];
    Result[2] = V1[0] * V2[1] - V1[1] * V2[0];
// 本函数可以通过向参数中传递储存结果的数组，来实现在main函数中获得计算结果的功能
// 在实践中也常用这一方法来使函数返回一个数组
// 本题限定了坐标维数仅有三维,如果输入的数组长度不能在编写时确定的话，还应该输入一个整数代表数组的长度
}

int main() {
    int DataNum = 0;
    long long Force[3] = {}; //输入的力
    long long Base[3] = {}; //简化点
    long long Position[3] = {}; //力的作用点
    long long FinalForce[3] = {}; //最终合成的力矢
    long long FinalTorque[3] = {}; //最终合成的力矩
    scanf("%d", &DataNum);
    scanf("%lld %lld %lld", &Base[0], &Base[1], &Base[2]);
    for (int i = 0; i < DataNum; i++) {
        scanf("%lld %lld %lld", &Force[0], &Force[1], &Force[2]);
        scanf("%lld %lld %lld", &Position[0], &Position[1], &Position[2]);
        for (int i = 0; i < 3; i++) {
            Position[i] -= Base[i];
        }
        long long Torque[3] = {};//用于储存计算结果的数组
        CrossProduct(Torque, Position, Force); //输入储存结果的数组,相对位置矢量,力矢量,得到力矩结果
        for (int i = 0; i < 3; i++) {
            FinalForce[i] += Force[i];
            FinalTorque[i] += Torque[i];
        }
    }
    printf("%lld %lld %lld\n", FinalForce[0], FinalForce[1], FinalForce[2]);
    printf("%lld %lld %lld", FinalTorque[0], FinalTorque[1], FinalTorque[2]);
    return 0;
}
```



### `F`  4260 大兔子乖乖拔大萝卜

本题考察的是对于高精度与数组或者字符串之间的关系。以后在做高精度相关的问题时，需要先转成数组或者字符串，再比较大小。

本题依旧是只需要找出最大的前3个就可以了，所以只要留下3个数组，分别存储第一、第二和第三就可以了。每一次枚举比较，以决定能否替代这3个中的一个。

本题可以通过先输入字符串之后，优先比较数组长度，如果长度相同，再从高到低比较每一位，直到出现不一致为止。

**致歉:本次由于出题人一开始造数据的疏忽，导致最后放hack数据的时间较晚，且最后的几组出现了`\r`的问题，从下次之后助教们后注意这一点，在避免出现`\r`的同时，也提醒大家考虑到`\r`可能会带来的问题。**

```c
#include<stdio.h>
#include<string.h>

char first[10010], second[10010], third[10010], tmp[10010];
int n;

int bigger(char a[], char b[])
{
	int lena = strlen(a), lenb = strlen(b);
	if (lena != lenb)
	{
		return lena > lenb;//如果a的位数比b的位数大，那a一定比b大
	}
	//如果位数一致，直接从高到低比较
	//虽然是字符串 但是'0'到'9'的ASCII也是从小到大排列的，可以直接比较
	int i;
	for (i = 0; i < lena; ++i)
	{
		if (a[i] > b[i])
		{
			return 1;//大于
		}
		else if (a[i] < b[i])
		{
			return 0;//小于
		}
	}
	return 0;//如果相等，a不大于b，需要返回0
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", tmp);
		if (bigger(tmp, first))
		{
			strcpy(third, second);
			strcpy(second, first);
			strcpy(first, tmp);
		}
		else if (bigger(tmp, second))
		{
			strcpy(third, second);
			strcpy(second, tmp);
		}
		else if (bigger(tmp, third))
		{
			strcpy(third, tmp);
		}
	}
	puts(first);
	puts(second);
	puts(third);
}
```

如果你提前学过了字符串相关的函数库`string.h`的部分函数，甚至可以直接调用`strcmp`函数来解决问题。

```c
#include<stdio.h>
#include<string.h>

char first[10010], second[10010], third[10010], tmp[10010];
int n;

int bigger(char *a, char *b) {
    int lena = strlen(a), lenb = strlen(b);
    if (lena != lenb) return lena > lenb;
    else return strcmp(a, b) > 0;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", tmp);
        if (bigger(tmp, first)) {
            strcpy(third, second);
            strcpy(second, first);
            strcpy(first, tmp);
        } else if (bigger(tmp, second)) {
            strcpy(third, second);
            strcpy(second, tmp);
        } else if (bigger(tmp, third)) {
            strcpy(third, tmp);
        }
    }
    puts(first);
    puts(second);
    puts(third);
}
```



### `G`  4300 汉诺塔防住了荷家军

当圆盘数足够多时，三柱汉诺塔的移动次数会远远超出`unsigned long long`的范围，所以可以采用`pow`函数进行计算，转化为`double`数据类型进行比较，`double`的数据范围为$1.7*10(-308)～1.7*10(308)$,足够用来比较

```c
#include<stdio.h>
#include<math.h>

int main(void)
{
	int min,x, f[310] = { 0,1,3 };
	int i;
	for (i = 3; i <= 300; i++)
	{
		min = 999999999;
		for (x = 1; x < i; x++)
		{
			if (2 * f[x] + pow(2, i - x) - 1 < min)
			{
				min = 2 * f[x] + (int)pow(2, i - x) - 1;
			}
		}
		f[i] = min;
	}
	int n;
	while(~scanf("%d", &n))
	{
		printf("%d\n", f[n]);
	}
	return 0;
}
```



### `H`  4299 小雷枚举排列数 

本题主要考查**递归**的基础知识，是一个很好的模板题，在以后的进阶题型中很常见。  

基本思路是先预留待填充的数组，利用递归逐位向数组里填充数，只要之前没有用过的数都可以填充进待填充的位置。填充满$n$位后输出结果。  

这里的输出结果在今后的进阶题目中可能很有用。

```c
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int a[1000];//存放生成的数 
int book[1000]; //表示递归生成到哪一位置的数 

void amn_out(int pos, int m, int n)//向a[pos]填数 m中取n 
{

    if (pos == n + 1)//递归边界
    {
        //此时a[1]-a[n]填满数 顺次输出为待求全排列
        for (int j = 1; j <= n - 1; j++) {
            printf("%d ", a[j]);
        }
        printf("%d\n", a[n]);

        return;
    }
    for (int i = 1; i <= m; i++) {
        if (book[i] == 0)//如果i没有在数组里面
        {
            a[pos] = i;
            book[i] = 1;
            amn_out(pos + 1, m, n);//向a[pos+1]填数            
            book[i] = 0;//收回，试下一个数

        }
    }
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    amn_out(1, m, n);

    return 0;
}
```



### `I`  4257 小迷弟积不出分

正常解法：

本题关键，如何产生[down,up]的随机数

我们通过rand()%32768/32768.0的方式产生了[0,1)的浮点数

再乘(up-down)产生了[0,up-down)的浮点数

最后加down即可产生[down,up)的浮点数，又因为在众多的浮点数中up这一个值可以忽略不计

因此我们产生了[down,up]的浮点数

回到本题，注意本题a<0，因此值域必属于(0,1]，我们产生x∈[down,up]，y∈[0,1]的随机数

最后我们看多少个点在x轴和函数中间 也就是小于(等于)exp(a*x*x) 最后除以总点数乘以总面积，就是所求的面积也即积分值

或者说，本题的数据范围很小，可以利用积分本身的意义，将区间拆成很多份累加也可以

另：在这里对于更新改判误伤的同学表示抱歉TAT

小迷弟很想做一个好人 但也想做一个负责任的助教 希望大家尽量用常规方法来做题

综上所述，有代码：

```c
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double a, down, up, x, y;

int main() {
    int num = 0, i;
    scanf("%lf %lf %lf", &a, &down, &up);
    for (i = 1; i <= 3000000; i++) {
        x = rand() % 32768 / 32768.0 * (up - down) + down;//这里很关键，貌似oj上的随机数产生了0~INT_MAX的数字 因此取模很有必要 不然会一直wa0.333
        y = rand() % 32768 / 32768.0;
        if (y < exp(a * x * x)) num++;
    }
    printf("%lf", num / 3000000.0 * (up - down));
    return 0;
}
```



### `J`  4324 多项式相加2021

对于本道题，如果多项式的每一项指数部分都在 $[0, 10^5]$ 这样的范围内，则我们只需要设置一个数组 `int coe[100005]`，每次读入的时候以指数部分作为数组下标，将系数记录进 `coe` 数组中即可完成任务。但本题中指数范围较大（`int` 范围，甚至可以是负数），直接采用上述方法进行计算将会导致数组越界，因此需要考虑其他方法。



注意到题目中的 $f(x), g(x)$ 都是以**严格降序**给出的，因此可以考虑这样一种做法：



\1. 用两个变量 $p, q$ 记录当前正在处理 $f(x), g(x)$ 从大到小的第 $i$ 项。一开始时 $p = q = 1$。

\2. 比较第 $p$ 项和第 $q$ 项的指数部分：

​	* 若指数部分相同，说明这两项的系数部分在结果中应当相加，并将 $p, q$ 都向后移动一位；

​	* 若 $p$ 对应的指数部分较大，说明只有 $f(x)$ 在结果的这一项中出现，并将 $p$ 向后移动一位；

​	* 若 $q$ 对应的指数部分较大，说明只有 $g(x)$ 在结果的这一项中出现，并将 $q$ 向后移动一位；



当 $p, q$ 将 $f(x), g(x)$ 的每一项都计算之后，最后结果的多项式也被计算出来了。可以发现，通过该方法得到的多项式，其指数部分也是严格递减的。由于 $p, q$ 只会移动最多 $n + m$ 次，因此总循环次数不超过 $n + m$ 次，可以在题目要求的时间范围内完成计算。



另外需要注意的是，本题的系数可能超出 `int` 范围，因此需要采用 `long long` 进行存储。

示例程序1：

```c
#include <stdio.h>

#define N (200000 + 5)

long long a[N], b[N];
long long s[N], t[N];

int main() {
    int n, m;
    int p = 1, q = 1;
    int i;

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i], &s[i]);
    for (i = 1; i <= m; i++)
        scanf("%lld%lld", &b[i], &t[i]);

    while (p <= n || q <= m) {
        if ((p <= n && q <= m && s[p] > t[q]) || q > m) {
            // 只计算 p 的情况：p 对应的指数较小，或另一个数组已经扫描完了
            printf("%lld %lld ", a[p], s[p]);
            p++;
        } else if ((p <= n && q <= m && s[p] < t[q]) || p > n) {
            // 只计算 q 的情况：q 对应的指数较小，或另一个数组已经扫描完了
            printf("%lld %lld ", b[q], t[q]);
            q++;
        } else {
            // 合并系数的情况：能来到这个分支，一定是 pq 都没有扫描完，且 f 的第 p 项和 g 的第 y 项系数相等
            if (a[p] + b[q] != 0)
                printf("%lld %lld ", a[p] + b[q], t[q]);
            p++, q++;
        }
    }

    return 0;c
}
```

示例程序2：

这种写法将计算结果先存下来，最后一起输出。

```c
#include <stdio.h>

long long poly_f_coe[100010];
long long poly_f_pow[100010];
long long poly_g_coe[100010];
long long poly_g_pow[100010];

long long poly_ans_coe[200020];
long long poly_ans_pow[200020];

int main() {
    int n, m, i;
    int current_i = 0;
    int current_j = 0;
    int current_k = 0;

    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%lld%lld", &poly_f_coe[i], &poly_f_pow[i]);
    }
    for (i = 0; i < m; i++) {
        scanf("%lld%lld", &poly_g_coe[i], &poly_g_pow[i]);
    }

    while (current_i < n || current_j < m) {
        if (current_i < n) {
            if (current_j < m) {
                if (poly_f_pow[current_i] > poly_g_pow[current_j]) {
                    poly_ans_coe[current_k] = poly_f_coe[current_i];
                    poly_ans_pow[current_k] = poly_f_pow[current_i];
                    current_k++;
                    current_i++;
                } else if (poly_f_pow[current_i] < poly_g_pow[current_j]) {
                    poly_ans_coe[current_k] = poly_g_coe[current_j];
                    poly_ans_pow[current_k] = poly_g_pow[current_j];
                    current_k++;
                    current_j++;
                } else {
                    poly_ans_coe[current_k] = poly_f_coe[current_i] + poly_g_coe[current_j];
                    poly_ans_pow[current_k] = poly_f_pow[current_i];
                    current_k++;
                    current_i++;
                    current_j++;
                }
            } else {
                poly_ans_coe[current_k] = poly_f_coe[current_i];
                poly_ans_pow[current_k] = poly_f_pow[current_i];
                current_k++;
                current_i++;
            }
        } else {
            poly_ans_coe[current_k] = poly_g_coe[current_j];
            poly_ans_pow[current_k] = poly_g_pow[current_j];
            current_k++;
            current_j++;
        }
    }

    for (i = 0; i < current_k; i++) {
        if (poly_ans_coe[i] != 0) {
            if (i != current_k - 1) {
                printf("%d %d ", poly_ans_coe[i], poly_ans_pow[i]);
            } else {
                printf("%d %d\n", poly_ans_coe[i], poly_ans_pow[i]);
            }
        }
    }
c
    return 0;
}
```



### `K`  4317 阿水记不住日期

本题为书上例题的修改版

需要注意以下几点：

1.运用`Zeller`公式进行计算式，要将1，2月份看作上一年的13，14月份

2.当ω为负数时，需要对其加7，将其转换为非负数

3.输出的数字应该居左输出

```c
#include <stdio.h>
int main()
{
    int year, month, day, weekday, monthDays, leap, i;
    scanf("%d%d", &year, &month);
    if (month == 1 || month == 2)
    {
        year--;
        month += 12;
    }
    weekday = (year % 100 + year % 100 / 4 + year / 100 / 4 - 2 * (year / 100) + (13 * (month + 1) / 5));
    while (weekday < 0)
        weekday += 7;
    weekday %= 7;
    if (month > 12)
    {
        year++;
        month -= 12;
    }
    leap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        leap = 1;

    printf("%04d.%02d\n", year, month);
    for (int i = 0; i < 33; i++)
        printf("-"); 
    printf("  \n");
    printf("Sun  Mon  Tue  Wen  Thu  Fri  Sat  \n");
    for (int i = 0; i < 33; i++)
        printf("-"); 
    printf("  \n");

    for (i = 0; i < weekday; i = i + 1)
        printf("     "); 
    if (month == 4 || month == 6 || month == 9 || month == 11)
        monthDays = 30;
    else if (month == 2)
    {
        if (leap == 1)
            monthDays = 29;
        else
            monthDays = 28;
    }
    else
        monthDays = 31;
    for (day = 1; day <= monthDays; day = day + 1)
    {
        printf("%-5d", day); 
        weekday = weekday + 1;
        if (weekday == 7)
        {
            weekday = 0;
            printf("\n");
        }
    }
    return 0;
}
```



### `L`  4281递归括号匹配

这是一道不难的填空题。只要你掌握了递归的原理，很容易完成填空：

```c
#include<stdio.h>

int Parenthesis()
{
	char c=getchar();
	if(c==')'||c==']'||c=='}'||c==EOF)
	{
		ungetc(c,stdin);//与getchar相反，向读入中退回一个字符
		return 1;
	}
	else if(c=='(')
	{
		int temp=Parenthesis();
		if(temp==0)//调用匹配失败
		{
			return 0;
		}
		c=getchar();
		if(c!=')')
		{
			return 0;
		}
		temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		return 1;
	}
	else if(c=='[')
	{
		int temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		c=getchar();
		if(c!=']')
		{
			return 0;
		}
		temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		return 1;
	}
	else if(c=='{')
	{
		int temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		c=getchar();
		if(c!='}')
		{
			return 0;
		}
		temp=Parenthesis();
		if(temp==0)
		{
			return 0;
		}
		return 1;
	}
}

int Matching()
{
	int ans=Parenthesis();//括号匹配
	if(ans==0)
	{
		return 0;
	}
	char c=getchar();//匹配完应该读完
	if(c!=EOF)
	{
		return 0;
	}
	return 1;
}

int main()
{
	int ans=Matching();
	if(ans==1)
	{
		printf("AC\n");
	}
	else
	{
		printf("CE\n");
	}
}
```





