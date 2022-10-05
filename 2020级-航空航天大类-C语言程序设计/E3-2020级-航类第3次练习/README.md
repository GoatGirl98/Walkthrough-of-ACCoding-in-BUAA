# E3-2020级-航类第3次练习

## 题目列表

- A 4277	一荷学弟卖基金
- B 4267	三荷学长买不来基金
- C 4294	荷荷学妹坐地铁
- D 4278	cbj加密数据
- E 4265	二荷学姐买基金
- F 4259	自动控制原理
- G 4240	小迷弟的灵光一现
- H 4230	数字反转2021
- I 4284	计数排序
- J 4293	遥不可及的军训

## A 一荷学弟卖基金
- 考查:输出输出 循环 浮点数
- 可以不开数组
- 思路:每读进来一组数据判断一次如果是学妹就输出.
```cpp
#include <stdio.h>
int main(){
	int n,m,cur,curm;
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d%d",&cur,&curm);
		if(cur == m){
			printf("%.2f\n",0.521 * curm);
		}
	}
	return 0;
}
```
## B 三荷学长买不来基金
- 考查:数据范围 求一组数据的最大和最小值
- 数组可以做,但是有不开数组的做法
- 最后结果可能会溢出所以我们用<b>long long</b>变量
```c
#include<stdio.h>
int main() {
    int n;long long max=-0x7fffffff,min=0x7fffffff;   
    long long end,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a);
    	if(max<a)max=a;
		if(min>a)min=a; 	
    }	
	end=(max-min)*(max-min);
	printf("%lld",end);
    return 0;
}
```
## C 荷荷学妹坐地铁
- 考查:分支 循环
- 简单的数学算式题.算法是先将每天的单程票价格加起来,如果价格大于15,则该日暂时认定买单日票.如果三天的价格加起来大于40,则买三日票.
- 注意输入的格式以及循环的次数,**注意数据的初始化**,局部变量未赋初值的话,值是不定的.在本地可能编译器优化为0了,但是OJ上不会.
- 因为没有天价地铁票,所以这里可以不考虑数据范围
```c
#include <stdio.h>
int main(){
	int d1 = 0,d2 = 0,d3 = 0,n,m,p,cur,result;
	scanf("%d%d%d",&n,&m,&p);
	while(n--){
		scanf("%d",&cur);
		d1 += cur;
	}
	if(d1 > 15)d1 = 15;
	while(m--){
		scanf("%d",&cur);
		d2 += cur;
	}
	if(d2 > 15)d2 = 15;
	while(p--){
		scanf("%d",&cur);
		d3 += cur;
	}
	if(d3 > 15)d3 = 15;
	result = d1 + d2 + d3;
	if(result > 40)result = 40;
	printf("%d\n",result);
	return 0;
}
```
## D cbj加密数据
- 考查字符处理 可以用`ctype.h`的库函数也可以自行处理
- 可以用`getchar`一个个读字符处理了再输出(如第一个代码)
- 可以用`gets`或者`fgets`把数据读到数组再处理并输出(如第二个代码)
- <b>切记不能用`scanf`因为有空格</b>
```cpp
#include <stdio.h>
int main()
{
	char c;
	while((c=getchar())!=EOF)
	{
		if(c>='A'&&c<='Z')
		putchar(c+'a'-'A');
		else if(c>='a'&&c<='z')
		putchar(c+'A'-'a');
		else if(c>'5'&&c<='9')
		putchar('9');
		else if(c>='0'&&c<'5')
		putchar('0');
		else if('5'==c)
		putchar('5');
		else
		putchar(c);
	}
	return 0;
 }
```
- 也可以使用`putchar`输出
```cpp
#include<stdio.h> 
int main(){
	char s[1020];
	gets(s);
	for(int i=0;s[i];i++){
		if(islower(s[i]))
		s[i]=toupper(s[i]);
		else if(isupper(s[i]))
		s[i]=tolower(s[i]);
		else if(s[i]>'5'&&s[i]<='9')
		s[i]='9';
		else if(s[i]<'5'&&s[i]>='0')
		s[i]='0';
	}
	printf("%s",s);
}
```
## E 二荷学姐买基金
- 考查:循环 数据范围,即使所有输入数据都在`int`范围内，但加和可能超过`int`范围.
- 思路:脑筋急转弯.本题由于不限制交易次数,因此可以想象每天都买入并卖出(实际并不是这样).只求所有上坡数据的两端之差的和即可(只要今天比昨天大就卖出).
- 实际上,上述就是一种非常简单的贪心算法.由于算法已经超出本课程的内容,有兴趣的同学可以自行百度.也可以用动态规划(DP)的思路求解.预告一下,此题还有后续哦~
- 可以不用数组
```cpp
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	long long a,b,i,ans=0;
	scanf("%lld",&a);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&b);
		if(b-a>0)
		ans+=(b-a);
		a=b;
	}
	printf("%lld",ans);
	return 0;
}
```

## F 自动控制原理
- 考查:判断 循环 浮点数
- 由于系统的阶跃响应满足减幅振荡,根据这一特点容易求出其调节时间,示例代码将数据用数组存储起来,然后从数组最后一个元素开始往前遍历,直到离开误差带时跳出循环.
- 大家之后会做很多实验,也会面临很多实验数据处理的问题,这时利用编程来处理数据,既准确又高效.希望学习编程对于大家来说是有帮助的.---题目作者
```c
#include <stdio.h>
#include <math.h>

int main()
{
    double wentai, data[1000] = {0};
    int i = 0;
    
    scanf("%lf", &wentai);
    while (scanf("%lf", &data[i]) != EOF)
    {
        i++;
    }
    
    for (i = i - 1; i >= 0; i--)
    {
        // 离开误差带时跳出循环
        if (fabs(data[i] - wentai) > 0.05 * wentai)
        {
            break;
        }
    }
    printf("%.2lf\n", 0.03 * (i + 1));
    
    return 0;
}
```
- 也可以正着找稳态起点 此方法可以不用数组
```c
#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0, ans = 0;
    double wentai, data;
    
    scanf("%lf", &wentai);
    while (scanf("%lf", &data) != EOF)
    {
        i++;
        if (fabs(data - wentai) > 0.05 * wentai)
        {
            ans = i;
        }
    }
    printf("%.2lf\n", 0.03*ans);
    
    return 0;
}
```


## G 小迷弟的灵光一现
- 考查:位运算 数组 异或的性质
- 思路小迷弟给了 必须用数组
- 首先考虑只有一个数出现奇数次的情况。根据异或运算$a\oplus a=0$，以及交换律、结合律等性质，将全体数做异或，则剩下来的就是所求的数。
- 如果是只有两个数出现奇数次，我们设异或结果为$a\oplus b=ans$，可以利用ans二进制中任意是1的位置来对原来所有数进行分类，分别异或可得a和b

```cpp
#include <stdio.h>
int arr[2000010] = {0};
int main(){

	int n,i,ans = 0,ans1;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",arr + i);
		ans ^= arr[i];
	}
	if(n & 1){//奇数直接出答案
		printf("%d\n",ans);
	}
	else{
		ans1 = ans;
		int pos = 1,k;
		for(k = 0;k < 32;k++){//找一位都是1的
			if(ans1 & (1 << k)){
				pos = (1 << k);break;
			}
		}
		for(i = 0;i < n;i++){
			if(arr[i] & pos){//如果那位上是1就异或ans1
				ans ^= arr[i];
			}
			else{//否则异或ans 此为 对原来所有数进行分类
				ans1 ^= arr[i];
			}
		}
		if(ans < ans1){//先输出大的
			printf("%d %d\n",ans,ans1);
		}
		else{
			printf("%d %d\n",ans1,ans);
		}
	}
	return 0;
}
```
## H 数字反转
- 考查:字符串处理
- 思路:
```cpp
#include <stdio.h>
int main() {
    char num[21] = "\0";
    char c;
    int length = 0, i, is_neg = 0, print_head;
    c = getchar();
    if (c == '-') {
        is_neg = 1;
        c = getchar();
    }
    while ((c >= '0' && c <= '9') || c == '.') {
        num[length] = c;
        length++;
        c = getchar();
    }
    if (length == 1 && num[0] == '0') {
        printf("0");
        return 0;
    }
    for (i = length - 1; num[i] == '0' && num[i - 1] != '.'; i--) {
        //去掉末尾多余的0
    }
    print_head = i;
    if (is_neg) {
        printf("-");
    }
    for (i = print_head; i >= 0; i--) {
        printf("%c", num[i]);
    }
}
```
- 另解:可以用`sscanf`
```cpp
#include<stdio.h>
#include<string.h>

int main()
{
	char buffer[30] = {0},tmp;
	scanf("%s",buffer);
	int start=0;
	int m = 0;
	int n = strlen(buffer) - 1;
	if(buffer[0] == '-') //先处理负号
	{
		putchar('-');
		m = 1;
		start = 1;
	}
	while(m < n) //翻转
	{
		tmp = buffer[m];
		buffer[m] = buffer[n];
		buffer[n] = tmp;
		m++;
		n--;
	}
	char *dotpos = strchr(buffer,'.');//找小数点
	int result1;
	if(!dotpos)
	{
		sscanf(buffer + start,"%d",&result1);
		printf("%d\n",result1);
	}
	else
	{
		*dotpos = ' ';
		sscanf(buffer + start,"%d",&result1);
		printf("%d.",result1);
		puts(dotpos + 1);
	}
	return 0;
}
```
## I 计数排序
- 考查:浮点数 数组 排序
- 思路:开长度为`20000`以上的数组把浮点数用对应的整数表示出来,然后每读入一个数计数
- `%g`格式控制符使程序简单
```cpp
#include <stdio.h>
#include <math.h>
int a[20001];
int main()
{   int i,j;
	double m;
	while(scanf("%lf",&m)!=EOF)
	{   i=round(m*100)+10000;
		a[i]++;
	}
	for(i=0;i<=20000;i++)
	{
		if(a[i]>0)
		for(j=1;j<=a[i];j++)
		{
			printf("%g\n",((double)i-10000)/100);
		}
	}
	return 0;
}
```
- 也可分别开两个数组处理正数和负数
### 题目解析

本题使用计数排序的方法对一个实数序列进行排序。

计数排序的原理已经在题目介绍中阐明，但是想要根据题目所介绍的方法完成此题，还要考虑如下细节：

1、所给序列是实数序列，而不是整数序列：

​		在题目介绍中，可以看到是以整数序列为例的，可以直接拿来当作数组下标，但是实数在计算机中以浮点数的形式存储，显然不能够拿来当作数组下标。但是题目给出的数据对实数加以了限制：保证 $a_i$ 的小数位数不会超过两位，且保留最少的小数位。并且实数的绝对值不超过 $100$ ，因此只要将序列中的实数乘以 $100$ ，就可以将题目所有可能涉及到的实数“有序地”映射到整数范围，可以用作数组下标。

​		这样好像已经把问题解决了，但是序列中实数可能是负数，乘以 $100$ 后仍然是负数。数组负数下标的应用同学们还没有学习过，但是只要将所有乘以 $100$ 后的实数加上一个足够大的偏置量（ $bias$ ），就可以将实数都映射到非负整数的范围内。这个偏置量可以取  $10000$ ，因为最小的负数是 $-100$  。

​		经过以上讨论，若想将实数 `num` 变换为用作数组下标的非负整数 `id`，代码可以这么写：

```c
//...
	double num;
	int id, bias = 10000;
	//对num进行赋值
	id = (int)(num * 100) + bias;
//...
```

但这么写会有问题，问题出在浮点误差上。譬如实数 $0.11$ ，浮点数无法精确表示它的值，在计算机中浮点数以 $0.10999999...$ 这样的近似值表示这个实数。同样地， 对于$11.00$ 浮点数会用  $10.99999...$ 来近似表示，对 $10.99999...$ 强制转换为 `int` 会得到 $10$ 而不是我们想要的  $11$ 。那么如何解决这个问题呢？用 `math.h` 库中的 `round` 函数就可以了，`round` 函数将传入的 `double` 类型参数四舍五入取整后，以 `double` 数据类型返回：

```c
//...
#include <math.h>
//...
	double num;
	int id, bias = 10000;
	//对num进行赋值
	id = (int)round(num * 100) + bias;
//...
```

有兴趣的同学可以运行以下代码，感受浮点误差带来的问题。

```c
#include <stdio.h>
#include <math.h>
int main() {
    double x = 0;
    int n = 10000;
    while (n--) {
        if ((int)(x * 100) != (int)round(x * 100)) {
            printf("%lf %d\n", x, (int)(x * 100));
        }
        x += 0.01;
    }
    return 0;
}
```

2、同一个实数可能在序列中出现多次：

​		题目并没有保证一个实数只会在实数序列里出现一次。解决方法是在实数所对应的数组元素中存储这个实数出现的次数。

3、如何将作为数组下标的非负整数转换回实数：

​		这里需要注意的是，输出的实数应该和所给的数据一样。比如，不能将输入的 `15.1` 输出为 `15.10` 。即，在最后输出的时候也要注意保留最少的小数位，结尾不能有多余的小数 $0$ 。 

### 示例代码1

```c
#include <stdio.h>
#include <math.h>
int s[20007];

int main(int argc, const char * argv[]) {

    int a, b, bias = 10000;
    double num;
    while (~scanf("%lf", &num)) {
        s[(int)round(num * 100) + bias]++;
    }
    
    for (int i = 0; i < 20007; i++) {
        for (int j = 0; j < s[i]; j++) {
            int ai = i - bias;
            if (ai < 0) printf("-");
            ai = ai > 0 ? ai : -ai;
            printf("%d", ai / 100);
            if (ai % 100) {
                if ((ai % 100) % 10)
                    printf(".%d", ai % 100);
                else
                    printf(".%d", (ai % 100) / 10);
            }
            printf("\n");
        }
    }

    return 0;
}
```

### 示例代码2

```c
#include <stdio.h>
#include <string.h>
int s[20007];

int main(int argc, const char * argv[]) {

    int a = 0, b = 0, bias = 10000, isnum = 0, sgn = 1, isdot = 0, cnt = 0;
    while (1) {
        char c = getchar();
        if (c == EOF) {
            if (isnum) s[sgn * (a * 100 + b) + bias]++;
            break;
        } else if (c == '\n') {
            if (cnt == 1) b *= 10;
            s[sgn * (a * 100 + b) + bias]++;
            isnum = 0;
            isdot = 0;
            cnt = 0;
            a = 0;
            b = 0;
            sgn = 1;
        } else if (c == '-') {
            sgn = -1;
        } else if (c == '.') {
            isdot = 1;
        } else {
            isnum = 1;
            if (isdot) {
                b *= 10;
                b += c - '0';
                cnt++;
            } else {
                a *= 10;
                a += c - '0';
            }
        }
    }
    
    for (int i = 0; i < 20007; i++) {
        for (int j = 0; j < s[i]; j++) {
            int ai = i - bias;
            if (ai < 0) printf("-");
            ai = ai > 0 ? ai : -ai;
            printf("%d", ai / 100);
            if (ai % 100) {
                if ((ai % 100) % 10)
                    printf(".%d", ai % 100);
                else
                    printf(".%d", (ai % 100) / 10);
            }
            printf("\n");
        }
    }

    return 0;
}
```

## J 即将到来的军训
- 思路:
- 首先统计1,2,3共有多少位，得到最后满足要求的队伍

- 之后，比较新队列与原队列，可以发现会有三种情况：
>	 一个人在正确的位置，本身不需要交换；
>	 两个人在对方的队伍里，需要一次两两交换；
>	 三个人分别在上/下一个人的队伍里，三个人需要两次两两交换；

由此，可以得到总的交换次序
```cpp
#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
int main()
{
	int N;
	int num[1010];
    int cnt[3] = {0};
    int i;
    int cnt12=0,cnt13=0;
    int cnt21=0,cnt23=0;
    int cnt31=0,cnt32=0;
    int ans=0;
    scanf("%d",&N);
    for (i = 0; i < N; i++) 
    {
        scanf("%d",&num[i]);
        cnt[num[i]-1]++;
    }
    for (i = 0; i < cnt[0]; i++) 
    {
        if (num[i] == 2) 
            cnt12++;
      	else if (num[i] == 3)
            cnt13++;
    }
    for (int i = cnt[0]; i < cnt[0]+cnt[1]; i++) 
    {
        if (num[i] == 1)
            cnt21++;
        else if (num[i] == 3)
            cnt23++;
    }

    for (int i = cnt[0]+cnt[1]; i < cnt[0]+cnt[1]+cnt[2]; i++) 
    {
        if (num[i] == 1) 
            cnt31++;
        else if (num[i] == 2)
            cnt32++;
    }
    ans += min(cnt12, cnt21); cnt12 -= min(cnt12, cnt21); cnt21 -= min(cnt12, cnt21);
    ans += min(cnt13, cnt31); cnt13 -= min(cnt13, cnt31); cnt31 -= min(cnt13, cnt31);
    ans += min(cnt23, cnt32); cnt23 -= min(cnt23, cnt32); cnt32 -= min(cnt23, cnt32);
    ans += ((cnt12 + cnt13)*2);
    printf("%d",ans);
    return 0;
}
```