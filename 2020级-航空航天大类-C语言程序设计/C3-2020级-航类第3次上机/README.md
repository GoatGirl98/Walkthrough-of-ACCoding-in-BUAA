# C3-2020级-航类第3次上机

## 题目列表

- A 4286 倒三角
- B 4268 荷荷学妹赚基金
- C 4287 一天不用switch我浑身难受
- D 4270 年 度 好 题
- E 4283 四荷学姐买不起基金
- F 4285 五荷一点都不喜欢重复
- G 4208 缺项一元三次方程
- H 4218 朵朵的日期计算

## 部分题解

一些过于简单的题目无需写题解，直接阅读标准代码即可。

一些困难题目还是希望同学们勤思考。题解仅供参考。

### `A` 4286 倒三角

#### 题目分析

只要按照规律输出图案即可
图形总共有n层，对于第i层（$0\leq i \leq n-1$）,其`$`符号有`2*(n-i)-1`,其左边的空格有`i`个。


#### 示例代码

```c
#include <stdio.h>
int main()
{
    int i, n, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) // 共n行
    {
        // 先输出空格
        for (j = 0; j < i; ++j)
        {
            putchar(' ');
        }
        // 再输出$
        for (k = 0; k < (2 * n - 2 * i - 1); ++k)
        {
            putchar('$');
        }
        // putchar('\n');  // 这种输出也可以
        printf("\n");
    }
}
```

### `B` 4268 荷荷学妹赚基金

#### 题目分析
本题需要熟悉简单的分支判断，根据题意需要将收入分为三种情况进行判断：小于等于800、大于800但小于等于1500、大于1500；然后根据不同情况去进行计算并输出；注意不要漏掉情况或者重复情况
#### 示例代码

```c
#include <stdio.h>
int n;
double money,tax;
int main(void)
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&money);
        if(money<=800)
        tax=money;
        else if(money<=1500)
        tax=800+(money-800)*0.8;
        else tax=800+700*0.8+(money-1500)*0.75;

        printf("%.2f\n",tax);
    }
    return 0;
}
```


### `C` 4287 一天不用switch我浑身难受

#### 题目分析

本题考察的是对于`switch-case`语句的基础语法与使用。本题不要求知道`switch-case`语句和`if-else`性能对比的具体原因，只需要知道本题卡死了所有通过结合`if-else`语句与其他算法思维（诸如二分查找、哈希等算法，当然如果你过了，欢迎联系出题人加强数据），具体原因HINT写的较为清楚，也欢迎上机结束后进一步研究，或者寻找可以用`if-else`通过的方法。（感谢LCY助教的补充）

#### 示例代码

```c
#include<stdio.h>
unsigned seed;
long long a, b;
long long ans;
int n, i;
int op;
int scheme[35];
int main() {
	scanf("%d%u", &n, &seed);
	for (i = 0; i <= 31; ++i) scanf("%d", &scheme[i]);
	while (n--) {
		seed ^= seed << 13;
		seed ^= seed >> 17;
		seed ^= seed << 5;
		op = scheme[seed & 31] & 31;
		a = n ^ 1145141919810ll;
		b = n ^ 1919810114514ll;
		switch (op) {
		case 0:  ans += a + b; break;
		case 1:  ans += a - b; break;
		case 2:  ans += a * b; break;
		case 3:  ans += a / b; break;
		case 4:  ans += a % b; break;
		case 5:  ans += a & b; break;
		case 6:  ans += a | b; break;
		case 7:  ans += a ^ b; break;
		case 8:  ans -= a ^ b; break;
		case 9:  ans -= a | b; break;
		case 10: ans -= a & b; break;
		case 11: ans -= a % b; break;
		case 12: ans -= a / b; break;
		case 13: ans -= a * b; break;
		case 14: ans -= a - b; break;
		case 15: ans -= a + b; break;
		case 16: ans &= a * b; break;
		case 17: ans &= a / b; break;
		case 18: ans &= a + b; break;
		case 19: ans &= a - b; break;
		case 20: ans &= a | b; break;
		case 21: ans &= a ^ b; break;
		case 22: ans &= a % b; break;
		case 23: ans &= a & b; break;
		case 24: ans ^= a / b; break;
		case 25: ans ^= a * b; break;
		case 26: ans ^= a - b; break;
		case 27: ans ^= a + b; break;
		case 28: ans ^= a ^ b; break;
		case 29: ans ^= a | b; break;
		case 30: ans ^= a & b; break;
		case 31: ans ^= a % b; break;
		default: break;
		}
	}
	printf("%lld", ans);
	return 0;
}
```

### `D` 4270 年 度 好 题

#### 题目分析
本题按照数学公式计算出分子和分母，在找到两者的最大公约数即可得到正确答案。
#### 示例代码

```c
#include<stdio.h>
int main()
{
	int a,b,c,d,i,max=1,ans1,ans2;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	ans1=a*d+c*b;
	ans2=b*d;
	for(i=2;i<=ans1&&i<=ans2;i++)
	{
		if(ans1%i==0&&ans2%i==0&&i>max) max=i;
	}
	ans1/=max;
	ans2/=max;
	printf("%d/%d",ans1,ans2);
	return 0;
}
```
### `E` 4283 四荷学姐买不起基金

#### 题目分析

本金最大可达`1e11`所以应用`long long`数据类型

最直接最精确的方式是直接比较两所银行的年利率

最后输出注意两位小数即可

#### 示例代码

```c
#include<stdio.h>
#include<math.h>

int main()
{
	long long s;
	int t;
	double m,n,n1;
	double bxm,bxn;
	scanf("%lld%lf%lf%d",&s,&m,&n,&t);
	n1=pow((100+n)/100.0,4);//将季利率转换为年利率
	bxm=s*pow((1+m/100.0),t);
	bxn=s*pow(n1,t);
	if((m/100.0+1>n1-1e-8)&&(m/100.0+1<n1+1e-8))
	{
		printf("%.2f\n%.2f\n",bxm,bxm);
		printf("Whatever\n");
	}
	else if(m/100.0+1>=n1+1e-8)
	{
		printf("%.2f\n%.2f\n",bxm,bxn);
		printf("51Mole!!\n");
	}
	else if(m/100.0+1<=n1-1e-8)
	{
		printf("%.2f\n%.2f\n",bxm,bxn);
		printf("51Seer!!\n");
	}
	return 0;
}
```


### `F` 4285 五荷一点都不喜欢重复

#### 题目分析

首先判断几位数，几位数就代表需要多少次循环

接下来就是暴力枚举

#### 示例代码
```c
#include<stdio.h>

int main()
{
	int m,n,single,ten,hund,thou,tk;
	scanf("%d%d",&m,&n);
	if(n==3)
	{
		for(hund=1;hund<=m;hund++)
			for(ten=1;ten<=m;ten++)
				for(single=1;single<=m;single++)
					if(hund!=ten&&ten!=single&&hund!=single)
						printf("%d%d%d\n",hund,ten,single);
	}
	else if(n==4)
	{
		for(thou=1;thou<=m;thou++)
			for(hund=1;hund<=m;hund++)
				for(ten=1;ten<=m;ten++)
					for(single=1;single<=m;single++)
						if(hund!=ten&&ten!=single&&hund!=single&&thou!=hund&&thou!=ten&&thou!=single)
							printf("%d%d%d%d\n",thou,hund,ten,single);
	}
	else if(n==5)
	{
		for(tk=1;tk<=m;tk++)
			for(thou=1;thou<=m;thou++)
				for(hund=1;hund<=m;hund++)
					for(ten=1;ten<=m;ten++)
						for(single=1;single<=m;single++)
							if(hund!=ten&&ten!=single&&hund!=single&&thou!=hund&&thou!=ten&&thou!=single&&tk!=thou&&tk!=hund&&tk!=ten&&tk!=single)
								printf("%d%d%d%d%d\n",tk,thou,hund,ten,single);
	}
	return 0;
}
```


### `G` 4208 缺项一元三次方程

#### 题目分析

本题是一元二次方程的延续，看起来略为麻烦，但事实上只需要老老实实照着题目给出的公式做就可以完成。

回答题目中提出的两个问题：

在C语言中，一般用`acos(-1)`来代替π这个数学常数，因为便于记忆与使用。当然，你也可以用其他反三角函数来代替与$π$相关的常数值。

对于采用`pow(double base,double exponent)`开立方，首先`exponent`可以写`1.0/3.0`，不能写`1/3`，原因是`1`与`3`都是整数类型，相除默认是带余除法，会得到0，而这里必须代入浮点数。

关于参数`base`为什么设计成只能是正数，数学上解释是：对于复数开方的结果，会将辐角主值除以3，因此在复数范围内，负数开立方其实不是实数。如果想完成实数范围内的开立方运算，必须将负号提到根号外才行，即需要根据根号内的正负，来对传入参数与返回值进行处理。参见https://zh.cppreference.com/w/c/numeric/math/pow

标程中的判断条件经过了数学上的简单化简，直接进行判断也是可行的。后面三个数的排序比较简单，判断三次即可。

#### 示例代码

```C
#include<stdio.h>
#include<math.h>

int main()
{
	double p,q;
	scanf("%lf%lf",&p,&q);
	if(q*q>p*p*p)
	{
		double u,v;
		if(q<0&&p>0)//第一个底数取负的条件
		{
			u=-pow(-q-sqrt(q*q-p*p*p),1.0/3.0);
		}
		else
		{
			u=pow(q+sqrt(q*q-p*p*p),1.0/3.0);
		}
		if(q<0||p<0)//第二个底数取负的条件
		{
			v=-pow(sqrt(q*q-p*p*p)-q,1.0/3.0);
		}
		else
		{
			v=pow(q-sqrt(q*q-p*p*p),1.0/3.0);
		}
		double x=u+v;
		printf("%.10lf\n",x);
	}
	else
	{
		double sp=sqrt(p);
		double temp=acos(q/p/sp)/3.0;
		double x1=2.0*sqrt(p)*cos(temp);
		double x2=2.0*sqrt(p)*cos(temp+2.0*acos(-1)/3.0);
		double x3=2.0*sqrt(p)*cos(temp+4.0*acos(-1)/3.0);
		if(x1>x2)//简单交换排序
		{
			double a=x1;
			x1=x2;
			x2=a;
		}
		if(x1>x3)
		{
			double a=x1;
			x1=x3;
			x3=a;
		}
		if(x2>x3)
		{
			double a=x2;
			x2=x3;
			x3=a;
		}
		printf("%.10lf %.10lf %.10lf\n",x1,x2,x3);
	}
}
```


### `H` 4218 朵朵的日期计算

#### 题目分析
由于母亲节在每年$5$月的第二个星期日，那么容易想到，先求解出$5$月$1$号是星期几（要明确$Zeller$公式各个参数的含义），假设是周日，即$week$为$0$，那么再过七天就是母亲节，即$day = 8$，$week$不为$0$的时候，容易找到关系$day = 15-week$；如果关系式没找着，也可以用循环来找到第二个星期日。之后再求解母亲节和母亲生日相差天数，题中HINTS已给出思路，用代码实现即可
#### 示例代码

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year, month = 5, day, birth_year, birth_month, birth_day, s1 = 0, s2 = 0, i, week, y, c;
    unsigned int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 把每个月的天数用数组储存起来
    
    scanf("%d", &year);
    scanf("%d%d%d", &birth_year, &birth_month, &birth_day);
    // 令day = 1，运用Zeller公式查询当年5月1日是星期几，注意Zeller公式的使用限定条件
    day = 1;
    y = year % 100;
    c = year / 100;
    week = (y + y/4 + c/4 - 2*c + 13*(month+1)/5 + day - 1) % 7;
    if (week < 0)
        week += 7;
    if (week == 0)
        day = 8;
    else
        day = 15-week;
    
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        d[2] = 29;  // 若year年为闰年，修改2月的天数
    // year年母亲节，即5月day日与当年1月1日相差天数s1
    for (i = 0; i < 5; i++)
        s1 += d[i]; //相差的整月天数
    s1 += day;
    // year年母亲生日，与当年1月1日相差天数s2
    for (i = 0; i < birth_month; i++)
        s2 += d[i]; //相差的整月天数
    s2 += birth_day;
    
    printf("%d\n%d\n", day, abs(s1-s2));
    
    return 0;
}
```
