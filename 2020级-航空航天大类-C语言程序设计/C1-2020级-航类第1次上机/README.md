# C1-2020级-航类第1次上机

如果字符画不会，可以看下这个链接，三分钟解决一切字符画： https://www.bilibili.com/video/BV1WX4y1372n?p=4

记得留意每道题下面的HINT

## 题目列表

- A 4201 北航欢迎你
- B 4217 简单方程
- C 4214 ZJD学GCD
- D 4213 计算绩点
- E 4223 High Heels！
- F 4220 cbj学数学分析(阶乘)
- G 4204 女神的密码
- H 4202 女神的密码2

## 部分题解

一些过于简单的题目无需写题解，直接阅读标准代码即可。

一些困难题目还是希望同学们勤思考。题解仅供参考。

### A 4201 北航欢迎你

#### 题目分析

这是一道简单的题目，使用编辑器中的“查找/替换”处理转义字符之后，补全 `printf` 函数即可。

#### 示例代码

```c
#include<stdio.h>

int main(){
    printf("                           aaaaaaaaaaaaaaaa                           \n");
    printf("                      aaaaa                aaaaa                      \n");
    printf("                  aaaa                           aaa                  \n");
    printf("               aaa                                  aaa               \n");
    printf("             aa                                        aa             \n");
    printf("           aa                                            aa           \n");
    printf("         aa                   \"                            aa         \n");
    printf("        aa                    \"                    \"\"       aa        \n");
    printf("      aa                     \"\"                \"\"\"\"\"   \'\'\'\'   aa      \n");
    printf("     aa                      \"\"            \"\"\"\"\"\"\"\"  \'\'  \'     aa     \n");
    printf("    aa                   \"\"\"\"\"\"\"\"\"\"\"\"   \"\"\"\"\"\"\"\"\"\"\"     \'       aa    \n");
    printf("   aa                   \"\"\"\" \"\"     \"\"\"\"\"\"\"\"\"\"\"\"      \'          aa   \n");
    printf("   a               \"\"\"\"\"\"    \"\" \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"      \'            aa  \n");
    printf("  aa           \"\"\"\"\"\"\"\"      \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"     \'\'             aa  \n");
    printf(" aa          \"\"\"\"\"\"\"\"    \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"     \'\"\"\"             aa \n");
    printf(" aa        \"\"\"\"\"\"\"\"\"     \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"     \'\"\"\"\"\"\"            a \n");
    printf(" a        \"\"\"\"\"\"\"\"\"\"       \'  \"\"\"\"\"\"\"\"\"\"\"\"\"     \' \"\"\"\"\"\"\"           aa\n");
    printf("aa       \"\"\"\"\"\"\"\"\"\"      \'\'\'\'  \"\"\"\"\"\"\"\"\"\"\"     \' \"\"\"\"\"\"\"\"\"          aa\n");
    printf("aa      \"\"\"\"\"\"\"\"\"\"\"             \"\"\"\"\"\"\"\"\"     \'  \"\"\"\"\"\"\"\"\"\"          a\n");
    printf("aa      \"\"\"\"\"\"\"\"\"\"\"            \"\"\"\"\"\"\"\"\"     \'   \"\"\"\"\"\"\"\"\"\"          a\n");
    printf("aa      \"\"\"\"\"\"\"\"\"\"\"            \"\"\"\"\"\"\"      \'    \"\"\"\"\"\"\"\"\"\"          a\n");
    printf("aa                             \"\"\"\"\"\"     \'\'     \"\"\"\"\"\"\"\"\"          aa\n");
    printf("aa       \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"     \'\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"          aa\n");
    printf(" a                            \"\"\"\"\"     \'                           a \n");
    printf(" aa                          \"\"\"\"\"     \'                            a \n");
    printf(" aa     \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\" \"\"\"\"\"    \'\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"        aa \n");
    printf("  aa                \"\"\"\"\"   \"\"\"\"     \'     \"\"\"\"                   aa  \n");
    printf("   a                     \"\" \"\"  \'  \'\'  \"\"\"                        aa  \n");
    printf("   aa                      \"\"  \'  \'                              aa   \n");
    printf("    aa                    \"\"   \' \'                              aa    \n");
    printf("     aa                   \"   \' \'                              aa     \n");
    printf("      aa                 \"     \"                              aa      \n");
    printf("        aa                   \"                              aa        \n");
    printf("         aa                                                aa         \n");
    printf("           aa                                            aa           \n");
    printf("             aa                                        aa             \n");
    printf("               aaa                                  aaa               \n");
    printf("                  aaaa                          aaaa                  \n");
    printf("                      aaaaa                aaaaa                      \n");
    printf("                           aaaaaaaaaaaaaaaa                          \n");
    
    return 0;
}
```


### B 4217 简单方程

#### 题目分析

由于 $a$ 不为0，本题可以用高中所学的一元二次方程的解法来求解。
由于后面的计算都是基于浮点数计算，使用`%lf`来读取a、b、c会很方便。  
先求 $delta$ ，根据其正负判断是否有解，小于0即无解，否则有解。  
如果有解，可求出两个根，再使用`if`语句判断哪个大哪个小。

- 由于a、b、c均不为0，本题不会有0解，这使得本题可以直接用`%0.6f`输出计算结果。
- 由于a、b、c非0，所以delta必定为整数，我们可以直接将delta和0比较来判断是否有解。
- 有兴趣的同学可以研究下，如果a、b、c可能为0，也不一定是整数，该怎么求解呢？

#### 示例代码

```c
#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, r1, r2, delta, min, max;
    scanf("%lf%lf%lf", &a, &b, &c);

    delta = b * b - 4.0 * a * c;
    if (delta < 0)
    {
        printf("no real roots");
    }
    else
    {
        r1 = (-b + sqrt(delta)) / (2.0 * a);
        r2 = (-b - sqrt(delta)) / (2.0 * a);
        if (r1 < r2)
        {
            min = r1;
            max = r2;
        }
        else
        {
            min = r2;
            max = r1;
        }

        printf("%.6f %.6f", min, max);
    }

    return 0;
}
```


### C 4214 ZJD学GCD

#### 题目分析

这道题的数据并不大，主体部分就是计算出两个数字的最大公约数，使用课件上的方法在限制时间范围内完全可以解决。而最小公倍数的算法就是 $\frac{乘积}{GCD}$ ，分数的化简只需要都除以最大公约数即可。下方同时还给出了辗转相除法这种效率较高的算法的示例代码。

#### 示例代码

```c
#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int gcd=(a<b)?a:b;
    
    while(a%gcd||b%gcd)
        gcd--;
    
    printf("%d %d\n%d/%d",gcd,a*b/gcd,a/gcd,b/gcd);
    
    return 0;
}

```

以下代码展示了辗转相除法的实现方法

```c
int M=(a>=b)?a:b;
int N=(M==a)?b:a;
int temp;
while(M%N)
{
    M=M%N;
    temp=M;
    M=N;
    N=temp;
}
int gcd=N;

```



### D 4213 计算绩点

#### 题目分析

根据题目要求，一边计算每门课程百分制对应的绩点GP，然后与各自的学分相乘并做加和，另一边记录总学分数的加和，最后相除即可。printf保留两位小数可以直接用`printf("%.2f")`进行输出

#### 示例代码

```c
#include<stdio.h>
double sum_grade, sum_point;
int score;
double credit;
int main() {
    while (scanf("%d%lf", &score, &credit) != EOF) {
        if(score >= 60)sum_grade +=  (4.0 - 3.0 * (100.0 - 1.0 * score) * (100.0 - 1.0 * score) / 1600.0) * credit;
        sum_point += credit;
    }
    printf("%.2f\n", sum_grade / sum_point);
    return 0;
}
```


### E 4223 High Heels！

#### 题目分析

这是一道简单题，考察多组数据的输入，根据题目格式输出以及简单判断；利用while循环，每组数据输入然后进行计算与判断，如果游戏失败则立即输出并返回，如果读到文件结尾且游戏成功，则按题目要求输出。

#### 示例代码

```c
#include <stdio.h>
int n,a,b;
int main(void)
{
    scanf("%d",&n);
    while(~scanf("%d%d",&a,&b))
    {
        if(b==1)a=-a;
        n+=a;
        if(n<=0)
        {
            printf("Sorry, you lose!\n");
            return 0;
        }
    }
    printf("AWESOME! > > > Heels:%d\n",n);
    
    return 0;
}
```


### F 4220 cbj学数学分析(阶乘)

#### 题目分析

不需要实际计算阶乘，而是应该看该阶乘有多少 5 的因子。

数5，每个5会带来一个0，每个25会带来两个0，每个5的p次方会带来p个0

#### 示例代码
```c
#include <stdio.h> 
int main(){ 
int n; 
    while(~scanf("%d",&n)){
        int count = 0; 
        while(n >= 5){ 
            count += n / 5; 
            n /= 5; 
        } 
        printf("%d\n",count);
    } 
    return 0; 
} 
```


### G 4204 女神的密码

#### 题目分析

对于长度没有明确给定的输入，可以使用 `while(scanf("%c",&in)!=EOF)` 来读入，随后按照题目规则逐字符处理即可。

#### 示例代码

```c
#include<stdio.h>
int main() 
{
  int a;
  while(scanf("%d.",&a)!=EOF)//读入数字，存到变量a中
  {
    printf("%c",a);
  } 
  return 0;
}
```

### H 4202 女神的密码2

#### 题目分析

对于长度没有明确给定的输入，可以使用 `while(scanf("%c",&in)!=EOF)` 来读入，随后按照题目规则逐字符处理即可。

#### 示例代码

```c
#include<stdio.h>
#include<ctype.h>

int main(){
    char in;
    while(scanf("%c",&in)!=EOF)
    {
        if(isupper(in))
        {
            printf("%c",'Z'-in+'A');
        }
        else if(islower(in))
        {
            printf("%c",'z'-in+'a');
        }
    }
    return 0;
}
```



