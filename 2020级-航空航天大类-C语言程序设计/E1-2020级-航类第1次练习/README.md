# E1-2020级-航类第1次练习

这是E1-2020级-航类第1次练习，未选入C1的助教题目会出现在这里。本次练习赛共10道题。

## 题目列表

- A 4232 一 道 水 题
- B 4216 简单的分数约分
- C 4211 字母频率统计2021
- D 4235 水君的价格
- E 4215 漏沙漏
- F 4227 小迷弟乘坐神奇电梯
- G 4226 9键输入
- H 4225 小兔子乖乖拔萝卜
- I 4203 奇妙的多边形
- J 4239 朵朵选靓号

## 部分题解

一些过于简单的题目无需写题解，直接阅读标准代码即可。

一些困难题目还是希望同学们勤思考。题解仅供参考。



### `A` 4232 一 道 水 题
本题比较简单，只需要把转义符正常输出就可以了。
```c
#include<stdio.h>
int main ()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %% %d = %d",a,b,a%b);
	return 0; 
}
```



### `B` 4216 简单的分数约分

很简单的一道gcd的应用，在输出的时候可以使用printf("%+d",i);来控制加减号，容易踩坑的点仅在忽略分母限定为正号的条件
建议同学们熟悉一下C语言的库函数，能帮助节省很多时间。

```c
#include<stdio.h>

int main()
{
	int m=0,n=0;
	int M,N=0;
	while (scanf("%d %d",&m,&n)!=EOF)
	{
		int GCD;
		int Max,Min;
		if(n<0)
		{
			n*=-1;
			m*=-1;
		}
		if (m<0)
		{
			M=-m;
		}
		else
		{
			M=m;
		}
		if (N<0)
		{
			N=-n;
		}
		else
		{
			N=n;
		}
		if(m%n==0)
		{
			printf("%d\n",m/n);
		}
		else
		{
			if(M/N==0)
			{
				if(M>=N)
				{
					Max=M;
					Min=N;
				}
				else
				{
					Max=N;
					Min=M;
				}
				while(Min)
				{
					int Temp=Max%Min;
					Max=Min;
					Min=Temp;
				}
				GCD=Max;
				printf("%d/%d\n",m/GCD,n/GCD);
			}
			else
			{
				int Integer=m/n;
				m-=n*Integer;
				if(M>=N)
				{
					Max=M;
					Min=N;
				}
				else
				{
					Max=N;
					Min=M;
				}
				while(Min)
				{
					int Temp=Max%Min;
					Max=Min;
					Min=Temp;
				}
				GCD=Max;
				printf("%d%+d/%d\n",Integer,m/GCD,n/GCD);
			}
		}
	}
	return 0;
}
```



### `C` 4211 字母频率统计2021

简单的数组应用。本题需要注意的地方都写在提示里了。字符也可以作为数组下标和循环条件，参与各种数学运算。注意大小写字母是相同的，以及不是字母的字符处理。

```c
#include <ctype.h>
#include <stdio.h>
int freq[100] = {0};
int main()
{
    int c, count = 0, i;
    while ((c = getchar())!=EOF)
        if (isalpha(c))
        {
            int upper = toupper(c);
            freq[upper]++;
            count++;
        }
    for (i = 'A'; i <= 'Z'; i++)
    {
        if (!freq[i]) continue; // 忽略未出现过的字母
        double fre = freq[i] / (double)count;
        printf("%c %.2lf%%\n", i, fre * 100);
    }
}
```

### `D` 4235 水君的价格

很简单。极端数据都已经给出了，只要解决样例中的极端数据，别的应该也就都解决了。

大致思路与热身赛N题一致：用unsigned long long输出结果，并分析是否为负数，以决定在开头要不要输出负号。

```C

#include<stdio.h>
#include<limits.h>

int main()
{
	long long a;
	while(~scanf("%lld",&a))
	{
		if(a==0)
		{
			printf("0\n");
		}
		else if(a>0)
		{
			unsigned long long sum=2*a;
			printf("%llu00\n",sum);
		}
		else if(a==LLONG_MIN)
		{
			printf("-1844674407370955161600\n");
		}
		else if(a<0)
		{
			a=-a;
			unsigned long long sum=2*a;
			printf("-%llu00\n",sum);
		}
	}
	return 0;
}

```


### `E` 4215 漏沙漏

完成本题最关键的点是要弄清楚沙漏底边长度和沙漏总层数的关系，以及每一层打印空格/沙子数量和所处的是第几层的关系。另外，要注意沙漏底边长度为奇数时沙漏由两个“完整的”三角形组成；而底边长度为偶数时，三角形的顶点将缺失。

实际上在HINT中的代码已经将两个关系描述的比较清楚了，同学们只要弄清楚什么时候应该打印沙子，什么时候不应该，将HINT代码稍加修改就可以将此题AC。当然有兴趣的同学也可以不借助HINT中的代码自己将这题做出，锻炼一下编程能力。

```c
#include <stdio.h>

int main()
{
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for (i = n; i > 0; i -= 2) 
    {
        for (j = 0; j < (n - i + 1) / 2; j++) 
        {
            putchar(' ');
        }
        putchar('*'); //打印一个*作为沙漏的墙壁
        for (j = 1; j < i - 1; j++) 
        {
            if ((n - i + 1) / 2 <= m && (n - i + 1) / 2 != 0) 
            {
                putchar(' '); //已经漏空了的情况
            } 
            else 
                putchar('*');
        }
        if (i > 1) //打印沙漏的另一边墙壁，当前行长度大于1才打印
            putchar('*');
        putchar('\n');
    }
    for (i = i + 2; i <= n; i += 2) 
    {
        for (j = 0; j < (n - i + 1) / 2; j++) 
        {
            putchar(' ');
        }
        putchar('*');
        for (j = 1; j < i - 1; j++) 
        {
            if ((n - i + 1) / 2 <= m) 
            {
                putchar('*'); //漏有沙子的情况
            } 
            else 
                putchar(' ');
        }
        if (i > 1)
            putchar('*');
        putchar('\n');
    }
}
```




### `F` 4227 小迷弟坐电梯

#### 题解视频
https://www.bilibili.com/video/BV1Zv411b7vS/

直接模拟每一秒的状态/电梯一个上下循环的状态显然不会是最优解，因为电梯何时能接到小迷弟是可以直接计算出来的。首先我们先计算出电梯从1层出发到楼顶再回到1层的时间发现是period=(m-1)<<1;这样我们可以计算出小迷弟出场前电梯能运行多少个周期，这些周期肯定无用，我们需要的是这些周期过后，离小迷弟出场还有多长时间，比如经过若N个周期，还有T秒小迷弟出场，根据之前的说法N+1个周期结束时小迷弟早已出场，故现在的时间是N*period。接下来我们需要根据s和t的大小来判断需要上行接到小迷弟还是下行接到小迷弟。显然s==t时，小迷弟不需要坐电梯！！！于是直接输出n即可。s<t时，电梯上行接到小迷弟，所以从1到s需要s-1秒，s>t时电梯要下行，故需要m-1+m-s=period+1-s秒，此时接到小迷弟，再需要s和t的距离的时间貌似就可以到达目的地了（s到t的距离可以通过判断s和t的大小分类讨论 也可以用abs绝对值函数）。但是还有一个问题这样的时间可能还没有n大 所以我们判断一下，如果比n小则还需要等一个周期，于是这种情况下再加一个周期即可。
```c
#include<stdio.h>
#include<math.h>

long long n,maxv,s,t,n,mm;

int main()
{
	scanf("%lld",&maxv);
	mm=(maxv-1)*2;//电梯上下一个周期的时间
	scanf("%lld %lld %lld",&s,&t,&n);
	if(s==t)
	{
		printf("%lld\n",n);//小迷弟那都不用去直接到包房
	}
	else
	{
		long long tmp1,tmp2;
		if(s<t)
		{
			tmp1=s-1;//电梯从1楼向上接到小迷弟
		}
		else
		{
			tmp1=mm+1-s;//电梯从maxv层向下接到小迷弟
		}
		long long tmp3=n/mm*mm+tmp1;//n秒之前电梯跑过n/mm*mm次轮回 又花了tmp1的时间接小迷弟
		if(tmp3<n)
		{
			tmp2=tmp3+mm;//但是仍有可能小于n 如果小于n必须加个周期才能保证在小迷弟出现之后接到小迷弟
		}
		else
		{
			tmp2=tmp3;
		}
		printf("%lld\n",tmp2+llabs(s-t));//再走两者的距离
	}
	return 0;
}
```

### `G` 4226 9键输入

本题考察对ASCII码的使用和基本的字符串处理。当然，字符处理也可以使用ASCII码的计算，也可使用包含于`ctype.h`中的库函数。

```c
#include <ctype.h>
#include <stdio.h>

int main()
{
    int ch, out; // 思考一下为什么要把字符定义为int类型
    while ((ch = getchar()) != EOF)
    {
        if (!isprint(ch)) //字符不可见则跳过
            continue;
        ch = tolower(ch);
        if (isdigit(ch))
            out = ch - 48;
        else if (ch < 'a')
            out = 1;
        else if (ch <= 'c')
            out = 2;
        else if (ch <= 'f')
            out = 3;
        else if (ch <= 'i')
            out = 4;
        else if (ch <= 'l')
            out = 5;
        else if (ch <= 'o')
            out = 6;
        else if (ch <= 's')
            out = 7;
        else if (ch <= 'v')
            out = 8;
        else if (ch <= 'z')
            out = 9;
        else
            out = 1;
        printf("%d", out);
    }
}
```


### `H` 4225 小兔子乖乖拔萝卜

只需要每次读入，更新三个最大值即可。注意更新的条件。

```c
#include<stdio.h>
int main()
{
	int k,temp;
	int max1=0;
	int max2=0;
	int max3=0;
    int i;
	while(scanf("%d",&k)!=EOF)
	{
		for(i=1;i<=k;i++)
		{
			scanf("%d",&temp);
			if(temp>max1)
			{
				max3=max2;
				max2=max1;
				max1=temp;					
			}
			else if(temp>max2)
			{
				max3=max2;
				max2=temp;
			}
			else if(temp>max3)
				max3=temp;
		}
		printf("%d %d %d\n",max1,max2,max3);
	}
	return 0;
}
```



### `I` 4203 奇妙的多边形
任意三条对角线都不会交于一点，这意味着每个交点只由22条对角线决定。
而每条对角线由22个顶点决定，所以我们只要确定44个顶点，便能确定唯一的交点。
所以答案很显然是 , 即 .

```c
#include<stdio.h>

long long n, Ans;

int main(){
    scanf("%lld", &n);
    
    Ans = n*(n-1)*(n-2)*(n-3)/24;
    
    printf("%lld", Ans);
    return 0;
}
```




### `J` 4239 朵朵选靓号

可以将11位手机号码视为一个long long类型的整数，之后采取循环移位的方法，确定手机号码是否含有233以及含有5的个数。
此外，在学习完字符串之后，这道题的解决方法将更为简单便捷。

```c
#include <stdio.h>

int main()
{
    long long num;
    int flag_233 = 0, cnt5 = 0;
    scanf("%lld", &num);

    while (num != 0)
    {
        if (num % 1000 == 233)
        {
            flag_233 = 1;
        }
        if (num % 10 == 5)
        {
            cnt5++;
        }
        num /= 10;
    }

    if (flag_233)
    {
        if (cnt5 < 3)
        {
            printf("Wonderful:%d", cnt5);
        }
        else
        {
            printf("Great:%d", cnt5);
        }
    }
    else
    {
        printf("Not good:%d", cnt5);
    }
    
    return 0;
}
```
