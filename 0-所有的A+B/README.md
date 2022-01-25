# 0-所有的A+B

由于一些历史原因，北航OJ有一堆几乎完全一样的A+B题目。

虽然在该项目设立之初，笔者并不打算收录他们，但是后来想想，不收录的话也难以对得起“普通课程题目全收录”这个称号（

所以最后还是打算把他们都收录一下，统一地放到这一栏目当中。各位想刷AC率的话也可以来直接提交（大雾）

那么在这里统一收录之后，这些A+B对应的练习赛/上机页面中将不再重复收录。

# a+b demo示例

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 478 总提交人数: 540

## 题目描述

计算 a+b。

## 输入

输入多组数据。

每组数据一行，包含2个整数 a, b（保证 a, b, a+b 在 int 范围内）。

## 输出

对于每组数据，输出一行，a+b 的值。

## 输入样例

```
1 2
1 3
```

## 输出样例

```
3
4
```

# 评测机信息

```
c++   : g++ main.cpp -O2 -std=c++14 -DONLINE_JUDGE -o main
c     : gcc main.c  -lm -O2 -std=c99 -DONLINE_JUDGE -o main
java  : javac Main.java
```

# AC代码示例

只对A+B demo示例 　

## C

```
#include <stdio.h>

int main() 
{
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)//注意while处理多个case
        printf("%d\n", a+b);
    return 0;
}
```

## C++

```
#include <iostream>
using namespace std;

int main() 
{
    int a, b;
    while(cin >> a >> b)//注意while处理多个case
        cout << a+b << endl;
    return 0;
}
```

## Java

```
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()) {
            int a = cin.nextInt(), b = cin.nextInt();
            System.out.println(a + b);
        }    
    }
}
```

# 评测结果缩写

```
      "Accepted" : "AC"  
      "Wrong Answer" : "WA"
      "Compiler Error" : "CE"
      "Runtime Error (SIGSEGV)" : "REG"
      "Runtime Error (SIGKILL)" : "MLE"
      "Runtime Error (SIGFPE)" : "REP"
      "Presentation Error" : "PE"
      "Memory Limit Exceed" : "MLE"
      "Time Limit Exceed" : "TLE"
      "Input File Not Ready" : "IFNR"
      "Output File Not Ready" : "OFNR"
      "Error File Not Ready" : "EFNR"
      "Other Error" : "OE"
```

# test a+b

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 1754 总提交人数: 1815

## 题目描述

计算 a+b

## 输入

第一行，一个正整数 n，表示数据组数。

接下来 n 行，每行2个整数 a, b （保证 a, b, a+b 均在int范围内）。

## 输出

对于每组数据，输出一行，为 a+b 的值。

## 输入样例

```
2
1 2
2 3
```

## 输出样例

```
3
5
```

## 代码样例

```
#include <stdio.h>
int main()
{
    int n, a, b;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", (a+b));
    }

    /* // 或用如下for循环代替while循环
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", (a+b));
    }
    */

    return 0;
}
```

# A+B

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 171 总提交人数: 176

## 题目描述

计算 A+B

## 输入

第一个数为数据组数n

接下来n行，每行2个整数A, B（保证A, B, A+B在int范围内）

## 输出

对于每组数据，输出一行，为A+B的值

## 输入样例

```
2
1 2
3 5
```

## 输出样例

```
3
8
```

# 水水哒a+b

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 123 总提交人数: 181

## 题目描述

大家好，熟悉的a+b又和大家见面了呢O(∩_∩)O。

大家赶紧动动手，A了我吧 ^_^

## 输入

共一组，每组两个数字a, b（a, b均在int范围内）

## 输出

输出一行，a+b的值

## 输入样例

```
1 2
```

## 输出样例

```
3
```

## 提示

```
题中没有限定a+b的范围，那a+b是不是有可能超过int范围呢？
```

# 来算a+b吧！

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 8 总提交人数: 8

## 题目描述

计算A+B

## 输入

第一个数为数据组数n

接下来n行，每行2个整数a,b，以一个空格隔开

(1≤n≤20,0≤a,b≤400000)

## 输出

对于每组数据，输出一行，a+b的值

## 输入样例

```
1
1 2
```

## 输出样例

```
3
```

## 备注

没想到啊，重新验证代码的时候，发现这题数据坏掉了？！无力吐槽...

# Gzh的a+b

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 4 总提交人数: 5

## 题目描述

签到题，如题，计算a+b。

## 输入

一组输入数据，2个整数a,b(保证a,b在int范围内)

## 输出

输出一行，a+b的值

## 输入样例

```
1 2
```

## 输出样例

```
3
```

# float a+b

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 5 总提交人数: 5

## 题目描述

计算实数 a+b

## 输入

第一个数为数据组数n

接下来n行，每行2个实数a, b（保证a, b, a+b在实数范围内）

## 输出

对于每组数据，输出一行，为 a+b 的值，保留到小数点后3位

## 输入样例

```
2
1 2
2 3.12345
```

## 输出样例

```
3.000
5.123
```
