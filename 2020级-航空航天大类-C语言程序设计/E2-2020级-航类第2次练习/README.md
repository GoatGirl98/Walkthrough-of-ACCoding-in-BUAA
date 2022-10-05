# E2-2020级-航类第2次练习

这是E2-2020级-航类第2次练习，未选入C1的助教题目会出现在这里。本次练习赛共10道题。

## 题目列表

- A 4264 Yes OK！
- B 4250 循环移位转圈圈
- C 4221 复数计算器
- D 4266 切换进制回文数
- E 4248 木木枭学高中集合论
- F 4256 高低位
- G 4244 CRC16
- H 4243 ZJD想当Manager
- I 4247 简易浮点数
- J 4258 浮点数进阶

## 部分题解

一些过于简单的题目无需写题解，直接阅读标准代码即可。

一些困难题目还是希望同学们勤思考。题解仅供参考。

### `A` 4264 Yes OK！

#### 题目分析

本题的考点很简单，就是**位运算**，代码也很简单，大家不要想复杂了；因为计算机中的数本身就是以补码形式储存的，所以我们先得到一个第 $n$ 位是 $1$ ，其他位是 $0$ 的数 $num$ ，可以用 $1<<n$ 来实现；然后将这个数与输入的数进行按位与运算，如果输入的数第 $n$ 位是 $1$ ，那么与出来的结果肯定不等于 $0$，反之一定等于 $0$ ，所以进行简单的判断然后输出就可以了；

注意两点，在判断和循环的时候，非0即真值，也就是说，下面的代码可以进入判断或者循环；

```c
if(-1)//可以进入
	//code
	
while(-1)//可以进入
{
	//code
}
```

另外注意输出的大小写，输出固定字符串的建议直接从题目中复制

#### 示例代码

```c
#include <stdio.h>
int t,k,n;
int main(void)
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&k,&n);
        if(k&(1<<n))
        printf("Yes!\n");
        else
        printf("NO!\n");
    }
    return 0;
}
```

关于 k&(1<<n) 具体是多少，自己输出一下就知道了；

### `B` 4250 循环移位转圈圈

#### 题目分析

本题主要考查**移位**的基础知识，利用**位运算符**取特定位。  
但有一些易错点：  
1.实际移位次数只需要`k%N`次，如果暴力移位`k`次会有部分数据点`TLE`  
2.**字面常量**的数据类型问题。例如进行`1<<N`的操作时，若`N`比较大，字面常量`1`超出默认的`int`范围，则需指定字面常量的数据类型为：long:`1L`, long long`1LL`, unsigned int:`1U`, unsigned long:`1UL`, unsigned long long:`1ULL`等

#### 示例代码

```c
#include<stdio.h>

int main(){
    int N,k;
	unsigned long long a,left,right,result;//注意数据范围 int 肯定不够用 
    while(scanf("%d%d%llu",&N,&k,&a)!=EOF){
    	k=k%N;//循环左移k次，本质上等于循环左移k%N次，减小运算量
		a<<=k;//将被操作数左移k 
		right=a&((1ULL<<N)-1);//将溢出N位的部分截断，实质上是留下了被操作数右半部分 
		left=(a&((1ULL<<(N+k))-(1ULL<<N)))>>N;//取被操作数左半部分，向右移位置于低位 
		result=right+left;//合并 
    	printf("%llu\n",result);
	}
	return 0;
}
```

*AUTHOR:孟大师*

### `C` 4221 复数计算器

#### 题目分析

本题考察了格式较为复杂的输入输出，switch-case语句，多重情况的判断与讨论，浮点数大小比较，浮点数是否为整数的判断。基本不涉及数据范围与精度问题。

#### 示例代码

```c
#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c,d,e,f;
    char sym;
    while(scanf("(%lf%lfi)%c(%lf%lfi)",&a,&b,&sym,&c,&d)!=EOF){
    	//吃掉每行结尾多余的\n等字符，防止读取下一行开头(时卡住 
    	char ctemp=getchar();
    	while(ctemp!='\n'&&ctemp!=EOF){
    		ctemp=getchar();
		}
		//基本switch-case语句 
    	switch(sym){
    		case '+':
    			e=a+c;
    			f=b+d;
    			break;
    		case '-':
    			e=a-c;
    			f=b-d;
    			break;
    		case '*':
    			e=a*c-b*d;
    			f=b*c+a*d;
    			break;
    		case '/':
    			e=(a*c+b*d)/(c*c+d*d);
    			f=(b*c-a*d)/(c*c+d*d);
    			break;
		}
		//以下涉及浮点数大小比较，浮点数是否为整数的判断 
		//如果实部为零
		if(fabs(e)<1e-5){
			//如果实部虚部都为零
			if(fabs(f)<1e-5){ 
				printf("0");
			}			
			//虚部不为零 只输出虚部，没有前导"+"号
			//虚部为1 则只输出i
			else if(fabs(f-1)<1e-5){ 
				printf("i");
			}
			//虚部为-1 则只输出-i
			else if(fabs(f+1)<1e-5){ 
				printf("-i");
			}
			//虚部为整数，输出整数，没有前导"+"号 
			else if(fabs(round(f)-f)<1e-5){
				printf("%.0fi",f);
			}
			//虚部有小数部分，保留两位小数，没有前导"+"号 
			else{
				printf("%.2fi",f);
			}
		}
		//如果实部不为零
		else{ 
			//正常输出实部 
			if(fabs(round(e)-e)<1e-5){
				printf("%.0f",e);
			}else{
				printf("%.2f",e);
			}
			//输出虚部  有前导"+"-"号 
			//虚部为零 不输出
			if(fabs(f)<1e-5){
				 
			}
			//虚部为1 则只输出+i 
			else if(fabs(f-1)<1e-5){
				printf("+i");
			}
			//虚部为-1 则只输出-i
			else if(fabs(f+1)<1e-5){ 
				printf("-i");
			}
			//以下对虚部为整数小数进行讨论，注意有前导+号 
			else if(fabs(round(f)-f)<1e-5){ 
				printf("%+.0fi",f);
			}
			else{
				printf("%+.2fi",f);
			}
		}
		printf("\n");
	}
	return 0;
}
```

#### 对输入部分的一些讨论

本题`scanf`部分最简便的实现方式是以下这种：（由于已经提示了评测数据每行结尾一定包含`\n`）

```c
    while(scanf("(%lf%lfi)%c(%lf%lfi)\n",&a,&b,&sym,&c,&d)!=EOF){
    }
```

但是以上语句可能出现，输入第二行后回车才返回上一行答案的情况，问题出在`scanf`函数结束输入的方式：**1 回车 2遇到非法字符 3指定宽度结束 例如%5s**。由于上面的方案每行输入匹配了`\n`，没有多余`\n`供`scanf`结束输入，程序就会等待直到下一行输入数据出现。**但这种方法最后输出数据是完整的，并不影响程序运行。**   
更好的方式是这样：  

```c
    while(scanf("(%lf%lfi)%c(%lf%lfi)",&a,&b,&sym,&c,&d)!=EOF){
        char ctemp=getchar();
        while(ctemp!='\n'&&ctemp!=EOF){
            ctemp=getchar();
        }
```

这样的方式可以让调试时更加优雅。  
当然还有其他技术方案，例如用`gets()`读入一整行字符串，使用`sscanf()`函数解析，但由于大家目前还没有学习字符串知识，这里不做详细展开。  
*AUTHOR:孟大师*

### `D` 4266 切换进制回文数

#### 题目分析

首先进行进制转换，之后对数字进行回文数判断即可，需要注意：1.进制转换的写法是否正确2.回文数判断可以用提示中两种不同方法进行，但是效果是一样的

#### 示例代码

```c
#include<stdio.h>
int main()
{
	int q,m,i,j,x,judge,k;
	char c[]="0123456789ABCDEFGHIJ";
	char a[103];
	scanf("%d",&q);
	while(scanf("%d",&m)!=EOF)
	{
		i=0;
		judge=1;
		while (m>0)
		{
			x=m%q;
			a[i]=c[x];
			m=m/q;
			i++;
		}//进制转换
		j=0;
		for(k=i-1;j<k;k--)
		{
			if(a[j]!=a[k])
				judge=0;
			j++;
		}//回文数判断
		if (judge)
		{
			for (i--;i>=0;i--)
				printf("%c",a[i]);
			printf("\n");
		}
	}
	return 0;
}
```

### `E` 4248 木木枭学高中集合论

#### 题目分析

很简单。直接填空即可。

一些同学问这个题的代码结构有什么意义，可以参见Gitee上的提问：https://gitee.com/duchenhong/programming_routine_2021c/issues/I3CITT

#### 示例代码

```c
#include<stdio.h>

int main()
{
	int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<(1<<n);i++)//所有可能元素选取
    {
        int j;
        for(j=0;j<n;j++)//每一位
        {
            if((i>>j)&1)//如果该位有元素
            {
				printf("%d",j);
            }
            else
            {
            	printf("-");
			}
        }
		printf("\n");
    }
}

```

### `F` 4256 高低位

#### 题目分析

本题目的二进制位运算模拟数字电路中全加器功能的实现,全加器的真值表和逻辑表达式在HINT中已经给出，通过这一资料可以写出全加器部分的代码，之后是考察对二进制中仅有首位为1的负数的理解，在转换时需要单独考虑，之后则是二进制中负数补码的考察。在得到正数补码后通过字符串模拟求和转化为十进制输出后即可，下面代码包括两种转换方式。代码片段1的转化是通过数组来储存每一位二进制对应权重，并对其求和来实现的超过`unsigned long long`类型的二进制数的表达。还有一种是通过秦九昭算法实现的进制转换

#### 示例代码1

```c
#include<stdio.h>

int main()
{
	int Dec[42]= {}; //十进制结果
	int DecLength=1;//十进制结果长度
	unsigned long long AHigh,ALow;
	unsigned long long BHigh,BLow;
	unsigned long long CLow=0x0;
	unsigned long long CHigh=0x0;
	scanf("%llu%llu%llu%llu",&AHigh,&ALow,&BHigh,&BLow);
	/*------------全加器------------*/
	unsigned long long CarryLow=0; //低位进位数纪录变量
	int Index;
	for(Index=0; Index<64; Index++)
	{
		CarryLow=CarryLow<<1;
		unsigned long long ToolNum=1;
		ToolNum=ToolNum<<Index;
		CLow|=ToolNum&(ALow^BLow^CarryLow);
		CarryLow=(ToolNum&((ALow&BLow)|(CarryLow&BLow)|(ALow&CarryLow)));
	}
	unsigned long long CarryHigh=CarryLow>>63; //高位进位数纪录变量，转存低位结果
	for(Index=0; Index<64; Index++)
	{
		unsigned long long ToolNum=1;
		ToolNum=ToolNum<<Index;
		CHigh|=ToolNum&(AHigh^BHigh^CarryHigh);
		CarryHigh=(ToolNum&((AHigh&BHigh)|(CarryHigh&BHigh)|(AHigh&CarryHigh)))<<1;
	}
	unsigned long long IsLessThanZero;
	/*-----------#全加器#-----------*/
	if (CHigh==0&&CLow==0) //防止0减一取反
	{
		printf("%d",0);
	}
	else if(CHigh==0x8000000000000000&&CLow==0x0)  //防止最小数减一取反
	{
		printf("-170141183460469231731687303715884105728");
	}
	else
	{
		/*------------绝对值------------*/
		IsLessThanZero=CHigh&0x8000000000000000;
		if(IsLessThanZero)
		{
			if (CLow<1)
			{
				CHigh--; //高位借位
				CLow=0xffffffffffffffff;//低位减一
			}
			else
			{
				CLow--; //低位减一
			}
			CLow=~CLow; //取反
			CHigh=~CHigh;
		}
		/*-----------#绝对值#-----------*/
		/*------------十进制------------*/
		int BitToDec[42]= {1}; //当前位二进制数的十进制权重
		int LastBitToDec[42]= {1}; //上一位二进制数的十进制权重,没啥用
		int TBDLenth=1;//当前位二进制数的十进制权重的数组长度
		int LowCounter=0,HighCounter=0; //当前处理位的偏移量
		unsigned long long ToolNumber=1; //用于截取某一位数字的工具数
		while (LowCounter<64)
		{
			if (CLow&(ToolNumber<<LowCounter))
			{
				/*-----向求和数中加上当前位的权重-----*/
				for(int i=0; i<TBDLenth; i++)
				{
					Dec[i]+=BitToDec[i];
					DecLength=i+1;
					if(Dec[i]>9)
					{
						Dec[i]%=10;
						Dec[i+1]++;
						DecLength=i+2;
					}
				}
				/*-----#向求和数中加上当前位的权重#-----*/
			}
			int WaitBit=0; //进位记录
			/*-----权重乘2-----*/
			int i;
			for(i=0; i<TBDLenth; i++)
			{
				LastBitToDec[i]=BitToDec[i];
				BitToDec[i]*=2;
				BitToDec[i]+=WaitBit;
				WaitBit=0;
				if(BitToDec[i]>9)
				{
					WaitBit=BitToDec[i]/10;
					BitToDec[i]%=10;
					if(i==TBDLenth-1)
					{
						TBDLenth++;
					}
				}
			}
			/*-----#权重乘2#-----*/
			LowCounter++;
		}
		while (HighCounter<64)
		{
			if (CHigh&(ToolNumber<<HighCounter))
			{
				/*-----向求和数中加上当前位的权重-----*/
				int i;
				for(i=0; i<TBDLenth; i++)
				{
					Dec[i]+=BitToDec[i];
					DecLength=i+1;
					if(Dec[i]>9)
					{
						Dec[i]%=10;
						Dec[i+1]++;
						DecLength=i+2;
					}
				}
				/*-----#向求和数中加上当前位的权重#-----*/
			}
			int WaitBit=0;//进位记录
			/*-----权重乘2-----*/
			int i;
			for(i=0; i<TBDLenth; i++)
			{
				LastBitToDec[i]=BitToDec[i];
				BitToDec[i]*=2;
				BitToDec[i]+=WaitBit;
				WaitBit=0;
				if(BitToDec[i]>9)
				{
					WaitBit=BitToDec[i]/10;
					BitToDec[i]%=10;
					if(i==TBDLenth-1)
					{
						TBDLenth++;
					}
				}
			}
			/*-----#权重乘2#-----*/
			HighCounter++;
		}
		/*-----------#十进制#-----------*/
		if (IsLessThanZero)
		{
			putchar('-');
		}
		int i;
		for(i=DecLength-1; i>=0; i--)
		{
			printf("%d",Dec[i]);
		}
	}
	return 0;
}
```

#### 示例代码2

```c
#include<stdio.h>

int main()
{
	unsigned long long AHigh,ALow;
	unsigned long long BHigh,BLow;
	unsigned long long CLow=0x0;
	unsigned long long CHigh=0x0;
	scanf("%llu%llu%llu%llu",&AHigh,&ALow,&BHigh,&BLow);
	/*------------全加器------------*/
	unsigned long long CarryLow=0; //低位进位数纪录变量
	int Index;
	for(Index=0; Index<64; Index++)
	{
		CarryLow=CarryLow<<1;
		unsigned long long ToolNum=1;
		ToolNum=ToolNum<<Index;
		CLow|=ToolNum&(ALow^BLow^CarryLow);
		CarryLow=(ToolNum&((ALow&BLow)|(CarryLow&BLow)|(ALow&CarryLow)));
	}
	unsigned long long CarryHigh=CarryLow>>63; //高位进位数纪录变量，转存低位结果
	for(Index=0; Index<64; Index++)
	{
		unsigned long long ToolNum=1;
		ToolNum=ToolNum<<Index;
		CHigh|=ToolNum&(AHigh^BHigh^CarryHigh);
		CarryHigh=(ToolNum&((AHigh&BHigh)|(CarryHigh&BHigh)|(AHigh&CarryHigh)))<<1;
	}
	unsigned long long IsLessThanZero;
	/*-----------#全加器#-----------*/
	if (CHigh==0&&CLow==0) //防止0减一取反
	{
		printf("%d",0);
	}
	else if(CHigh==0x8000000000000000&&CLow==0x0)  //防止最小数减一取反
	{
		printf("-170141183460469231731687303715884105728");
	}
	else
	{
		/*------------绝对值------------*/
		IsLessThanZero=CHigh&0x8000000000000000;
		if(IsLessThanZero)
		{
			if (CLow<1)
			{
				CHigh--; //高位借位
				CLow=0xffffffffffffffff;//低位减一
			}
			else
			{
				CLow--; //低位减一
			}
			CLow=~CLow; //取反
			CHigh=~CHigh;
		}
		/*-----------#绝对值#-----------*/
		/*------------十进制------------*/
		int BitToDec[42]= {0}; //当前位二进制数的十进制权重
		int LastBitToDec[42]= {0}; //上一位二进制数的十进制权重,没啥用
		int TBDLenth=1;//当前位二进制数的十进制权重的数组长度
		int LowCounter=0,HighCounter=0; //当前处理位的偏移量
		unsigned long long ToolNumber=1; //用于截取某一位数字的工具数
		while (HighCounter<64)
		{
			if (CHigh&(ToolNumber<<(63-HighCounter)))
			{
				/*-----向当前最低位+1-----*/
				int ForwardSave=0;
				int i;
				for(i=0; i<TBDLenth; i++)
				{
					BitToDec[i]+=ForwardSave;
					ForwardSave=0;
					BitToDec[i]++;
					if(BitToDec[i]>9)
					{
						ForwardSave=1;
					}
					else
					{
						break;
					}
				}
				if (ForwardSave)
				{
					BitToDec[TBDLenth]=1;
					TBDLenth++;
				}
			}
			/*-----#向当前最低位+1#-----*/
			int WaitBit=0;//进位记录
			/*-----结果乘2-----*/
			int i;
			for(i=0; i<TBDLenth; i++)
			{
				LastBitToDec[i]=BitToDec[i];
				BitToDec[i]*=2;
				BitToDec[i]+=WaitBit;
				WaitBit=0;
				if(BitToDec[i]>9)
				{
					WaitBit=BitToDec[i]/10;
					BitToDec[i]%=10;
					if(i==TBDLenth-1)
					{
						TBDLenth++;
					}
				}
			}
			/*-----#结果乘2#-----*/
			HighCounter++;
		}
		while (LowCounter<64)
		{
			if (CLow&(ToolNumber<<(63-LowCounter)))
			{
				/*-----向当前最低位+1-----*/
				int ForwardSave=0;
				int i;
				for(i=0; i<TBDLenth; i++)
				{
					BitToDec[i]+=ForwardSave;
					ForwardSave=0;
					BitToDec[i]++;
					if(BitToDec[i]>9)
					{
						ForwardSave=1;
					}
					else
					{
						break;
					}
				}
				if (ForwardSave)
				{
					BitToDec[TBDLenth]=1;
					TBDLenth++;
				}
				/*-----#向当前最低位+1#-----*/
			}
			if(LowCounter<63)
			{
				int WaitBit=0; //进位记录
				/*-----结果乘2-----*/
				int i;
				for(i=0; i<TBDLenth; i++)
				{
					LastBitToDec[i]=BitToDec[i];
					BitToDec[i]*=2;
					BitToDec[i]+=WaitBit;
					WaitBit=0;
					if(BitToDec[i]>9)
					{
						WaitBit=BitToDec[i]/10;
						BitToDec[i]%=10;
						if(i==TBDLenth-1)
						{
							TBDLenth++;
						}
					}
				}
			}
			/*-----#结果乘2#-----*/
			LowCounter++;
		}
		/*-----------#十进制#-----------*/
		if (IsLessThanZero)
		{
			putchar('-');
		}
		int i;
		for(i=TBDLenth-1; i>=0; i--)
		{
			printf("%d",BitToDec[i]);
		}
	}
	return 0;
}
```

### `G` 4244 CRC16

#### 题目分析

本题仅需要按照题目要求进行运算即可，16 进制的读写可以使用 `%x` （小写）或 `%X` （大写）实现。

#### 示例代码

```c
#include<stdio.h>
int main(){
    int a,i,j,crc=0xFFFF,str[10];
    for(i=0;i<8;i++)
    {
    	scanf("%X",&a);
    	str[i]=a;
	}
	i=0;
    while(i<8)
	{
		crc=crc^str[i];
        for(j=0;j<8;j++)
		{
        	if(crc&0x0001)
			{
        		crc=crc>>1;
                crc=crc^0xA001;
			}
            else
            {
            	crc=crc>>1;
			}
		}
        i++; 
	}
	printf("%02X %02X",crc&0xFF,crc>>8);
}
```

### `H` 4243 ZJD想当Manager

#### 题目分析

由题意可知，只需要使用$99\times2$的二维数组储存好每名球员的传球接球数据，读入询问号码后按要求输出该球员的传接球次数，如果传接球次数均为0，则可以说明该球员没有参与到比赛当中，按题目要求输出对应内容即可。

#### 示例代码

```c
#include <stdio.h>

int main()
{
	int a[100]={0},b[100]={0};
	int n,i,m;
	int pass,get;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&pass,&get);
		a[pass]+=1,b[get]+=1;
	}
	scanf("%d",&m);
	if(a[m]|b[m])			     //条件判断，如果传接球不同时为零
		printf("%d %d",a[m],b[m]);
	else
		printf("N0t 1n my team!");
		
	return 0;
}
```

### `I` 4247 简易浮点数

#### 题目分析

本题的主要目的是让大家对浮点数有个基本的印象。题目中给出了一个简易的浮点数标准，大家只要按照步骤去做，就可以AC此题。仍然需要强调的一点是，**本题中计算浮点数值的方法和实际有很大区别，有兴趣想要了解真正浮点数规则（IEEE 754）的同学请自行搜索**，或者阅读本周 `J` 题 `浮点数进阶` 的题面来了解实际中所使用的 IEEE 754 浮点数标准。

要AC此题主要需要掌握的就是如何将二进制数转换为十进制数，尤其是带有小数点的二进制数。

将带有小数点的二进制数用 $a_na_{n-1}...a_1a_0.a_{-1}a_{-2}...a_{-m+1}a_{-m}$ 表示，其对应的实数值可以用公式来表示：

​																			 $$\sum\limits_{i=-m}^{n} a_i \times 2^{i}$$

同学们将这个公式转为代码即可。

#### 示例代码

```c
#include <stdio.h>

int main()
{
	char a[100];
	int len;
	scanf("%s", a); //读入一行字符串
	for (len = 0; a[len] != '\0'; len++) //将各位数字字符转换为数值
	{
		a[len] -= '0';
	}
	int k;
	while (~scanf("%d", &k)) //循环读入k
	{
		//计算bias = 2^(k - 1) - 1
		int bias = 1;
		int i;
		for (i = 0; i < k - 1; i++)
		{
			bias *= 2;
		}
		bias -= 1;
		//计算E
		double E = 0, b = 1;
		for (i = k; i >= 1; i--)
		{
			E += a[i] * b;
			b *= 2;
		}
		//计算F
		double F = 1;
		b = 1.0 / 2;
		for (i = k + 1; i <= len; i++)
		{
			F += a[i] * b;
			b /= 2;
		}
		//计算 x = (-1)^s * F * 2^(E-bias)
		double x = (a[0] == 0 ? 1 : -1) * F, Eb = (E - bias) > 0 ? (E - bias) : (bias - E);
		b = (E - bias) > 0 ? 2 : 0.5;
		for (i = 0; i < Eb; i++)
		{
			x *= b;
		}
		//输出
		printf("%.8lf\n", x);
	}
}
```

### `J` 4258 浮点数进阶

#### 题目分析

完成本题的同学可以说是已经基本认识到了 IEEE 754 标准下的浮点数是个什么样的东西，并且拥有较为强大的编码能力。

对于一个 IEEE 754 标准的浮点数：$se_{k-1}......e_1e_0f_{n-1}......f_1f_0\ \ \ (1+k+n=m; s,e_i, f_j \in \{0, 1\})$，它的值是可以被一个带分数精确表示的。

先把特殊情况放在一边，以 $e_{k-1}......e_1e_0$ 的每一位既不全为 $1$ 也不全为 $0$ 为例来讲，有以下步骤计算它的值：

+ 将二进制数 $e_{k-1}......e_1e_0$ 转换为十进制数 $E$
+ 计算 $x=(-1)^s \times (1.f_{n-1}......f_1f_0)_2 \times 2^{(E-bias)}$

在本周 `I` 题 `简易浮点数` 我们已经联系过计算这样一个东西的近似实数值，那么它的精确值该怎么计算呢？我们需要认识到，和十进制的小数一样，对一个二进制小数乘以一个十进制的 $2$，等价于将小数点向右移动一位；同理除以 $2$ 等价于将小数点向左移动一位，因为 $2$ 是二进制数的位权。

如果我们将向右移动规定为正方向，那么 

$$(1.f_{n-1}......f_1f_0)_2 \times 2^{(E-bias)}$$ 

实际上就是将二进制小数 $ 1.f_{n-1}......f_1f_0 $ 的小数点移动了 $E-bias$ 位。那么很自然的，小数点前的部分就是 $|x|$ 的带分数表示的整数部分，小数点后的部分就是 $|x|$ 的带分数表示的分式部分。

其中，整数部分是很好计算的。但是分式计算看上去要我们实现分式加法，其实不用。对于一个二进制小数 $0.a_{0}a_{1}...a_{m-2}a_{m-1}$，它的十进制值的分式表示实际上就是：

​																						$$\frac{\sum\limits_{i=0}^{m-1} a_i \times 2^{m-1-i}}{2^m}$$

尽管这个分式没有经过约分，但是这么计算显然不需要分式加法，计算完后求个gcd约分即可。

经过以上的讨论，其余的不同情况也可以引刃而解，剩下来的工作就交给同学们编码了。

#### 示例代码

```c
#include<stdio.h>

int main()
{
	char m[20];
	while (~scanf("%s", m)) //循环读入二进制浮点数
	{
		//数组f用来存储二进制小数，开足够的空间来满足小数点的移动
		//dot标记小数点所在的位置，即f[dot]是小数部分的最高位，起始位置为15
		int bias = 15, f[40] = {0}, dot = 15;
		//将各位数字字符转换为数值
		int i;
		for (i = 0; i < 16; i++)
		{
			m[i] -= '0';
		}
		//判断特殊情况
		int flag = 1;
		//判断阶码是否为全1
		for (i = 1; i <= 5; i++)
		{
			if (m[i] == 0)
			{
				flag = 0;
			}
		}
		if (flag) //如果阶码为全1
		{
			flag = 1;
			//判断尾数是否为全1
			for (i = 6; i < 16; i++)
			{
				if (m[i] == 1)
				{
					flag = 0;
				}
			}
			if (flag) //如果是全1，输出正或负无穷
			{
				printf(m[0] == 0 ? "inf\n" : "-inf\n");
			}
			else //否则输出不是一个数
			{
				printf("NaN\n");
			}
			continue; //继续判断下一个数字
		}
		//将尾数移到小数点后
		for (i = 0; i < 10; i++)
		{
			f[dot + i] = m[6 + i];
		}
		//计算E的值
		int E = 0, base = 1;
		for (i = 5; i >= 1; i--)
		{
			E += m[i] * base;
			base *= 2;
		}
		if (E == 0) //E为0说明阶码全为0，小数点应该移动 1-bias 位
		{
			E = 1 - bias;
		}
		else //否则小数点应该移动 E-bias 位，并且小数点前一位应该为1
		{
			E = E - bias;
			f[dot - 1] = 1;
		}
		dot = dot + E; //移动小数点
		i=0;
		int a = 0, b, j; /*变量i用来存储带分数的整数部分，a和b分别存储分子和分母*/
		base = 1;
		//首先计算整数部分
		for (j = dot - 1; j >= 0; j--)
		{
			i += f[j] * base;
			base *= 2;
		}
		//其次计算分母
		j = 39;
		while (f[j] == 0) //找到最后一位非0的小数
		{
			j--;
		}
		b = 1 << (j - dot + 1);
		//最后计算分子
		base = 1;
		while (j >= dot)
		{
			a += f[j--] * base;
			base *= 2;
		}
		//约分a和b
		int x = a, y = b, gcd;
		if(y)
		{
			while((x %= y) && (y %= x));
		}
		gcd = x + y;
		a /= gcd;
		b /= gcd;
		//输出整数部分
		if (i)
		{
			printf(m[0] ? "-%d" : "%d", i);
		}
		//输出分子分母
		if (a)
		{
			if (m[0])
			{
				printf("-%d/%d", a, b);
			}
			else
			{
				printf(i ? "+%d/%d" : "%d/%d", a, b);
			}
		}
		//特殊判断是0的情况
		if (i == 0 && a == 0)
		{
			printf("0");
		}
		//换行
		printf("\n");
	}
	return 0;
}
```
