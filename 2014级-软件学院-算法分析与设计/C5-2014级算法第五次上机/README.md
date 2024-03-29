# C5-2014级算法第五次上机

# `A` 万恶的双“12”

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

想必大家双“11”剁掉的小爪子们已经长好了，所以双“12”又快到了。然而Nova君对剁手之痛记忆犹新，不想再次尝试，所以想进行穿越，企图避开双“12”。Nova君能力有限，只可以穿越到2015年随机的某一天，请大家算算，Nova君是否能逃过双“12”的浩劫？

## 输入

多组测试数据（组数不超过10组），对于每组数据，输入一行，包含两个正整数，分别代表2015年的某天日期（包含月和日，格式详见样例）

## 输出

对于每组数据，输出一行：

如果刚巧这天是双“12”，则输出 “Oh my god! It's today!!” ；

如果在双“12”之前，则输出 “It will come in x day(s) ORZ”，x代表距离双“12”的天数 ；

如果在双“12”之后，则输出“Lucky , it has passed!” ；

## 输入样例

```
12 18
12 12
1 1
```

## 输出样例

```
Lucky , it has passed!
Oh my god! It's today!!
It will come in 345 day(s) ORZ
```

## 思路

签到水题，不多说

# `B` 零崎的悠哉日常Ⅰ

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

最近，零崎发现自己的基友们都很闲，于是提议大家来玩一个叫“跑得快”的游戏吧，输的人就去操场跑三千米。经过一番苦战，除了跑的最快的jhljx，其他人都要去跑三千米了……

关于长跑，零崎有一个无耻的习惯，那就是紧跟着第一的人跑（如果前面没人就干脆不跑）。因为学院路这边的操场上每天都有很多人跑步锻炼身体，零崎肯定是逃不掉这个三千米的，跑完不过是时间问题。

为了简化问题，假设这些人跑步都是匀速的，零崎会跟在第一个人后面跑，如果被更快的人超过，零崎会加速跟在那个人后面。那么零崎到底多久能跑完？

## 输入

多组输入数据。

每组输入数据第一行为一个整数N，为操场上跑步的总人数。

接下来N行每行两个数Vi,Ti为第i个人的速度(km/h)和出发时间(s)（负数为在零崎之前出发，不考虑超过零崎一圈的情况）

每组输入数据中至少有一组出发时间非正的数据和一组出发时间非负的数据。

## 输出

对于每组数据，输出一行，为零崎跑完三千米的时间，以秒为单位向上取整。

## 输入样例

```
4
20 0
25 -155
27 190
32 200
```

## 输出样例

```
538
```

## Hint

double ceil(double x) 头文件 math.h / cmath

## 思路

仔细思考，可以发现，所有在零崎前面跑的人都不会被计算在内（比自己慢的不会影响自己速度，比自己快的也不会超过自己）

中间的细节可以不用考虑，那些在在自己之后跑的比自己慢，或者到终点前追不上自己的也不用管

**说白了，最后的答案就是零崎以及零崎后面的选手，最快到达终点的所用时间**

# `C` 收徒

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

Nova君想要找个徒弟和他一起玩游戏机，然而，Nova君是个要求很多的人，游戏能力在他之上的或者和他一样强的都不要，要了岂不是很没面子 ╮(╯▽╰)╭ 能力太差的也不要_Orz__ 所以Nova君决定在游戏能力在他之下的人里挑选能力最强的。世界那么大，很可能有一些人能力值一样。Nova君在想，到底有多少人有资格呢？请来帮帮他找机友。

## 输入

多组测试数据（组数不超过10），对于每组数据，输入两行，第一行为两个正整数N和M，分别表示所有候选人的个数以及Nova君的能力值；第二行包含N个正整数，表示N个候选人的能力值（已经按非降序排列好）。N<=1000000

## 输出

对于每组数据，输出一行，输出有资格的人的个数。

## 输入样例

```
7 9
2 4 6 8 8 8 9
```

## 输出样例

```
3
```

## HINT

```
请用二分实现
```

## 思路

水题，STL水过就行了

# `D` 零崎的悠哉日常Ⅱ

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

零崎闲下来的时候很喜欢去看书，特别是在沙河的时候，经常和社团的小伙伴一起去自习室看小说。教学楼跑的次数多了，自然对路也比较熟，比如教三大教室旁边的楼梯间里或者教学楼连通走廊的制图教室外经常有妹子读英语什么的……

说起来教室之间有各种各样不同的路可以走，不同的路的容纳量也不同，那么这么多教室这么多路，如果从一间教室前往另一间教室上课，最多可以有多少人一起走呢？零崎虽然对路和每条路的容量很熟，不过教室这么多，路太多了怎么算得清呢？

## 输入

多组输入数据。每组数据N+1+T行。

第一行为三个整数，教室数V，路的数量N和查询数量T。

接下来N行每行三个整数s,t,c为一条教室s到t容量为c的路。

最后T行每行两个整数x，y为查询的教室编号。

## 输出

每组样例输出T行，每次查询一行，为x,y间通路的最大流量。

## 输入样例

```
5 7 2
1 2 10
1 4 2
2 4 6
2 3 6
3 4 3
3 5 8
4 5 5
1 5
4 2
```

## 输出样例

```
11
0
```

## 思路

最大流模板

但是本题涉及到多组查询，如果你采用的是ISAP或者HLPP预流推进等算法，计算一次之后的图会变成残留网络，与原网络不符，所以需要存储原网络并且复原

# `E` 零崎的悠哉日常Ⅲ

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

零崎在空闲时间很多的时候，就喜欢玩一些非常耗时间的游戏，比如可以死上几千次的I wanna，又比如一不小心就要重头开始的多米诺骨牌。

在摆放多米诺骨牌时，如果中途碰倒一块，就会产生雪崩般的影响。比如说**11__1x11_11**这种形状，零崎这么作死的人当然会在中间x位置放一枚骨牌……这种作死的做法有*pl*的概率会倒向左边并把左边的1个骨牌碰倒，或者有*pr*的概率会倒向右边并把右边的2个都碰倒。（骨牌不是量子态不会既左倒又右倒……）

现在零崎准备把手里的N枚多米诺骨牌摆成一条直线，那么他摆放骨牌次数的期望是多少？

## 输入

多组输入数据。

每组数据为三个数，第一个为整数N<10000，接下来两个浮点数pl，pr，0<pl+pr<1

## 输出

对于每组数据，输出一行，为采取最佳摆放方式时的次数期望，保留两位小数

## 输入样例

```
2 0.1 0.1
10 0.2 0.3
```

## 输出样例

```
2.66
44.03
```

## Hint

几何分布的期望Ex=1/p

O(n^2)可过

## 思路

概率dp

确定了摆放次数和左右倒的概率之后

先把不会倒的概率写出来设为p

那么显然初始方程为:dp[0]=0 dp[1]=1/p

然后后面的初试方程均为:

dp[k] = 0到k-1会倒的概率的倒数

所以如何计算这个呢

那就假设计算的是[l,r]之间会倒的情况

其实直接把[l,r]的期望根据已有期望来算就行啦
$$
E[l][r] = dp[l]+dp[r]+(pl*dp[l]+pr*dp[r]+1)/p
$$
仔细读题，往右倒不是说倒后面俩，而是自己和右边的，碰左边的话自己不会倒

所以初始dp[k]=E[0] [k-1]

然后如果n^2可过的话，这题我就大概有底了

实际上就是计算一下每一次从哪插入更合适，最后dp[n]就是所求了

概率区间状压dp是真的得多做，没做过真的不会...

所以

dp[k] = min(E[l] [r]) 其中l = j r = k - 1 - j 然后每一次求出中间插入的最小期望即可

# `F` 阿姆斯特朗回旋加速喷气式阿姆斯特朗炮

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

时代在进步，在Nova君的改进下，阿姆斯特朗回旋加速喷气式阿姆斯特朗炮终于进化成为了先进的电磁轨道炮，不仅能够在直筒中发射直线型电磁炮，还能利用正负极磁场，在两座炮台间形成弧形电磁炮，大大加强了御敌能力。某一天，天人（外星人）入侵了地球，现在要用阿姆斯特朗回旋加速喷气式阿姆斯特朗炮进行轰击，简化图如下： ![img](http://ww1.sinaimg.cn/mw690/006jMFyngw1eyupfrs57wj30kg0drgm3.jpg)

现在抽象问题，假设外星人都在X轴上方（不含X轴本身）出现，现在有三门阿姆斯特朗回旋加速喷气式阿姆斯特朗炮，中间的A炮，可以发射以原点O为起点的任意射线的电磁炮，其方向向量和X轴正方向夹角为Θ，可以消灭位于射线的所有敌人，位于两翼的炮B和炮C形成电磁回路，两炮口间有半圆形的弧形电磁炮，可以消灭位于弧形线上的所有敌人，设半圆的半径为R。每当发现敌人，A炮可以计算出敌人与O点连线和X轴正方向的夹角Θi，B炮和C炮可以计算出敌人所处弧形炮的半径Ri。现在有N个敌人，至少需要发射几次炮弹才能清理所有的外星人？（B、C联动只算发射一次）

PS：

(1) 假设Θi为角度制，范围1~179（单位：度）

(2) 假设敌人出现的最大半径为1000

## 输入

多组测试数据（组数不超过10），对于每组数据，输入N+1行，第一行输入一个正整数N，代表外星人的个数。接下来的N行，每行输入两个正整数，为对应的A炮计算出的Θi 和 B、C炮计算出的Ri。

## 输出

对于每组数据，输出一行，代表发射的最少次数。

## 输入样例

```
3
1 2
2 2
3 4
```

## 输出样例

```
2
```

## 思路

二分图最大匹配模板

直接套匈牙利算法即可

但是呢，其实最基础的网络最大流同样可以用来解决二分图最大匹配问题（虽然会稍微慢一些），具体如何建模较为基础，可以稍微想想

# `G` 就决定是你了！

时间限制：20000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

Nova君来到神奇宝贝中心，准备从存储机中挑选若干个Pockmon去挑战最后的四天王和联盟冠军。Nova君现在有N只可挑选的Pockmon，对于第 i 只Pockmon，他的体总为 wi ，战斗力为 vi 。现在联盟规定，只能携带总重量为M的Pockmon进行挑战。那么，Nova君要怎么挑选才能使战斗力最强呢？大家肯定会说，这不是个简单的背包问题嘛？嗯，大概。但是现在有个问题，由于某些Pockmon在冒险的途中，和存储机内的其他Pockmon产生了羁绊，有可能对另一只Pokmon产生依赖，非得被依赖的那只被选中才能发挥战斗力，否则只能是个战斗力为0的卖萌生物而已，好在每只Pockmon都很专情，只会依赖一只（或者不依赖）。

PS：

(1) 依赖关系不对称，即，若A依赖B，B不一定依赖A，俗称beitai；

(2) 可能出现这样的情况：A依赖B，B依赖C，C依赖A，俗称love triangle，当然也有可能是多边形（悲伤脸）

(3) 保证不会出现自己依赖自己的情况

## 输入

多组测试数据（组数不超过10），对于每组数据，输入4行，第一行是两个正整数N，M，表示Pockmon总数和联盟允许的最大重量，第二行包含N个正整数w1，w2...wn，表示第 i 个Pockmon的重量，第三行包含N个正整数v1，v2...vn，表示第 i 个Pockmon的战斗力，第四行包含N个正整数D1，D2...Dn，表示第 i 个Pockmon依赖的Pockmon的序号，如果没有依赖对象，则 Di=0。

PS：输入数据都在INT范围内，N不超过1000

## 输出

对于每组数据，输出一行，表示战斗力的最大值

## 输入样例

```
3 10
4 5 6
2 3 4
3 1 2
3 10
4 5 6
2 3 4
0 1 1
```

## 输出样例

```
0
6
```

## 思路

**注：本题的数据疑似为错误。做题时请谨慎。**

带有图形依赖的01背包问题

在《背包九讲》当中有提到过这个东西，那么这个就涉及到树形dp的问题了，建议多去做一做树形dp的题目再回来看这里

本题由于没有说是无环图，所以自然是可能存在环的，所以我们需要对整个图进行一次缩点，并生成一些新的背包。

再接下来就是树形dp的活了

**此处给出一个Tarjan缩点+树形DP的做法，无法AC本题，但是在[P2515 [HAOI2010]软件安装](https://www.luogu.com.cn/problem/P2515)与数据强度更大的[160. 树形背包](https://loj.ac/p/160)中均验证正确。** 由此可以怀疑本题的数据点多半是错误的。该错误做法在第一个链接中，由于数据范围较小，可以AC，在第二个链接中，数据范围较小的点也找不出错误，但是复杂度完全是错的，而且提升了数组上限之后，**竟然就从AC变成WA了**，真是蹊跷至极...

综上，**本题为错题的几率是特别高的，各位慎做...**
