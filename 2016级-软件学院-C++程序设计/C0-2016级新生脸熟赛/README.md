# C0-2016级新生脸熟赛

# `A` Hello BUAA_SOFT! by ModricWang

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

欢迎成为北航软件学院的一员。快来跟OJ打个招呼吧~

## 输入

无

## 输出

输出一行，内容为“Hello BUAA_SOFT!”

## 输入样例

## 输出样例

```
Hello BUAA_SOFT!
```

## HINT

感叹号为英文半角



# `C` 师恩难忘

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

Alan马上就要去上大学了，他想起了他亲爱的高中老师，决定临走前去见他一面。老师对他还是那么亲切，只是身体不太好了，写总评不太利索了。Alan见状，便主动请缨，帮老师写总评。

## 输入

第一个数为数据组数n，表示需要判定成绩的卷子

接下来n行，每行1个整数a，表示老师已经批改好的卷子的分数，需要你帮助老师写总评

(1≤n≤21,0≤a≤100)(1≤n≤21,0≤a≤100)

(评价标准：分数段在[85,100]，获得A评价；分数段在[70,84]，获得B评价；分数段在[60,69]，获得C评价；分数小于60分，获得D评价)

(感谢指正，已经修复bug)

## 输出

对于每组数据，输出一行，该学生的评价（不要有多余的换行！）

## 输入样例

```
1
98
```

## 输出样例

```
A
```



# `D` 试试A/B问题吧！

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

计算A/B，如果算式有问题，请输出Error！否则保留2位小数输出（具体可参考样例）

（不考虑精度差的版本，不了解的同学直接做题就可以了）

## 输入

第一个数为数据组数n

接下来n行，每行2个实数a,b

(1≤n≤21,−21000000≤a,b≤210000001≤n≤21,−21000000≤a,b≤21000000)

## 输出

对于每组数据，输出一行，a/b的值

## 输入样例

```
2
1.0 2.0
2.7 0
```

## 输出样例

```
0.50
Error!
```



# `E` IPv4

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

IPv4是第四版互联网通信协议的缩写，是目前应用最为广泛的互联网协议。一个IPv4网络地址通常采用点分十进制(Dotted Decimal)的表述格式。例如我们非常熟悉的用于配置路由的局域网IP即为192.168.1.1。

IPv4地址一般划分成五类：

A类(大型网)地址: 1.0.0.1-126.255.255.254

B类(中型网)地址: 128.1.0.1-191.255.255.254

C类(小型网)地址: 192.0.1.1-223.255.255.254

D类(多点广播)地址: 224.0.0.1-239.255.255.254

E类(实验)地址: 240.0.0.1-255.255.255.254

现在你的任务是，判断输入的IPv4地址属于A,B,C,D或E类地址中的哪一类。

## 输入

第一行为数据组数n

接下来n行，每行一个以点分十进制格式表示的IPv4地址，保证输入的是合法的A,B,C,D或E类IPv4地址。

## 输出

对于每组数据，输出一个占一行的大写字母，表示地址的分类。

## 输入样例

```
2
192.168.1.1
13.12.11.5
```

## 输出样例

```
C
A
```



# `F` 整数除法

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

计算机里常见的整数除法都是去掉小数部分。C和C++当然也是这样。

但是向下取整也是很有用的。

现在来计算[a/b]，其中[x]表示小于等于x的最大整数。 其中a和b都在int范围内。

对于非法的输入，输出error

## 输入

2个整数，a和b。

-2^31<=a<=2^31-1

-2^31<=b<=2^31-1

注：这个范围即是目前主流机器上int的范围。

## 输出

输出[a/b]的值。如果遇到了非法输入，输出error

## 输入样例

```
9 4
```

## 输出样例

```
2
```

## 思路

注意分类讨论

# `H` 巨坑的(A*B)%p (有毒慎入) by ModricWang

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

相信大家已经学会了加法。那么乘法和取模想必大家也会很快学会~

乘法的定义：

乘法是指将相同的数加起来的快捷方式。其运算结果称为积。

取模的定义：

取模运算：a % p（或a mod p），表示a除以p的余数。

## 输入

第一个数为数据组数n

接下来n行，每行3个数a,b,p(保证a,b,p在long long范围内，且a,b,p都是正整数)

## 输出

对于每组数据，输出一行，(a*b)%p的值

## 输入样例

```
1
123456789012345 1234567890123456 9876543210
```

## 输出样例

```
4696172190
```

## HINT

```
用高精度来做当然可以过题，但是这就不优雅了~
p.s.: 现在它没那么优雅了。
p.p.s.:我觉得楼上说的不对
```

## 思路

本题做出来了G也就有了，所以不摆G的题面了。

那么这题需要大家学习快速幂做乘法取模的方法。本题最大的坑点在于**需要使用unsigned long long而不是long long**

当然了，**最暴力的做法就是手写高精模板取模，对于学习高精度的同学来说自然是极好的，但是本题不推荐**

实际上 `__uint128_t`就能水过去了

# `I` 数星星

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

各位同学来到帝都仰望星空大学，数星星自然就是必备技能了。我们把天空看作二维空间，一颗星星由满足下列要求的五个点p1，p2，p3，p4，p5组成：

（1） p1.y>p5.y

（2） p5.y=p2.y

（3） p3.y，p4.y<p5.y

（4） p5.x<p1.x<p2.x

（5） p5.x<p4.x<p1.x

（6） p1.x<p3.x<p2.x

现在给你天空中的n个点，你能数出天空中有多少星星吗？

## 输入

第一行为一个数n（5≤n≤20）。

接下来n行，每行两个正整数x，y，代表天空中点的坐标（1≤x，y≤20）。

## 输出

一个数字，天空中星星的数量（一个点可以同时属于多个星星）。

## 输入样例

```
5
2 3
5 1
5 5
4 4
3 5
```

## 输出样例

```
0
```

## 思路

本题最为稳妥的一个思路就是**全组合+全排列**

首先全组合，找出C(n,5)种星星的组合，每一种组合内的5个坐标进行全排列，只要有一种排列方式满足星星的条件即为合法

# `J` jhljx玩游戏

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

jhljx是一个很爱浪的人，他云游四方，有一天来到一个island，叫做**normal island**。
他和岛上的一个原住民玩游戏。他们找来一堆椰果，总共有n个。

jhljx和原住民决定分掉这n个椰果，jhljx规定：每个人一次只能拿不超过3个果子，但是不能不拿。如果某个人拿光最后的果子，则获得胜利。
游戏开始时由jhljx开始拿。如果两个人都足够聪明，那么jhljx是否能赢得比赛呢？如果能，输出Yes，反之，输出No。

## 输入

输入多组数据。（注意输入多组数据需要用while(cin>>n)这样的语法来输入）
对于每组数据，输入数据为一个正整数n（保证1<=n<=100）。

## 输出

对于每组数据，输出一行，为Yes或No。

## 输入样例

```
3
4
```

## 输出样例

```
Yes
No
```

## 思考题

1. 如果每次拿的果子是[1，m]区间内的任意数字，程序又将如何修改？
2. 如果每次拿的果子是一个数列{Am}中的数字A1, A2, A3, ... , Am，程序又将如何修改？？

如果你通过本题已经理解了这两个思考题，那么恭喜你对该问题已经有了比较深入的理解。

## 思路

经典的nim游戏模型，只要n被4整除必然是后手赢

# `K` jhljx讲Excel(I)

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## Problem Description

整数对于大家来说都很熟悉，比如我们用到的十进制数。

1=1×1001=1×100

11=1×101+1×10011=1×101+1×100

111=1×102+1×101+1×100111=1×102+1×101+1×100

而对于刚刚进入大学的你们，你们以前应该或多或少地接触过Office这款软件，其中Excel是一个和表格相关的软件。里面的行和列都很有特色。其中，列是按照下面的模式来组织的：

- 1 ----> A
- 2 ----> B
- 3 ----> C
  ....
- 26 ----> Z
- 27 ----> AA
- 28 ----> AB
  ....
- 52 ----> AZ
- 53 ----> BA
  ....

我们本次的任务就是将右面的部分转换成左边的。而与该题配套的另一道题将会让你将左面的部分转换成右面的部分。
PS：这道题是一道科普题，大家可以先自己思考，如果不会可以看题目下方的详细解析。

## Input

由于大家尚未接触数组，所以为了方便大家初学，本题数据只有一行，为好多字符组成的序列，类似AA，AB这样。
输入字符只有A,B,C,...,Z这26个英文大写字母。

## Output

输出字符序列对应的数字，保证输出结果在int范围内。

## Sample Input

```
ABCDEFG
```

## Sample Output

```
334123303
```

## Learning Tag

- 字符读入
- 多进制的使用

## 思路

进制转换，但是和普通的进制转换稍有不同。

本题为Excel特有的26进制转10进制，原本的26进制内，每位数组为0到25，而在这里却是1到26。所以我们可以先按照A=0,B=1,....,Z=25的对应关系，转一次26进制到10进制，然后再将相同位数重复的1由26进制转为10进制，两者相加即为结果。

# `L` jhljx讲Excel(II)

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## Problem Description

整数对于大家来说都很熟悉，比如我们用到的十进制数。

1=1×1001=1×100

11=1×101+1×10011=1×101+1×100

111=1×102+1×101+1×100111=1×102+1×101+1×100

而对于刚刚进入大学的你们，你们以前应该或多或少地接触过Office这款软件，其中Excel是一个和表格相关的软件。里面的行和列都很有特色。其中，列是按照下面的模式来组织的：

- 1 ----> A
- 2 ----> B
- 3 ----> C
  ....
- 26 ----> Z
- 27 ----> AA
- 28 ----> AB
  ....
- 52 ----> AZ
- 53 ----> BA
  ....

我们本次的任务就是将左面的部分转换成右边的。而与该题配套的另一道题将会让你将右面的部分转换成左面的部分。详见[jhljx讲Excel（I）](http://biancheng.love/problem/409/index)。

## Input

输入多组数据。
每组数据一行，为一个正整数n（保证n在int范围内）。

## Output

输出这个数字对应的字符串。

## Sample Input

```
26
27
52
53
```

## Sample Output

```
Z
AA
AZ
BA
```

## Learning Tag

- 字符串
- 多进制的使用

## 思路

进制转换，但是和普通的进制转换稍有不同。

本题为10进制转换为Excel特有的26进制，原本的26进制内每一位为0到25，而这里为1到26。所以我们可以正常地按照10进制先转换为26进制，然后在结果中查看，如果某一位小于等于0的话，就要向他的高位借1（即自己加上26，高位减1。之所以是小于等于0就要借位，是因为借位会出现连锁反应）。这样就可以得到正确的结果了。
