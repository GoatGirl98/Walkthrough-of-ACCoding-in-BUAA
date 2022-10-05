# pre-热身赛 

本次练习不计成绩，大家放松去练习，不要有压力。

虽然不计成绩，但每一次练习都很重要，建议一定认真去练习，学习是自己的事情。

本次不练习，下次计成绩的练习可能就不会了。

大家需要尽快熟悉OJ平台的评测结果。

## 题目列表

- A 4191 helloworld
- B 4187 佛像
- C 4189 阿瓦隆卡牌
- D 4182 返航小统计
- E 4194 PHP是最好的语言
- F 4197 单节得分王
- G 4196 刀客塔的烦恼
- H 4199 二进制逆序
- I 4185 数列级数
- J 4188 数数入门
- K 4195 cbj学数学分析
- L 4183 女神的生日
- M 4192 正反相加
- N 4193 真•简单的a+b
- O 4190 忍蛙的圆形轨迹
- P 4184 YourSQL2.0
- Q 4198 基础物理实验 2

## 部分题解

一些过于简单的题目无需写题解，直接阅读标准代码即可。

一些困难题目还是希望同学们勤思考。题解仅供参考。

### A 4191 helloworld

签到题。

```c
#include<stdio.h>

int main(){
    printf("helloworld");
    return 0;
}
```

### B 4187 佛像

本题考察字符画输出。这是历年考试必考的内容，必会必过，上机时请自行锻炼找BUG。

只需要转义反斜杠以及双引号即可通过。

```c
#include <stdio.h>
int main()
{
    printf("                      _ooOoo_\n");
    printf("                     o8888888o\n");
    printf("                     88\" . \"88\n");
    printf("                     (| -_- |)\n");
    printf("                      O\\ = /O\n");
    printf("                  ____/'---'\\____\n");
    printf("                   .\' \\\\| |// \'.\n");
    printf("                 / \\\\||| : |||// \\\n");
    printf("               / _||||| -:- |||||- \\\n");
    printf("                 | | \\\\\\ - /// | |\n");
    printf("                | \\_| \'\'\\---/\'\' |_/\n");
    printf("                \\ .-\\__ `-` ___/-. /\n");
    printf("              ___`. .\' /--.--\\ `. . __\n");
    printf("           .\"\" \'< `.___\\_<|>_/___.\' >\'\"\".\n");
    printf("         | | : `- \\`.;`\\ _ /`;.`/ - ` : | |\n");
    printf("           \\ \\ `-. \\_ __\\ /__ _/ .-` / /\n");
    printf("   ======`-.____`-.___\\_____/___.-`____.-'======\n");
    printf("                      `=---=\'\n");
    return 0;
}
```


### C 4189 阿瓦隆卡牌

本题是一个比较简单的练习输入输出以及逻辑关系的题目

基本思路就是先判断前五个字符中`'W'`的个数，并判断第六个字符的内容

本题中由两个条件：成功完成3个及以上的任务、成功隐藏先知的身份

两个条件进行与运算后的结果即为正方阵营的获胜情况

两个条件的对立条件进行或运算的结果即为反方阵营的获胜情况

可知两个阵营的获胜为对立条件

即可简单地仅判断某一方阵营的胜负来得到另一方阵营的胜负情况

```c
#include<stdio.h>

int main(){
    char TheMerlinFinded=0; //标示先知是否被发现
    int SuccessTaskNum=0; // 任务成功数量计数变量
    for(int i=0;i<5;){
        char Task=0;
        Task=getchar();
        if(Task=='W' || Task=='L'){
        /*---------过滤空格等无效字符---------*/
            i++;
        }
        if(Task=='W'){
            SuccessTaskNum++;
        }
    }
    getchar();
    TheMerlinFinded=getchar();
    printf("%d\n",SuccessTaskNum);
    if(SuccessTaskNum>=3 && TheMerlinFinded=='H'){// 通过与关系，判定好人方是否获胜
        printf("King Arthur Win");
    }else{
        printf("Medrawt Win");
    }

    return 0;
}
```

### D 4182 返航小统计

```c
#include<stdio.h>

int main(){
    int n,id,day,hour,min,aimday,count=0;
    scanf("%d",&aimday);
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
    	scanf("%d%d%d:%d",&id,&day,&hour,&min);
    	if(day==aimday){
    		printf("%d %02d:%02d\n",id,hour,min);
    		count++;
		}
	}
	printf("%d",count);
}
```

### E 4194 PHP是最好的语言

#### 题目分析

本题没有给出最大输入的数据数量，因此想要完整保存所有数据是不现实的，最好的办法是边读入边计票（大概类似于唱票），示例程序没有使用结构体，感兴趣的同学可以自行了解结构体的用法。

#### 示例代码

```c
#include<stdio.h>
#include<string.h>
int main()
{
	char lan[25][25]={'\0'};
	char temp[25]={'\0'};
	int count[25]={0},i=0,j,max=0;
	while(scanf("%s",temp)!=EOF)
	{
		if(i==0)
		{
			strcpy(lan[0],temp);
			count[0]++; 
			i++;
		}
		else
		{
			int flag=0;
			for(j=0;j<i;j++)
			{
				if(strcmp(lan[j],temp)==0)
				{
					count[j]++;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				strcpy(lan[i],temp);
				count[i]=1;
				i++;
			}
		}
	}
	for(j=0;j<i;j++)
	{
		if(count[j]>max) max=count[j];
	}
	for(j=0;j<i;j++)
	{
		if(count[j]==max) printf("%s\n",lan[j]);
	}
	return 0;
}
```

### F 4197 单节得分王

#### 题目分析
本题考察结构体的使用和排序，由于数据范围较小，无须考虑程序的性能，于是难点就落在数据的读取及处理，示例中给出一种处理方式，用`getchar()`函数将每行字符一个一个读取，  

直到读到数字为止，则读到了球员的名字，之后再用$scanf$函数读取数字，读取完毕后从头开始查找该球员之前是否得过分，最后调用$qsort$排序输出即可。  

#### 示例代码
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNumOfPlayer 50
#define maxLengthOfName 50

typedef struct
{
    char name[maxLengthOfName];
    int score;
} player;

player play[maxNumOfPlayer];

int cmp(const void*p1, const void*p2) {
    player* pp1 = (player*)p1;
    player* pp2 = (player*)p2;
    if (pp1->score != pp2->score)
        return pp2->score - pp1->score;
    else
        return strcmp(pp1->name, pp2->name);
}

int main()
{
    int n, i, j, point, flag, numOfPlayer = 0, mark;
    char c, name[maxLengthOfName];
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        // 读取行末换行符
        while (getchar() != '\n');
        c = getchar();
        j = 0;
        mark = 0;
        // 当字符c不是数字的时候继续读取
        while (!(c >= '0' && c <= '9'))
        {
            name[j++] = c;
            c = getchar();
        }
        name[j-1] = '\0';
        point = c-'0';
        scanf("%d", &flag);
        // 若没有进球，则continue
        if (!flag)
            continue;
        
        for (j = 0; j < numOfPlayer; j++)
        {
            if (!strcmp(play[j].name, name))
            {
                mark = 1;
                play[j].score += point;
                break;
            }
        }
        // 本次得分球员之前未得分
        if (!mark)
        {
            numOfPlayer++;
            strcpy(play[j].name, name);
            play[j].score += point;
        }
    }
    
    qsort(play, numOfPlayer, sizeof(play[0]), cmp);
    for (i = 0; i < numOfPlayer; i++)
    {
        printf("%s %d\n", play[i].name, play[i].score);
    }
    
    return 0;
}
```

### G 4196 刀客塔的烦恼

```c
#include <stdio.h>

int main() {
    int level, exp, money;//定义变量
    scanf("%d %d %d", &level, &exp, &money);//输入等级、作战记录、钱 数
    int level_need = 80 - level;//距离满级所差的等级数
    int exp_need = level_need * 10; //计算升到满级需要的作战记录数
    int money_need = level_need * 1000; //计算升到满级需要的钱数
    if (exp_need <= exp && money_need <= money) { //如果两者都够，输出YES
        printf("YES %d %d", exp_need, money_need);
    } else if (exp_need <= exp && money_need > money) { //如果作战记录足够，但钱不够
        printf("NO 0 %d", money_need - money);
    } else if (exp_need > exp && money_need <= money) { //如果钱足够，但作战记录不够
        printf("NO %d 0", exp_need - exp);
    } else { //如果两者都不够
            printf("NO %d %d", exp_need - exp, money_need - money);
    }
}
```

### H 4199 二进制逆序


#### 题目分析

本题将一个数字的所有二进制位取出，并倒序放到输出数字中即可。

应注意数据范围。如果单纯使用`int`型变量和`%d`输出会得到`WA`。

使用位运算时请注意**位运算操作符的优先级**！

#### 示例代码

以下代码较易理解，固定输出位。

```c
#include<stdio.h>

int main()
{
	unsigned int num, out;
	while (~scanf("%u", &num))
	{
		out = 0;
		int i;
		for (i = 0; i < 32; i++)
		{
			int tmp = (num >> (31 - i)) & 1; // 取位
			if (tmp == 0)
			{
				out = out & (~(1 << i)); // 置零
			}
			else
			{
				out = out | (1 << i); // 置一
			}
		}
		printf("%u\n", out); // 输出使用%u，代表无符号整数。很重要！！
	}
}
```

循环中也可以这样操作。将原数的右端填入新数的右端并向左推。

```c
for (int i = 0; i < 32; i++)
{
    out <<= 1;
    out |= (num & 1);
    num >>= 1;
}
```

### I 4185 数列级数

#### 示例代码

本题主要考察循环以及数据类型之间的转换，以下为标程

```C
#include <stdio.h>
int main(void)
{
    int q, m, k;
    double sum = 1.0;

    scanf("%d", &q);
    while (q--)
    {
        sum = 1.0, m = 1;
        scanf("%d", &k);
        
        while (sum <= k)
        {
            m++;
            sum += 1.0 / m;
        }
        printf("%d\n", m);
    }

    return 0;
}
```

#### 另一种解法

本题查一下OEIS就可以打表。当然，上机与考试时禁止查OEIS。[OEIS:A002387](http://oeis.org/A002387)

如果打表的话，例如写成这样：

```C
#include<stdio.h>

long long ans[30];

void init()
{
	ans[0]=1;
	ans[1]=2;
	ans[2]=4;
	ans[3]=11;
	ans[4]=31;
	ans[5]=83;
	ans[6]=227;
	ans[7]=616;
	ans[8]=1674;
	ans[9]=4550;
	ans[10]=12367;
	ans[11]=33617;
	ans[12]=91380;
	ans[13]=248397;
	ans[14]=675214;
	ans[15]=1835421;
	ans[16]=4989191;
	ans[17]=13562027;
	ans[18]=36865412;
	ans[19]=100210581;
	ans[20]=272400600;
	ans[21]=740461601;
	ans[22]=2012783315;
	ans[23]=5471312310;
}

int main()
{
	init();
	int q;
	while(~scanf("%d",&q))
	{
		while(q--)
		{
			int k;
			scanf("%d",&k);
			printf("%lld\n",ans[k]);
		}
	}
}
```

仅供参考。同样地，Q题“基础物理实验2”数据范围只有30，只要你能找到全体答案，当然也可以打表。

然而，打表是一种很糟糕的写法，仅在迫不得已的情形，或者数据量非常小的情形，才会考虑使用。本题的正规写法参见标准程序。

### J 4188 数数入门

本题注意数据范围进行枚举即可

```C
#include <stdio.h>  
int a[10];
int main()
{
	int m,n;
	int i;
	scanf("%d %d",&m,&n);
	if(m==0)
		a[0]++;
	for(;m<=n;m++)
		for(i=m;i;i/=10)
			a[i%10]++;
	for(i=0;i<=9;i++)
		printf("%d ",a[i]);
	return 0;
} 
```

本题在M与N的差距范围更大的时候，还可以采用一种名为“数位动态规划”的做法来完成（有过竞赛基础的同学可能会对此耳熟能详），由于该做法很明显超出了本课程的考察范围，故不做展开介绍，有兴趣的同学可以在搜索引擎上自行进行查阅。

### K 4195 cbj学数学分析

思路:把n个数读入数组并用qsort排序,取前面m个取平均.
#### 示例代码:
```c
#include <stdio.h>
#include <stdlib.h>
int arr0[200000] = {0};
int cmp(const void *a,const void *b){
	return *((int *)b) - (*(int *)a);
}
int main(){
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i = 0;i < n;i++){
		scanf("%d",arr0 + i);
	}
	qsort(arr0,n,sizeof(int),cmp);
	double s = 0;
	for(i = 0;i < m;i++){
		s += arr0[i];
	}
	s /= m;
	if(s >= 60.0){
		printf("%.3f\n",s);
	}
	else{
		puts("Jianglaoshi%%%");
	}
	return 0;
}
```

### L 4183 女神的生日

#### 示例代码

本题考察的是结构体的使用以及排序

```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sb{
    char name[24];
    int y,m,d;
}a[120],b[1];//b数值用来交换
int main()
{
    int i,j,n,m,k;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%s %d %d %d",a[i].name,&a[i].y,&a[i].m,&a[i].d);
    for (i=0;i<n-1;i++)
         for (j=i+1;j<n;j++)
         {
             if ((a[i].y>a[j].y) || (a[i].y==a[j].y && a[i].m>a[j].m) || (a[i].y==a[j].y && a[i].m==a[j].m && a[i].d>=a[j].d))    //岁数大就交换到前面去，注意是a[i].d>=a[j].d而不是a[i].d>a[j].d，因为题目上说年龄相等，后输入的先输出
            {
                b[0]=a[i];
                a[i]=a[j];
                a[j]=b[0];//交换
            }
        }
    for (i=0;i<n;i++) printf("%s\n",a[i].name);
    return 0;
}

```

仅供参考。同样的，D题“返航小统计”可以和本题一样使用结构体，只需要加一步计数即可。

### M 4192 正反相加

#### 题目分析

这道题不需要复杂的数学操作，只考查了字符串相关函数的简单使用，其中反读数需要将字符串倒置，可以自行编写函数来操作，然后逐个位数相加进位即可。需要注意的是，输入的数字不超过100位并不意味着相加的结果不超过100位。用字符串模拟高精度数加法的思想在后续题目中也会有所体现。

#### 示例代码

```C
#include <stdio.h>
#include <string.h>

char ch1[101]={};
char ch2[101]={};
char ch3[102]={};					 //三个全局变量，ch1为读入数，ch2为倒置，ch3为计算结果

void reverse(void)						//将ch1倒置的函数
{
	int len = strlen(ch1);
	int i;
	for(i = 0;i < len;i++)
		ch2[i] = ch1[len-1-i];
}
int main()
{
	int i,add = 0;
	
	gets(ch1);
	
	int len = strlen(ch1);
	reverse();
	for(i = len-1;i >= 0;i--){
		if(ch1[i]+ch2[i]+add-2*'0'>=10)			//这里的分情况讨论是为了进位
			ch3[len-1-i] = ch1[i]+ch2[i]+add-'0'-10,add = 1;
		else
			ch3[len-1-i] = ch1[i]+ch2[i]+add-'0',add = 0;
	}
	if(add)
		ch3[len] = '1';				//如果最后一位可以进位上来，那么位数增加，最高位为1
	
	int len2 = strlen(ch3);
	
	for(i=len2-1;i>=0;i--)
		printf("%c",ch3[i]);		//倒序相加再倒序打印，可以方便最后一位的进位
		
	return 0;
}
```
### N 4193 真•简单的a+b

#### 题目分析

本题考查基础知识，虽然可以用奇奇怪怪的东西用极短的代码量解决掉。但是属于旁门左道，并不提倡。

`a`，`b`虽然在`long long`范围内，但是`a+b`就不一定了

##### Case 1

对于一正一负，必然不会爆`long long`的范围，所以我们照常输出`a+b`即可。

##### Case 2

`a`, `b`均为正数，`a+b`就有可能超过`LLONG_MAX`导致溢出 于是会输出一个负数。

对应本题的第 $5$ 组到第 $9$ 组数据，都是会爆掉`long long`范围的，于是在这种情况下我们可以考虑用`unsigned long long`。

因为`LLONG_MAX`的最大值是 $2^{63}-1$ 两个正数相加最大值是 $2^{64}-2$ 而`unsigned long long`的最大值是 $2^{64}-1$ ，完全不用担心溢出的问题 于是我们输出`unsigned long long`的`a+b`即可

##### Case 3

 对于一般的两个负数 我们取`unsigned long long`类型的`aa` 和 `bb`，令`aa=-a`,`bb=-b`

然后输出`unsigned long long`的`-(aa+bb)`即可 

这里需要注意的是，尽管`a`或者`b`有可能会取`LLONG_MIN`而导致取**直接取相反数**还是`LLONG_MIN`，但是强制类型转换变成`unsigned long long`并不影响，还是相当于直接取相反数。因为十六进制的`0x8000000000000000`在`long long` 表示 $-2^{63}$ ，而在`unsigned long long` 中表示 $2^{63}$，所以直接强制转换即可。但是**一旦 `a` 和 `b` 均为 $2^{63}$ 则需要转入`Case 4`进行讨论。** 

##### Case 4

当`a==LLONG_MIN`且`b==LLONG_MIN`（`LLONG_MIN`是$-2^{63}$）时（最后一组数据），`unsigned long long`正好存不下（其最大可以表示到 $2^{64} - 1$ ），于是导致了输出错误.

我们需要对这种情况进行特判输出 $-2^{64}$ 对应的值，即 $-18446744073709551616$ ，其余的取负正常输出即可 
```
#include <stdio.h>
int main(){
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	if(a>=0&&b>=0){
		unsigned long long int sum=a+b;//a+b可能超过long long最大值 故用必正的unsigned long long
		printf("%llu\n",sum);
	}
	else if(((a>0&&b<=0))||((a<=0)&&(b>0))){
		long long int sum=a+b;//因为一正一非正 故相加不会超过long long范围正常输出即可
		printf("%lld\n",sum);
	}
	else if(a==-9223372036854775808ll&&b==-9223372036854775808ll){
		printf("-18446744073709551616\n");//特判 理由见上
	}
	else if(a<=0&&b<=0){//因为特殊情况已经在上面被讨论 故剩下的可以放开手脚取相反数相加
		a=-a,b=-b;
		unsigned long long int sum=a+b;
		printf("-%llu\n",sum);
	}
	return 0;
}
```


### O 4190 忍蛙的圆形轨迹

#### 题目分析

本题的原型为Nowcoder 2020 多校 2-B Boundary。原题允许使用各种语言，例如C++、Java、Python等等，也允许用C，当然允许C89。

本题只允许用C89。作为整场比赛的压轴题，难度最高。

本题的含义，即求解 **全体过原点的圆当中，经过给定点最多的圆上，给定点数是多少** 。

#### 核心算法

标程采用了**初等几何**的做法：圆周角定理，固定端点，跑顶点，统计角的众数。

_当然有用到较高几何知识的巧妙做法。这超纲了，只需要知道最简单的做法就行_ 

**统计众数**这种事情，可以采用这种办法：**先排序**，然后对数组**只跑一遍**，统计连续相同数的最大值。 

如果你懂C++，会容易想到C++STL中的map。这也超纲了，对于本课而言，不需要知道map。本题是一种退而求其次的办法。

——但是远远没完。问题还多得很——

#### 实现细节

##### 圆的问题

- 1. 固定端点，跑顶点的角，即使相等，也未必证明它们就在同一个圆上。

这点说的完全没错。这是整个算法需要谨慎考虑的一点，否则算法自然会失效。

解决办法，是用**叉乘**来检验，使得固定端点后，要跑的顶点全在一个半平面内。

为什么？试想，对于一个圆上的整点，个数自然有限，那么原点的右边自然存在一个相邻点。统计这个圆的时候，用原点和它右边的相邻点做端点就足够了。

##### eps的问题

- 2. 题中Hint说，“如果用到开平方，eps取1e-14”是什么意思？

是这样的。我们要用什么来表示这个角？难道说，要直接把角度求出来吗？

如果要求角，一定要用到反三角函数。而这显然不是必要的。我们想对角排序，无需对具体得角度排序，只需要对**余弦**排序就足够了，因为余弦方便计算。（正弦、正切等相对不容易计算。）

高中学过，余弦的计算方法有两种：向量内积除以向量模长、余弦定理。两种办法是**等价的**，用哪个都一样。都需要在分母的位置开平方。

我们的点都是整点，本来不会出现精度问题，但是开平方，就会出现精度问题。

一种解决办法，是直接对**余弦的平方**排序，钝角时要记得乘个负号保证单调性。在计算的时候，就避开了开平方，这样就根本没有eps问题。当然，为了让代码便于理解，暂时不介绍这种做法。

另一种解决办法，是使用eps。在上文“统计连续相同数的最大值”的地方，希望连续相同数**区间的两个端点**，相差不超过eps。因为它们代表的是同一个圆周角，两头之间不能超过eps。

提醒：不可以在qsort比较函数compare里面使用eps，下文还会提到。

本题的数据量很大，而开一次平方的误差不大，因此eps需要尽可能小。一般情况下，double完全保证的有效数字最高是15位。（对于较小的数能更精确。）如果你对代码没有信心，可以把eps改得更小一些试试看。

##### 比较函数的问题

- 3. C里面，较快的排序只能用qsort。它的比较函数有没有讲究？

非常重要。

对于本题而言，比较函数老老实实按照规范形式写。即：

大于返回1（正数），小于返回-1（负数），**等于返回0**。

请务必这样写，并且，**千万不要在比较函数里面写eps**。对于qsort而言，这一定会造成排序没做好。我们需要排序完全做好。

C语言的qsort函数，就是简单的**快速排序算法**，具体的算法内容是数据结构课、算法课的内容，超纲，不需要了解。但你需要知道，比较函数compare就是qsort的评判标准，快速排序的执行过程比较杂乱，引入eps非常容易造成混乱。尤其是在后文还要找连续区间相等，不停判断区间端点的时候，排序没有做好是致命的。

##### 连续区间的问题

- 4. 如何只跑一遍求“连续区间数值相等”？

首先，确保之前的排序已经做好了，即严格排序已经完成了。

我们引入两个游标，一个左游标，一个右游标。然后从数组的最左边开始往右跑。

先固定一个左游标，然后令右游标为左游标，检查二者是否相等。如果相等，就将右游标向右移动，继续上述检查。如果不相等，则停止，处理其他内容，例如区间长等等。处理完了之后，再更新左游标为刚才的右游标，重复操作，直到左游标或右游标跑到数组右端为止。

在有eps的情况下，检查左右游标所在的值，距离是否超过eps，即区间的两个端点涵盖的取值范围是否超过eps。

#### 标程代码

如果你写了很长时间，还没有通过，可以参考下面的做法，对比对比与自己的算法流程有什么不同，深入思考，然后调试自己的代码。

希望同学们，在学会C语言的基础上，也能掌握规范整齐的代码书写方法，以及养成勤于思考的习惯。

```C

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int comp(const void *p1,const void *p2)/*qsort比较函数，不要忘记相等时返回0*/
{
    double *a=(double*)p1;
    double *b=(double*)p2;
    if(*a<*b)
    {
        return 1;
    }
    else if(*a>*b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int X[2005],Y[2005];/*初始点集*/

int Cross(int lhs,int rhs)/*叉乘*/
{
    return X[lhs]*Y[rhs]-X[rhs]*Y[lhs];
}

int Dis2(int lhs,int rhs)/*距离平方*/
{
    int dx=X[lhs]-X[rhs],dy=Y[lhs]-Y[rhs];
    return dx*dx+dy*dy;
}

double GetCos(int i,int j)/*计算夹角余弦*/
{
    int a2=Dis2(0,i),b2=Dis2(i,j),c2=Dis2(0,j);
    return (double)(b2+c2-a2)/((double)2*sqrt(b2)*sqrt(c2));
}

double Cos[2005];/*夹角余弦*/

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",X+i,Y+i);
    }
    int ans=1;
    for(i=1;i<=n;i++)
    {
        int cnt=0;
        int j;
        for(j=1;j<=n;j++)
        {
            if(Cross(i,j)>0)/*夹角可以有两个朝向，可以将一半的朝向舍去*/
            {
                Cos[++cnt]=GetCos(i,j);
            }
        }
        qsort(Cos+1,cnt,sizeof(double),comp);
        int l,r;
        for(l=1;l<=cnt;)/*这个循环很巧妙，请仔细思考它的原理*/
        {
            r=l;
            while(Cos[l]-Cos[r]<1e-14&&Cos[r]-Cos[l]<1e-14&&r<=cnt)
            {
                r++;
            }
            ans=ans>(r-l+1)?ans:(r-l+1);
            l=r;
        }
    }
    printf("%d\n",ans);
    return 0;
}

```

#### 另一种解法

另一种解法，使用反演变换的方法也能解出来。仅有细节不同，大体流程与标程解法大致相同。这种方法超出了本课范围，不必掌握，仅知道还有更多更厉害的解法即可。

```C

#include<stdio.h>
#include<stdlib.h>
#include<float.h>

int comp(const void *p1,const void *p2)
{
	double *a=(double*)p1;
	double *b=(double*)p2;
	if(*a<*b)
	{
		return 1;
	}
	else if(*a>*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

struct poi
{
	double first;
	double second;
};

struct poi points[10010];
int topp;

double m[10010];
int topm;

int maxPoints()
{
	int res=1;
	int i;
	for(i=0; i<topp; ++i)
	{
		topm=0;
		int j;
		for(j=i+1; j<topp; ++j)
		{
			if(points[j].first*points[i].second==points[i].first*points[j].second)
			{
				continue;
			}
			double dx=points[j].first-points[i].first;
			double dy=points[j].second-points[i].second;
			if(dy!=0)
			{
				m[topm]=dx/dy;
			}
			else
			{
				m[topm]=DBL_MAX;
			}
			topm++;
		}
		qsort(m,topm,sizeof(double),comp);
		int l,r;
		for(l=0; l<topm;)
		{
			r=l;
			while(m[l]-m[r]<1e-14&&m[r]-m[l]<1e-14&&r<topm)
			{
				r++;
			}
			res=res>(r-l+1)?res:(r-l+1);
			l=r;
		}
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	double x,y;
	while(n--)
	{
		scanf("%lf%lf",&x,&y);
		double temp=x*x+y*y;
		struct poi pp;
		pp.first=x/temp;
		pp.second=y/temp;
		points[topp]=pp;
		topp++;
	}
	printf("%d\n",maxPoints());
	return 0;
}

```

### P 4184 YourSQL2.0

去年上机题目的升级版，新规定了输出格式，让输出看上去更美观（

本题并不难，但是一道较为综合的结构体排序，考验同学们的细心和耐心，需要同学们完成各个函数功能的设计，主要需要考虑的地方有：

+ 结构体的设计，如何来存储表；
+ 字符串的处理，如何处理读入的数据；
+ 每一个元组的比较，即compare函数的设计；
+ 排好序的表的输出，要正确按照题目的要求输出最终结果。

刚接触C语言的同学做不出来很正常，但是在整个课程学完之后，感兴趣的同学可以回过头来做一下这题，当做一种复习。

标程如下。或许可以期待YourSQL3.0（

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWNUM 1007
#define COLNUM 107
#define LEN 107
#define INT 0
#define REAL 1
#define VARCHAR 2
#define DATE 3
int type[COLNUM], wide[COLNUM], sp[COLNUM][2], row, col, n;
char title[COLNUM][LEN], typeString[LEN];
typedef struct table
{
    union attr
    {
        char varchar[LEN];
        double real;
        int date;
        int intNum;
    } A;
    char rawData[LEN];
    int length;
} T;
T t[ROWNUM][COLNUM];

void readTable()
{
    
    int i, j, y, m, d;
    scanf("%d %d", &row, &col);
    for (i = 0; i < col; i++)
    {
        scanf("%s", title[i]);
        if (strlen(title[i]) > wide[i])
            wide[i] = (int)strlen(title[i]);
    }
    for (i = 0; i < col; i++)
    {
        scanf("%s", typeString);
        if (strcmp(typeString, "INT") == 0)
            type[i] = INT;
        else if (strcmp(typeString, "REAL") == 0)
            type[i] = REAL;
        else if (strcmp(typeString, "VARCHAR") == 0)
            type[i] = VARCHAR;
        else
            type[i] = DATE;
    }
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            scanf("%s", t[i][j].rawData);
            t[i][j].length = (int)strlen(t[i][j].rawData);
            if (t[i][j].length > wide[j])
                wide[j] = t[i][j].length;
            switch (type[j])
            {
                case INT:
                    sscanf(t[i][j].rawData, "%d", &t[i][j].A.intNum);
                    break;
                case REAL:
                    sscanf(t[i][j].rawData, "%lf", &t[i][j].A.real);
                    break;
                case VARCHAR:
                    sscanf(t[i][j].rawData, "%s", t[i][j].A.varchar);
                    break;
                case DATE:
                    sscanf(t[i][j].rawData, "%d-%d-%d", &y, &m, &d);
                    t[i][j].A.date = d + m * 100 + y * 10000;
                default:
                    break;
            }
        }
}

void readSP()
{
    int i;
    char colName[LEN];
    while (~scanf("%s %d", colName, &sp[n][1]))
    {
        for (i = 0; i < col; i++)
            if (strcmp(colName, title[i]) == 0)
            {
                sp[n][0] = i;
                break;
            }
        n++;
    }
}

int cmp(const void *a, const void *b)
{
    T *t1 = (T *)a, *t2 = (T *)b;
    int i, c, sgn, ret = 0;
    for (i = 0; i < n; i++)
    {
        c = sp[i][0];
        sgn = sp[i][1];
        switch (type[c])
        {
            case VARCHAR:
                ret = sgn * strcmp(t1[c].A.varchar, t2[c].A.varchar);
                break;
            case INT:
                ret = sgn * (t1[c].A.intNum - t2[c].A.intNum);
                break;
            case REAL:
                if (t1[c].A.real - t2[c].A.real > 0)
                    ret = sgn * 1;
                else if (t1[c].A.real - t2[c].A.real < 0)
                    ret = sgn * -1;
                else
                    ret = 0;
                break;
            case DATE:
                ret = sgn * (t1[c].A.date - t2[c].A.date);
            default:
                break;
        }
        if (ret != 0)
            return ret;
    }
    return 0;
}

void printTable()
{
    char format[LEN];
    int i, j;
    putchar('|');
    for (j = 0; j < col; j++)
    {
        sprintf(format, "%%%ds", wide[j]);
        printf(format, title[j]);
        putchar('|');
    }
    putchar('\n');
    for (i = 0; i < row; i++)
    {
        putchar('|');
        for (j = 0; j < col; j++)
        {
            sprintf(format, "%%%ds", wide[j]);
            printf(format, t[i][j].rawData);
            putchar('|');
        }
        putchar('\n');
    }
}

int main()
{
    readTable();
    readSP();
    qsort(t, row, sizeof(*t), cmp);
    printTable();
    return 0;
}
```


### Q 4198 基础物理实验 2

本题的正解是采用概率统计+递推的方法，主要的工作量在于私下的思维推导。

假设当前我们还有k个球没有抽到过，那么要想转移到还有k-1个没有抽到过的时候，自然就是要从n个当中抽到这k个中的任意一个，很明显这样做的概率是$\frac{k}{n}$，对应的期望就是$\frac{n}{k}$了。

那么实际上题目中分析的整个过程就是从还有n个球没抽到到还有0个球没抽到，一步步递推的过程。

答案显而易见，就是 $\frac{n}{n} + \frac{n}{n-1} + ... + \frac{n}{1} = n\left(1 + \frac{1}{2} + ... + \frac{1}{n}\right)$

在计算出了答案之后，后面的一切都变得简单了。我们只需要通过模拟分数的加法和约分来完成问题，在这里需要注意的是约分的时候采用除以一定量的质数或者直接求最大公约数，以及在处理的过程中是否会出现爆精度的问题（虽然预期是需要搞到long long就够了，从提交结果来看，采用更加暴力的做法的话甚至可能需要用到int128，这超出了本课程要求的范围，且本地不太好调试）。

在输出的时候，你需要注意各部分固定的输出宽度，除了一遍遍暴力除法可以得到长度，也可以考虑sprintf的方式直接做好所有工作，在输出时直接输出该字符串即可。

```c
#include<stdio.h>
#include<string.h>
typedef long long ll;
//最大公约数 用于约分
ll gcd(ll a, ll b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

//分数 p是分子 q是分母
typedef struct decimal {
    ll p, q;
}decimal;

decimal sum(decimal a, decimal b) {
    decimal ret;
    ret.p = a.p * b.q + a.q * b.p;
    ret.q = a.q * b.q;
    ll g = gcd(ret.p, ret.q);
    ret.p /= g;
    ret.q /= g;
    return ret;
}

char up[20], down[20], integer[20];

void print(decimal ans) {
    if(ans.q == 1) printf("%lld\n", ans.p);//整数输出
    else {//带分数输出
        ll Integer = ans.p / ans.q, Up = ans.p % ans.q;
        sprintf(up, "%lld", Up);
        sprintf(down, "%lld", ans.q);
        sprintf(integer, "%lld", Integer);
        int len_int = strlen(integer), len_up = strlen(up), len_down = strlen(down);
        int i;
        for(i = 0; i < len_int; i++) putchar(' ');
        puts(up);
        printf("%s", integer);
        for(i = 0; i < len_down; i++) putchar('-');
        putchar('\n');
        for(i = 0; i < len_int; i++) putchar(' ');
        puts(down);
    }
    putchar('\n');
}

int n;
decimal a, b;
int main() {
    while(scanf("%d", &n) != EOF) {
        a.p = 0;
        a.q = 1;
        int i;
        for(i = 1; i <= n; ++i) {
            b.p = n;
            b.q = i;
            a = sum(a, b);
        }
        print(a);
    }
}
```

当然，类似前面“级数求和”的问题，本题仍然可以打表输出。比如，你继续去OEIS上查。但是，只能查到整数部分、部分分母以及假分数的分子，带分数的分子查不到，并且分母的28到30也查不到。于是你需要在草稿纸上暴力手算，至多加一个计算器算，算到地老天荒。比如，2小时后，你终于算完了，抄到代码里面。此时若是一不小心抄错，比如抄乱了两个数，就会一直WA，WA到怀疑人生。

（这可能是某位助教的打表经历）

在赛后补题的时候，不建议直接将打表的做法的代码进行复制粘贴，而是建议阅读和理解正解的做法。


```C


#include<stdio.h>

int main()
{
	int n;
	int flag=0;
	while(~scanf("%d",&n))
	{
		if(flag!=0)
		{
			printf("\n");
		}
		flag=1;
		if(n==0)
		{
			printf("0\n");
		}
		else if(n==1)
		{
			printf("1\n");
		}
		else if(n==2)
		{
			printf("3\n");
		}
		else if(n==3)
		{
			printf(" 1\n");
			printf("5-\n");
			printf(" 2\n");
		}
		else if(n==4)
		{
			printf(" 1\n");
			printf("8-\n");
			printf(" 3\n");
		}
		else if(n==5)
		{
			printf("  5\n");
			printf("11--\n");
			printf("  12\n");
		}
		else if(n==6)
		{
			printf("  7\n");
			printf("14--\n");
			printf("  10\n");
		}
		else if(n==7)
		{
			printf("  3\n");
			printf("18--\n");
			printf("  20\n");
		}
		else if(n==8)
		{
			printf("  26\n");
			printf("21--\n");
			printf("  35\n");
		}
		else if(n==9)
		{
			printf("  129\n");
			printf("25---\n");
			printf("  280\n");
		}
		else if(n==10)
		{
			printf("  73\n");
			printf("29---\n");
			printf("  252\n");
		}
		else if(n==11)
		{
			printf("  551\n");
			printf("33----\n");
			printf("  2520\n");
		}
		else if(n==12)
		{
			printf("  551\n");
			printf("37----\n");
			printf("  2310\n");
		}
		else if(n==13)
		{
			printf("  9473\n");
			printf("41-----\n");
			printf("  27720\n");
		}
		else if(n==14)
		{
			printf("  13433\n");
			printf("45-----\n");
			printf("  25740\n");
		}
		else if(n==15)
		{
			printf("  18581\n");
			printf("49-----\n");
			printf("  24024\n");
		}
		else if(n==16)
		{
			printf("  4129\n");
			printf("54-----\n");
			printf("  45045\n");
		}
		else if(n==17)
		{
			printf("  340463\n");
			printf("58------\n");
			printf("  720720\n");
		}
		else if(n==18)
		{
			printf("  620743\n");
			printf("62------\n");
			printf("  680680\n");
		}
		else if(n==19)
		{
			printf("  1662439\n");
			printf("67-------\n");
			printf("  4084080\n");
		}
		else if(n==20)
		{
			printf("  3704479\n");
			printf("71-------\n");
			printf("  3879876\n");
		}
		else if(n==21)
		{
			printf("  408335\n");
			printf("76------\n");
			printf("  739024\n");
		}
		else if(n==22)
		{
			printf("  46533\n");
			printf("81------\n");
			printf("  235144\n");
		}
		else if(n==23)
		{
			printf("  4597419\n");
			printf("85-------\n");
			printf("  5173168\n");
		}
		else if(n==24)
		{
			printf("  9265735\n");
			printf("90--------\n");
			printf("  14872858\n");
		}
		else if(n==25)
		{
			printf("  142406227\n");
			printf("95---------\n");
			printf("  356948592\n");
		}
		else if(n==26)
		{
			printf("   73762267\n");
			printf("100---------\n");
			printf("   343219800\n");
		}
		else if(n==27)
		{
			printf("   206234003\n");
			printf("105----------\n");
			printf("   2974571600\n");
		}
		else if(n==28)
		{
			printf("   2755866803\n");
			printf("109----------\n");
			printf("   2868336900\n");
		}
		else if(n==29)
		{
			printf("   71315126587\n");
			printf("114-----------\n");
			printf("   80313433200\n");
		}
		else if(n==30)
		{
			printf("   65960897707\n");
			printf("119-----------\n");
			printf("   77636318760\n");
		}
	}
}

```
