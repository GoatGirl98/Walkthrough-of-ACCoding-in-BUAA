# E8-2020级-航类第8次练习

## 题目列表

+ A 4364 字符串库函数测试
+ B 4236 格雷编码
+ C 4276 小迷弟搞偷袭
+ D 4423 李白打酒
+ E 4417 djj的奇怪数列
+ F 4251 补码相反数
+ G 4424 李白打酒2.0
+ H 4390 动态链表操作
+ I 4297 大美丽和大凶残
+ J 4425 蒙达鲁克硫斯伯古比奇巴勒城的名册
+ K 4401 小迷弟的灵光三现
+ L 4422 简单的函数求和

### `A` 4364 字符串库函数测试
本题主要考察字符串库函数的应用。

```C

#include<stdio.h>
#include<string.h>

char input[55];
char instr[55];

char op[55];

void handler()
{
	if(strcmp(instr,"strlen")==0)
	{
		printf("%d\n",strlen(input));
	}
	else if(strcmp(instr,"strstr")==0)
	{
		scanf("%s",op);
		char *loc=strstr(input,op);
		if(loc==NULL)
		{
			printf("NULL\n");
		}
		else
		{
			printf("%d\n",loc-input);
		}
	}
	else if(strcmp(instr,"strcpy")==0)
	{
		scanf("%s",op);
		strcpy(input,op);
	}
	else if(strcmp(instr,"strcat")==0)
	{
		scanf("%s",op);
		strcat(input,op);
	}
}

int InstrCnt;

int main()
{
	scanf("%s",input);
	scanf("%d",&InstrCnt);
	while(InstrCnt--)
	{
		scanf("%s",instr);
		handler();
	}
	printf("%s\n",input);
}

```

### `B` 4236 格雷编码

本题考查位运算 格雷编码的任意两个相邻的代码只有一位二进制数不同,在数字电子技术中有应用
输出时需要提取每一位
```c
#include <stdio.h>
int main(){
	int m,n,i,j,g;
	scanf("%d%d",&m,&n);
	for(j = m;j <= n;j++){
		printf("%d ",j);
		for(i = 7;i >= 0;i--){
			putchar('0' + ((j & (1 << i)) >> i));
		}
		g = j ^ (j >> 1);
		putchar(' ');
		for(i = 7;i >= 0;i--){
			putchar('0' + ((g & (1 << i)) >> i));
		}
		putchar('\n');
	}
	return 0;
}
```

### `C` 4276 小迷弟搞偷袭

#### 题目分析

本题考查快排+二分，首先不排序直接在数组中找答案，大概需要n×m次运算，这样自然是很慢的，于是我们通过n×log(n)次运算的快速排序+m×log(n)次运算的二分查找，可以很快找到答案。

本题的第一个坑点在于排序函数中要用比较两个指针指向值的大小来返回值，而不是直接返回二者之差，因为当二者做差的值超出int范围时，会计算错误导致排序错误。

本题第二个难点在于二分的写法，要求找最大的小于给定值的数，我们不妨找最小的大于等于这个值的数，再返回前一个下标即可，这里为了减少可能的错误，我把太大/太小的数提前判断，剩下的二分过程见代码。

#### 示例代码

```c
#include <stdio.h>
#include <stdlib.h>
int n,a[200100],m,ask;
int cmp(const void* aa,const void* bb) {
	int *a=(int *)aa,*b=(int *)bb;
	if(*a>*b) return 1;
	if(*a<*b) return -1;
	return 0;
}
int bs(int key) {
	int l=0,r=n-1;
	while(l<r) {
		int mid=l+r>>1;
		if(a[mid]<key) l=mid+1;
		else r=mid;
	}
	return l-1;
}
int main() {
	int i;
	scanf("%d %d",&n,&m);
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0; i<m; i++) {
		scanf("%d",&ask);
		if(ask<=a[0]) {
			puts("too weak");
			continue;
		}
		if(ask>a[n-1]) {
			printf("%d\n",a[n-1]);
			continue;
		}
		printf("%d\n",a[bs(ask)]);
	}
	return 0;
}
```

### `D` 4423 李白打酒

#### 题目分析

本题考点是数组和简单模拟，酒壶最多有 $5\times 10^4+1$ 个，因此用数组 $wine[50005]$ 记录每个酒壶的**剩余酒量**，根据每一天的不同情况修改数组对应元素的值即可。本题核心在于找**数组中的最大最小值**，由于题目数据保证 $O(n^2)$ 可以通过，因此直接循环查找即可。

若每次都对酒壶调用 $qsort$ 排序，那么程序总的时间复杂度是 $O(n^2logn)$ ，是会超时的；并且采用循环查找方法时，若每次都循环查找 $5\times 10^4$ 个元素也同样会超时，因此程序中用变量 $havePot$ 来记录**当前一共有多少个酒壶**，初始为 $1$ ，这样**每次查找只需要查找 $havePot$ 次**；需要注意的是，在遇友人时并不需要查找最大最小值，还有其他一些不必要的运算尽量减少，才能保证不 $TLE$ 。

其次还要考虑数据范围，对最后酒的总量作估计，**可能会超过** `int` ，但不超过 `long long` ，因此定义 $haveWine$ 为 `long long` 类型；另外由于数组 $wine$ 是 `int` 类型，则 $2\times wine[index]$ **有可能溢出** `int` ，因此 `if` 语句中写作 $v-wine[index]>wine[index]$ ，保证了数据不会溢出。

本题出错率很高，大多数同学出错在查找最大最小值这一环节上。建议同学们编写代码时条理清晰，清楚每一步的作用，考试时亦是如此，才不容易出错。

#### 示例代码

```c
#include <stdio.h>
#define INT_MAX 0x7FFFFFFF

int wine[50005];
int maxIndex(int n);    // 返回所有酒壶中最大值的下标
int minIndex(int n);    // 返回所有酒壶中最小值的下标


int main() {
    int v, n, i, op, havePot = 1, index;
    scanf("%d%d", &v, &n);
    long long haveWine = v;
    wine[0] = v;    // 初始第一壶酒有 v 斗

    for (i = 1; i <= n; i++) {      // 每一天
        scanf("%d", &op);
        if (op == 3) {      // 遇友人
            haveWine += v;
            wine[havePot++] = v;			// 将数组对应元素置为v，同时酒壶数+1
        } else if (op == 1) {       // 遇店
            index = minIndex(havePot);
            if (index != -1) {      // 表示并非所有酒壶都是空的
                if (v - wine[index] > wine[index]) {    // 最大可加量>剩余量，表示还能加一倍量
                    haveWine += wine[index];
                    wine[index] <<= 1;
                } else {
                    haveWine += v - wine[index];
                    wine[index] = v;
                }
            }
        } else if (op == 2) {       // 遇花
            index = maxIndex(havePot);
            if (index == -1) {      // 表示所有酒壶都是空的
                printf("Day %d: Such beautiful flowers, what a pity!\n", i);
                continue;
            }
            haveWine--;
            wine[index]--;
        }
        printf("Day %d: %lld\n", i, haveWine);
    }
    
    return 0;
}
int maxIndex(int n) {
    int ret = -1, i, max = 0;   // 最大值初始设为0
    for (i = 0; i < n; i++) {
        if (wine[i] > max) {
            max = wine[i];      // 更新最大值
            ret = i;            // 更新返回的下标值
        }
    }
    return ret;
}
int minIndex(int n) {
    int ret = -1, i, min = INT_MAX;   // 最小值初始设为int的最大值
    for (i = 0; i < n; i++) {
        if (wine[i] < min && wine[i] != 0) {     // 找最小值时空壶不纳入
            min = wine[i];
            ret = i;
        }
    }
    return ret;
}
```

### `E` 4417 djj的奇怪数列
#### 题目分析

本题是一个队列的题目，满足先进先出规则；

队列中的初始元素为1，2，3，4，5；每次取出队列的头元素，判断其是否满足被n整除为0，

* 若满足则直接输出；
* 若不满足，根据头元素的尾数以及题目所给的添加数字规则，在队列尾增加相应的数字；

可以发现，这样形成的队列刚好是满足题目要求的数组从小到大的排列。

#### 示例代码

```C
#include <stdio.h>
#include <assert.h>
typedef long long ll;
ll queue[1000005]={1,2,3,4,5};
int n;
int head,tail=5;
int main(void)
{
    scanf("%d",&n);
    while(1)
    {
        if(queue[head]%n==0)
        {
            printf("%lld\n",queue[head]);
            break;
        }
        ll temp=queue[head];
        switch (temp%10)
        {
        case 1:
            queue[tail++]=temp*10+3;
            queue[tail++]=temp*10+5;
            break;
        case 2:
            queue[tail++]=temp*10+3;
            queue[tail++]=temp*10+4;
            break;
        case 3:
            queue[tail++]=temp*10+1;
            queue[tail++]=temp*10+4;
            break;
        case 4:
            queue[tail++]=temp*10+5;
            break;
        case 5:
            queue[tail++]=temp*10+1;
            queue[tail++]=temp*10+2;
            queue[tail++]=temp*10+3;
            queue[tail++]=temp*10+4;
            queue[tail++]=temp*10+5;
            break;
        default:
            break;
        }
        head++;
    }
}
```

### `F` 4251 补码相反数

#### 题目分析

根据HINT所说，对输入的二进制进行手动取反加一即可；注意只有100...000的情况是Overflow，以及注意输入全部是0的情况

#### 示例代码

```c
#include <stdio.h>
#include <string.h>

char s[100005];
int main(void)
{
    int i,len;
    
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);

        for(i=0;i<len;i++)
        s[i]=s[i]=='0'?'1':'0';//取反

        for(i=len-1;i>=0;i--)//加一
        {
            if(s[i]=='1')
            s[i]='0';
            else
            {
                s[i]='1';
                break;
            }
        }

        if(i==0)//如果输入是100...000的情况
        printf("Overflow!!\n");
        else
        printf("%s\n",s);
    }
    return 0;
}
```

### `G` 4424 李白打酒2.0

#### 题目分析

题目数据范围不大，我们可以尝试递归求解。递归函数需要三个参数，分别表示**剩下多少店**，**剩下多少花**，和当前**手中剩余的酒量**，对于每一次奇遇都有两种选择，即**遇店和遇花**，只须递归地调用 $travel$ 函数即可。

当剩余店铺数为 $0$ ，且恰好剩余 $1$ 次花和 $1$ 斗酒时，即为一个符合条件的次序，此时令 $cnt+1$ 后返回；如果在选择过程出了错，即 $dian<0\ ||\ hua\leq 0\ ||\ jiu\leq 0$ 时，直接 $return$ 回到上一层。  

#### 示例代码

```c
#include <stdio.h>

long long cnt;
int n, m, v;
int min(int a, int b) {
    return a < b ? a : b;
}
void travel(int dian, int hua, int jiu) {
    if (dian < 0 || hua <= 0 || jiu <= 0)
        return;
    if (dian == 0 && hua == 1 && jiu == 1) {
        cnt++;
        return;
    }
    
    // 遇到店
    travel(dian - 1, hua, min(2 * jiu, v));
    
    // 遇到花
    travel(dian, hua - 1, jiu - 1);
}

int main() {
    scanf("%d%d%d", &n, &m, &v);
    travel(n, m, v);
    printf("%lld\n", cnt);
    return 0;
}
```

### `H` 4390 动态链表操作

#### 题目分析
本题是基础的动态链表操作。本题比较麻烦的是对于链表转接的操作，那么对于链表尾部的处理就要格外小心。另外一个比较坑的点是对于第一个节点（即索引为0的节点）的处理，此时需要更换头部指针。

#### 示例代码

```c
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ta
{
    char value[105];
    struct ta *next;
} table;

int index;
char optable, s[105];

table *ahead, *aend, *bhead, *bend;

int TrimEnd(char *base);
int readOperation();
void init();
void deleteOne();
void insert();
void move();
void output(table *head, table *end);

int main()
{

    init();
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    optable = 'a';
    for (int i = 0; i < n; i++)
    {
        index = i;
        scanf("%s", s);
        insert();
    }
    optable = 'b';
    for (int i = 0; i < m; i++)
    {
        index = i;
        scanf("%s", s);
        insert();
    }
    for (int i = 0; i < k; i++)
    {
        int op = readOperation();
        switch (op)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteOne();
            break;
        case 3:
            move();
            break;
        case 0:
            goto out;
        }
    }
out:
    output(ahead, aend);
    printf("\n");
    output(bhead, bend);
}

void output(table *head, table *end)
{
    table *p = head;
    int cnt = 0;
    for (; p != end; p = p->next, cnt++)
        printf("%s\n", p->value);
    if (cnt == 0)
        printf("Empty!\n");
}

void init()
{
    // 初始化链表
    ahead = (table *)malloc(sizeof(table));
    aend = ahead;
    ahead->next = NULL;

    bhead = (table *)malloc(sizeof(table));
    bend = bhead;
    bhead->next = NULL;
}

void deleteOne()
{
    table *head, *last;
    optable == 'a' ? (head = ahead) : (head = bhead);
    if (index == 0)
    {
        optable == 'a' ? (ahead = head->next) : (bhead = head->next);
        free(head);
        return;
    }
    while (index--)
        last = head, head = head->next;
    last->next = head->next, free(head);
}

void insert()
{
    table *p = (table *)malloc(sizeof(table)), *head, *last;
    strcpy(p->value, s);
    optable == 'a' ? (head = ahead) : (head = bhead);
    if (index == 0)
    {
        p->next = head;
        optable == 'a' ? (ahead = p) : (bhead = p);
        return;
    }
    while (index--)
        last = head, head = head->next;
    last->next = p, p->next = head;
}

void move()
{
    table *head, *last, *end, *p, *otherhead, *otherend;
    optable == 'a' ? (head = ahead, end = aend) : (head = bhead, end = bend);
    optable == 'a' ? (otherhead = bhead, otherend = bend) : (otherhead = ahead, otherend = aend);
    if (index == 0)
    {
        optable == 'a' ? (ahead = aend) : (bhead = bend);
        p = head;
        while (1)
        { // 换尾
            if (p->next == end)
            {
                p->next = otherend;
                break;
            }
            p = p->next;
        }
        while (otherhead->next != otherend)
            otherhead = otherhead->next;
        otherhead->next = head;
        return;
    }
    while (index--)
        last = head, head = head->next;
    last->next = end;
    p = head;
    while (1)
    { // 换尾
        if (p->next == end)
        {
            p->next = otherend;
            break;
        }
        p = p->next;
    }
    if (otherhead == otherend)
    {
        optable == 'a' ? (bhead = head) : (ahead = head);
        return;
    }
    while (otherhead->next != otherend)
        otherhead = otherhead->next;
    otherhead->next = head;
}

int readOperation()
{
    int op;
    if (~scanf("%d %c %d", &op, &optable, &index))
    {
        if (op == 1)
            scanf("%s", s);
        return op;
    }
    else
        return 0;
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}
```

### `I` 4297 大美丽和大凶残
虽然这道题的题目非常长，但是事实上只需要按照题目给出的指示去做就可以了。

这里有一个巧妙的想法：用0表示无意义，1表示美丽，-1表示凶残。那么代码就长这样：

```C

#include<stdio.h>
#include<math.h>

int mod(int m,int n)
{
	if(n<0)
	{
		n=-n;
	}
	int ans=m%n;
	while(ans<0)
	{
		ans+=n;
	}
	return ans;
}

int fish(int m,int n)
{
	if(m==1||n==1)
	{
		return 1;
	}
	if(m>0&&n==-1)
	{
		return 1;
	}
	if(m<0&&n==-1)
	{
		return -1;
	}
	if(m==-1&&mod(n,4)==1)
	{
		return 1;
	}
	if(m==-1&&mod(n,4)==3)
	{
		return -1;
	}
	if(abs(m)==abs(n))
	{
		return 0;
	}
	if(abs(n)>abs(m))
	{
		if((m>0||n>0)&&(mod(n,4)==1||mod(m,4)==1))
		{
			return fish(n,m);
		}
		else if(m<0&&n<0&&mod(n,4)==3&&mod(m,4)==3)
		{
			return fish(n,m);
		}
		else
		{
			return -fish(n,m);
		}
	}
	else
	{
		int temp=mod(m,n);
		if(mod(temp,2)==0)
		{
			if(temp>0)
			{
				temp-=abs(n);
			}
			else
			{
				temp+=abs(n);
			}
		}
		if(n<0&&((temp>0&&m<0)||(temp<0&&m>0)))
		{
			return -fish(temp,n);
		}
		else
		{
			return fish(temp,n);
		}
	}
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int ans=fish(m,n);
		if(ans==1)
		{
			printf("Great beauty!\n");
		}
		else if(ans==-1)
		{
			printf("Great ferocity!\n");
		}
		else
		{
			printf("Nonsense.\n");
		}
	}
}

```

### `J` 4425 蒙达鲁克硫斯伯古比奇巴勒城的名册

本题主要考察结构体二重指针的使用。如果被排序的数组是`data`，则每次交换时会有1000多个字节被交换，但如果被交换的是结构体指针数组`dataP`，每次交换的数据量将只有8个字节。
在编写排序函数的时候，先将它转化为指向`struct People`的二重指针，再对其解引用为一重指针，再进行比较。

```c
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct People
{
    int age, index;
    char name[1005];
} data[200005], *dataP[200005];

int cmp(const void *a, const void *b)
{
    struct People *p, *q;
    p = *((struct People **)a);
    q = *((struct People **)b);
    if (p->age == q->age)
    {
        return p->index - q->index;
    }
    else
    {
        return p->age - q->age;
    }
}

int main()
{

    int n,m, t,i;
    scanf("%d %d", &n,&m);
    for (i = 0; i < n; ++i)
    {
        scanf("%d %s", &data[i].age, data[i].name);
        dataP[i] = data + i;
        data[i].index = i;
    }

    qsort(dataP, n, sizeof dataP[0], cmp);

    for (i = 0; i < m; ++i)
    {
        scanf("%d",&t);
        t--;
        printf("%d %s\n", dataP[t]->age, dataP[t]->name);
    }
}
```

### `K` 4401 小迷弟的灵光三现

本题是为了模拟期末考试压轴题难度而出，期末考试附加题应该不会考察很偏算法的东西，但是不会提供网站让大家学习，总的难度大致和KL平行。

大 致 了 解 就 好 x

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef long long ll;
struct query {
	ll l,r,id;
}ask[2000100];
struct answer {
	ll x;
} ans[2000100],now;
int n,m,k,l,r,len,id[2000100],c[2000100];
ll cnt[2000100];
//卡常小技巧 奇偶优化 可以了解一手x 
int cmp(const void* xx, const void* yy) {
	struct query* x = (struct query*)xx;
	struct query* y = (struct query*)yy;
	if (id[x->l] == id[y->l]) {
		if ((id[x->l] & 1) == 1){
			if((x->r) < (y->r)) return 1;
			else return -1;
		}
		else {
			if(x->r > y->r) return 1;
			return -1;
		}
	}
	else {
		if(id[x->l] < id[y->l]) return 1;
		else return -1;
	}
}
//两个核心函数 
void add(int x) {
	now.x+=cnt[x^k];
	cnt[x]++;
}
void del(int x) {
	cnt[x]--;
	now.x-=cnt[x^k];
}
int main() {
	scanf("%d %d %d",&n,&m,&k);
	len=sqrt(n);//分块 
	int i;
	for(i=1; i<=n; i++) {
		scanf("%d",&c[i]);
		c[i]=c[i]^c[i-1];//这里求异或前缀和 就把c[l]^...^c[r]的问题转化成了sum[l-1]^sum[r] 
		id[i]=(i-1)/len+1;
	}
	for(i=0; i<m; i++) {
		scanf("%lld %lld",&ask[i].l,&ask[i].r);
		ask[i].l--;
		ask[i].id=i;
	}
	qsort(ask,m,sizeof(ask[0]),cmp);
	for(i=ask[0].l; i<=ask[0].r; i++) add(c[i]);
	ans[ask[0].id].x=now.x;
	l=ask[0].l,r=ask[0].r;
	for(i=1; i<m; i++) {//莫队常规操作add与del 
		while (l>ask[i].l) add(c[--l]);
		while (r<ask[i].r) add(c[++r]);
		while (l<ask[i].l) del(c[l++]);
		while (r>ask[i].r) del(c[r--]);
		ans[ask[i].id].x=now.x;
	}
	for(i=0; i<m; i++) printf("%lld\n",ans[i].x);
	return 0;
}
```

### `L` 4422 简单的函数求和

本题的做法是采用杜教筛在长度巨大的时候，完成积性函数前缀和。

联系到莫比乌斯反演，我们只需要仿照对欧拉函数的求和，先求出 $x^3+3x^2+x$ 的前缀和为 $\frac{n(n+1)(n+1)(n+4)}{4}$ 然后结合费马小定理+逆元的知识即可完成。

本题后来放宽了时限，让唯一一位提交了较慢做法的同学通过了，实际上在性能差距还较远。

```c
#include<stdio.h>
typedef unsigned long long ll;
#define MAXN 2000001
const ll ha = 23333;
const int mod = 1000000007;
const int inv_4 = 250000002;
int g[MAXN],p[MAXN],cut,pri[MAXN],tot,head[MAXN];
ll n,sum[MAXN];
//手写哈希
int hashcode(ll x) {return x % ha;}
struct data{int next;ll x,v;}e[MAXN];
void add(int u,ll v,ll x) {
    e[++cut].v=v;e[cut].x=x;e[cut].next=head[u];head[u]=cut;
}
void build() {
    g[1] = 5;
    for (int i = 2; i < MAXN; i++) {
        g[i] += (i*(1ll * i*i%mod + 3 * i + 1) - g[1]) % mod;
        if (g[i] >= mod)g[i] -= mod;
        for (int j = (i << 1); j < MAXN; j += i) {
            g[j] -= g[i];
            if (g[j] < 0)g[j] += mod;
        }
        g[i] += g[i - 1];
        if (g[i] >= mod)g[i] -= mod;
    }
}
ll solve(ll x) {
    if(x<MAXN) return g[x];
    ll ans=0,k=x%ha,last;
    for(int i=head[k];i;i=e[i].next)
      if(e[i].v==x) return e[i].x;
    for(ll i=2;i<=x;i=last+1) {
        last=x/(x/i);
        ans=(ans+(last-i+1)%mod*solve(x/i)%mod)%mod;
    }
    ans=((x%mod*(x+1)%mod)%mod*((x+1)%mod*(x+4)%mod)%mod*inv_4%mod-ans+mod)%mod;
    add(k,x,ans);
    return ans;
}
void wr(ll x) {
    if (x > 9)wr(x / 10);
    putchar(x % 10 + 48);
}
int main() {
    build();
    while(scanf("%llu", &n) != EOF) wr(solve(n)), putchar('\n');
    return 0;
}
```

