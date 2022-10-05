# A - 国庆快乐！：）

| 难度  |         考点          |
| :---: | :-------------------: |
|   1   | `printf()` 的换行输出 |

## 题目分析

仿照 Hello World 程序中的输出样例，输出题目中要求的字符串即可。

（请直接复制题目中的输出数据到你的程序中，避免手动输入错误）

## 示例程序

```c++
#include <stdio.h>

int main() 
{
    printf("2020/10/10\n");
    printf("I love you, China");

    return 0;
}
```




# B - Hinge Loss

| 难度  |     考点      |
| :---: | :-----------: |
|   2   | `if` 判断语句 |

## 题目分析

本题需要依次判断三种不同情况并分别处理，采用多个 `if` 语句可以实现分类判断，并且注意要覆盖所有情况。另外，判断相等时要用 `a == b` 而不是 `a = b`，输出字符串时建议直接从题目中复制并粘贴。

使用 `scanf()` 输入变量时，需要特别注意：

1. 变量前一定要加取地址符 `&`
2. 如果输入两个或多个变量，则各个 `%d` 之间不要有空格


## 示例程序

```c++
#include<stdio.h>

int main()
{
    int a, x;
    scanf("%d%d", &x, &a);
    if (x > a)
		printf("0");
    if (x <= a)
        printf("%d", -x + a);
    if (x == a)
        printf("\nIndifferentiable Point"); // 注意此处判断相等的表达式。

    return 0;
}

```




# C - 五则运算

| 难度  |              考点              |
| :---: | :----------------------------: |
|   2   | 数学运算，`if...else` 判断语句 |

## 题目分析

本题来源于 PPT 中的例题。

题目保证了结果不会超出 `int` 范围，因此对于加减乘运算只要直接用 `printf()` 输出结果即可，注意每输出一行都要用换行符 `\n` 进行换行。

对于整除和取模操作，需要用 `if` 额外判断除数是否为 `0`，如果为 `0` 则输出 `Divided by zero!`，这里同样注意不要遗漏换行符 `\n`。另外，如果 `if` 或 `else` 中有多条语句，则需要添加一对花括号 `{}` 将多条语句包括起来。

在 C 语言中，两个整数用 `/` 操作默认为整除。提示：如果想获得小数结果，可以用 `(double)a / b` 或者 `1.0 * a / b` 先将 `a` 强制转换为浮点数类型后再相除。

## 示例程序

```c++
#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    if (b == 0)
    {
        printf("Divided by zero!\n");
        printf("Divided by zero!\n");
    }
    else
    {
        printf("%d\n", a / b);
        printf("%d\n", a % b);
    }

	return 0;
}
```




# D - 散落的零钱


| 难度  | 考点  |
| :---: | :---: |
|   3   | 循环  |

## 题目分析

本题需要根据输入的 $n$，重复执行 $n$ 次“输出 1”的操作。使用循环语句循环 $n$ 次可以有如下两种方法：

```c++
while (n > 0)
{
	... // 循环内容
    n = n - 1;
}
```

```c++
int i;
for(i = 1; i <= n; i = i + 1) //或 for(i = 0; i < n; i = i + 1)
{
    ... // 循环内容
}
```

提示：如果将 `while` 循环中 `(n > 0)` 改为 `(n >= 0)`，实际会执行几次？如果将 `for` 循环中 `(i = 1; i <= n; i = i + 1)` 改为 `(i = 1; i < n; i = i + 1)`，实际会执行几次？你可以自行测试并理解“如何根据循环次数设计循环条件”。

另外需要注意，OJ 会忽略行末空格，因此你可以重复输出 $n$ 次字符串 `"1 "`（不包括引号，注意后面有一个空格），实现每两个 `1` 之间用空格分隔的效果。

## 示例程序

```c++
#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i = i + 1)
		printf("1 ");

	return 0;
}
```






# E - 简单平方和运算

| 难度  |      考点      |
| :---: | :------------: |
|   3   | 数学运算，循环 |

## 题目分析

本题是一道简单的数学问题。注意：如果在 `main()` 函数内部声明一个 `int` 型的变量，则注意是否需要给该变量赋初始值，如题目中的 `ans`。


## 示例程序

```c++
#include <stdio.h>

int main()
{
    int n, ans = 0, temp;
    scanf("%d", &n); // 读取数据组数n
    while (n > 0)      // 执行n次循环
    {
        scanf("%d", &temp);
        ans = ans + temp * temp; 
        n = n - 1;
    }
    printf("%d", ans); // 输出结果

    return 0;
}
```

使用 `for` 循环代替 `while` 循环的一种实现方法如下：

```c++
#include <stdio.h>

int main()
{
    int n, ans = 0, temp, i;
    scanf("%d", &n); // 读取数据组数n
    for(i = 1; i <= n; i = i + 1)      // 执行n次循环
    {
        scanf("%d", &temp);
        ans = ans + temp * temp; 
    }
    printf("%d", ans); // 输出结果

    return 0;
}
```




# F - 减肥

| 难度  |         考点         |
| :---: | :------------------: |
|   4   | 判断、循环、简单计算 |

## 题目分析

本题需要按照题目要求进行判断。统计星号个数可以采用循环累加，也可以根据 $a,b$ 的大小直接利用面积公式计算。

## 示例程序

```c++
#include <stdio.h>

int main()
{
	int s, a, b, i, m, cnt = 0;
    scanf("%d", &s);
    if (s == 3)			// 蛋糕为三角形
    {
        scanf("%d", &a);
        for (i = 1; i <= a; i = i + 1)	// i 表示当前是三角形的第几层
            cnt += i * 2 - 1;			// 第 i 层的星号个数为 2i - 1, cnt 表示从三角形第一行到当前第i行的星号总数
    }
    else 				// 蛋糕为长方形
    {
        scanf("%d%d", &a, &b);
        cnt = a * b;
    }
    scanf("%d", &m);
    if (cnt <= m)
        printf("ENJOY YOUR MEAL!");
    else
        printf("FBI WARNING!");

    return 0;
}
```





# G - 向上取整

| 难度  |                考点                |
| :---: | :--------------------------------: |
|   3   | 条件判断，循环，向上取整和向下取整 |

## 题目分析

本题有三种解法，具体分析如下：

### 方法一：利用循环暴力求解

我们只需要找到满足 $a \leq bx$ 的最小整数解 $x_{\min}$ 即可，因此可以先声明并初始化一个变量 `int x = 0`，如果 $x$ **不满足** $a \leq bx$（即 `!(a <= b * x)`），就令 `x = x + 1`，直到条件满足并输出结果。

### 方法二：利用判断分类求解

通过观察发现，大部分情况下有 $\left\lceil \dfrac ab \right\rceil = \left\lfloor \dfrac ab \right\rfloor + 1$，并且只有当 $\dfrac ab$ 是整数时，有$\left\lceil \dfrac ab \right\rceil = \left\lfloor \dfrac ab \right\rfloor$，因此只需要特殊判断 `a % b` 是否为 $0$ 即可。

### 方法三：利用表达式直接求解

向上取整和向下取整可以双向转化：$\left\lceil \dfrac ab \right\rceil = \left\lfloor \dfrac {a + b - 1}b \right\rfloor$，因此直接利用表达式 `(a + b - 1) / b` 也可实现本题。

## 示例程序 1

```c++
// 方法一：利用循环暴力求解
#include <stdio.h>

int main()
{
	int a, b;
	int x = 0; // 根据题意，x 最小为 0，因此初始值设置为 0
	scanf("%d%d", &a, &b);
	while (!(a <= b * x)) // 当 x 不满足 a <= bx 时，就令 x = x + 1
		x = x + 1;
	printf("%d", x);

	return 0;
}
```

## 示例程序 2

```c++
// 方法二：利用判断分类求解
#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if(a % b == 0)		// 如果 a / b 是整数
		printf("%d", a / b);
	else 
		printf("%d", a / b + 1);

	return 0;
}
```

## 示例程序 3

```c++
// 方法三：利用表达式直接求解
#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", (a + b - 1) / b);

	return 0;
}
```





# H - Easy GCD


| 难度  |    考点    |
| :---: | :--------: |
|   3   | 最大公因数 |

## 题目分析

本题来源于 PPT 中的例题，比较简单，使用 PPT 中的代码可以直接通过本题。

本题的难点是根据最大公约数的求解方法构造循环条件，也就是代码中的 `while (!(a % gcd == 0 && b % gcd == 0))` 这一条语句。这个循环条件的逻辑较为复杂，同学们可以想想为什么这么写。


## 示例程序

```c++
#include <stdio.h>

int main()
{
	int a, b, gcd;
	scanf("%d%d", &a, &b);
	gcd = a;
	if (b < gcd)
		gcd = b;
	while (!(a % gcd == 0 && b % gcd == 0))
	{
		gcd = gcd - 1;
	}
	printf("%d", gcd);

	return 0;
}
```

提示：除了 PPT 中的方法，这道题也可以使用递归的方法解决（我们以后会学习到递归，因此在此不做详细讲解）。这里给出更相减损法和辗转相除法的示例程序。

```c++
// 更相减损法
#include <stdio.h>

int gcd(int x, int y)
{
	if (x == y)
	{
		return x;
	}
	if (x > y)
	{
		return gcd(x - y, y);
	}
	else
	{
		return gcd(y - x, x);
	}
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", gcd(a, b));

	return 0;
}
```



```c++
// 辗转相除法
#include<stdio.h>

int gcd(int x, int y) 
{
    if(y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", gcd(a, b));

	return 0;
}
```





# I - 水水的分数加法

| 难度  |        考点        |
| :---: | :----------------: |
|   3   | 简单四则运算，数学 |

## 题目分析

题意是计算 $\dfrac{a}{b}+\dfrac{c}{d}$。根据分数加法的运算法则可知 $\dfrac{a}{b}+\dfrac{c}{d}=\dfrac{ad}{bd}+\dfrac{bc}{bd}=\dfrac{ad+bc}{bd}$，整体上可以分为三个步骤：

1. 计算公分母 $p = bd$。由题意可知，数据的取值范围都在 $[1, 500]$ 之间，因此直接将 $bd$ 分母相乘即可，不会产生数据溢出等错误。
2. 计算通分后的两个分子和 $q = ad + bc$。
3. 计算约分后的结果，即对非最简分数，将分子 $p$ 和分母 $q$ 同时除以它们的最大公因数 $\gcd(p, q)$。

最大公因数的计算方法可以参考 H 题 Easy GCD 这道题的题解，代码也可直接复用。

输入两个分数的方法根据题目的提示可以相应写出，`scanf()` 的第一个参数(格式字符串)为 `"%d/%d %d/%d"`。

## 示例程序

```c++
#include <stdio.h>

int main()
{
	int a, b, c, d; // 输入的两个分数的分子和分母
	int p, q;       // 计算结果的分子和分母
	int gcd;        // 计算结果的分子分母之间的最大公因数，用于约分

	// 同时输入两个分数
	scanf("%d/%d %d/%d", &a, &b, &c, &d);

	q = b * d;			// 计算公分母 q = bd
	p = a * d + b * c; 	// 计算通分后的两个分子和 q = ad + bc

	// 求 gcd 的代码直接参考 H 题 Easy GCD
	gcd = p;
	if (q < gcd)
		gcd = q;
	while (!(p % gcd == 0 && q % gcd == 0))
		gcd = gcd - 1;

	// 约分
	p = p / gcd;
	q = q / gcd;

	// 输出
	printf("%d/%d + %d/%d = %d/%d", a, b, c, d, p, q);

	return 0;
}
```




# J - 周游加拿大

| 难度  |        考点        |
| :---: | :----------------: |
|   4   | 循环与条件判断 |

## 题目分析

根据题干解释，我们可声明一个变量，用来存储当前坐标 $x$ 。在读入每天新的旅行距离 $x_i$ 后，判断表达式 $x+x_i$ 是否超出旅行区间范围 $[-50, 50]$。如果超出，则输出一行 `“can't move, touch fish.”` ；如果没超出，则将 $x+x_i$ 赋值给 $x$ ，并进行下一天旅行的判断。

最后输出一行结果 $x$。

## 示例程序

```c++
#include <stdio.h>

int main()
{
	int i, x_end = 0, x, n;
	scanf("%d", &n);
	for (i = 0; i < n; i = i + 1)
	{
		scanf("%d", &x);
		if (x_end + x >= -50 && x_end + x <= 50)
		{
			x_end = x_end + x;
		}
		else
		{
			printf("can't move, touch fish.\n");
		}
	}
	printf("%d\n", x_end);

	return 0;
}
```
