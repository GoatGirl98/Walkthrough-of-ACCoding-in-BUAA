# C10-2016级C++第十次上机

# `A` 王助教改首字母大写

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

王助教经常会忘了首字母大写。现在把王助教的文章给你，请你帮他把句首字母大写都改正过来吧。

**只以出现的标点符号作为唯一分句标准。**

## 输入

一个多行的字符串s，表示王助教写的文章。

0<len(s)≤100000<len(s)≤10000

**保证s中只含有字母，数字，空格，换行和英文标点符号。**

英文标点符号包括 `,.?!;:'"`

## 输出

一个多行的字符串，表示句首字母大写已经改正的文章。

## 输入样例

```
you ask me to tell you the data on the online judge. it's okay to 
get data other than judging data, but you may just make your code
to fit the judging data if you have it. this will hide the true
problem under your code. you just get an "accepted" and think
things are all right. nobody know what is really going on. "accepted"
is not "correct".
```

## 输出样例

```
You ask me to tell you the data on the online judge. It's okay to 
get data other than judging data, but you may just make your code
to fit the judging data if you have it. This will hide the true 
problem under your code. You just get an "accepted" and think
things are all right. Nobody know what is really going on. "accepted"
is not "correct".
```

## hint

换行符可能有\n和\r\n两种。

## 思路

全部读入之后进行离线处理

仅以句号 问号 叹号作为分隔点，判断每一局的第一个费空格类字符是否是小写字母，如果是则更改为大写字母，否则不动

# `B` 王助教又填数独

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

这次王助教已经快要把数独填完了。现在把这个数独给你，请你帮王助教计算一下还有多少种让数独成立的填满数独的填法吧。

数独成立是指**每行1-9都只能出现一个，每列1-9都只能出现一个，每个九宫格1-9都只能出现一个。**

**什么都不填也算一种填法的。**

## 输入

输入9行，每行9个整数dij，表示数独9*9的格子。

0表示这个地方可以填写数字，1~9代表王助教填写的数字。

0≤dij<100≤dij<10

**保证填法不超过200种。**

## 输出

输出一行一个整数，还有多少种让数独成立的填满数独的填法。

## 输入样例

```
1 8 3 4 6 2 5 9 7
4 6 2 7 5 9 3 8 1
9 7 5 3 1 8 6 2 4
8 3 4 6 2 5 7 1 9
5 1 9 8 7 3 4 6 2
6 2 7 9 4 1 8 5 3
3 9 1 5 8 4 2 7 0
2 5 6 1 3 7 9 4 8
7 4 8 2 9 6 1 3 5
```

## 输出样例

```
1
```

## 思路

这回的数独**就是真正的数独搜索问题了**

就正常的按照类似八皇后问题那样，逐行逐元素进行dfs搜索即可，**边界数据一种是给定的数独本身就已经不合法了，此时答案是0;另一种提示说了，已经填完整的合法数独答案是1**

**本题解给出了两个代码，另一种搜索方式就是先检索每一行空缺的个数，由少到多进行逐行搜索，在81个空格中只有24到28个左右的给定数据时，其速度会比普通搜索快4到5倍以上。**

**由于本问题属于精确覆盖问题，所以采用Dancing Link(DLX)搜索方式也是可以的。**

# `C` ModricWang的空间折跃

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

ModricWang是一名高阶圣堂武士，对于空间折跃略有研究。

某日，在一个叫地球的地方，ModricWang看到了一种叫梅花桩的东西。这个梅花桩有n根柱子，从左到右一字排开。开始时ModricWang站在整个场地的左边，由于ModricWang会空间折跃，可以以任意一根柱子作为起点。不过，ModricWang在学习空间折跃的时候没有好好练习，因此，虽然他可以瞬间在水平或竖直移动任意距离，但是他只会往更高的地方折跃，不知道怎么下来。请问，在这些梅花桩上，ModricWang最多能折跃多少次？（包括从场外折跃进来的一次）

## 输入

第一个数为桩数n，1≤n≤100001≤n≤10000

接下来n个整数，都在long long范围内

## 输出

一行，ModricWang最多能折跃的次数（包括从场外折跃进来的一次）

## 输入样例

```
5
1 2 3 2 1 
```

## 输出样例

```
3
```

## HINT

ModricWang不希望你用什么LIS之类的高级玩意，如果你一定要用，那。。。随你吧

## 思路

读题，坑点在于**可以左右横跳**。**所以需要先对该数组进行从小到大排序，然后再求最长的严格上升子序列。O(n^2)和O(nlogn)均可过。**

# `D` ModricWang的满天繁星

时间限制：1000ms  内存限制：65536kb

通过率：/ `(%) `  正确率：/ `(%)`

## 题目描述

ModricWang在虚空之战后接管了黄金舰队。面对满天繁星，ModricWang想知道，自己的视野里有多少个星球？ 将ModricWang的视野抽象成一个字符串，其中'*'表示星球，请统计出视野里的星球数量。 

![](http://sc2.nos.netease.com/2/zz/201603/wall078-1024x768.jpg)

## 输入

一行，一个字符串

字符串长度为len， 1≤n≤10001≤n≤1000

保证字符串中不含文件尾、空格、回车等不可见字符。//也就是说，保证你一个cin能读入整个字符串

## 输出

一个数字，视野中星球的数量

## 输入样例

```
#####*#*###
```

## 输出样例

```
2
```

## 思路

水题，判断*个数即可。