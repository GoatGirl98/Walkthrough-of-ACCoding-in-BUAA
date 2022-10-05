# R1-Solution

只罗列往届题目

## 题目列表

- A 176 jhljx学字符串
- B 236  字典序排序（简单）
- C 224  Equation（简单）
- D 225 Keyboard(简单)
- E 584 王助教理牌
- F 615 王助教改首字母大写
- G 79 microhhh的雷达
- J 25 质数判断
- K 1030 统计质数
- L 92 jhljx分解质因数
- N 158 区间排序
- O 2759 k关键字排序
- P 2958  二分查找PLUS
- Q 3339 填报高考志愿
- R 3347 蟠桃大会

### `A`  jhljx学字符串

####  题目分析

直接采用`qsort`按照字典序排序即可

注意多组数据判断至`EOF`为结尾

#### 示例代码

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1010
typedef long long ll;
int n, i;
char s[maxn][110];
int cmp(const void* p1, const void* p2) {
    char* a = (char*)p1, * b = (char*)p2;
    int flag = strcmp(a, b);
    if (flag < 0)return -1;
    else if (flag > 0) return 1;
    else return 0;
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; ++i) scanf("%s", s[i]);
        qsort(s, n, sizeof(s[0]), cmp);
        for (i = 0; i < n; ++i) puts(s[i]);
    }
}
```

### `B` 字典序排序（简单）

#### 思路分析

类似A题，对字符串内的字符采用`qsort`排序即可。

#### 示例代码

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1010
typedef long long ll;
int n, i;
char s[maxn];
int cmp(const void* p1, const void* p2) {
    char* a = (char*)p1, * b = (char*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int main() {
    while (scanf("%s", s) != EOF) 
        qsort(s, strlen(s), sizeof(s[0]), cmp), puts(s);
}
```

### `C`  Equation（简单）

####  题目分析

字符串读入并且分类讨论

首先采用`strstr`或者其他函数，查找到`?` `=` `+`的所在位置，值得注意的是，问号不一定存在。

- 如果没有问号，直接按照加号和等号分割字符串，判断加和是否相等，并按要求输出
- 如果有问号，则枚举问号与加号和等号的相对位置（并判断在a+b=c当中的哪一个位置），分别进行计算

#### 示例代码1

```c
#include<stdio.h>
#include<string.h>
typedef long long ll;
char s[30];
int len;//字符串长度
char* pos_que, * pos_plu, * pos_equ;//分别找问号 加号 等号在哪里
int flag;//等式是否正确
//s[l...r]对应的数字是多少
ll get_num(int l, int r) {
	ll ret = 0, f = 1;
	int i = l;
	if (s[i] == '-') f = -1, ++i;
	else if (s[i] == '+') f = 1, ++i;
	for (; i <= r; ++i) ret = (ret << 1) + (ret << 3) + (s[i] ^ 48);
	return ret * f;
}
int main() {
	while (scanf("%s", s) != EOF) {
		len = strlen(s);
		pos_que = strstr(s, "?");
		pos_plu = strstr(s, "+");
		pos_equ = strstr(s, "=");
		if (pos_que != NULL) {
			//计算等式
			if (pos_que > pos_equ) printf("%lld\n", get_num(0, pos_plu - s - 1) + get_num(pos_plu - s + 1, pos_equ - s - 1));
			else if(pos_que > pos_plu) printf("%lld\n", get_num(pos_equ - s + 1, len - 1) - get_num(0, pos_plu - s - 1));
			else printf("%lld\n", get_num(pos_equ - s + 1, len - 1) - get_num(pos_plu - s + 1, pos_equ - s - 1));
		}
		else {
			//检查等式是否正确
			flag = get_num(0, pos_plu - s - 1) + get_num(pos_plu - s + 1, pos_equ - s - 1) == get_num(pos_equ - s + 1, len - 1);
			puts(flag ? "Right!" : "Error!");
		}
	}
}
```

#### 示例代码2
```C
#include <stdio.h>
#include <string.h>
char s[200];
int flag;
int main(void)
{
	while(~scanf("%s",s))
	{
		flag=0;
		int len=strlen(s);
		for(int i=0;i<len;i++)
		if(s[i]=='?')
		{
			flag=1;
			if(s[i+1]=='+')flag=2;
			else if(s[i+1]=='=')flag=3;
			else if(s[i-1]=='=')flag=4;
		}
		if(flag)
		{
			int a,b,c;
			if(flag==2)
			{
				sscanf(s,"?+%d=%d",&b,&c);
				printf("%lld\n",c*1ll-b);
			}
			else if(flag==3)
			{
				sscanf(s,"%d+?=%d",&a,&c);
				printf("%lld\n",c*1ll-a);
			}
			else if(flag==4)
			{
				sscanf(s,"%d+%d=?",&a,&b);
				printf("%lld\n",a*1ll+b);
			}
		}
		else
		{
			int a,b,c;
			sscanf(s,"%d+%d=%d",&a,&b,&c);
			if(a+b==c)
			puts("Right!");
			else
			puts("Error!");
		}
	}
	return 0;

}
```

### `D` Keyboard(简单)

#### 题目分析

较为简单的字符判断+统计问题。需要注意以下两点：

- 输出时统一输出大写（见题目样例）
- 判断的时候不区分大小写
- 输入的一行字符串可能有空格，请考虑用`gets`或者`fgets`完成

#### 示例代码

```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 114514
char s[maxn];
int len;
int occur[27];//是否出现了a到z的字母(部分大小写)
int cnt;//没出现的次数
int i;
int main() {
    while (fgets(s, maxn, stdin)) {
        len = strlen(s);
        while (s[len - 1] == '\n' || s[len - 1] == '\r') s[--len] = '\0';
        memset(occur, 0, sizeof(occur));
        for (i = 0; i < len; ++i) 
            if (isalpha(s[i])) 
                occur[toupper(s[i]) - 'A'] = 1;
        cnt = 0;
        for (i = 0; i < 26; ++i) 
            if (!occur[i]) 
                putchar((char)('A' + i)), putchar(' '), cnt++; 
        if (!cnt)puts("OK!");
        else putchar('\n');
    }
}
```

### `E` 王助教理牌

#### 题目分析

较为麻烦的字符串处理题目。

首先可以分别处理`m` `p` `s` `z` 四种花色

在查找每种花色的时候，需要将对应花色前面所有的有效数字记录进来（从开头或者上一个字母到字母之间的所有数字），查找好所有的数字之后，按照字符排序一题的做法，排序之后输出即可。

#### 示例代码

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//输入的字符串
char s[50];
//按照某种花色搜索到的卡牌, 记录下他们的数字
char card[50];
int cnt;
int cmp(const void* p1, const void* p2) {
    char* a = (char*)p1, * b = (char*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
//传入的s，是以字符串形式传入的卡牌花色 根据这个来找对应卡牌
void print(const char* color) {
    memset(card, 0, sizeof(card));//注意初始化清零
    cnt = 0;
    char* start = s, * pos;//查找起点 需要注意的是同一种花色的卡牌会分散
    while ((pos = strstr(start, color)) != NULL) {
        char* ptr = pos;//备份
        pos--;
        //必须在字符串范围内 而且还是数字 直接往后找就行
        for(; pos - s >= 0 && isdigit(*pos); --pos)
        {
            card[cnt] = *pos;
            cnt++;
        }
        start = ptr + 1;
    }
    if (cnt == 0) return;//这个花色的啥都没找着
    qsort(card, cnt, sizeof(card[0]), cmp);
    printf("%s%s", card, color);
}
int main() {
    while (scanf("%s", s) != EOF) 
        print("m"), print("p"), print("s"), print("z"), putchar('\n');
}
```

### `F` 王助教改首字母大写

#### 题目分析

练字符串（x） 练英语（√）

具体的要求见公告，说白了就是，引号内的内容一律不用管，只需要考虑句号、叹号、问号后面的第一个非空字符，将其变成大写即可。

为了方便处理，我们可以将多行数据读入一行数据当中（采用`getchar`或者`fgets`+`strcat`的组合均可）

然后判断句子分割位置，逐句子处理输出。

#### 示例代码

```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char in[114514];
char out[114514];
char sentence[114514];
int in_len, out_len, sen_len;
int i;
char c;
int main() {
	while ((c = getchar()) != EOF) 
		if (c != '\r') 
			in[in_len++] = c;
	out_len = sen_len = 0;
	for (i = 0; i < in_len; ++i) {
		sentence[sen_len++] = in[i];
		if (in[i] == '.' || in[i] == '?' || in[i] == '!') {
			int sen_index = 0;//从0开始往后找
			while (isspace(sentence[sen_index]))sen_index++;
			if (islower(sentence[sen_index])) 
                sentence[sen_index] = toupper(sentence[sen_index]);
			strcat(out, sentence);
			memset(sentence, 0, sizeof(sentence)), sen_len = 0;
		}
	}
	puts(out);
}
```

### `G` microhhh的雷达

#### 题目分析

较为复杂的字符串处理问题。

A类信号的处理不多说，每8个字符构成一个ASCII码，直接输出即可。

B类信号关键在于，分别找出`jhljx`和`xihang`的位置（注意可能有`jhljxihang`这样的数据，此时应当认定为`xihang`，具体见样例即可），然后找出对应坐标的位置有多少。值得注意的是，就算完整找到2个人名，凑不齐4个坐标，那么依旧只有一个有效的人和坐标的组合。

说白了，雷达出现的人数为出现的人名与坐标个数/2的最小值。

#### 示例代码

```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 114514
//需要寻找和特判的关键串 需要特判这俩合在一块的情况
const char jhljx[8] = "jhljx";
const char xihang[8] = "xihang";
const char jhljxihang[13] = "jhljxihang";
const char head[5] = "0x";
//一个字符是不是十六进制
int is_hex(char a) {
    return isdigit(a) || (a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F');
}
//十六进制字符转数字
int hex_form(char a) {
    if (isdigit(a)) return a - '0';
    else if (isupper(a)) return a - 'A' + 10;
    else return a - 'a' + 10;
}


char type[5];//处理类型是A还是B
char s[maxn];//输入的字符串
int len;
//A型处理的子函数 获取s[l...r]的二进制数对应的十进制数
int bin_num(int l, int r) {
    int ret = 0, i;
    for (i = l; i <= r; ++i)
        ret = (ret << 1) + s[i] - 48;
    return ret;
}
//A型处理
void handle_A() {
    int i;
    for (i = 0; i < len; i += 8) putchar((char)bin_num(i, i + 7));
    putchar('\n');
}

//在知道s[l,l+1]是"0x"时,判断s[l...l+4]是否是B类坐标
int parse_num(int l) {
    return is_hex(s[l + 2]) && is_hex(s[l + 3]) && s[l + 4] == '#';
}
//记录坐标出现的地方
typedef struct num {
    int _index;//从 s[_index] 开始是坐标
    int value;//具体值
}num;
num pack[10];
int cnt;//出现了多少次坐标 本题合法的话只会出现0/2/4次
int indexJ, indexX;//jhljx和xihang在字符串中出现的位置
//B型处理
void handle_B() {
    indexJ = indexX = -1;
    cnt = 0;//坐标个数清零

    char* start = s, *pos = NULL;//查找的起点和找到的位置
    //本题保证只出现一次jhljx 就找最后一次jhljx出现位置就好了
    //因为可能出现jhljx和jhljxihang，所以需要多次查找
    while ((pos = strstr(start, jhljx)) != NULL) {
        //需要确认这个是jhljx而不是xihang
        if(pos > s + len - strlen(jhljxihang) || strncmp(pos, jhljxihang, strlen(jhljxihang)) != 0)
            indexJ = pos - s;
        start = pos + 1;
    }
    start = s, pos = NULL;//清零
    if ((pos = strstr(start, xihang)) != NULL)
        indexX = pos - s;
    start = s, pos = NULL;//清零
    //寻找所有坐标，以"0x"为查找目标 再判断是不是坐标
    while ((pos = strstr(start, head)) != NULL) {
        if (parse_num(pos - s)) {
            pack[cnt]._index = pos - s;
            pack[cnt].value = hex_form(s[pos + 2 - s]) * 16 + hex_form(s[pos + 3 - s]);
            cnt++;
        }
        start = pos + 1;
    }
    int name_cnt = (indexJ >= 0) + (indexX >= 0);//看找出了多少个名字
    int num_cnt = cnt >> 1;//看找到了多少个坐标对(两个坐标为一对)
    int real_cnt = name_cnt < num_cnt ? name_cnt : num_cnt;//两者的较小者才是真正找到的有效信息个数

    if (real_cnt == 0)
        puts("nothing found!");//谁都没找到
    else if (real_cnt == 1) {//找到一个
        printf("%s", indexX >= 0 ? xihang : jhljx);
        printf("(%d,%d)\n", pack[0].value, pack[1].value);
    }
    else {//找到两个
        printf("%s", indexX < indexJ ? xihang : jhljx);//需要按照先后顺序进行输出
        printf("(%d,%d) ", pack[0].value, pack[1].value);//这里注意要有个空格
        printf("%s", indexX > indexJ ? xihang : jhljx);
        printf("(%d,%d)\n", pack[2].value, pack[3].value);
    }
}

int main() {
    while (scanf("%s%s", type, s) != EOF) {
        len = strlen(s);
        if (type[0] == 'A') handle_A();
        else handle_B();
    }
}
```

### `J`  质数判断

####  题目分析

经典的质数判断，直接判断到根号n之前即可。偶数除了2之外可以直接返回不是质数，进一步优化时间。

#### 示例代码

```c
#include<stdio.h>
int t;
int n;
int mark;
int main() {
    while (scanf("%d", &t) != EOF) {
        while (t--) {
            scanf("%d", &n);
            if (!(n % 2)) puts(n == 2 ? "Yes" : "No");     
            else {
                mark = 0;
                if (n == 1) mark = 1;
                for (int k = 3; k * k <= n && !mark; k += 2)
                    if (!(n % k))
                        mark = 1;
                puts(mark ? "No" : "Yes");
            }
        }
    }
}
```

### `K`  统计质数

####  题目分析

本题明确说明，暴力判断无法通过，于是我们可以考虑采用线性算法完成本题。

如果x是质数，那么所有被 $x$ 整除的数必然不是质数（$x>2$），所以可以提前判断他们不是质数。

将所有是质数的记录下来判断即可。

有些同学比较“聪明”，直接特判了1000万以内有多少质数，骗过了最后一个点。期末能骗过去当然就算骗过去了，但还是建议平时练习的事后耗子尾汁（

#### 示例代码

```c
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define maxn 10000010
unsigned n;
unsigned prime[maxn], cnt;
bool vis[maxn];
unsigned out;
unsigned i, j;
//欧拉筛
void get_prime(unsigned n) {
	vis[1] = 1;
	for (i = 2; i <= n; ++i) {
		if (!vis[i])prime[++cnt] = i;
		for (j = 1; j <= cnt && prime[j] * i <= n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
}
int main() {
	scanf("%u", &n);
	get_prime(n);
	printf("%u", cnt);
}
```

### `L`  分解质因数

####  题目分析

直接从小到大判断，并进行质因数分解。

假如说其被 $2$ 整除，则将这个数的所有 $2$ 因子全部提出来，也就是一直除以 $2$ 直到不能被 $2$ 整除为止，再往后判断。

最后需要注意对 $1$ 的特判。

将J和K的做法结合一下，就可以去做烧仙草数这题了

#### 示例代码

```c
#include<stdio.h>
#define maxn 10010
int result[maxn];
int counter;
int main() {
   int n;
    while (scanf("%d", &n) != EOF) {
        if (n > 1) {
            int k = 2;
            counter = 0;
            while (k <= n) {
                if (!(n % k)) {
                    n /= k;
                    result[counter++] = k;
                    continue;
                }
                k++;
            }
            for (int i = 0; i < counter - 1; ++i)printf("%d*", result[i]);
            printf("%d\n", result[counter - 1]);
        }
        else { puts("1"); }
    }
    return 0;
}
```

### `N`  区间排序

####  题目分析

`qsort`对结构体排序的经典题目，根据题目书写判断条件即可。

#### 示例代码

```c
#include<stdio.h>
#include<stdlib.h>
typedef struct section {
    int l, r;
}section;
section a[1010];
int n, i;
int cmp(const void* p1, const void* p2) {
    section* a = (section*)p1, * b = (section*)p2;
    if (a->l < b->l)return -1;
    else if (a->l == b->l && a->r < b->r) return -1;
    else if (a->l == b->l && a->r > b->r) return 1;
    else if (a->l > b->l)return 1;
    else return 0;
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
        qsort(a, n, sizeof(a[0]), cmp);
        for (i = 0; i < n; ++i) printf("%d %d\n", a[i].l, a[i].r);
    }
}
```

### `O`  k关键字排序

####  题目分析

`qsort`对结构体排序的经典题目，在书写判断条件时，通过for循环，逐一对关键字进行判断即可。

#### 示例代码

```c
#include<stdio.h>
#include<stdlib.h>
typedef struct info {
    int key[12];
    int _index;
}info;
info a[1010];
int n, k, i, j;
int cmp(const void* p1, const void* p2) {
    info* x = (info*)p1, * y = (info*)p2;
    int i;
    for (i = 0; i <= k; ++i) {
        if (x->key[i] < y->key[i]) return -1;
        else if (x->key[i] > y->key[i])return 1;
    }
    if (x->_index < y->_index) return -1;
    else if (x->_index > y->_index)return 1;
    else return 0;
}
int main() {
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < k; ++j)
            scanf("%d", &a[i].key[j]);
        a[i]._index = i + 1;
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (i = 0; i < n; ++i) printf("%d ", a[i]._index);
}
```

### `P`  二分查找PLUS

####  题目分析

下界二分查找&上界二分查找的经典问题。

下界二分查找，即题目“惹shy的二分查找”解决的问题，意在找出第一个大于等于某个值的数

上界二分查找，即题目“二荷的二分查找”解决的问题，意在找出第一个严格大于某个值的数（虽然那道题目找的是第一二个小于某个值的数，颠倒一下就可以了）

那么我们只要找到第一个大于等于某值的数 $a[L]$，还有第一个大于某值的数 $a[R]$，两者并非同一个数，即查找的到，输出 $a[L],a[L+1],...,a[R-1]$即可。

本题数据较弱，直接找第一个大于等于某值的数之后往后暴力找也能过。但是不建议这么做。

#### 示例代码

```c
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define maxn 114514
typedef long long ll;
ll rd() {
    ll k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
ll n, q;
ll a[maxn], b;
ll ans;
int cmp(const void* p1, const void* p2) {
    ll* a = (ll*)p1, * b = (ll*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int lower_bound(ll a[], int lo, int hi, ll val) {
    if (val > a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] < val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int upper_bound(ll a[], int lo, int hi, ll val) {
    if (val >= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] <= val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int main() {
    n = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    q = rd();
    while (q--) {
        b = rd();
        int l = lower_bound(a, 1, n, b), r = upper_bound(a, 1, n, b);
        if ((r - l) && a[l] == b) printf("Yes %d %d\n", l, r - l);
        else puts("No");
    }
}
```

### `Q`  填报高考志愿

####  题目分析

下界二分查找的综合问题。

找到了第一个大于等于估分成绩的数之后，那么前一个就是最大的小于估分成绩的数，比较他俩中满意度最小的那个就行了。

注意数据范围，以及第一个大于等于估分成绩的数位最开头的数的边界情况。

#### 示例代码

```c
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define maxn 114514
typedef long long ll;
ll rd() {
    ll k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
ll m, n;
ll a[maxn], b;
ll ans;
int cmp(const void* p1, const void* p2) {
    ll* a = (ll*)p1, * b = (ll*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
int lower_bound(ll a[], int lo, int hi, ll val) {
    if (val > a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] < val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int upper_bound(ll a[], int lo, int hi, ll val) {
    if (val >= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] <= val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int main() {
    m = rd(), n = rd();
    for (int i = 1; i <= m; ++i) a[i] = rd();
    qsort(a + 1, m, sizeof(a[0]), cmp);
    while (n--) {
        b = rd();
        int l = lower_bound(a, 1, m, b);
        if (l > 1)ans += min(llabs(a[l] - b), llabs(a[l - 1] - b));
        else ans += llabs(a[l] - b);
    }
    wr(ans);
}
```

### `R`  蟠桃大会

####  题目分析

贪心+排序的经典问题

- 在桃子足够多的时候，最多可以拿m\*n个桃子；每一种桃子最多只能拿m个
- 在拿的时候，自然是要优先拿走更多数字更大的桃子，所以要采用`qsort`进行排序
- 注意数据范围，虽然结果在`int`范围内，但是每一盘拿走的桃子个数\*编号的数值可能超过`int`表示范围

#### 示例代码

```c
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long ll;
const ll mod = 100007;
ll m, n;
ll ans;
typedef struct info {
    ll num, cnt;
}info;
int cmp(const void* p1, const void* p2) {
    info* x = (info*)p1, * y = (info*)p2;
    if (x->num > y->num) return -1;
    else if (x->num < y->num)return 1;
    else return 0;
}
info a[114514];
int sz, i;
ll remain_cnt;
int main() {
    scanf("%lld%lld", &m, &n);
    while (scanf("%lld%lld", &a[sz].num, &a[sz].cnt) != EOF) ++sz;
    qsort(a, sz, sizeof(a[0]), cmp);
    remain_cnt = m * n;
    for (i = 0; i < sz && remain_cnt; ++i) {
        if (remain_cnt < a[i].cnt && remain_cnt < m) ans += a[i].num * remain_cnt, ans %= mod, remain_cnt = 0;
        else if (a[i].cnt > m) ans += a[i].num * m, ans %= mod, remain_cnt -= m;
        else ans += a[i].num * a[i].cnt, ans %= mod, remain_cnt -= a[i].cnt;
    }
    printf("%lld\n", ans);
}
```

