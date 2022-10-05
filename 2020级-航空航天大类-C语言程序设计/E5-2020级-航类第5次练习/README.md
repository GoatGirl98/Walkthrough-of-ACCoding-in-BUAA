# E5-2020级-航类第5次练习

## 题目列表

- A 4295 有些奇怪的字符画
- B 4318 逆序输出字符串
- C 4206 女神的考验
- D 4229 NBSI码
- E 4222 ssd的变量命名
- F 4348 给朵朵打电话
- G 4241 小迷弟的碎碎念
- H 4338 简易的程序查重
- I 4271 不可思议的展开
- J 4329 找出上机大佬
- K 4261 晶钻与明珠
- L 4238 小迷弟帮室友追女神

### `A`  4295 有些奇怪的字符画

#### 示例代码

```c
#include <stdio.h>
int main(){
printf("\
#include <stdio.h>\n\
int main()\n\
{\n\
    printf(\n\
        \"                      _ooOoo_\\n\"\n\
        \"                     o8888888o\\n\"\n\
        \"                     88\\\" . \\\"88\\n\"\n\
        \"                     (| -_- |)\\n\"\n\
        \"                      O\\\\ = /O\\n\"\n\
        \"                  ____/\\\'---\\\'\\\\____\\n\"\n\
        \"                   .\\\' \\\\\\\\| |// \\\'.\\n\"\n\
        \"                 / \\\\\\\\||| : |||// \\\\\\n\"\n\
        \"               / _||||| -:- |||||- \\\\\\n\"\n\
        \"                 | | \\\\\\\\\\\\ - /// | |\\n\"\n\
        \"                | \\\\_| \\\'\\\'\\\\---/\\\'\\\' |_/\\n\"\n\
        \"                \\\\ .-\\\\__ `-` ___/-. /\\n\"\n\
        \"              ___`. .\\\' /--.--\\\\ `. . __\\n\"\n\
        \"           .\\\"\\\" \\\'< `.___\\\\_<|>_/___.\\\' >\\\'\\\"\\\".\\n\"\n\
        \"         | | : `- \\\\`.;`\\\\ _ /`;.`/ - ` : | |\\n\"\n\
        \"           \\\\ \\\\ `-. \\\\_ __\\\\ /__ _/ .-` / /\\n\"\n\
        \"   ======`-.____`-.___\\\\_____/___.-`____.-\\\'======\\n\"\n\
        \"                      `=---=\\\'\\n\");\n\
    return 0;\n\
}\n");
	return 0;
}
```


### `B`  4318 逆序输出字符串

#### 考查内容

二维数组 gets/fgets函数读取一行字符串

#### 示例代码
```c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

char buffer[100][1020] = {0};

void reverse(char *str)
{
	int n = strlen(str);
	char tmp;
	int lb = 0,ub = n - 1;
	while(lb < ub)
	{
		tmp = str[lb];
		str[lb] = str[ub];
		str[ub] = tmp;
		lb++;
		ub--;
	}
}

int main()
{
	int cur = 0;
	while(gets(buffer[cur]))
	{
		reverse(buffer[cur]);
		cur++;
	}
	while(cur--)
	{
		puts(buffer[cur]);
	}
	return 0;
}
```


### `C` 4206 女神的考验

#### 题目分析

数据点不含空格，可以直接使用scanf+%s进行输入

对每一个输入的字符串从最左位开始判断

开头只能是字母（isalpha）或者_

其余只能是字母或数字（isalnum）或下划线

```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int cnt=0,n,i,len;
	char a[40],b[110][40];
	while(~scanf("%s",a))
	{
		len=strlen(a);
		if(isalpha(a[0])||a[0]=='_')//判断首位是否符合 
		{
			for(i=1;i<len;i++)
			{
				if(!(isalnum(a[i])||a[i]=='_'))//判断其余是否符合 
					break;
			}
			if(i==len)
			{
				cnt++;
				strcpy(b[cnt],a);
			}
		}
	}
	for(i=1;i<=cnt;i++)
		puts(b[i]);
	printf("%d",cnt);
	return 0;
}
```


### `D`  4229 NBSI码

#### 题目解析

按照题意，将每一位数字分别乘上1、2、3……9，求和后将结果%11，然后判断识别码和它是否相同即可。

本题没有特别的坑点，只需要注意将char型的数字转换成int型的数字。

#### 示例代码

```c
#include<stdio.h>
#include<string.h>

int res, len;
char s[15];

int main(){
 int ord=1, i;
 
 scanf("%s", s);
 
 len = strlen(s);
 for(i=0; i<len-1; ++i)
     if(s[i] != '-'){
      res += (s[i]-'0')*ord;
      ord ++;
     }
 res %= 11;
 if((s[len-1]!='X'&&res==s[len-1]-'0') || (s[len-1]=='X'&&res==10))
     printf("Right");
 else{
  for(i=0; i<len-1; ++i)
      printf("%c", s[i]);
  if(res == 10)
   printf("X");
  else    printf("%d", res);
 }
    return 0;
}
```

### `E`  4222 ssd的变量命名

#### 题目解析

本题主要考察对字符串的过滤处理即对字符串中的部分信息的提取处理，顺便复习一下变量命名的的知识。本题可以采用截取-修改-储存的方式完成，也可以使用屏蔽掉无效字符并在原字符串上修改输出的方法做。示例代码给出后者

#### 示例代码

```c
#include<stdio.h>
int main(){
    int DataNum=0;
    scanf("%d",&DataNum);
    for(int d=0;d<DataNum;d++){
        char VariableName[10005]={};
        scanf("%s",VariableName);
        int Index=0;
        if(VariableName[1]=='_'){//匈牙利命名法
            VariableName[1]='\n';
            VariableName[0]='\n';
            Index=2;
        }
        if(VariableName[Index]>='a'&&VariableName[Index]<='z'){//驼峰命名法
            VariableName[Index]+='A'-'a';
            Index++;
        }
        while (VariableName[Index])//下划线命名法或帕斯卡命名法
        {
            if(VariableName[Index]=='_'){
                VariableName[Index]='\n';
                if(VariableName[Index+1]>='a'&&VariableName[Index+1]<='z'){
                    VariableName[Index+1]+='A'-'a';
                }
            }
            Index++;
        }
        Index=0;
        while (VariableName[Index])
        {
            if(VariableName[Index]!='\n'){
                putchar(VariableName[Index]);
            }
            Index++;
        }
        putchar('\n');
    }
    return 0;
}
```


### `F`  4348 给朵朵打电话

#### 题目分析

按题给HINT，可以先顺时针输出自然数，再把对应的数字换成字符串中的字符

```
0    1    2    3    4    5    
19   20   21   22   23   6    
18   31   32   33   24   7    
17   30   35   34   25   8    
16   29   28   27   26   9    
15   14   13   12   11   10   
```

首先观察以上把自然数螺旋输出的$6\times 6$的矩阵，可以发现数字$0\sim19$是最外层，数字$20\sim31$是第二层，数字$32\sim35$是第三层，每一层都是自然数从左到右、从上到下、从右到左，从下到上地依次递增。

因此对于输入的`n`，可以判断出一共有$(n+1)/2$层，用控制变量`i`来循环遍历每一层，对于每一层，又可以拆分成四个循环，引入控制变量`j`，将该层四条边上各元素的值保存好。

以下先写出顺时针输出自然数的代码

```c
#include <stdio.h>

int main() {
    int a[20][20] = {0};
    int n, i, j, k = 0;
    
    scanf("%d", &n);
    // 一共有 (n + 1) / 2 层
    for (i = 0; i < (n + 1) / 2; i++) {
      	// 从左到右遍历
        for(j = i; j < n - i; j++)
            a[i][j] = k++; // 赋值后k的值加一
      	// 从上到下遍历
        for(j = i + 1; j < n - i; j++)
            a[j][n-i-1] = k++;
      	// 从右到左遍历
        for(j = n - i - 2; j > i - 1; j--)
            a[n-i-1][j] = k++;
      	// 从下到上遍历
        for(j = n - i - 2; j > i; j--)
            a[j][i] = k++;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%-5d", a[i][j]);
        printf("\n");
    }
    
    return 0;
}
```

接着只需要定义题目所给字符串（注意转义字符），然后将程序中的`k`变成字符串的下标即可

#### 示例代码

```c
#include <stdio.h>
// 获取数组元素个数，由于字符串中末尾有'\0'，因此计算字符个数时应-1
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))

int main() {
    char a[20][20] = {0}, str[] = "\\duoduo!/";
    int n, i, j, k = 0, num = ArrayNum(str) - 1;
    
    scanf("%d", &n);
    for (i = 0; i < (n + 1) / 2; i++) {
        for(j = i; j < n - i; j++) {
            a[i][j] = str[k];
            k = (k + 1) % num;
        }
        for(j = i + 1; j < n - i; j++) {
            a[j][n-i-1] = str[k];
            k = (k + 1) % num;
        }
        for(j = n - i - 2; j > i - 1; j--) {
            a[n-i-1][j] = str[k];
            k = (k + 1) % num;
        }
        for(j = n - i - 2; j > i; j--) {
            a[j][i] = str[k];
            k = (k + 1) % num;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
    
    return 0;
}
```

### `G`  4241 小迷弟的碎碎念

#### 示例代码

```c
#include <stdio.h>
int n;
char str[12];
//其实两个参数就可以 这里为了表达意思更明确设了第三个参数 
//step表示我们递归到了第几层 now是我们要输出的字符串数组 len是我们现在字符串的长度 
void dfs(int step,char now[],int len) {
	if(!step) {//已经填满了 
		puts(now);//输出即可 
		return;
	}
	now[len]='l';//将新的一位设为'l' 
	dfs(step-1,now,len+1);//向下递归 步数少1 长度多1 
	now[len]='n';//同理 
	dfs(step-1,now,len+1);
	now[len]='x';//同理 
	dfs(step-1,now,len+1);
}
int main() {
	scanf("%d",&n);
	int i,now=1;
	for(i=1; i<=n; i++) now=(now<<1)+now;//每位有3种选择 所以乘3 
	printf("%d\n",now);
	dfs(n,str,0);
	return 0;
}
```



### `H`  4338 简易的程序查重
#### 题目分析
本题主要考查**字符串**的基础知识，包含以下知识点：  
字符串数组（二维数组） 
字符串复制（复制指定位数后补充`\0`）  
字符串匹配

#### 示例代码

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//s1 s2存放读入的两段程序 去掉空白字符后的总字符串
//stemp暂存某一行
char s1[1000],s2[1000],stemp[105]; 
int s1pos=0,s2pos=0;
int n1,n2,m; 

int do_str(char *s,int spos)
{
	char* pos=NULL;
	char* t=stemp;
	gets(stemp);
	pos=strstr(stemp,"//");//寻找注释字符的位置，并在该位置标结束符号。相当于截断字符串 去掉了注释
	if(pos!=NULL){
		*pos='\0';
	}
	//去掉空白字符 将非空白字符读入 空白字符跳过
	while(*t!='\0'){
		if(*t!=' '&&*t!='\n'&&*t!='\r'&&*t!='\t'){
			s[spos]=*t;
			spos++;
		}
		t++;
	}
	return spos;   
}


int main(){
	int i,sumk=0;
	char *t;
	scanf("%d%d%d",&n1,&n2,&m);
	while(getchar()!='\n');//去掉行尾空白字符 很重要
	for(i=0;i<n1;i++){
		s1pos=do_str(s1,s1pos);
	}
	s1[s1pos]='\0';
	for(i=0;i<n2;i++){
		s2pos=do_str(s2,s2pos);
	}
	s2[s2pos]='\0';
	for(i=0;i<=s1pos-m;i++){
		strncpy(stemp,s1+i,m);//复制指定长度字符串
		stemp[m]='\0';//补\0，否则后续程序找不到字符串结尾
		t=strstr(s2,stemp);//按长度匹配
		if(t!=NULL){//若匹配成功则计数
			sumk++;
		}
	}
	printf("%d",sumk);
	return 0;
}
```



### `I`  4271 不可思议的展开

这个题只需要找到规律就行了，找到规律之后，就是一个简单的二维递推练习。

```C
#include<stdio.h>

long long A[500][500];

void init()
{
	A[0][0]=1;
	int i;
	for(i=1;i<490;i++)
	{
		if(i%2==1)//奇数从左下往右上填
		{
			A[i][0]=0;
			int j;
			for(j=1;j<=i;j++)
			{
				A[i-j][j]=(A[i-j][j-1]+A[i-j+1][j-1])%998244353;
			}
		}
		else//偶数从右上往左下填
		{
			A[0][i]=0;
			int j;
			for(j=1;j<=i;j++)
			{
				A[j][i-j]=(A[j-1][i-j]+A[j-1][i-j+1])%998244353;
			}
		}
	}
}

int main()
{
	init();
	int m,n;
	scanf("%d%d",&m,&n);
	int i;
	for(i=0;i<m;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			printf("%lld",A[i][j]);
			if(j!=n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
```

### `J`  4329 找出上机大佬

#### 题目分析

本题有很多很多种方法。题解里使用计数排序，效率较冒泡排序高很多。

#### 示例代码 计数排序

```c
#include <stdio.h>
#include <string.h>

char scores[100005][505];
char tempName[505];
char laji[5];

int main()
{
    int n, m, cnt = 0, i, max = 0;
    double tmp;
    scanf("%d%d", &n, &m);
    gets(laji);
    while (n--)
    {
        gets(tempName);
        scanf("%lf", &tmp);
        gets(laji);
        int index = (int)(tmp * 100 + 1e-9);
        strcpy(scores[index], tempName);
        if (max < index) max = index;
    }
    for (i = max; cnt < m && i >= 0; i--)
    {
        if (scores[i][0] != 0)
        {
            puts(scores[i]);
            cnt++;
        }
    }
}
```

还提供了使用冒泡排序的方法：

#### 示例代码 冒泡排序

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char laji[5];
char str[10005][505];
double score[10005];

int main()
{
    int n, m, i, flag;
    double tmp;
    char temp[5005];
    scanf("%d%d", &n, &m);
    gets(laji);
    for (i = 0; i < n; i++)
    {
        gets(str[i]);
        scanf("%lf", &score[i]);
        gets(laji);
    }
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (score[j] < score[j + 1])
            {
                tmp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = tmp;
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
                flag = 1;
            }
        }
        if (0 == flag)
            break;
    }
    for (i = 0; i < m; i++)
    {
        puts(str[i]);
    }
}
```

### `K`  4261 晶钻与明珠

这个题用了不太容易的想法。算法的前半段（贪心算法）已经写在题中了，但是后半段需要自己思考。

见[相关提问](https://gitee.com/duchenhong/programming_routine_2021c/issues/I3I8Y9)

题中给出的的算法是，只要有晶钻就买晶钻，没有晶钻就买明珠，什么都没有就把明珠换成晶钻。同时也指出了这个原始算法的问题：按照这个算法，最后有可能会剩下明珠。

既然如此，不妨定量分析：假设剩下了x颗明珠。根据之前的算法，这意味着：之前存在没有晶钻的x天，用来买明珠了。

那么考虑天数x的奇偶性之后，**修改这x天的策略**，最多还能再多得到x/2颗晶钻。前一半天数买，后一半天数换，如果是奇数的话多余一天什么也做不了。

于是假设原始算法执行完，得到y颗晶钻与x颗明珠，那么最终答案就是y+x/2。

```C
#include<stdio.h>

int t,n;
char s[2000005];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		int cnt1=0,ans=0;
		int i; 
		for(i=0;i<n;i++)
		{
			switch(s[i])
			{
			case'0':
				if(cnt1>0)
				{
					ans++;
					cnt1--;
				}
			break;
			case'1':
				cnt1++;
			break;
			default:
				ans++;
			}
		}
		printf("%d\n",ans+cnt1/2);
	}
	return 0;
}
```

### `L`  4238 小迷弟帮室友追女神

#### 题目解析

此题可以参照之前的“木木枭学高中集合论”的思路，利用一个m位二进制数代表任意一种选择方式
0代表不选 1代表选择 之后将每一种需要的累加起来 如果每一种礼物都不多于拥有的礼物数 
且选择的女神数大于原有答案 则更新 最后输出答案即可 

#### 示例代码

```c
#include <stdio.h>
#include <string.h>
long long a[100][100],h[100],m,n,shu[100],tmpp[100];
int main() {
	scanf("%lld %lld",&m,&n);
	int i,j,k;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&h[i]);
	}
	shu[0]=1;
	for(i=1;i<=m;i++){
		shu[i]=shu[i-1]<<1;//保存二的方幂 
	}
	int tmp=shu[m],maxv=0;//tmp就是前面所说的二进制数的总数 
	for(i=1;i<tmp;i++){
		memset(tmpp,0,sizeof(tmpp));//别忘清空数组 手动清除为0也可以 
		int cnt=0;
		for(j=1;j<=m;j++){
			if(shu[j-1]&i){//这一位为1则代表选择这位女神 
				cnt++;//选择女神数+1 
				for(k=1;k<=n;k++){
					tmpp[k]+=a[j][k];//将需要的礼物加起来 
				}
			}
		}
		int flag=0;
		for(j=1;j<=n;j++){
			if(tmpp[j]>h[j]){//大于的话说明礼物不够 
				flag=1;
				break;
			}
		}
		if(!flag){//礼物都够 
			if(cnt>maxv){
				maxv=cnt;//大于答案则更新 
			}
		}
	}
	printf("%d",maxv);
	return 0;
}
```
另一种解法 也是让我欣喜的是 很多同学用到了之前所学的递归 学以致用 点赞！
```c
#include <stdio.h>
int n,m,ngift[25][25],hgift[25],ans,tmpgift[25],vis[25];
void dfs(int step,int total){//step是到了第几个人 total是选择了几个人
	if(step==m+1){//递归到了终点也就是最后一个人也结束了
		if(total>ans) ans=total;//大于总数 更新答案并返回
		return;
	}
	int i,flag=0;
	for(i=1;i<=n;i++){
		if(tmpgift[i]+ngift[step][i]>hgift[i]){//已经大于了 没有进行的必要了
			flag=1;
			break;
		}
	}
	if(!flag){//不大于 可以选
		for(i=1;i<=n;i++){
			tmpgift[i]+=ngift[step][i];//将已经消耗的礼物更新
		}
		dfs(step+1,total+1);//到下一个人 并且选择了这个人
		for(i=1;i<=n;i++){
			tmpgift[i]-=ngift[step][i];//递归回来 要减下去表示不选了
		}
	}
	dfs(step+1,total);//递归到下一个人 并且不选这个人
}
int main(){ 
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&ngift[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		scanf("%d",&hgift[i]);
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
```
