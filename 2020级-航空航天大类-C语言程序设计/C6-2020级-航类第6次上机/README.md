# C6-2020级-航类第六次上机

## 比赛简介
这是 C语言程序设计 的第6次上机，你可能需要以下知识才能较为轻松地完成本次的所有题目：
- 快速排序
- 结构体
- 链表
- 字符串
- 指针
本次上机 8 题，做出 3 题你就非常优秀了。以后要习惯挫折，每次上机不太可能在短时间内做出所有题！

再次重申，题目难度与题目的排布顺序并不完全相关！请根据题目通过率等信息进行难度判断，掌控好自己的做题节奏！

## 题目列表

- A 4391 统计成绩（套娃版）
- B 4392 出人意料的送分
- C 4381 五月加急名单
- D 4388 合成单向链表
- E 4282 吃糖
- F 4386 另类合成
- G 4383 String.ReplaceAll()
- H 4385 合成宝石

### A 4391 统计成绩（套娃版）

本题是求平均分以上同学的平均分。

所以要先求平均分。

在求了平均分之后将平均分再与每一个同学的成绩逐一比较，将大于等于平均分的人的成绩再算一次平均即可。

```c
#include <stdio.h>

int score[1001];

int main() {
    int n, i, sum = 0, sum1 = 0, cnt = 0;
    double ave, ave1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &score[i]);
        sum += score[i];
    }
    ave = 1.0 * sum / n;
    for (i = 0; i < n; i++) {
        if (score[i] >= ave) {
            sum1 += score[i];
            cnt++;
        }
    }
    ave1 = 1.0 * sum1 / cnt;
    printf("%.2lf", ave1);
}
```

### B 4392 出人意料的送分
一道很基础的快排模板题，没有坑点。

```c
#include<stdio.h>
#include<stdlib.h>

int n;
int a[200005];

int cmp(const void *a, const void *b)
{
	int *c=(int*)a;
	int *d=(int*)b;
	if(*c>*d)
	{
		return 1;
	}
	else if(*c<*d)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
	}
	qsort(a+1, n, sizeof(a[1]), cmp);
	for(i=1; i<=n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
```
### C 4381 五月加急名单
本题是一道简单的结构体排序题。

在输入结构体之后根据rush成员的大小进行排序，再输出即可。

```c
#include <stdio.h>

typedef struct list {
    char name[101];
    int age;
    char dst[101];
    int rush;
} list;

list rush_list[51];

int main() {
    int n, p;
    char lj[5];
    scanf("%d", &n);
    gets(lj);
    for (int i = 0; i < n; ++i) {
        gets(rush_list[i].name);
        scanf("%d", &rush_list[i].age);
        gets(lj);
        gets(rush_list[i].dst);
        scanf("%d", &rush_list[i].rush);
        gets(lj);
        if (i != n - 1) {
            gets(lj);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rush_list[j].rush < rush_list[j + 1].rush) {
                list temp;
                temp = rush_list[j];
                rush_list[j] = rush_list[j + 1];
                rush_list[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n", rush_list[i].name);
        printf("%d\n", rush_list[i].age);
        printf("%s\n", rush_list[i].dst);
        printf("%d\n", rush_list[i].rush);
        if (i != n - 1)
            printf("\n");
    }
}
```

### D 4388 合成单向链表

我们在习惯上，会将链表尾结点的 `next` 赋为 `NULL` ，于是找寻链表尾结点即判断那个结点的 `next == NULL`。

在将结点添加到链表尾部的函数中，我们可以利用寻找链表尾结点的函数，将尾结点找到后插入结点。注意维护尾结点的 `next` 为 `NULL`。

**注意处理 `head` 为 `NULL` 的情况。**

#### 部分示例代码

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
};

/*
 * 函数作用:  找到head指向的链表的最后一个节点，并返回指向它的指针
 *
 * 参数说明:
 * head:     指向链表头节点的指针。若链表为空，则head为NULL;
 *
 * 返回值:    指向链表尾节点的指针。若链表为空，则返回NULL.
 */
struct node *find_tail_of_link_list(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        return tail;
    }
}

/*
 * 函数作用:    将数据data存入new_node指向的节点，并将这个节点掺入到head指向的链表的尾部
 *              ，并返回指向链表头节点的指针
 *
 * 参数说明:
 * head:        指向链表头节点的指针。若链表为空，则head为NULL;
 * new_node:    指向创建好的新节点的指针;
 * data:        新节点中应该存储的数据.
 *
 * 返回值:       指向链表头节点的指针.
 */
struct node *add_node_to_link_list(struct node *head, struct node *new_node, int data)
{
    new_node->data = data;
    new_node->next = NULL;
    struct node *tail = find_tail_of_link_list(head);
    if (tail == NULL)
    {
        return new_node;
    }
    else
    {
        tail->next = new_node;
        return head;
    }
}

char buffer[64];

void output(struct node *head, struct node *tail)
{
    if (head == NULL)
    {
        printf("The link list is empty.\n");
        return;
    }
    struct node *n = head;
    putchar('\n');
    while (1)
    {
        sprintf(buffer, "%d", n->data);
        int len = (int) strlen(buffer);
        putchar('+');
        for (int i = 0; i < len; i++)
        {
            putchar('-');
        }
        printf(n == tail ? "+-+\n|%d|\\|" : "+----+\n|%d|next|", n->data);
        if (n == head)
        {
            printf(" <----head");
        }
        if (n == tail)
        {
            printf(" <----tail");
        }
        printf("\n+");
        for (int i = 0; i < len; i++)
        {
            putchar('-');
        }
        printf(n == tail ? "+-+\n " : "+-|--+\n ");
        if (n != tail)
        {
            for (int i = 0; i < len + 2; i++)
            {
                putchar('_');
            }
            printf("|\n |\n V\n");
        }
        if (n->next == NULL)
        {
            break;
        }
        n = n->next;
    }
    putchar('\n');
}

int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = NULL, *tail;
    while (n--)
    {
        int data;
        scanf("%d", &data);
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        head = add_node_to_link_list(head, new_node, data);
    }
    tail = find_tail_of_link_list(head);
    output(head, tail);
    return 0;
}

```


### E 4282 吃糖

我们规定从左往右是第$1、2、3……n$堆，用数组$a_i$记录第$i$堆糖的数量，用变量$Ans$记录所需要吃的糖果数。

对于第$1、2$堆糖：如果它们之和小于等于$m$，那我们就不用管，继续看第$2、3$堆糖；如果大于$m$，设$a_1+a_2$比$m$多$x$，那么我们将$Ans$加$x$，如果$x$比$a_2$小，我们把第二堆的糖果吃掉$x$个，如果$x$比$a_2$大，那就把第二堆吃完，把第一堆的糖果吃到$m$个，之后处理第$2、3$堆糖。

对于第$2、3$堆糖，如果它们之和小于等于$m$，我们同样不用处理，继续看第$3、4$堆糖；如果大于$m$，设$a_2+a_3$比$m$多$x$，那么我们将$Ans$加$x$，把第二堆糖吃掉$x$个，然后处理第$3、4$堆糖。（不可能会有$x>a_2$的情况发生，想一想为什么）

对于之后的相邻两堆都重复对第$2、3$堆的操作即可，最后的$Ans$就是最少的糖果数。

正确性可以用数学归纳法证明，这里不赘述辽。

#### 示例代码
```c
#include<stdio.h>

int n, m, Ans;
int a[100005];

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
	}
	if(a[1]+a[2] > m)
	{
		Ans += a[1]+a[2]-m;
		if(a[1]+a[2]-m > a[2])
		{
			a[2] = 0;
			a[1] = m;
		}
		else
		{
			a[2] = m-a[1];
		}
	}
	for(i=2; i<n; ++i)
	{
		if(a[i]+a[i+1] <= m)
		{
			continue;
		}
		Ans += a[i]+a[i+1]-m;
		a[i+1] = m-a[i];
	}
	printf("%d", Ans);
	return 0;
}
```
### F 4386 另类合成

#### 题目分析

本题是字符串+指针的考察；将字符串new覆盖字符串old可以使用strcpy函数，该函数会将一个字符串复制到，也可以理解为覆盖到一个字符数组，并在最后添加空字符，用法如下

```C
strcpy(old,new);
```

如果想要在old的指定位置开始进行覆盖的话，改变strcpy函数中的第一个参数的地址即可，例

```C
strcpy(old+1,new);//从old[1]开始，用字符串new进行覆盖，并在末尾添加空字符
```

因此，对于本题我们的写法就可以写成如下

#### 示例代码

```c
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX_strLEN 10000
#define MAX_allLEN 100000
char old[1000000],new[100000];
int point;
int main(void)
{

    scanf("%s",old);

    while(scanf("%s",new)!=EOF)
    {
        scanf("%d",&point);
        strcpy(old+point,new);
    }
    puts(old);

    return 0;
}
```


### G 4383 String.ReplaceAll()

#### 题目分析

本题考查指针和`strstr`库函数的使用。推荐新建一个数组，存放新的字符串。遇到子串就放进新的字符串就OK了。

实际上，本题根本无需替换原字符串，遇到要替换的字符串直接输出就OK了。

#### 示例代码

```c
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 此函数用来去除字符串结尾的\r
int TrimEndR(char *base)
{
	while (base[strlen(base) - 1] == '\r')
	{
		base[strlen(base) - 1] = '\0';
	}
	return strlen(base);
}

char str[3015], old[30], news[30], newstr[3015];
char laji[5];

int main()
{
	int n;
	scanf("%d", &n), gets(laji); // scanf之后记得gets
	for (int i = 0; i < n; i++)
	{
		gets(str), gets(old), gets(news);
		TrimEndR(str), TrimEndR(old), TrimEndR(news);
		int strL = strlen(str), oldL = strlen(old), newL = strlen(news), cnt = 0;
		for (char *p = str; p < str + strL; p += oldL) // 每次找到旧串后将p跳过旧串的长度。
		{
			char *n = strstr(p, old);
			if (n == NULL)
			{
				for (; p < str + strL; p++, cnt++)
				{
					newstr[cnt] = *p;
				}
				break;
			}
			for (; p < n; p++, cnt++)
			{
				newstr[cnt] = *p;
			}
			for (int i = 0; i < newL; i++, cnt++)
			{
				newstr[cnt] = news[i];
			}
		}
		newstr[cnt] = '\0';
		puts(newstr);
	}
}
```
### H 4385 合成宝石

#### 题目分析
这道题可以看成是一道简单的“高精度算法”，可以将1级到9级宝石分别看成这个三进制九位数的个位、十位、百位...
进位过程就是:高位+=低位/3
判断依据就是：将数字从个位进到第$q$位，第$q$位是0就说明合成不了，非0就说明可以合成。

#### 示例代码
```c
#include<stdio.h>

int bag[2][10]= {0};

int main()
{
	int n,m;
	int a,b;
	int p,q;
	int c=0,i;
	scanf("%d %d",&n,&m);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		bag[a][b]++;
	}
	while(m--)
	{
		scanf("%d %d",&p,&q);
		c=0;
		for(i=1; i<=q; ++i)
		{
			c/=3;
			c+=bag[p][i];
		}
		if(c)
		{
			printf("%%\n");
		}
		else
		{
			printf("\"\'\n");
		}
	}
}
```

