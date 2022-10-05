# E6-2020级-航类第6次练习

## 题目列表

+ A 4209 cbj绘图
+ B 4349 有点“新意“的签到题？
+ C 4379 解谜小游戏
+ D 4363 合成大西瓜
+ E 4389 旗鼓相当的对手
+ F 4384 简易的人员信息整理
+ G 4288 忍蛙的冠军巅峰
+ H 4394 井 字 棋 带 师
+ I 4315 ssd恰自选
+ J 4332 兔狗贴贴
+ K 4289 小迷弟磕cp
+ L 4253 GCD Plus

## `A` 4209 cbj绘图

### 题目分析

考查转义符,建议用`puts`.如果用`printf`需要转义`%`为`%%`

### 示例代码
```c
#include <stdio.h>
int main(){
	puts("%%%%%%%%%%%%%%%%%%%___%%%%%%%__%%%%%%%%%%%%___%%%%%%%%%%%___%%%%%%%%%%%%%%%%%%%%%%%%%___%%%%%");
	puts("%%%%%%%___%%%%%%%%/%%/\\%%%%%|%%|\\%%%%%%%%%/%%/\\%%%%%%%%%/%%/\\%%%%%%%%%%___%%%%%%%%%%/%%/\\%%%%");
	puts("%%%%%%/__/\\%%%%%%/%%/\"/%%%%%|%%|\"|%%%%%%%/%%/::|%%%%%%%/%%/::\\%%%%%%%%/__/\\%%%%%%%%/%%/:/%%%%");
	puts("%%%%%%\\__\\\"\\%%%%/%%/\"/%%%%%%|%%|\"|%%%%%%/%%/:|:|%%%%%%/%%/:/\\:\\%%%%%%%\\%%\\:\\%%%%%%/%%/:/%%%%%");
	puts("%%___%/%%/\"\"\\%%/%%/\"/%%%%%%%|__|\"|__%%%/%%/:/|:|__%%%/%%/::\\%\\:\\%%%%%%%\\__\\:\\%%%%/%%/::\\%___%");
	puts("%/__/\\%%/\"/\\/%/__/\"/%%%%____/__/\"\"\"\"\\%/__/:/_|::::\\%/__/:/\\:\\_\\:\\%%%%%%/%%/::\\%%/__/:/\\:\\%%/\\");
	puts("%\\%%\\\"\\/\"/~~%%\\%%\\\"\\%%%%\\__\\\"\"\"\"/~~~~%\\__\\/%%/~~/:/%\\__\\/%%\\:\\/:/%%%%%/%%/:/\\:\\%\\__\\/%%\\:\\/:/");
	puts("%%\\%%\\\"\"/%%%%%%\\%%\\\"\\%%%%%%|~~|\"|%%%%%%%%%%%/%%/:/%%%%%%%\\__\\::/%%%%%/%%/:/__\\/%%%%%%\\__\\::/%");
	puts("%%%\\__\\/%%%%%%%%\\%%\\\"\\%%%%%|%%|\"|%%%%%%%%%%/%%/:/%%%%%%%%/%%/:/%%%%%/__/:/%%%%%%%%%%%/%%/:/%%");
	puts("%%%%%%%%%%%%%%%%%\\%%\\\"\\%%%%|__|\"|%%%%%%%%%/__/:/%%%%%%%%/__/:/%%%%%%\\__\\/%%%%%%%%%%%/__/:/%%%");
	puts("%%%%%%%%%%%%%%%%%%\\__\\/%%%%%\\__\\|%%%%%%%%%\\__\\/%%%%%%%%%\\__\\/%%%%%%%%%%%%%%%%%%%%%%%\\__\\/%%%%");
	return 0;
}
```
## `B` 4349 有点“新意“的签到题？

### 题目分析

本题目将排序法和输出字符画结合起来进行考察，数据量保证了$$O(n^2)$$算法的不可行，同时通过限制内存的方式限制了$qsort$快排，又由于数据的最大值已经给定，因此采用桶排序（计数排序）是一个非常好的选择，另请参阅E3 中的`I`题目[计数排序](https://accoding.cn/problem/4284/index)

### 示例代码

```c
#include <stdio.h>
int arr[501]= {0};
void printX(int n) {
    int i,j;
    for(i=0; i<n/2; i++) {
        for(j=0; j<n; j++) {
            if(j==i) {
                putchar('\\');
                continue;
            }
            if(j==n-1-i)  putchar('/');
            else putchar(' ');
        }
        putchar(10);
    }
    if(n&1) {
        for(i=0; i<n/2; i++) putchar(' ');
        printf("x\n");
    }
    for(i=n/2-1; i>=0; i--) {
        for(j=0; j<n; j++) {
            if(j==i) {
                putchar('/');
                continue;
            }
            if(j==n-1-i)  putchar('\\');
            else putchar(' ');
        }
        putchar(10);
    }
}
int main(void) {
    int n,i,j;
    while(~scanf("%d",&n))
        arr[n]++;
    for(i=12; i>=0; i--) {
        for(j=0; j<arr[i]; j++)
            printX(i),putchar(10);
    }
    return 0;
}
```
### 示例代码2

```c
#include<stdio.h>
int arr[501]={0};
void print(int x)
{
    int i,j;
    if(x%2==0)
    {
        for(i=0;i<x/2;i++)
        {
            for(j=0;j<i;j++) printf(" ");
            printf("\\");
            for(j=i+1;j<x/2;j++) printf(" ");
            for(j=i+1;j<x/2;j++) printf(" ");
            printf("/");
            for(j=0;j<i;j++) printf(" ");
            printf("\n");
        }
        for(i=x/2-1;i>=0;i--)
        {
            for(j=0;j<i;j++) printf(" ");
            printf("/");
            for(j=i+1;j<x/2;j++) printf(" ");
            for(j=i+1;j<x/2;j++) printf(" ");
            printf("\\");
            for(j=0;j<i;j++) printf(" ");
            printf("\n");
        }
    }
    else
    {
        for(i=0;i<x/2;i++)
        {
            for(j=0;j<i;j++) printf(" ");
            printf("\\");
            for(j=i+1;j<x/2;j++) printf(" ");
            printf(" ");
            for(j=i+1;j<x/2;j++) printf(" ");
            printf("/");
            for(j=0;j<i;j++) printf(" ");
            printf("\n");
        }
        for(j=0;j<i;j++) printf(" ");
        printf("x\n");
        for(i=x/2-1;i>=0;i--)
        {
            for(j=0;j<i;j++) printf(" ");
            printf("/");
            for(j=i+1;j<x/2;j++) printf(" ");
            printf(" ");
            for(j=i+1;j<x/2;j++) printf(" ");
            printf("\\");
            for(j=0;j<i;j++) printf(" ");
            printf("\n");
        }
    }
}

int main()
{
    int n,i,j;
    while(scanf("%d", &n)!=EOF)
    {
        arr[n]++;
    }
    for(i=500;i>=1;i--)
    {
        for(j=0;j<arr[i];j++)
        {
            print(i);
            printf("\n");
        }
    }
    return 0;
}

```
## `C` 4379 解谜小游戏

### 题目分析
课件原题，参考例9-5
### 示例代码
```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define eps 1e-8
struct data {
	double value;
	int order;
	int rank;
	char str[100];
} list[500005];

int cmp1(const void *p1, const void *p2)
{
	if(fabs(((struct data *)p1)->value-((struct data *)p2)->value)<eps) return 0;
	else if(((struct data *)p1)->value>((struct data *)p2)->value) return 1;
	else return -1;
}

int cmp2(const void *p1, const void *p2)
{
	if(((struct data *)p1)->order==((struct data *)p2)->order) return 0;
	else if(((struct data *)p1)->order>((struct data *)p2)->order) return 1;
	else return -1;
}

int main()
{
	int n=0,i;
	while(scanf("%s",list[n].str)!=EOF)
	{
		list[n].order=n+1;
		list[n].value=atof(list[n].str);
		n++;
	}
	printf("%d\n",n);
	qsort(list,n,sizeof(struct data),cmp1);
	list[0].rank=1;
	for(i=1;i<n;i++)
	{
		if(fabs(list[i].value-list[i-1].value)<eps) list[i].rank=list[i-1].rank;
		else list[i].rank=i+1;
	}
	qsort(list,n,sizeof(struct data),cmp2);
	for(i=0;i<n;i++)
	{
		printf("%d: %s\n",list[i].rank,list[i].str);
	}
	return 0;
}
```

## `D` 4363 合成大西瓜

### 题目分析

本题标准答案是采用数组模拟二进制加法，但由于数据范围较小，对算法并没有太多要求，只要能够按题意进行建模模拟即可

###示例代码

```c
#include<stdio.h>
int main() 
{
	int sum[1020]={0};
	int a,i;
	while(scanf("%d",&a)!=EOF)
	{
		if(sum[a]==0)
			sum[a]=1;
		else
		{
			sum[a]=0;
			for(i=a+1;i<=1019;i++)//进位
			{
				if(sum[i]==1)
					sum[i]=0;
				else
				{
					sum[i]=1;
					break;
				}
			}
		}
		for(i=1019;;i--)
			if(sum[i]==1)
			{
				printf("%d\n",i);//输出最大的水果
				break;
			}
	}
	for(i=1019;i>=0;i--)
		if(sum[i]==1)
			printf("%d ",i);//输出全部水果
	return 0;
}
```

## `E` 4389 旗鼓相当的对手

###题目分析

这道题直接用刚学的结构体知识就可以做了，利用结构体输入所有数据之后先按照字典序对所有人进行排列，可以使用<string.h>中的strcmp函数进行比较，数据量不大，可以使用冒泡/选择排序，当然也可以用qsort

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct MyStruct
{
    char name[10];
    int a, b, c, sum;
}stu[1000],temp;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%s%d%d%d", stu[i].name, &stu[i].a, &stu[i].b, &stu[i].c );
        stu[i].sum = stu[i].a + stu[i].b + stu[i].c;
    }
    for (int i = 0; i < n+1;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            if(strcmp(stu[i].name,stu[j].name)>0)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    for (int i = 0; i < n-1;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            if(abs(stu[i].sum-stu[j].sum)<=10&&abs(stu[i].a-stu[j].a)<=5&&abs(stu[i].b-stu[j].b)<=5&&abs(stu[i].c-stu[j].c)<=5)
            {
                printf("%s %s\n", stu[i].name, stu[j].name);
            }
        }
    }
}
```
以下为qsort做法
```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct MyStruct
{
    char name[10];
    int a, b, c, sum;
}stu[1000],temp;
int cmp(const void *p1,const void *p2)
{
    struct MyStruct *q1 = (struct MyStruct *)p1, *q2 = (struct MyStruct *)p2;
    return strcmp(q1->name, q2->name);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%s%d%d%d", stu[i].name, &stu[i].a, &stu[i].b, &stu[i].c );
        stu[i].sum = stu[i].a + stu[i].b + stu[i].c;
    }
    qsort(stu, n, sizeof(stu[0]), cmp);
    for (int i = 0; i < n-1;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            if(abs(stu[i].sum-stu[j].sum)<=10&&abs(stu[i].a-stu[j].a)<=5&&abs(stu[i].b-stu[j].b)<=5&&abs(stu[i].c-stu[j].c)<=5)
            {
                printf("%s %s\n", stu[i].name, stu[j].name);
            }
        }
    }
}
```

## `F` 4384 简易的人员信息整理

###题目分析

本题主要考查**结构和联合**的应用，还涉及了**输入输出**技巧与易错点。

1.首先本题中结构体需要根据人员类型不同，存储`int`或`字符串`类型数据，此时可以使用**联合**知识点，在同一块内存中存储不同类型数据。

2.本题对于有前导零的数据要求**原样输出**，较为简便的方法是把原数据直接作为`字符串`存储，再使用`sscanf`从字符串中解析相关内容。 

3.本题涉及到对结构体的排序，大家要熟练掌握。

###示例代码

```c
#include<stdio.h>
//为本题量身定做的结构体，用于存储每条人员数据
struct UnivPerson
{
	char name[10];
	char num_char[10]; 
	int num;
	char sex;
	char job;
	union{
		int class0;
		char position[10];
	}category;
};
//适用于结构体排序的cmpfunc函数，学习由结构体指针间接访问元素的运算符->
int cmpfunc (const void * a, const void * b)
{
	struct UnivPerson *p1 = (struct UnivPerson *)a;
	struct UnivPerson *p2 = (struct UnivPerson *)b;
	return (p1->num)-(p2->num);
   //从小到大 小于零不换 
}

int main(){
    struct UnivPerson Person[105];
	int i=0,n;
	char query_job;
	int query_class;
	char query_position[10];
	scanf("%d",&n);
	while(getchar()!='\n');
    for(i=0;i<n;i++){
    	scanf("%s %s %c %c",Person[i].name,Person[i].num_char,&Person[i].sex,&Person[i].job);
		//巧用sscanf函数，从字符串中解析输入
    	sscanf(Person[i].num_char,"%d",&Person[i].num);
    	if(Person[i].job=='S'){
    		scanf("%d",&Person[i].category.class0);
		}
		else{
			scanf("%s",Person[i].category.position);
		}
	}
	while(getchar()!='\n');
	qsort(Person,n,sizeof(Person[0]),cmpfunc);
	scanf("%c",&query_job);
	if(query_job=='S'){
		scanf("%d",&query_class);
		for(i=0;i<n;i++){
			if(Person[i].job=='S'){
				if(Person[i].category.class0==query_class){
					printf("%-8s %-8s %c %c %d\n",Person[i].name,Person[i].num_char,Person[i].sex,Person[i].job,Person[i].category.class0);
				}
			}
		}
	}
	else{
		scanf("%s",query_position);
		for(i=0;i<n;i++){
			if(Person[i].job=='T'){
				if(strcmp(Person[i].category.position,query_position)==0){
					printf("%-8s %-8s %c %c %s\n",Person[i].name,Person[i].num_char,Person[i].sex,Person[i].job,Person[i].category.position);
				}
			}
		}
	} 
	
	return 0;
}

```

## `G` 4288 忍蛙的冠军巅峰

###题目分析

这道题有很多种做法，在后台看到了有各种各样模拟比赛过程的手段。如果是对于比赛过程的简单模拟，采用多次结构体排序与位运算交替进行的方式，可以通过本题。这些方法可以自行尝试，不再多讲。

对k进行数学归纳，可以证明：第k场比赛，如果选取第k个项目，则这场比赛后场上留下的选手，二进制编号从左到右第k位为0；第k场比赛，如果不选取第k个项目，则这场比赛后场上留下的选手，二进制编号从左到右第k位为1。因此，整个比赛的过程，就是场上剩余选手二进制编号从左到右各位逐个确定的过程。

发现这个规律之后，可以写出很短的代码通过本题。这个规律也说明，在这种规则下，使得一位选手成为冠军的方案不唯一，并且二进制编号里只有一个1其余位都是0的选手无法成为冠军，因为没有对应的场次排列。

###示例代码

```C
#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==i)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	printf("\n");
	return 0;
}
```

## `H` 4394 井 字 棋 带 师

### 题目分析
这道题并不复杂，我们要合理安排程序的结构，如果不使用函数可能会使程序显得繁琐，而且也会更容易出错。设计函数时考虑所需的参数，以及需要返回什么，能帮助我们更方便地解决问题，可以参考示例代码。

### 示例代码
```c
#include <stdio.h>

int chess[5][5], temp[5][5];
// isWin函数不仅用来判断是否获胜，而且，若获胜计算出三子连成一线的总数
int isWin(int x[][5], int n);
int evaluate(int n);    // n 代表是'X'方或是'O'方

int main() {
    int i, j, e;
    
    while (scanf("%d%d%d", &chess[0][0], &chess[0][1], &chess[0][2]) != EOF) {
        for (i = 1; i < 3; i++)
            for (j = 0; j < 3; j++)
                scanf("%d", &chess[i][j]);
        if (isWin(chess, 1))
            printf("inf\n");
        else if (isWin(chess, 2))
            printf("-inf\n");
        else {
            e = evaluate(1) - evaluate(2);
            printf("%d\n", e);
        }
        // 记得每组数据后加空行
        printf("\n");
    }
    
    return 0;
}
int isWin(int x[][5], int n) {
    int i, cnt = 0;
    // 三条横线+三条竖线
    for (i = 0; i < 3; i++) {
        if (x[i][0] == n && x[i][1] == n && x[i][2] == n)
            cnt++;
        if (x[0][i] == n && x[1][i] == n && x[2][i] == n)
            cnt++;
    }
    // 两条斜线
    if (x[0][0] == n && x[1][1] == n && x[2][2] == n)
        cnt++;
    if (x[0][2] == n && x[1][1] == n && x[2][0] == n)
        cnt++;
    return cnt;
}
int evaluate(int n) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (chess[i][j])
                temp[i][j] = chess[i][j];
            else
                temp[i][j] = n;
        }
    }
    // 将chess中空位全部用n填充后调用isWin函数
    return isWin(temp, n);
}

```

## `I` 4315 ssd恰自选

###题目解析

本题主要考察使用结构体以及qsort对多个关键字进行排序,首先将菜品按照美味度/饱腹值有限，序号其次的关键字进行升序排序后，按顺序选择食物直到没有再也吃不下当前菜品里面的所有食物。

###示例代码

```c
#include<stdio.h>
#include<stdlib.h>

typedef struct _Dish
{
    unsigned long long Index;
    long long Deli;
    unsigned long long Mass;
    unsigned long long Left;
}Dish;

int Compare(const void* a,const void* b){
    Dish A= *(Dish*)a;
    Dish B= *(Dish*)b;
    long long AC=A.Deli*(long long)B.Mass;
    long long BC=B.Deli*(long long)A.Mass;
    if(BC-AC==0){//int 和 short的积不会超过long long
        return A.Index-B.Index;
    }
    return BC-AC;
    
}

Dish Sec[200000]={};
int main(){

    unsigned long long Storage=0;
    unsigned long long Delicious=0;
    int DataNum=0;
    scanf("%llu",&Storage);
    scanf("%d",&DataNum);
    for (int i = 0; i < DataNum; i++)
    {   
        unsigned long long Index=0;
        long long DishDelicious=0;
        unsigned long long DishLeft=0;
        unsigned long long DishMass=0;
        scanf("%llu %lld %llu %llu",&Index,&DishDelicious,&DishMass,&DishLeft);
        Sec[i].Index=Index;
        Sec[i].Mass=DishMass;
        Sec[i].Deli=DishDelicious;
        Sec[i].Left=DishLeft;
    }

    qsort(Sec,DataNum,sizeof(Dish),Compare);

    for(int i=0;i<DataNum;i++){
        if (Storage>=Sec[i].Mass && Sec[i].Deli>0)
        {
            
            unsigned long long Need=Storage/Sec[i].Mass;
            if(Need>Sec[i].Left){
                Need=Sec[i].Left;
            }
            Storage-=Need*Sec[i].Mass;
            Delicious+=Need*Sec[i].Deli;
            printf("%llu %llu\n",Sec[i].Index,Need);
        }
    }
    printf("%llu",Delicious);
    return 0;
}
```

## `J` 4332 兔狗贴贴
###题目分析

如果熟悉复数计算类型的题目，那么这个题的解法非常简单。

比如：对于复数a+bi，可以定义一个结构体类型，里面封装两个成员：a和b。

本题就是要封装：$$\frac{a+b\sqrt{5}}{2}$$

这种类型的数。在数学上，两个基底为1和根号5（或者二分之一和二分之根号五）对于有理数线性无关（就像1和i对于实数线性无关一样），而在本题的运算中a和b总是有理数（利用奇偶关系与2的幂次分析，甚至可以证明是整数），所以只有a和b均对应相等，两个这种类型的数才会相等。因此，本题中的结构体也符合这样的相等规则。同理，就容易设计加法、乘法规则。这里快速幂已经写好了，直接套用就可以。

本题实际上是要求解斐波那契数列与卢卡斯数列，并且引入了数学上负下标的概念。在这里的定义规则（递推关系不变）下，斐波那契数列的第0项是0，第1项是1，在0附近的数列是-8 5 -3 2 -1 1 0 1 1 2 3 5 8；卢卡斯数列的第0项是2，第1项是1，在0附近的数列是-11 7 -4 3 -1 2 1 3 4 7 11。可知，负下标将斐波那契数列的偶数项取负，将卢卡斯数列的奇数项取负。

当然，你也可以采用对二分之负一加根号五进行快速幂的方式解决负下标问题。

###示例代码

```C
#include<stdio.h>

struct CinderLuca
{
	long long Luca;
	long long Cinder;
};

struct CinderLuca Mult(struct CinderLuca A,struct CinderLuca B)
{
	struct CinderLuca C;
	C.Luca=(A.Luca*B.Luca+5*A.Cinder*B.Cinder)%998244353;
	if(C.Luca%2==0)
	{
		C.Luca=C.Luca/2;
	}
	else
	{
		C.Luca=(C.Luca+998244353)/2;
	}
	C.Cinder=(A.Luca*B.Cinder+A.Cinder*B.Luca)%998244353;
	if(C.Cinder%2==0)
	{
		C.Cinder=C.Cinder/2;
	}
	else
	{
		C.Cinder=(C.Cinder+998244353)/2;
	}
	return C;
}

struct CinderLuca FastPower(struct CinderLuca base,long long exponent)
{
	struct CinderLuca power;
	power.Luca=2;
	power.Cinder=0;
	for(; exponent!=0; exponent>>=1)
	{
		if(exponent&(1==1))
		{
			power=Mult(power,base);
		}
		base=Mult(base,base);
	}
	return power;
}

int main()
{
	long long n;
	scanf("%lld",&n);
	if(n==0)
	{
		printf("2 0\n");
		return 0;
	}
	int flag=0;
	if(n<0)
	{
		flag=1;
		n=-n;
	}
	struct CinderLuca power;
	power.Luca=1;
	power.Cinder=1;
	struct CinderLuca ans=FastPower(power,n);
	if(flag)
	{
		if(n%2==0)
		{
			ans.Cinder=(998244353-ans.Cinder)%998244353;
		}
		else
		{
			ans.Luca=(998244353-ans.Luca)%998244353;
		}
	}
	printf("%lld %lld\n",ans.Luca,ans.Cinder);
}
```

## `K` 4289 小迷弟磕cp

###题目分析

本题考查结构体、快速排序和二分查找 
为了方便操作我们处理一对cp最好的方式是将cp放到一个结构体中。
如果我们用二重循环遍历来暴力查找，查找的期望次数应该是对每一对cp在同样的数组中找与它正好相反的cp，这样我们大概需要n平方左右的次数，这显然效率很低，并且无法处理样例中1 2重复的情况（需要去重）。
这时我们需要对结构体按照第一个数字升序如果第一个数字相同按第二个数字升序排序。这样我们遇到重复的，必然是挨着的就可以continue掉，解决了重复的问题，我们对于一对cp：a,b，在同样的数组中二分查找b,a，这样效率高了很多，最后因为ab找到ba的同时ba也会找到ab，于是我们把答案除以二即为所求。
当然如果你不喜欢结构体的排序和二分，可以把一个结构体转化成一个n进制数~，见方法二。

###示例代码

方法一：

```C
#include <stdio.h>
#include <stdlib.h>
int m, n, t, cnt = 0;
struct CP {
	int a,b;
} cp[33000],tmp;
int cmp(const void *x, const void *y) {
	struct CP *p1 = (struct CP *)x,*p2 = (struct CP *)y;
	if(p1->a > p2->a) return 1;//比较第一关键字 按照升序排列 
	else if(p1->a < p2->a) return -1;
	else if(p1->b > p2->b) return 1;//第一关键字相同 按第二关键字升序排列 
	else if(p1->b < p2->b) return -1;
	return 0;//不然双方一样大 返回0 
}
int main() {
	int i;
	scanf("%d%d%d",&n,&t,&m);
	for(i = 0; i < m; i ++) scanf("%d%d", &cp[i].a, &cp[i].b);//把人们要磕的cp放到结构体里 
	qsort(cp, m, sizeof(cp[0]), cmp);//按照上述比较函数排序 
	for(i = 0; i < m; i ++) {
		if(cp[i].a == cp[i + 1].a && cp[i].b == cp[i + 1].b) continue;//注意有重复 像样例中的1 2只找一次就可以了所以重复的要continue 
		tmp.a = cp[i].b,tmp.b = cp[i].a;//从同样的数组中找它倒过来的 如果找到了就是人们想磕的 
		if(bsearch(&tmp, cp, m, sizeof(cp[0]), cmp) != NULL) cnt++;//结构体也是可以用库函数二分找到的~ 
	}
	printf("%d",cnt>>1);//比如1 2和2 1都有过 1 2找到了2 1   2 1也找到了1 2  所以要对半输出 
	return 0;
}

```
方法二：
注意到每个人的学号在t到t+n-1范围内，于是我们把所有的学号减去t。
新的范围就是[ 0,n-1 ]，我们将每一对cp的第一个数字乘以n（相当于n进制数的十位 思考为什么要选择n）再加上第二个数字，这样不同的cp就被我们彻底区分开了，剩下的仿照上一种方法的思路即可，具体可以看代码。
```C
#include <stdio.h>
#include <stdlib.h>

int m, n, t, cnt = 0;
long long tmpa,tmpb,cp[33000];

int cmp(const void *x, const void *y) {
	long long *xx=(long long *)x,*yy=(long long *)y;
	if(*xx>*yy) return 1;
	else if(*xx<*yy) return -1;
	return 0;
}

int main() {
	int i;
	scanf("%d%d%d",&n,&t,&m);
	for(i = 0; i < m; i ++) {
		scanf("%lld%lld", &tmpa, &tmpb);
		cp[i]=(tmpa-t)*n+(tmpb-t);//将两个学号压成一个n进制数 要先减t
	}
	qsort(cp, m, sizeof(cp[0]), cmp);
	for(i = 0; i < m; i ++) {
		if(cp[i]==cp[i+1]) continue;//重复了不能算
		tmpa=cp[i]/n;tmpb=cp[i]%n;//把原来的第一个数和第二个数取出来
		long long tmp=tmpb*n+tmpa;//原来的个位数和十位数交换
		if(bsearch(&tmp, cp, m, sizeof(cp[0]), cmp) != NULL) cnt++;//如果调过来找到了 说明 存在a b   b a的情况 答案+1
	}
	printf("%d",cnt>>1);//答案减半输出
	return 0;
}
```

## `L` 4253 GCD Plus

###题目分析

本题考察的是高精度的加减法、高精度乘以和除以低精度或者位移的书写。
所谓高精度，就是在普通数据类型无法满足更大整数表示的要求时，采用数组或者字符串进行模拟运算、表示、输入输出的操作。
在学过结构体之后，我们推荐采用`BigInteger`的结构体对高精度进行封装，需要维护表示高精度的数组，以及当前使用的数组长度是多少。

### 普通高精度做法
将数组的每一位表示10进制中的1位，普通地进行运算即可。
```c
#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll radix = 10;
typedef struct BigInteger {
	ll num[1010];
	int size;
}BigInteger;

BigInteger Minus(BigInteger a, BigInteger b) {
	BigInteger c = a;
	int i = 0;
	for (i = 1; i <= c.size; ++i) {
		c.num[i] -= b.num[i];
		if (c.num[i] < 0) {
			c.num[i + 1] -= 1;
			c.num[i] += radix;
		}
	}
	while (!c.num[c.size] && c.size) --c.size;
	return c;
}

BigInteger right_one(BigInteger a) {
	BigInteger c = a;
	int i = 0;
	for (i = c.size; i > 0; --i) {
		c.num[i - 1] += (c.num[i] & 1ll) * radix;
		c.num[i] >>= 1;
	}
	c.num[0] = 0;
	while (!c.num[c.size] && c.size)--c.size;
	return c;
}

BigInteger right(BigInteger a, int b) {
	BigInteger c = a;
	int k = 0;
	for (k = 0; k < b; ++k) {
		int i = 0;
		for (i = c.size; i > 0; --i) {
			c.num[i - 1] += (c.num[i] & 1ll) * radix;
			c.num[i] >>= 1;
		}
		c.num[0] = 0;
	}
	while (!c.num[c.size] && c.size)--c.size;
	return c;
}

BigInteger left(BigInteger a, int b) {
	BigInteger c = a;
	int k = 0;
	for (k = 0; k < b; ++k) {
		int i = 0;
		for (i = 1; i <= c.size; ++i) c.num[i] <<= 1;
		for (i = 1; i <= c.size; ++i) {
			if (c.num[i] >= radix) {
				c.num[i] -= radix;
				c.num[i + 1]++;
			}
		}
		if (c.num[c.size + 1]) c.size++;
	}
	return c;
}

int Bigger(BigInteger a, BigInteger b) {
	if (a.size != b.size)return a.size > b.size;
	int i = 0;
	for (i = a.size; i; --i)
		if (a.num[i] != b.num[i])
			return a.num[i] > b.num[i];
	return 0;
}

BigInteger gcd(BigInteger a, BigInteger b) {
	int r = 0;
	while (!(a.num[1] & 1 || b.num[1] & 1)) {
		a = right(a, 1);
		b = right(b, 1);
		++r;
	}
	while (1) {
		while (!(a.num[1] & 1)) a = right(a, 1);
		while (!(b.num[1] & 1)) b = right(b, 1);
		if (Bigger(a, b)) a = Minus(a, b);
		else b = Minus(b, a);
		if (a.size == 0) return left(b, r);
		if (b.size == 0) return left(a, r);
	}
}

char s[10010];

void read(struct BigInteger* a) {
	scanf("%s", s);
	int len = strlen(s);
	a->size = 0;
	long long wid = 1, cur = 0;
	int i;
	for (i = len - 1; i + 1; --i) {
		cur += (s[i] ^ '0') * wid;
		wid = wid * 10;
		if (wid == radix) {
			wid = 1;
			a->num[++a->size] = cur;
			cur = 0;
		}
	}
	if (cur) a->num[++a->size] = cur;
}

void print(BigInteger* a) {
	printf("%lld", a->num[a->size]);
	int i = 0;
	for (i = a->size - 1; i > 0; --i)//0处不放东西,就算答案是0也没问题
		printf("%lld", a->num[i]);
	putchar('\n');
}

struct BigInteger a, b, res;

int main() {
	read(&a);
	read(&b);
	res = gcd(a, b);
	print(&res);
}
```

### 压位高精度做法

将数组的每一位当做十进制当做的8位，等价于1亿进制的运算。在输出的时候需要注意，最开头的元素正常输出，由于数组1位代表十进制8位，所以后面的数在输出的时候需要按照8位宽度、不足补0的形式输出。
这种做法可以充分利用普通的整型计算的优势，获得更快的运算速度。
```c
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef long long ll;
const ll radix = 100000000;
typedef struct BigInteger {
	ll num[150];
	int size;
}BigInteger;

BigInteger Minus(BigInteger a, BigInteger b) {
	BigInteger c = a;
	int i = 0;
	for (i = 1; i <= c.size; ++i) {
		c.num[i] -= b.num[i];
		if (c.num[i] < 0) {
			c.num[i + 1] -= 1;
			c.num[i] += radix;
		}
	}
	while (!c.num[c.size] && c.size) --c.size;
	return c;
}

BigInteger right_one(BigInteger a) {
	BigInteger c = a;
	int i = 0;
	for (i = c.size; i > 0; --i) {
		c.num[i - 1] += (c.num[i] & 1ll) * radix;
		c.num[i] >>= 1;
	}
	c.num[0] = 0;
	while (!c.num[c.size] && c.size)--c.size;
	return c;
}

BigInteger right(BigInteger a, int b) {
	BigInteger c = a;
	int k = 0;
	for (k = 0; k < b; ++k) {
		int i = 0;
		for (i = c.size; i > 0; --i) {
			c.num[i - 1] += (c.num[i] & 1ll) * radix;
			c.num[i] >>= 1;
		}
		c.num[0] = 0;
	}
	while (!c.num[c.size] && c.size)--c.size;
	return c;
}

BigInteger left(BigInteger a, int b) {
	BigInteger c = a;
	int k = 0;
	for (k = 0; k < b; ++k) {
		int i = 0;
		for (i = 1; i <= c.size; ++i) c.num[i] <<= 1;
		for (i = 1; i <= c.size; ++i) {
			if (c.num[i] >= radix) {
				c.num[i] -= radix;
				c.num[i + 1]++;
			}
		}
		if (c.num[c.size + 1]) c.size++;
	}
	return c;
}

bool Bigger(BigInteger a, BigInteger b) {
	if (a.size != b.size)return a.size > b.size;
	int i = 0;
	for (i = a.size; i; --i)
		if (a.num[i] != b.num[i])
			return a.num[i] > b.num[i];
	return 0;
}

BigInteger gcd(BigInteger a, BigInteger b) {
	int r = 0;
	while (!(a.num[1] & 1 || b.num[1] & 1)) {
		a = right(a, 1);
		b = right(b, 1);
		++r;
	}
	while (1) {
		while (!(a.num[1] & 1)) a = right(a, 1);
		while (!(b.num[1] & 1)) b = right(b, 1);
		if (Bigger(a, b)) a = Minus(a, b);
		else b = Minus(b, a);
		if (a.size == 0) return left(b, r);
		if (b.size == 0) return left(a, r);
	}
}

char s[10010];

void read(struct BigInteger* a) {
	scanf("%s", s);
	int len = strlen(s);
	a->size = 0;
	long long wid = 1, cur = 0;
	int i;
	for (i = len - 1; i + 1; --i) {
		cur += (s[i] ^ '0') * wid;
		wid = wid * 10;
		if (wid == radix) {
			wid = 1;
			a->num[++a->size] = cur;
			cur = 0;
		}
	}
	if (cur) a->num[++a->size] = cur;
}

void print(BigInteger* a) {
	printf("%lld", a->num[a->size]);
	int i = 0;
	for (i = a->size - 1; i > 0; --i)//0处不放东西,就算答案是0也没问题
		printf("%08lld", a->num[i]);
	putchar('\n');
}

struct BigInteger a, b, res;

int main() {
	read(&a);
	read(&b);
	res = gcd(a, b);
	print(&res);
}
```
