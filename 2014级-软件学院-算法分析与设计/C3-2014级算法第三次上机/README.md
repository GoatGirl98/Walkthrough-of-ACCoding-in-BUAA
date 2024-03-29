# C3-2014级算法第三次上机

# `A` 吃土

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

## 输入

多组测试数据（不超过10组），每组数据两行

第一行为一个正整数N（N<=10000），表示排队挖土的总人数

第二行为N个正整数a1,a2,,,an（INT范围内），表示每个人挖土所需的时间

## 输出

对于每组数据，输出一行，表示等待时间之和的最小值

## 输入样例

```
5
1 2 3 4 5
```

## 输出样例

```
20
```

## 思路

贪心，排序就完事了

# `B` 零崎的朋友很多Ⅰ

时间限制：2000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

零崎有很多朋友，其中有一个叫做lfj的接盘侠。

lfj是一个手残，他和零崎一起玩网游的时候不好好打本，天天看拍卖行，没过多久，就成为了一个出色的商人。时间一长，虽然挣了不少钱，却没时间练级了。

作为lfj的友人，零崎实在看不下去，于是他决定帮lfj一把。当然了，零崎肯定不会自己动手，活还得你们来干。

lfj可以提供给你们拍卖行所有能买到物品的价格和利润，由于游戏产出不限，所以可以假定只要有钱，即使是同一种东西，多少个也都能买到手。lfj还会告诉你他初始的成本。虽然零崎想让你们给出一次交易中利润最大的购买方案，但是lfj觉得只要知道最大利润就可以了。

## 输入

每组数据第一行为两个整数P和N，表示本金和拍卖行物品种类数。

接下来N行，每行两个数据pi,ci代表第i类物品的利润和购买价格。

1<=P<=20000,1<=N<=300,1<=c,p<=200

## 输出

对于每组数据，输出一行，为能获得的最大利润

## 输入样例

```
3 1
2 1
2 3
1 1
1 2
2 1
```

## 输出样例

```
6
4
```

## Hint

使用if直接比较不要调用max（）以防超时

## 思路

完全背包

# `C` 零崎的朋友很多Ⅱ

时间限制：2000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

零崎有很多朋友，其中有一个叫做lfj的接盘侠。

lfj是一个手残，他和零崎一起玩网游的时候不好好打本，天天看拍卖行，没过多久，就成为了一个出色的商人。不过再出色的投机商也有失手成为接盘侠的一天。所谓真正的接盘侠从来不给自己留活路。当lfj接盘成功之时，即分文不剩之日。

作为lfj的友人，零崎实在看不下去，于是他决定帮lfj一把。当然了，零崎肯定不会自己动手，活还得你们来干。

lfj可以提供给你们拍卖行所有能买到物品的价格和利润，还有他的本金。既然是接盘侠，就必须分文不剩。虽然零崎想让你们给出一次接盘中利润最大的购买方案，但是lfj觉得只要知道最大利润就可以了。

## 输入

每组数据第一行为两个整数P和N，表示本金和拍卖行物品个数。(注意：与B题不同每类物品只有一件

接下来N行，每行两个数据pi,ci代表第i类物品的利润和购买价格。

1<=P<=20000,1<=N<=300,1<=c,p<=200

## 输出

对于每组数据，输出一行，为能获得的最大利润

如果不能成功接盘，则输出jpx

## 输入样例

```
3 1
2 1
4 3
3 1
1 3
2 2
```

## 输出样例

```
jpx
4
```

## Hint

使用if直接比较不要调用max（）以防超时

## 思路

需要装满背包的01背包，稍微用点小技巧，就可以区分是否是装满的状态了，其他的和01背包没有区别

# `D` 零崎的朋友很多Ⅲ

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

零崎有很多朋友，其中有一个叫jhljx。

jhljx大家很熟悉了，他数学不好也是出了名的，大家都懂。

现在jhljx遇到了矩阵乘法，他当时就懵了。数都数不清的他，矩阵乘法怎么可能会算的清楚呢？虽然零崎觉得还不如让你们来算，不过好歹也要给jhljx个面子，给她留下一个证明自己数学实力的机会。为了减小jhljx的计算量，让他赶快算出不正确答案来（估计他算上几遍都不一定能出一个正确答案），零崎请你们帮助jhljx。

## 输入

多组输入数据。

每组数据以N开始，表示矩阵链的长度。接下来一行N+1个数表示矩阵的行/列数。

1<=N<=300

## 输出

对于每组样例，输出一行最少运算次数的方案，每两个矩阵相乘都用“()”括起来，详见样例

如果存在多种解决方案,最终输出结果选取先计算左边的矩阵，详见Hint

## 输入样例

```
3
10 30 5 60
3
10 20 5 4
```

## 输出样例

```
((A1A2)A3)
((A1A2)A3)
```

## Hint

对于输入的第二组数据,

如果计算顺序为((A1A2)A3)，结果为10×20×5 + 10×5×4= 1200,

如果计算顺序为A1(A2A3), 结果为20×5×4 + 10×20×4 = 1200

那么输出结果选取第一个

## 思路

矩阵链乘 经典DP模型

在判断如何输出的时候，就优先把括号往前放就好了

事实上，该问题拥有 $O(n\log n)$ 的 "Hu-shing Algorithm" ，该算法在《算法导论》中也提及了一次，关于该做法可以去看题目编号4171 (来源No.1 Shawn's friends' Interview Algorithm Contest) 的代码。

# `E` 最优二叉搜索树

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

## 输入

## 输出

```
对每组数据，输出最优二叉查找树对应的搜索期望代价，保留小数点后3位
```

## 输入样例

```
5
0.15 0.10 0.05 0.10 0.20
0.05 0.10 0.05 0.05 0.05 0.10
```

## 输出样例

```
2.750
```

## 思路

最优二叉搜索树 经典DP模型，具体详见算法导论。

顺便说个有意思的，早期严蔚敏的《数据结构》有手写计算次优查找树的问题，这谁背的下来DP方程啊...所以可以通过一定的公式计算近似值

但是需要知道，该问题有Knuth优化部分循环，得到 $O(n^2)$ 的做法，可以写一下。另外就是如果要输出具体的二叉搜索树的话，则需要类似上面的矩阵链乘一样，记录 $root[i][j]$ ，即内部节点 $i, i+1,...,j$ 之间的树的根节点是谁，最后再递归输出，而这部分也正是优化为 $O(n^2)$ 的关键要素。该优化技巧也是在 $root$ 数组的单调性保证下才做到的。本题数据范围较小，具体的性能差异可以看题目编号2552(来源: 2018级算法第三次上机)

# `F` 暗号

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

作为一名情报局特工，Nova君(2号)有着特殊的传达情报的技巧。为了避免被窃取情报，每次传达时，他都会发出两句旁人看来意义不明话，实际上暗号已经暗含其中。解密的方法很简单，分别从两句话里删掉任意多个字母，使得两句话剩余的部分相同，通过一定的删除手法，可以让剩余的部分相同且长度最大，就得到了可能的暗号。暗号可能有多个，还要进行筛选，现在情报局人手不够，希望你能助一臂之力，筛选工作不用你完成，你只需计算出暗号长度以及个数即可。（注意，字母的位置也是暗号的重要信息，位置不同的字母组成的暗号不算同一种，详见样例）

## 输入

多组测试数据（组数小于20）

每组数据输入两行，分别为两个字符串（只含英文字母，无空格），每个字符串以"." 结束

## 输出

对于每组数据，输出两行，第一行为暗号的长度，第二行为暗号的个数（答案可能很大，对个数100000000求模）

## 输入样例

```
AAAA.
AA.
```

## 输出样例

```
2
6
```

## 思路

LCS 求长度我不说了

主要就是边dp LCS的同时也dp对应的方案数量（类似于求二维前缀和那样）

由于字符串较长，所以采用滚动数组

# `G` 双“11”的抉择

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

把钱花完了，所以单身了，单身了所以过双“11”，过双“11”所以把钱花完了。

今年Nova君(三号)照旧过着他暗无天日的“买买买”的双“11”，然而因为囊中羞涩，并不能够太任性。他的购物车中，列满了数不清的商品，共有N件，好多商品居然还不止一件 __(:3 」∠) 现在Nova君要做出一个艰难的抉择，他要从所有商品中挑出m件拼成一个订单，请问有多少种凑单的方法呢？求访法数对M的余数。

PS:同一种商品不作区分。

## 输入

多组测试数据（不超过100组）

每组数据两行，第一行为三个正整数N,m,M，具体意义详见描述，第二行为N个正整数a1,a2,,,an，代表第i个商品的个数

(1<=N,ai,m<=1000，2<=M<=10000)

## 输出

对于每组数据，输出一行，表示方法总数

## 输入样例

```
3 3 10000
1 2 3
```

## 输出样例

```
6
```

## 思路

多重集组合数问题

首先想到暴力搜索的办法，设dp[i] [j]为前i种物品选出j个的总方案数则有：

dp[i] [j] = sum(k:0~min(a[i],j))d[i - 1] [j - k]

dp[i] [j - 1] = sum(k:0~min(a[i],j - 1))d[i - 1] [j - k - 1]

但这个dp在此题的情况下会TLE

接着想到优化方案：对于每个i,j分情况讨论a[i]、j、j - 1的关系，然后将上述求和式展开，查看二者的关系，得到优化后的状态转移方程 具体见代码

