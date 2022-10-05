# C8-Solution

## `A` 4415 选择题
### 答案

`CCCCC`

#### 第一题

- A. 错误，二元运算符中成员选择（.）和成员选择（->）的优先级高于正号和负号
- B. 错误，运算符还有三元运算符（三目运算符），即条件运算符（?:）
- C. 正确
- D. 错误，`==` 的优先级高于 `&` ，因此 `if(x & 11 == 10)` 可以写为 `if(x & 0)`

#### 第二题

- A. 正确
- B. 正确
- C. 错误，`precision` 还可以为 $0$
- D. 正确

#### 第三题

- A. 错误，在ASCII编码表中小写字母都在大写字母后面
- B. 错误，`a` 指向一个由 $50$ 个指向 `int` 型变量的指针组成的数组
- C. 正确
- D. 错误，`abs()` 函数属于 `stdlib.h`

#### 第四题

- A. 错误，通过数组下标完成的操作都能通过指针实现
- B. 错误，指针在储存时占用的储存空间大小是固定的
- C. 正确
- D. 错误， `double (*abd)(double, double);` 是合法的

#### 第五题

- A. 正确
- B. 正确
- C. 错误，`unsigned int` 所能储存的最大正整数是 $4294967295$ ， `int` 所能储存的最大正整数 $2147483647$
- D. 正确

## `B` 4414 三角形面积·改

### 题目分析
本题不需要用到数组，给定数据组数`n`，可直接用`for`或`while`进行多次运算，注意数据类型需要使用`double`类型以及结果保留一位小数

### 示例代码
```c
#include<stdio.h>

int main()
{
    int n;
    double a, b, c, p,ans;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%lf%lf%lf", &a, &b, &c);
        p = (a + b + c) / 2;
        ans = p * (p - a) * (p - b) * (p - c);
        printf("%.1f\n", ans);
    }
}
```

## `C` 4340 大化实验好难啊
### 题目分析

本题中的砝码实际上就是二进制中的对应的位，该位为$1$即选择这一砝码，为$0$则不选择，每种砝码只有一个且二进制数与十进制数一一对应，所以是一个判断对应数二进制补码为$1$的位的问题。

### 示例代码

```c
#include <stdio.h>

int main()
{
    unsigned int Mass = 0;
    scanf("%u", &Mass);
    for (int i = 0; i < 32; i++)
    {
        unsigned int ToolNum = 1u << i;
        if (ToolNum & Mass)
            printf("%u\n", ToolNum);
    }
    return 0;
}
```

## `D` 4418 301 Moved Permanently 2021
### 题目分析
本题主要考察重定向，可以参考课件中的 `freopen` 的使用方法。
感兴趣的同学也可以了解一下 `FILE` 类型的用法。
### 示例代码
```c
#include <stdio.h>

int main()
{
    freopen("301.txt", "w", stdout);
    int n, op, i;
    long long a1, b1;
    double a2, b2;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &op);
        if (op == 1 || op == 2)
        {
            scanf("%lld%lld", &a1, &b1);
            printf("%lld", a1 + b1);
        }
        else
        {
            scanf("%lf%lf", &a2, &b2);
            printf("%.4f", a2 + b2);
        }
        if (i != n)
            printf("\n");
    }
    return 0;
}
```
## `E` 4416 位 互 换

### 题目分析

本题是一个**位运算**的基础题目，并没有涉及数据范围等坑点。大致需要掌握的基础技能有：取出特定位、特定位置零、特定位置一个指定数。  

当然，涉及位运算符的时候，运算符优先级容易出错，一劳永逸的方法是大家可以全部加上括号。

### 示例代码

```c
#include <stdio.h>

int main()
{
    int a, m, n, m_bit, n_bit, result;

    while (scanf("%d%d%d", &a, &m, &n) != EOF)
    {
        //分别提取第m n位
        m_bit = (a & (1 << m)) >> m;
        n_bit = (a & (1 << n)) >> n;
        //指定位置零
        a &= ~(1 << m);
        a &= ~(1 << n);
        //指定位置指定数
        a |= m_bit << n;
        a |= n_bit << m;
        //输出
        printf("%d\n", a);
    }
    return 0;
}
```

## `F` 4393 剔除名单
### 题目分析

字符串处理，反复的按顺序找依次出现的`'c' 'b' 'j'`并标记,最后如果找不出了就遍历字符串输出没有被标记的字符。

出题灵感是`debug`这个题 传送门：https://accoding.cn/problem/1071/

### 示例代码
```c
#include <stdio.h>
#include <string.h>

int decbj(char *str, int n)
{
    int i, j = 0;
    int pos[3] = {0};
    char *cbj = "cbj";
    for (i = 0; i < n; i++)
    {
        if (str[i] == cbj[j])
        {
            pos[j] = i;
            j++;
            if (j >= 3)
            {
                str[pos[0]] = '\t';
                str[pos[1]] = '\t';
                str[pos[2]] = '\t';
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    char str[1024] = {0};
    fgets(str, 1024, stdin);
    int i, l = strlen(str);
    while (decbj(str, l)) ;
    for (i = 0; str[i]; i++)
    {
        if (str[i] != '\t')
            putchar(str[i]);
    }
    return 0;
}
```
## `G` 4347 轰炸
### 题目分析

本题可定义两个空间至少为$n*m$的数组进行记录每一个坐标被轰炸的次数以及最后一次轰炸的轮数，首先对数组进行初始化，接下来对于每一个被轰炸过的坐标对应的数组$+1$，并且记录论述，最后输入关键点的坐标，若关键点对应的值非$0$，则输出`Y`以及对应的两个整数，如果关键点对应的值为$0$，则输出`N`。

### 示例代码
```c
#include<stdio.h>

int main()
{
    int n, m, x, y,a[310][310]={},x1,y1,x2,y2,xi,yi,b[310][310];
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int k = 1; k <= x;k++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int i = x1; i <= x2;i++)
            for (int j = y1; j <= y2;j++)
            {
                a[i][j]++;
                b[i][j] = k;
            }
    }
    while(y--)
    {
        scanf("%d%d", &xi, &yi);
        if(a[xi][yi]>0)
            printf("Y %d %d\n", a[xi][yi], b[xi][yi]);
        else
            printf("N\n");
    }
}
```

## `H` 4421 两面包夹芝士

### 题目解析

本题主要考察函数递归以及记忆化的方法。

假设荷沸水的总量为 $x$ 个单位，那么净化 $x$ 个单位的荷沸水所需要的最小费用可以用函数 $f(x)$ 来表示：

$$f(x)=min\left(\begin{matrix} f(x-1)+c1 & \text{whenever}\\ f(\frac{x}{2}) + c2 & \text{only when}\ x\ mod\ 2=0\\ f(\frac{x}{3}) + c3 & \text{only when}\ x\ mod\ 3=0\end{matrix}\right)$$

其中 $min$ 代表最小值函数，$mod$ 代表求余运算。同学们看到这里应该已经意识到可以使用递归来解决这个问题了，但是直接递归可能会导致 $\text{TLE}$ ，因为直接递归可能会对同一情况进行多次运算，导致不必要的时间开销。比如，计算 $f(12)$ 的时候会计算 $f(6)$ 和 $f(3)$，计算其中的 $f(6)$ 的时候又会计算 $f(3)$，可以发现 $f(3)$ 在这个情况中至少运算了两次，其中第二次计算实际上是不必要的，因为之前计算过一次了。因此我们可以开一个数组存储计算过的 $f(x)$ ，在递归函数即检查荷沸水的总量为 $x$ 个单位时的最小花费是否被计算过，若计算过直接返回结果即可。

当然这道题目也可以采用循环来计算（动态规划），状态转移方程和题解开头给出的公式一样。

### 示例代码——递归

```c
#include <stdio.h>
int s[100007], c1, c2, c3;

int dfs(int x) {
    if (s[x] != 0) {
        return s[x];
    }
    
    int min = dfs(x - 1) + c1;
    if (x % 2 == 0) {
        int r = dfs(x / 2) + c2;
        min = r < min ? r : min;
    }
    if (x % 3 == 0) {
        int r = dfs(x / 3) + c3;
        min = r < min ? r : min;
    }

    return s[x] = min;
}

int main()
{
    int n;
    scanf("%d %d %d", &c1, &c2, &c3);
    s[1] = c1;
    while (~scanf("%d", &n)) {
        printf("%d\n", dfs(n));
    }
}
```

### 示例代码——循环

```c
#include <stdio.h>
int s[100007], c1, c2, c3;

int main()
{
    int n;
    scanf("%d %d %d", &c1, &c2, &c3);
    s[1] = c1;
    for (int i = 2; i <= 100000; i++) {
        s[i] = s[i - 1] + c1;
        if (i % 2 == 0) {
            int r = s[i / 2] + c2;
            s[i] = r < s[i] ? r : s[i];
        }
        if (i % 3 == 0) {
            int r = s[i / 3] + c3;
            s[i] = r < s[i] ? r : s[i];
        }
    }
    while (~scanf("%d", &n)) {
        printf("%d\n", s[n]);
    }
}
```
## `I` 4419 k-排列
### 题目解析

本题主要考查快速排序、二分查找以及排列的思想。

首先题目给出了提示，可以尝试设计函数以 $O(n)$ 的时间复杂度求出某个 $1$ 到 $n$ 的全排列在字典序中的前面或后面一个全排列，那我们首先来解决这个问题。具体的做法参见这个[链接](https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/)。虽然这个链接给出的是求下一个排列的做法，但是求出上一个排列的做法也可以如法炮制，这个问题就留给同学们自己思考（其实只要改变两个不等号的方向即可）。

有了求出某个全排列的上/下一个全排列的方法，这样我们就可以求出某个全排列 $P_i$ （下标 $i$ 代表它在字典序中的编号）的上/下 $k$ 个全排列 $P_{i-k}$ 和 $P_{i+k}$，这样我们自然可以想到一种很基本的做法：遍历给出的所有全排列，判断它是否在 $P_{i-k}$ 和 $P_{i+k}$ 之间，如果是就拿出来，最后排序输出。这样当然可行，但是在 $m$ 和 $q$ 很大的情况下会超时，我们要想办法优化时间复杂度。

首先我们注意到题目要求最后以字典序输出，我们不妨一开始就对给出的 $m$ 个全排列按照字典序升序排序，对于每次询问给出的 $P_i$ ，查找 $m$ 个全排列中的 $P_x$ 和 $P_y$ ，使得 $[x,y] \subseteq [i-k,i+k]$ ，之后输出 $m$ 个全排列中的 $P_x$ 和 $P_y$ 之间的全排列即可。这里如果我们采用顺序查找的方式，时间复杂度其实不会有很明显的优化。我们可以注意到， $m$ 个全排列按照字典序升序排序后，我们可以采用二分查找的方式，查找我们需要的 $P_x$ 和 $P_y$ 。算法的主要流程描述如下：

```
输入n,m,m个全排列,q
按照字典序升序排序m个全排列
while q--:
	输入p(i)和k
	求出p(i-k),p(i+k)
	二分查找p(x),p(y)
	from p=p(x) to p=p(y)
		输出p
	if 什么都没有输出：
		错误处理
```

这种方法可过此题，如果过多调用了时间复杂度为 $O(n)$ 的求上/下一个全排列的函数，可能会导致超时。

在上述方法中求出全排列 $P_{i-k}$ 和 $P_{i+k}$ 的时间复杂度实际上为 $O(k\times n)$，仍然有优化空间。如果我们使用[康托展开](https://www.acwing.com/blog/content/1861/)，可以至多以 $O(n^2)$ 的时间复杂度求出 $P_{i-k}$ 和 $P_{i+k}$ ，由于 $n$ 一般远小于 $k$ ，这个做法可以节省很多时间，有兴趣的同学可以了解一下。

*康托展开实际上是至少以 $O(n^2)$ 的时间复杂度求出全排列 $P_i$ 的序号 $i$ 的算法，可以用它进一步优化我们的做法。

### 示例代码1

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char pl[100007][20];
/*
 * sgn == 1  next
 * sgn == -1 previous
 */
int next_prev_p(char *p, int n, int sgn) {
    
    int j = n - 1, i = n - 2;
    while ((p[i] - p[j]) * sgn > 0) {
        i--;
        j--;
        if (i < 0) {
            return 0;
        }
    }
    for (int k = n - 1; k > i; k--) {
        if ((p[k] - p[i]) * sgn > 0) {
            char temp = p[k];
            p[k] = p[i];
            p[i] = temp;
            int x = j, y = n - 1;
            while (x - y < 0) {
                char temp = p[x];
                p[x] = p[y];
                p[y] = temp;
                x++;
                y--;
            }
            break;
        }
    }
    
    return 1;
}

int cmp(const void *a, const void *b) {
    
    return strcmp((char *)a, (char *)b);
}

int lower_bound(char *key, int n) {
    
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (strcmp(key, pl[mid]) <= 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int upper_bound(char *key, int n) {
    
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (strcmp(key, pl[mid]) >= 0) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main(int argc, const char * argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%s", (char *)(&pl[i]));
    }
    
    qsort(pl, m, sizeof(pl[0]), cmp);
    
    int q, k;
    char l[20], r[20];
    scanf("%d", &q);
    while (q--) {
        scanf("%s %d", l, &k);
        strcpy(r, l);
        int rl = 1, rr = 1;
        while (k-- && (rl || rr)) {
            rl = next_prev_p(l, n, -1);
            rr = next_prev_p(r, n, 1);
        }
        int kl = lower_bound(l, m), kr = upper_bound(r, m);
        for (int i = kl; i < kr; i++) {
            printf("%s\n", pl[i]);
        }
        if (kr <= kl) {
            printf("No such permutation.\n");
        }
    }
}
```

### 示例代码2——康托展开

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
struct permutation {
    char p[20];
    ll id;
};
struct permutation pl[100007];
ll pn[20], digit[256];

ll cantor(char *p, int n) {
    ll u[20] = {0}, a, ans = 0;
    for (int i = 0; i < n; i++) {
        a = digit[p[i]];
        u[a] = 1;
        for (int j = 1; j <= digit[p[i]]; j++) {
            a -= u[j];
        }
        ans += a * pn[n - i - 1];
    }
    
    return ans + 1;
}

int cmp(const void *a, const void *b) {
    
    struct permutation *pa = (struct permutation *) a;
    struct permutation *pb = (struct permutation *) b;
    if (pa->id < pb->id) return -1;
    else if (pa->id > pb->id) return 1;
    else return 0;
}

int lower_bound(struct permutation *p, int n) {
   
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (cmp(p, &pl[mid]) <= 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void init(int n) {
    
    pn[0] = 1;
    for (int i = 1; i <= n; i++)
        pn[i] = i * pn[i - 1];
    ll d = 0;
    for (char c = '0'; c <= '9'; c++)
        digit[c] = d++;
    for (char c = 'A'; c <= 'F'; c++)
        digit[c] = d++;
}

int main(int argc, const char * argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++) {
        scanf("%s", pl[i].p);
        pl[i].id = cantor(pl[i].p, n);
    }
    
    qsort(pl, m, sizeof(struct permutation), cmp);

    int q, k;
    struct permutation p;
    scanf("%d", &q);
    while (q--) {
        scanf("%s %d", p.p, &k);
        ll pos = cantor(p.p, n);
        ll l = pos - k < pn[1] ? pn[1] : pos - k;
        ll r = pos + k > pn[n] ? pn[n] : pos + k;
        p.id = l;
        int kl = lower_bound(&p, m);
        p.id = r + 1;
        int kr = lower_bound(&p, m);
        for (int i = kl; i < kr; i++) {
            printf("%s\n", pl[i].p);
        }
        if (kr <= kl) {
            printf("No such permutation.\n");
        }
    }
}
```

