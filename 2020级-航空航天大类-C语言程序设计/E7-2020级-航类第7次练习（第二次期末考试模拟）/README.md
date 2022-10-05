# E7-2020级-航类第7次练习

## 题目列表

+ A 4355 旗开得胜
+ B 4362 切切切
+ C 4412 七巧板入门
+ D 4357 Dec to 2's complement
+ E 4358 二荷的二分查找
+ F 4252 小迷弟的破镜重圆
+ G 4351 JJ照镜子
+ H 4409 名字的奥妙
+ I 4212 找数学
+ J 4344 cbj学数独
+ K 4361 数数入坟

## `A` 4355 旗开得胜

### 示例代码

```c
#include<stdio.h>
int main()
{
printf("   /----\\       /-------\\  /-------\\\n");
printf("  / /|  |       |       |  |       |\n");
printf(" |_/ |  |       |       |  |       |\n");
printf("     |  |       |       |  |       |\n");
printf("     |  |       |       |  |       |\n");
printf("     |  |       |       |  |       |\n");
printf("     |  |       |       |  |       |\n");
printf("/----/  \\----\\  |       |  |       |\n");
printf("\\------------/  \\-------/  \\-------/\n");
return 0;
}

```

## `B` 4362 切切切

### 题目分析

本题是一个简单的数学计算题，可以不需要复杂的算法知识，结合简单的几何计算即可得出结果；
由相似三角形面积与边长的关系可以得到${x_0+a-c \over a}=\sqrt{1\over 2}$，解得$c=x_0+a-\sqrt{{1}\over {2}}\times a$
**ps**:有的同学用二分去做也是可以的，可以，但没必要。

### 示例代码

```C
#include <stdio.h>
#include <math.h>
int x,y,a,b;
int main(void)
{
    scanf("%d%d%d%d",&x,&y,&a,&b);
    double ans=x+a-sqrt(0.5)*a;
    printf("%.5f\n",ans);

    return 0;
}
```

## `C` 4412 七巧板入门

### 题目分析

不难分析，最小的两种正方形是由两个直角三角形或者四个直角三角形拼成的。同时，由于这两个正方形的较大者边长是较小者边长的根号2倍，所以这两种正方形不可以互相混搭拼接，只能在他们各自的基础上组成更大的正方形。

那么答案就显而易见了，只有当三角形的个数为 $2\times x \times x$ 或者 $4\times x \times x$ ($x$ 为正整数)的情况下，才能拼成三角形，其他时候均不可以。

### 示例代码

```c
#include<stdio.h>
#include<math.h>
const double eps = 1e-8;
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n % 2) puts("NO");
		else {
			int len = (int)(sqrt(n / 2) + eps);
			int len2 = (int)(sqrt(n / 4) + eps);
			puts((len * len == n / 2 || (n % 4 == 0 && len2 * len2 == n / 4)) ? "YES" : "NO");
		}
	}
}
```

## `D` 4357 Dec to 2's complement

### 题目分析

本题考察位运算。

由于我们需要输出整数的 $64$ 位二进制补码表示，且整数不会超过 `long long` 的范围，因此需要我们使用 `long  long` 类型来保存输入的整数。接下来我们将这个数据中的每一个 `bit` 提取出来即可，因为 `long long` 本身在计算机中就是以补码形式存储的。

### 示例代码

```c
#include<stdio.h>

void print_bin(long long n, int bits)
{
	if (bits)
	{
		print_bin(n >> 1, bits - 1);
		printf("%lld", n & 1);
	}
}

int main()
{
	long long n;
	while (~scanf("%lld", &n))
	{
		print_bin(n, 64);
		printf("\n");
	}
	return 0;
}
```

## `E` 4358 二荷的二分查找

### 题目分析

和学姐的二分查找非常类似，只不过是找不到的情况特殊处理一下。

`C++`中有专门处理这种情况的函数，`lower_bound`和`upper_bound`，感兴趣的同学可以自行百度了解下。

### 示例代码

```c
#include <stdio.h>
#include <string.h>

int a[1000005];

int findIndex(int *base, int target, int left, int right)
{
    if (base[right] == target || left == right)
        return right;
    int mid = (left + right) / 2;
    if ((left + right) & 1)
        mid++;
    if (base[mid] < target)
        return findIndex(base, target, left, mid - 1);
    else
        return findIndex(base, target, mid, right);
}

int main()
{
    int n, m, tmp;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        int index = findIndex(a, tmp, -1, n);
        printf("%d\n", index + 1);
    }
}

```

## `F` 4252 小迷弟的破镜重圆

### 题目分析

本题需要我们快速计算一个区间 [ L , R ] 内数的和，如果我们每次都从a[L] 加到a[R] 。这样计算自然是很慢的，但如果我们提前计算出a[1]（这里我们假设数组下标从1开始）到a[t] 的和计算出来记为sum[t] 。
当我们需要a[L] 加到a[R] 的值时，我们只需要在之前预处理出的答案数组中找到sum[R]和sum[L-1]，二者做差就可以避免大量重复计算了（因为往往我们对于不同区间的和，都要重复计算很多次这些相加）。
于是我们预处理完毕，每次只需要看sum[i]是否和sum[j]模m同余就好了。

### 示例代码

```c
#include<stdio.h>
int a[50010],fir[50010],las[50010],sum[50010],n,m;
int main() {
	scanf("%d %d",&n,&m);
	int i,j,ans=0;
	for(i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]+a[i])%m;//这里提前取模可以让程序效率++
		if(!sum[i]) ans=i;
	}
	for(i=1; i<=n; i++) {
		for(j=i; j<=n; j++) {
			if(sum[i]==sum[j]) {
				if(j-i>ans) {
					ans=j-i;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
```

但这并不是最快速的做法，因为我们用了两重循环，当n达到题目要求的范围附近时，我们大概需要10000*10000次运算，这自然效率较低。
于是我们可以提前处理出sum数组中不同取模结果最先（这里设为L数组）和最后（这里设为R数组）出现的位置，对于所有模m的结果，我们取R[i] - L[i]的最大就可以了。这样我们就用一重循环就解决了这个问题。

```c
#include<stdio.h>
int a[50010],fir[50010],las[50010],mo[50010],n,m,sum;
int main() {
	scanf("%d %d",&n,&m);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum=(sum+a[i])%m;
		mo[i]=sum;
	}
	for(i=0;i<=n;i++) las[mo[i]]=i;//这里从前向后记录  对于相同的mo[i]，las数组记录的一定是最后出现的
	for(i=n;i>=0;i--) fir[mo[i]]=i;//这里从后向前记录  对于相同的mo[i]，fir数组记录的一定是最先出现的

	int ans=0;
	for(i=0;i<m;i++){//结果中只可能出现0到m-1
		if(las[i]-fir[i]>ans){
			ans=las[i]-fir[i];//保存最大答案
		}
	}
	printf("%d",ans);
	return 0;
}
```

## `G` 4351 JJ照镜子

### 题目分析

本题目相当于再次考察了字符串倒置，前面加入了一些繁杂的判断处理条件希望同学们使用`switch`来进行处理。

### 示例代码

```c
#include <stdio.h>
#include <string.h>
char str[2005];
void handle(char * str) {
	int i,len=strlen(str);
	for(i=0; i<len; i++) {
		switch(str[i]) {
			case '\\':
				str[i]='/';
				break;
			case '/':
				str[i]='\\';
				break;
			case '{':
				str[i]='}';
				break;
			case '}':
				str[i]='{';
				break;
			case '[':
				str[i]=']';
				break;
			case ']':
				str[i]='[';
				break;
			case '(':
				str[i]=')';
				break;
			case ')':
				str[i]='(';
				break;
			case 'p':
				str[i]='q';
				break;
			case 'q':
				str[i]='p';
				break;
			case 'b':
				str[i]='d';
				break;
			case 'd':
				str[i]='b';
				break;
			case '<':
				str[i]='>';
				break;
			case '>':
				str[i]='<';
				break;
		}
	}
}
void printRev(char * str) {
	int i,len=strlen(str);
	for(i=len-1; i>=0; i--)
		putchar(str[i]);
}
int main(void) {
	while(~scanf("%s",str))
	{
		handle(str);
		printRev(str);
		putchar(10);
	}
	return 0;
}
```

## `H` 4409 名字的奥妙

### 题目分析

本题的名字规范与链表有异曲同工之妙，可以使用动态规划的方法进行实现，对每一个输入的数据，在链表中寻找其父节点，若找到了即插入父节点之后，否则插入链表末尾。在完全读取后，链表部分有序，此时对链表进行排序后即可按顺序输出，记得free是良好习惯噢

### 示例代码

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	char SelfName[20];
	char FatherName[20];
	struct Person *Next;
	struct Person *Previous;
};

struct Person *Head = NULL;
struct Person *Tail = NULL;

void RenewTheList()
{
	struct Person *EndPtr = Tail->Previous;
	while (EndPtr->Previous!= NULL)
	{
		if (strcmp(EndPtr->FatherName, EndPtr->Previous->SelfName) != 0)
		{
			struct Person *HeadPtr = Head;
			while (HeadPtr->Next != NULL)
			{
				if (strcmp(EndPtr->FatherName, HeadPtr->SelfName) == 0)
				{
					EndPtr->Next->Previous = EndPtr->Previous;
					EndPtr->Previous->Next = EndPtr->Next;
					if (EndPtr->Next==NULL)
					{
						Tail=EndPtr->Previous;
					}
					EndPtr->Previous = HeadPtr;
					EndPtr->Next = HeadPtr->Next;
					HeadPtr->Next->Previous = EndPtr;
					HeadPtr->Next = EndPtr;
					EndPtr=Tail;
					break;
				}
				HeadPtr = HeadPtr->Next;
			}
		}
		EndPtr = EndPtr->Previous;
	}
	if (Head->Next->Next&&(Head->SelfName,Head->Next->FatherName)!=0)
	{
		struct Person* NewHead=Head;
		struct Person *HeadPtr = Head;
		while (HeadPtr->Next != NULL)
		{
			if (strcmp(Head->FatherName, HeadPtr->SelfName) == 0)
			{
				NewHead=Head->Next;
				Head->Next->Previous = Head->Previous;
				Head->Previous = HeadPtr;
				Head->Next = HeadPtr->Next;
				HeadPtr->Next->Previous = Head;
				HeadPtr->Next = Head;
				break;
			}
			HeadPtr = HeadPtr->Next;
		}
		Head=NewHead;
	}
	return;
}

struct Person *CheckExist(char *FatherName)
{
	if (Head->Next == NULL)
	{
		return NULL;
	}
	struct Person *Ptr = Head;
	while (Ptr != NULL)
	{
		if (strcmp(Ptr->SelfName, FatherName) == 0)
		{
			return Ptr;
		}
		Ptr = Ptr->Next;
	}
	return NULL;
}

int main()
{
	Head = (struct Person *)malloc(sizeof(struct Person));
	Head->Next = NULL;
	Head->Previous = NULL;
	Tail = Head;
	char Self[20] = {};
	char Father[20] = {};
	while (~scanf("%s %s", Self, Father))
	{
		char c;
		while ((c=getchar() )!= '\n'&&c!=-1);
		struct Person *Check = CheckExist(Father);
		if (Check != NULL)
		{
			struct Person *Temp = (struct Person *)malloc(sizeof(struct Person));
			Temp->Next = Check->Next;
			Temp->Previous = Check;
			Check->Next = Temp;
			Temp->Next->Previous = Temp;
			strcpy(Temp->SelfName, Self);
			strcpy(Temp->FatherName, Father);
		}
		else
		{
			struct Person *Temp = (struct Person *)malloc(sizeof(struct Person));
			Temp->Previous = Tail;
			Temp->Next = NULL;
			Tail->Next=Temp;
			strcpy(Tail->SelfName, Self);
			strcpy(Tail->FatherName, Father);
			Tail=Temp;
		}
	}
	RenewTheList();
	struct Person *PrintPtr = Head;
	while (PrintPtr->Next!=NULL)
	{
		printf("%s %s\n",PrintPtr->SelfName,PrintPtr->FatherName);
		PrintPtr=PrintPtr->Next;
		free(PrintPtr->Previous);
		PrintPtr->Previous=NULL;
	}
	return 0;
}
```

## `I` 4212 找数字

### 题目分析

本题是简单字符串的操作，你可以逐个字符处理，也可以利用scanf以及%d来处理；出题人的做法事实上是用到了有限状态机的思想；

从输入中每次读取一个字符，根据字符判断当前的状态并进行相应的操作；

+ 如果当前读到的字符是数字字符，那么先暂时更新当前数 $num$ ，不进行求和；
+ 如果当前读到的字符不是数字字符，那么对数 $num$ 求和并重新置零；
+ 如果当前读到的字符是 `#` ，输出，结束程序；

需要注意几种特殊数据

+ `12cbd#` ，应该输出12
+ `cb0d#` ，应该输出0，而不是 `No numbers`
+ `cbd0#` ，应该输出0，而不是 `No numbers`

### 示例代码1

```C
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

long long sum, num;
int flag;
char ch;
int main(void)
{
    while ((ch = getchar()) != EOF)
    {
        if (ch >= '0' && ch <= '9') //如果当前读到的是数字字符
        {
            flag = 1;                    //记录是否读到过数
            num = num * 10 + (ch - '0'); //更新num
        }
        else //如果不是数字字符
        {
            sum += num; //对num进行求和
            num = 0;
            if (ch == '#') //如果读到结尾
            {
                if (flag) //如果曾经读到过数
                    printf("%lld\n", sum);
                else //否则
                    puts("No numbers");

                return 0;
            }
        }
    }
    return 0;
}
```

### 示例代码2

```C
//This code is contributed by Jingze Zhang
#include<stdio.h>
#include<math.h>

int main()
{
	int sum=0,temp,flag=1;
	char c=0;
	while(c!='#')
	{
		if(scanf("%d",&temp)==0)
		{
			scanf("%c",&c);
		}
		else
		{
			sum+=temp;
			flag=0;
		}
	}
	if(sum==0&&flag) printf("No numbers");
	else printf("%d",sum);
	return 0;
}
```

## `J` 4344 cbj学数独

### 题目分析

思路：枚举、深度优先搜索。从左上角格子开始,逐行的填数，每填一个数需要先检查是否能填（行，列，宫不能有重复数字）填满一行就填下一行，填满81个就输出结果。

### 示例代码

```c
#include<stdio.h>

int mat[9][9] =
{
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0}
};

int check(int x,int y,int num)
{
	int i,j,gx = x / 3,gy = y / 3;
	for(i = 0; i < 9; i++)
	{
		if(mat[x][i] == num && i != y)
		{
			return 0;
		}
	}
	for(i = 0; i < 9; i++)
	{
		if(mat[i][y] == num && i != x)
		{
			return 0;
		}
	}
	for(i = gx * 3; i < gx * 3 + 3; i++)
	{
		for(j = gy * 3; j < gy * 3 + 3; j++)
		{
			if(mat[i][j] == num && (i != x || j != y))
			{
				return 0;
			}
		}
	}
	return 1;
}

void dfs(int x,int y)
{
	int i,j;
	if(x >= 9) //填完整个表了
	{
		for(i = 0; i < 9; i++)
		{
			for(j = 0; j < 9; j++)
			{
				printf("%d ",mat[i][j]);
			}
			putchar('\n');
		}
		return;
	}
	else //x<=8
	{
		if(y >= 9) //填完一行了
		{
			dfs(x + 1,0);
		}
		else
		{
			if(mat[x][y]) //填完当前位置了
			{
				dfs(x,y + 1);
			}
			else
			{
				for(i = 1; i <= 9; i++)
				{
					if(check(x,y,i))
					{
						mat[x][y] = i;
						dfs(x,y + 1);
						mat[x][y] = 0;
					}
				}
			}
		}
	}
}

int main()
{
	int i,j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	dfs(0,0);
	return 0;
}
```

## `K` 4361 数数入坟

### 题目分析

本题是一个数位dp入门题，预计考场上把本题做出来的人数不多于3

### 数位dp+记忆化搜索做法

我们采用二维数组 $dp[pos][status]$ 来记忆化当前的搜索，其中pos表示搜索的数位数，status表示搜索到该数位出现了多少数位上的奇数。

需要注意每一位对应的都有上限 $up$（即输入的数，如果当前位的上一位并非是输入的数，则本位上限可以到9）

那么往下搜索就有 dfs(pos, status, limit) = \sum_{i=0}^{up}dfs(pos - 1, status + i \% 2 == 1, limit \&\& (i == up))

那么我们最一开始要搜索的就是 $dfs(strlen(s) - 1,\ 0,\ 1)$ 往下搜索即可。

### 示例代码1

```c
#include<stdio.h>
#include<string.h>
#define maxn 105
typedef long long ll;
const ll mod = 998244353;
int s[maxn];
//pos sta
ll dp[maxn][maxn];
ll dfs(int pos, int sta, int limit) {
    if (pos == -1) return sta;
    if (!limit && dp[pos][sta] != -1)
        return dp[pos][sta];
    ll ret = 0;
    int up = limit ? s[pos] : 9;//无限制则最高可以冲到9
    for (int i = 0; i <= up; ++i) {
        ret = (ret + dfs(pos - 1, sta + (i & 1), limit && (i == up))) % mod;
    }
    if (!limit) dp[pos][sta] = ret;
    return ret;
}
ll solve(char* x) {
    memset(dp, 0xff, sizeof(dp));
    int len = strlen(x);
    for (int i = 0; i < len; ++i) s[i] = x[len - 1 - i] - 48;
    return dfs(len - 1, 0, 1);
}
char a[maxn];
int main() {
    while (scanf("%s", a) != EOF)
        printf("%lld\n", solve(a));
}
```

### 找数学规律的做法

本方法仅对本题的数位统计又用，并不适用于其他数位dp的问题，故不做展开介绍，直接放代码。

### 示例代码2

```c
#include<stdio.h>
#include<string.h>
#define maxn 105
typedef long long ll;
const ll mod = 998244353;
ll pow10[maxn];
ll dp[maxn];
char a[maxn];
int s[maxn];
ll ans;
ll AmodP(ll a, ll p) {
	while (a < 0) a += p;
	return a % p;
}
void init() {
	pow10[0] = 1;
	int i = 0;
	for (i = 1; i < maxn; ++i) pow10[i] = 10 * pow10[i - 1], pow10[i] %= mod;
	for (i = 1; i < maxn; ++i) dp[i] = (dp[i - 1] * 10) % mod + pow10[i - 1], dp[i] %= mod;
}
ll solve(char* x, int num) {
	ll ret = 0, cnt = 1, tail = 0;
	int len = strlen(x), i = 0;
	for (i = 0; i < len; ++i) s[i] = x[len - 1 - i] - 48;
	for (i = 0; i < len; ++i) {
		int tmp = s[i];
		if (tmp > num) ret += (dp[i] * tmp) % mod + cnt, ret %= mod;
		else if (tmp == num) ret += (dp[i] * tmp) % mod + tail + 1, ret %= mod;
		else ret += (dp[i] * tmp) % mod;
		tail += tmp * cnt, tail %= mod;
		cnt = (cnt * 10) % mod;
	}
	if (!num) {
		ll ans = 1;
		for (i = 0; i < len; ++i) {
			ret = AmodP(ret - ans, mod);
			ans = (ans * 10) % mod;
		}
	}
	return ret;
}
int main() {
	init();
	while (scanf("%s", &a) != EOF) {
		ans = 0;
		ans += solve(a, 1); ans %= mod;
		ans += solve(a, 3); ans %= mod;
		ans += solve(a, 5); ans %= mod;
		ans += solve(a, 7); ans %= mod;
		ans += solve(a, 9); ans %= mod;
		printf("%lld\n", ans);
	}
}
```
