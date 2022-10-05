# C2-2020级-航类第2次上机

如果字符画不会，可以看下这个链接，三分钟解决一切字符画： https://www.bilibili.com/video/BV1WX4y1372n?p=4

记得留意每道题下面的HINT

## 题目列表

- A 4263 test a xor b
- B 4245 ZYT学五则运算
- C 4246 有理有据的送分
- D 4205 小迷弟的迷惑行为
- E 4207 ONOS大班的班长选举
- F 4254 cbj学进制转换
- G 4242 ZYT学“真·位运算
- H 4224 朵朵买甜瓜

## 部分题解

一些过于简单的题目无需写题解，直接阅读标准代码即可。

一些困难题目还是希望同学们勤思考。题解仅供参考。

### A 4263 test a xor b

#### 题目分析

签到题。

本题目需要注意的就是以下几点。

\- n组数据，需要通过while或者for循环来解决。

\- a和b的范围为1到10^18  所以需要用long long或者unsigned long long

\- 异或的位运算符号是^

#### 示例代码

```c
#include <stdio.h>

long long n, a, b;

int main() {

	scanf("%lld", &n);

	while (n--) {

		scanf("%lld%lld", &a, &b);

		printf("%lld\n", (a ^ b));

	}

	return 0;

}
```


### B 4245 ZYT学五则运算

#### 题目分析

本题需要注意的是：

计算除法和取模时需要判断除数是否为0

计算除法时按照**整形计算**

#### 示例代码

```c
#include<stdio.h>

int main()
{
	int a, b;
    char x;
	
	while(~scanf("%d%c%d",&a,&x,&b))
    {
        if((x=='/'||x=='%')&&b==0)
            printf("WA\n");
        else if(x=='+')
            printf("%d\n",a+b);
        else if(x=='-')
            printf("%d\n",a-b);
        else if(x=='*')
            printf("%d\n",a*b);
        else if(x=='/')
            printf("%d\n",a/b);
        else if(x=='%')
            printf("%d\n",a%b);
    }
	
	return 0;
}
```


### C 4246 有理有据的送分

#### 题目分析
我们开一个数组$a[n+5]$，$a[i]$表示第$i$把椅子上的题解数量，一开始把$a[1]$到$a[n]$都赋值为1。每一次回收题解时，只需要把$a[x]$到$a[y]$都赋值为0即可。 

最后求$\sum_{i=1}^na[i]$就可以了。
#### 示例代码

```c
#include <stdio.h>

int n, m, Ans;
int a[10005];

int main(){
	int i, x, y;
	
	scanf("%d%d" , &n , &m);
	
	for(i=1; i<=n; ++i)
		a[i] = 1;
	while(m --){
		scanf("%d%d", &x, &y);
		for(i=x; i<=y; ++i)
			a[i] = 0;
	}
	for(i=1; i<=n; ++i)
		Ans += a[i];
		
	printf("%d", Ans);
	return 0;
}
```


### D 4205 小迷弟的迷惑行为

#### 题目分析

本题考查浮点数的精度问题，如果你选择换底公式(int)(lnx/lny)来计算原式的话，可以尝试输入3 243(3^5)会发现输出4，如果用double输出发现是4.999999，也就是说本题是比较恶心的卡精度问题，如果只用换底公式，只能获得0.9分，并过不了最后一组数据。如果你用小聪明，用(int)(log10x/log10y)来计算，也是过不了最后一组数据的，如果你还能用小聪明，用(int)(log2x/log2y)来计算，发现还是过不了最后一组数据。这就是小迷弟为换底公式精心准备的数据（x）。（马老师：小聪明啊~）

于是需要看一眼hint，我们可以这么输出(int)(lnx/lny+1e-8)这样就可以把精度问题解决。比如原来lnx/lny的准确值离一个整数就差一点点因为加了eps而超过了这个整数，但事实上小迷弟并没有发现任何一组数据是加了eps之后反而输出错的。

如果你觉得以上纯属扯淡，可以再看hint用for循环来做，初始化一个变量值是1每次乘以x直到大于y输出循环次数-1即可，注意此题数据范围，如此计算可能爆掉int的范围，会导致死循环tle。所以所有变量要设成long long型变量，这也是小迷弟为另一种方法挖的一个小坑。

最后的最后，本题的最后一组数据是1188 1188^3，可以用三种换底公式分别试一下，发现都输出2，刚好卡掉三种公式（耶）。

#### 示例代码

##### 解法1 换底公式eps

```C
#include<stdio.h>
#include<math.h>

int main(){
  double x,y;
  scanf("%lf%lf",&x,&y);
  long long ans=(long long)(log(y)/log(x)+1e-8);//eps设为1e-8可以更小但不能过小
  printf("%lld\n",ans);
}
```



##### 解法2 注意i开long long 不然可能会爆int 导致死循环 

```C
#include <stdio.h>
#include <math.h>
long long x,y;
int main(){
	scanf("%lld %lld",&x,&y);
	long long i=1,ans=0;
	for(i=1;i<=y;i=i*x,ans++){}
	printf("%lld",ans-1); 
	return 0;
}
```


### E 4207 ONOS大班的班长选举

#### 题目分析
本题的难点在于如何查找并记录多个最大值的序号。可以使用边遍历边丢弃的方法减少遍历次数。

本题无需使用排序算法，也不能使用排序。否则会收获`TLE`哦。
#### 示例代码

```c
#include <stdio.h>
int stus[1000050] = {0};
int main()
{
	int n, tmp, max = 0, I;//max初始值需要为0
	scanf("%d", &n);
	while (~scanf("%d", &tmp))
	{
		stus[tmp]++;
		if (max < stus[tmp]) max = stus[tmp]; // 记录最大值
	}
	for (i = 1; i <= n; i++)
		if (stus[i] == max)
			printf("%d %d\n", i, max);
}
```


### F 4254 cbj学进制转换

#### 题目分析

- 进位制 数学问题
- 思路是提取出每一位然后反着输出

#### 示例代码
```c
#include <stdio.h>
int main(){
	int num,radix;scanf("%d%d",&radix,&num);
	int arr[32] = {0},i=0;
	while(num){
		arr[i] = num % radix;
		num /= radix;
		i++;
	}
	while(i--){
		putchar(arr[i] + '0');
	}
	putchar('\n');
	return 0;
}
```


### G 4242 ZYT学“真·位运算

#### 题目分析

本题主要考查了 `与` 和 `左移` 两种位运算

#### 示例代码

```c
#include<stdio.h>

int main()
{
  unsigned long long int n;
  scanf("%ulld",&n);
  printf("%u",((n&0xff000000)>>8)|((n&0x00ff0000)<<8)|((n&0x0000ff00)>>8)|((n&0x000000ff)<<8));
  return 0;
}
```

### H 4224 朵朵买甜瓜

#### 题目分析

每个西瓜都只有甜与不甜两个状态，分别用数字$1$和$0$表示，由于甜西瓜只有$1$个，可以任意假定某一个西瓜为甜瓜，其余三个非甜瓜，再进行逻辑检验，此过程可以由循环实现，样例的$x$数组无具体含义，只是为了方便循环存取数据，当然也可以定义$16$个变量来读取题中的$16$个数据。

另外可以进一步思考，如果甜瓜的个数不确定，那么循环应该怎么写呢？

#### 示例代码

```c
#include <stdio.h>

int main() {
	int i, x[20] = {0};
	while (scanf("%d", &x[1]) != EOF)
	{
		for (i=2; i<=16; i++)
			scanf("%d", &x[i]);
			
		for (i=1; i<=4; i++)
		{
			// 四个西瓜watermelon，第一个为w[1]，每次循环开始均置0
			int w[5] = {0};
			w[i] = 1;
			// 数组元素同样可以作为另一个数组的下标
			if ((w[x[1]]==x[2]) + (w[x[3]]==x[4]) == 1 &&
				(w[x[5]]==x[6]) + (w[x[7]]==x[8]) == 1 &&
				(w[x[9]]==x[10]) + (w[x[11]]==x[12]) == 1 &&
				(w[x[13]]==x[14]) + (w[x[15]]==x[16]) == 1)
				printf("%d\n", i);
		}
	}
	return 0;
}
```



