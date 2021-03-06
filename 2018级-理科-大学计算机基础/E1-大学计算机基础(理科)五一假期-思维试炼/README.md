# E1-大学计算机基础(理科)五一假期-思维试炼

# `A` 美丽的阶乘

时间限制：1000ms  内存限制：65536kb

通过率：159/260 `(61.15%) `  正确率：159/908 `(17.51%)`

## 题目描述

对于任意一个自然数，它的阶乘通常是很美的，因为它有非常多的因子，甚至后面会有非常多的0。定义一个数的“美丽程度”为它在十进制下后面(末位起)的连续0的个数。给出n，求n!的美丽程度。

## 输入

包括一行，一个整数n。

## 输出

一行，一个整数，n!的美丽程度。

## 输入样例1

```
5
```

## 输出样例1

```
1
```

## 输入样例2

```
4
```

## 输出样例2

```
0
```

## 输入样例3

```
10
```

## 输出样例3

```
2
```

## 样例解释

5!=120，末尾有1个0，答案为1。其他样例请自行理解。

## 数据范围

保证1≤n≤1e18。

## 思路

1到n分别质因数分解，拆出多少个5答案就是多少

然而这个完全可以直接用n求出来，每次除以5的商求和即为答案

# `B` 三重分解

时间限制：1000ms  内存限制：65536kb

通过率：144/159 `(90.57%) `  正确率：144/241 `(59.75%)`

## 题目描述

对于一个正整数n，找到三个正整数a,b,c，使得n=a+b+c，且abc都不是3的整数倍。如果找不到这样的分解，请输出”impossible!”(无引号)。

## 输入

包括一行，一个整数n。

## 输出

如果找不到这样的分解，请输出”impossible!”(无引号)，占一行。

如果你找到了这样的分解，请在第一行输出”YES”(无引号)，第二行三个整数，表示一组满足题意的a,b,c

## 输入样例1

```
3
```

## 输出样例1

```
YES
1 1 1 
```

## 输入样例2

```
233
```

## 输出样例2

```
YES
77 77 79
```

## 样例解释

对于样例1，只有一种分解方法。

对于样例2，有很多种分解方法，比如80,80,73也是一种可以的分解，你只需要输出任意一种满足条件的即可。

## 数据范围

保证3≤n≤1000000。

## 思路

只要大于2，答案就是可以的

输出的时候要么拆出1和1要么拆出1和2，这个无所谓

# `C` 最小互质序列

时间限制：1000ms  内存限制：65536kb

通过率：157/162 `(96.91%) `  正确率：157/207 `(75.85%)`

## 题目描述

定义一个序列为互质序列：当且仅当它的所有任意相邻两项互质。例如：著名的斐波那契数列(1,1,2,3,5,8,13.....)就是一个互质序列。

现在要求你找到一个长度为n，严格单调递增，且最大元素尽可能小的互质序列，输出它的最大元素。

## 输入

包括一行，一个整数n，表示要求的是一个长度为n的，最大元素尽可能小的互质序列。

## 输出

包括一行，一个整数a，表示这个序列中最大的元素是a。

## 输入样例

```
2
```

## 输出样例

```
2
```

## 样例解释

当n=2时，最大元素最小的单调递增互质序列为：1,2。最大元素为2。

## 数据范围

保证1≤n≤10000000。

## 思路

显而易见，答案就是他自己

# `D` 似曾相识

时间限制：1000ms  内存限制：65536kb

通过率：104/124 `(83.87%) `  正确率：104/269 `(38.66%)`

## 题目描述

某一天，某一位同学突然开始了刷题，每一道题目都由一个长度为m的正整数数列描述，当且仅当两个数列的每一项都对应相等的时候，才认为这两道题相同。

这位同学由于过度熬夜刷题，记忆力衰退明显，他几乎记不得他做过了哪些题目！已知他一晚上一共刷了n道题，请你帮他判断一下每道题是他第一次接触的题目，还是他已经刷过的题目。

## 输入

包括n+1行。

第一行两个整数：n，m。表示有n道题，每道题由长度为m的正整数数列描述。

## 输出

包括n行。

每行”YES”或”NO”，输出”YES”表示这道题他第一次接触。输出”NO”表示这道题他做过了。

## 输入样例1

```
4 3
1 1 2
3 2 2
1 1 2
3 2 3
```

## 输出样例1

```
YES
YES
NO
YES
```

## 输入样例2

```
4 4
1 1 1 2
1 1 2 1
1 1 1 1
1 1 2 1
```

## 输出样例2

```
YES
YES
YES
NO
```

## 样例解释

对于样例1，第三题和第一题是一样的，所以第三行输出NO。

对于样例2，第四题和第二题是一样的，所以第四行输出NO。

## 数据范围

保证3≤n≤1000，3≤m≤1000，每一数值ai有1≤ai≤1000000(1e6)。

## 提示

每读取一个数列，都和之前所有的进行比对，不但代码相对不好写，而且还会TLE

## 思路

采用字典dict结构，把有的数列转换为字符串（比如1 3 15变成“1#3#15”）进行存储，只要查找字典结构即可

# `E` 定闹钟

时间限制：1000ms  内存限制：65536kb

通过率：105/110 `(95.45%) `  正确率：105/190 `(55.26%)`

## 题目描述

有一天，xx同学躺在床上想要睡觉。突然他想起他即将在某一些时间需要起床做一些事情，于是他尝试给自己定一个闹钟。

这一天，他将会有n件事情，每件事情距离现在xi分钟。而他的手机非常的古老，每天只能设定一种闹钟。这种闹钟形如a+bk(k为自然数)的格式，只能设定它在第a分钟响起，且在之后的每过b分钟响起。

xx担心他某件事情被自己给睡过去，于是要求每件事情开始的时候，闹钟都必须响一次。当然他还想多睡一会，所以希望没事的时候闹钟响的次数尽可能的少。请你帮忙设计a和b的值。（不要担心这一天有多少分钟，可以认为这一天是无限的）

## 输入

包括两行。

第一行一个整数n，表示他今天会有n件事情。

第二行n个整数x1...xn，表示他将会在xi分钟有事情。保证x正整数数列是单调递增的。

## 输出

包括一行，两个整数，a和b，如题所述。

## 输入样例

```
3
5 7 9
```

## 输出样例

```
5 2
```

## 样例解释

xx同学在这一天有三件事情，分别在5分钟，7分钟，9分钟之后。当然你可以让a=b=1，这样也会让xx同学每件事情都有闹钟响起，但这会严重影响他的睡眠。所以令闹钟第一次在5分钟时响起，之后在7分钟、9分钟分别响起即可保证其他时间响起次数最少。

## 数据范围

保证3≤n≤100000，1≤xi≤10000000000(1e10)。

## 思路

取相邻两者差最小即可

# `F` 交作业计划

时间限制：1000ms  内存限制：65536kb

通过率：68/87 `(78.16%) `  正确率：68/211 `(32.23%)`

## 题目描述

xx同学是一个不学无术的同学，现在他的数学分析老师要挂他的科，除非他能把这学期的作业补齐上交。

于是xx同学听话的补完了所有的作业，在某一周的星期一开始在教室等老师。而老师也不是每天都来的，他在每个星期一到星期日都有一个概率会到来。现在xx同学等着急了，希望你帮他算一下他等到老师来的期望天数。

## 输入

包括一行，七个实数a1...a7，表示老师周一、周二、...、周日每天会来的概率(保证ai有0.1≤ai≤0.9)。

## 输出

包括一行，一个实数，表示老师第一天来的期望天数。（你的答案与标准答案的误差小于0.0001即认为正确）

## 输入样例

```
0.5 0.5 0.5 0.5 0.5 0.5 0.5
```

## 输出样例

```
2.00000000
```

## 样例解释

设老师第i天才来的概率是Pi，则：

P1=0.5，P2=（1-0.5）0.5，P3=（1-0.5）（1-0.5）0.5.......

也就是说Pi=P（前i-1天他都没有来）×P（他第i天来了），请记得星期日之后又是星期一。

那么E（P）= 1×P1+2×P2+3×P3+........ = 2.00000000

## 思路

一直模拟运算，直到小于了对应的精度为止

# `G` 因子数之和

时间限制：1000ms  内存限制：65536kb

通过率：57/87 `(65.52%) `  正确率：57/193 `(29.53%)`

## 题目描述

对于一个正整数a，它的因子数即它的所有因子的个数，包括1和它本身。例如2的因子数为2；6的因子数为4；9的因子数为3。现在给出正整数n，要你求出1到n的所有数的因子数之和。

## 输入

包括一行，一个整数n。

## 输出

包括一行，一个整数，表示1到n的所有数的因子数之和。

## 输入样例

```
4
```

## 输出样例

```
8
```

## 样例解释

对于样例，1的因子数是1，2的因子数是2,3的因子数是2,4的因子数是3。总计为8。

## 数据范围

保证3≤n≤100000。

## 思路

线性打表即可，对于整数k而言，其他所有k的倍数的值都要加上k

最后从1加到n就是解

# `H` 电话号码

时间限制：1000ms  内存限制：65536kb

通过率：75/87 `(86.21%) `  正确率：75/173 `(43.35%)`

## 题目描述

在X国，所有电话号码都形如8aaaaaaa，其中a为任意一位数字。也就是说，电话号码由8位组成，其中第一位必须是8。

某一天，bzb拿出了一串数字（长度为偶数），说它有可能是一串电话号码。此时在一旁的lyz表示不信。于是他们要进行一个游戏：每一轮由lyz先在这些数中拿走一个数，再由bzb在剩下的数中拿走一个数。请问bzb是否能够保证这样进行到数字只有8位的时候，是一个电话号码？

## 输入

包括两行，第一个整数n，表示这串数字的长度。

第二行n个一位数字，表示bzb找到的这串数字。

## 输出

如果bzb总是有办法让最后剩下一个电话号码，输出”YES”，否则输出”NO”。

## 输入样例1

```
10
8 8 8 1 2 3 4 5 6 7
```

## 输出样例1

```
YES
```

## 输入样例2

```
12
8 3 8 3 1 2 3 4 5 6 7 8
```

## 输出样例2

```
NO
```

## 样例解释

对于样例1，因为长度只有10，所以游戏只会进行一轮，不管lyz如何拿数，都不能把前面的3个8拿完。所以长度为8时一定是一个电话号码。

对于样例2，游戏会进行两轮，lyz只需要把第一个和第三个8拿走，剩下的数就不可能形成一个电话号码了。

## 数据范围

保证10≤n≤10000000。

## 思路

只要前面的n-7个数当中，拥有不少于(n-8)/2+1个8，即为YES，否则就是NO

# `I` 巧妙的分解

时间限制：1000ms  内存限制：65536kb

通过率：63/74 `(85.14%) `  正确率：63/125 `(50.40%)`

## 题目描述

对于连续正整数序列1到n，现在你需要把他们分成两部分。设两部分的和分别是sum1和sum2，你需要保证gcd(sum1,sum2)>1（其中gcd表示两个数的最大公因数）。如果找不到这样的分解，请输出”impossible!”。

## 输入

包括一行，一个整数n。

## 输出

如果找不到这样的分解，请输出”impossible!”(无引号)，占一行。

如果你找到了这样的分解，请在第一行输出”YES”(无引号)，之后的两行表示一个可以的方案：第一行第一个数a，表示第一个集合一共有多少个数，后面有a个数表示每个数；第二行一个数b，表示第二个集合一共有多少个数，后面有b个数表示每个数。

对于多个正确答案，你只需要输出任意一个。

## 输入样例1

```
3
```

## 输出样例1

```
YES
1 2
2 1 3
```

## 输入样例2

```
4
```

## 输出样例2

```
YES
2 1 3
2 2 4
```

## 样例解释

对于样例1，sum1=2，sum2=4，它们满足gcd(2,4)>1。

对于样例2，sum1=4，sum2=6，它们满足gcd（4,6）>1。同样你也可以把它们分解为（2）和（134），也就是说输出：

```
YES
1 2
3 1 3 4 
```

也被视为正确的。

## 数据范围

保证2≤n≤100000。

## 思路

如果n不大于2，那么无法满足条件

如果大于2是计数，把(n+1)/2单独拎出来，剩下的n-1个数为另一组，最大公约数就是(n+1)/2

如果大于2是偶数，把1和n拎出来，剩下的n-2个数为另一组，最大公约数就是n+1

# `J` 混和

时间限制：1000ms  内存限制：65536kb

通过率：74/77 `(96.10%) `  正确率：74/98 `(75.51%)`

## 题目描述

给出两个长度为n的序列ai和bi，令ci=ai+bi，那么c也是一个长度为n的由a和b决定的数列了。

现在你有机会改变序列b的元素顺序，使得新计算得到的c序列中奇数尽可能多，输出最多的奇数个数。

## 输入

包括三行，第一行一个整数n。

第二行n个数，表示数列ai。

第三行n个数，表示数列bi。

## 输出

输出一行，一个整数，表示c序列中最多可能的奇数个数。

## 输入样例

```
3
1 2 3
1 2 3
```

## 输出样例

```
2
```

## 样例解释

对于样例，把b数组改为2 1 3，与a数组相加得到3 3 6，其中有2个奇数，是最多可能情况。

## 数据范围

保证2≤n≤100000，1≤ai,bi≤1e9。

## 思路

min(数列1的偶数个数，数列2的奇数个数)+min(数列1的奇数个数，数列2的偶数个数)即为所求

# `K` 积木塔

时间限制：1000ms  内存限制：65536kb

通过率：57/61 `(93.44%) `  正确率：57/90 `(63.33%)`

## 题目描述

一天bzb和lyz搭起了积木塔(你可以百度一张积木塔图片看看)，并且玩起了积木塔游戏。游戏如下：

积木塔是一个多层的积木组成的塔，每一层有三个1×3的积木块，如果第一层横着摆三条成3×3的一层，那么第二层就需要竖着摆三条，第三层再需要横着摆三条...以此类推，交错摆放。由于bzb的手艺精湛，每一次的积木塔都是完美的。所谓完美的意思就是：中间的任何一层，只要中间第二块积木在，它就能支撑起上面所有的积木；只要第一、三块积木同时在，它们也能撑起上面所有的积木。如果任何一层中满足上面两条中的一条，那么这个积木塔就是稳定的，否则它将倒塌。

双方要轮流对积木塔块进行移除，每人每次移除某一层中一条积木，当某一方移除一条后积木塔不稳定就会倒下，该方也就失败了。

bzb眼疾手快决定先进行操作，之后lyz再进行操作。请问对于n层的积木(除了顶层不能操作以外，其他的n-1层都可以操作)bzb是否必胜？

## 输入

包括一行，一个整数n，表示积木塔的高度。

## 输出

如果bzb能够必胜，输出”YES”,否则输出”NO”。

## 输入样例

```
2
```

## 输出样例

```
YES
```

## 样例解释

对于样例，这是一个两层塔，也就是说只有最下面一层可以操作。第一次操作bzb只需要把最下层中间的一条移除，不管lyz如何操作都会失败。

## 数据范围

保证2≤n≤100000。

## 思路

偶数必赢，奇数必输

# `L` 降维打击

时间限制：1000ms  内存限制：65536kb

通过率：40/40 `(100.00%) `  正确率：40/67 `(59.70%)`

## 题目描述

有n只蚂蚁爬上了一个长度为m的很细很细的木棍（坐标0到m）。突然它们意识到了危险决定离开这条木棍，但是又没有人指挥，于是他们随便选了一个方向开始爬行。

已知蚂蚁的爬行速度是1，爬行方向只有+1和-1两种；由于木棍很细，如果两只蚂蚁相遇了，它们就会碰头然后各自掉头返回。当蚂蚁走到了0或m的位置，它就会掉下木棍，当爬行方向是+1时，每个单位时间蚂蚁的坐标将会+1(如果没相遇的话)。

请问所有蚂蚁都掉下木棍需要多长时间？

## 输入

包括n+1行，第一行两个整数n，m，如题。

以下每一行，两个整数xi和ai，表示一只蚂蚁的状态，其中xi表示这只蚂蚁的坐标，ai表示这只蚂蚁初次选择的行进方向，保证ai=1或ai=-1。

## 输出

输出一个整数，表示所有蚂蚁掉下木棍所需要的时间。

## 输入样例

```
2 3
1 1
2 -1
```

## 输出样例

```
2
```

## 样例解释

对于样例，两只蚂蚁将会在0.5单位时间相遇，再花0.5s回到自己最初的位置，但此时位于1的蚂蚁方向是-1，位于2的蚂蚁方向是+1，所以在下一时刻，它们分别到达了0和3，掉下了木棍。

## 数据范围

保证2≤n，m≤100000。保证没有蚂蚁初始位置相同。

## 思路

**每一只蚂蚁的具体移动轨迹我们无需知道，假如两个蚂蚁碰面交换方向了，我们也可以等价于两只蚂蚁穿过了彼此**

那么很容易发现，每只蚂蚁的运动时间只和初始的坐标有关，坐标x，方向往左就需要x，方向往右就是L-x

取最大值即可

# `M` 均匀守卫

时间限制：1000ms  内存限制：65536kb

通过率：39/42 `(92.86%) `  正确率：39/68 `(57.35%)`

## 题目描述

有n个守卫护卫一个长度为n+m个单位的圆形边界的宫殿，他们在圆周上的位置均匀，即每相邻两个人之间的距离都是(n+m)/n。现在国王要加派m名守卫，和之前的n位一起守卫宫殿，同样的，这n+m个守卫也要在圆周上位置平均，即相邻两个人之间的距离是1，那么原有的n名卫士就可能会改变位置。现在希望你计算一种改变位置的策略，使得原有的n名卫士的位置变化之和最少。即原有的卫士移动的最少。

## 输入

包括一行，两个整数n，m如题。

## 输出

输出一个实数，原有的n名卫士移动的最小距离和。你的答案与标准答案误差小于0.001时即会被视为正确。

## 输入样例1

```
2 2
```

## 输出样例1

```
0.000000000000000
```

## 输入样例2

```
3 1
```

## 输出样例2

```
0.666666666666667
```

## 样例解释

对于样例1，最开始有两名守卫，加派两名守卫后，之前的两名并不需要移动，所以距离和为0。

对于样例2，假设三人为ABC，令A不动，B和C分别移动到A的左右两端，新加入的守卫站到A的对面，此时距离和最小。B移动的距离为4/3-1，C移动的距离为3-8/3。

## 数据范围

保证1≤n+m≤100000。

## 思路

数学题，具体的思路在代码当中，不再赘述

# `N` 涂鸦

时间限制：1000ms  内存限制：65536kb

通过率：20/38 `(52.63%) `  正确率：20/119 `(16.81%)`

## 题目描述

有一天xx接触到了涂鸦，它发现涂鸦是一种不断覆盖的有趣游戏。

于是他开始闭着眼睛刷一面n×m的墙，他一共会进行k次操作，他的每次操作只能涂一整行或者涂一整列，当然涂成什么颜色要看心情的。其中所有颜色都是正整数。最开始这面n×m的墙上都是0号颜色。

我们会用一行三个数op、num、color来描述他的一个操作：当op=1时，他是涂了一整行，其中num是这一行的行号，其中color是所涂的颜色，也即此时这一行都会变成color所表示的颜色；当op=2时，他是涂了一整列，同样的num是列号，color是涂色。

你需要直接告诉xx这面墙在他的胡乱操作之后变成了什么样子。

## 输入

包括k+1行，第一行三个整数n，m，k如题。

以下k行，每行三个整数op、num、color，描述xx的一次操作。

## 输出

输出一个n×m的矩阵，n行m列，每行元素用空格隔开。

## 输入样例1

```
2 2 2
1 1 1
2 1 2
```

## 输出样例1

```
2 1
2 0
```

## 输入样例2

```
5 3 4
1 1 2
1 3 2
2 2 3
1 5 4
```

## 输出样例2

```
2 3 2
0 3 0
2 3 2
0 3 0
4 4 4
```

## 样例解释

对于样例1，第一次将第一行涂成了颜色1，第二次将第一列涂成了颜色2，此时(1,1)的位置被覆盖成了颜色2。而(2,2)没有被涂过，保持0。

## 数据范围

保证1≤n×m≤100000，2≤k≤100000，1≤color≤1000。

## 思路

这是一个建模优化的问题，暴力做法必然是行不通的

那么我们可以考虑，**实际上真正的最终颜色，只有最晚涂在这个方格上面的那次操作**

**再考虑到面积的限制，我们完全可以只开一个100000的数组，做好行列坐标与实际下标的映射，然后倒着涂色，一旦涂上了就做标记，之后不再涂色即可**

# `O` 合理分配

时间限制：1000ms  内存限制：65536kb

通过率：22/28 `(78.57%) `  正确率：22/130 `(16.92%)`

## 题目描述

一天xx拿着n个并不完全相同的派，准备平分给他的m位同学们。

同学和xx的要求是一致的，希望与别人获得同样大小的派，但是每个人拿到的都只能是一块派（可以是某个派上切下来的），而不能是多个派拼在一起。这对他们来说是一个很难计算的问题，希望你帮他们算出每个人最多可以拿到多大面积的派？（注意本题是要平均分给m+1个人的。）

## 输入

包括两行，第一行两个整数n，m如题。

第二行空格隔开的n个整数，表示n个派各自的面积ai。

## 输出

输出一个实数，每个人最多能拿到的派的大小。你的答案与标准答案的误差小于0.001即认为是正确的。答案将确保前10位小数精确。

## 输入样例1

```
2 1
1 3
```

## 输出样例1

```
1.50000000
```

## 输入样例2

```
3 4
1 2 4
```

## 输出样例2

```
1.00000000
```

## 样例解释

对于样例1，一共有两个人要分两个派，最佳策略是丢掉面积为1的派，两个人平分面积为3的派。

对于样例2，一共有五个人要分三个派，任何大于1的答案都只能使面积为2的派分出1份，面积为4的派分出≤3份，不能够凑齐五份。

## 数据范围

保证1≤n，m≤10000，1≤ai≤10000。

## 思路

二分答案

换言之，就是判断，如果所有的人都分到相同分量的派，其中的最大可行解是什么

# `P` 轰炸坦克

时间限制：1000ms  内存限制：65536kb

通过率：20/28 `(71.43%) `  正确率：20/59 `(33.90%)`

## 题目描述

在某一条线段区域上出现了若干坦克，坐标为1到n(保证n>1)。之所以说坐标是1到n，是因为我们也不知道坦克在哪，只知道每一辆都是在1到n闭区间的某个整数点上。

最开始坦克静止在自己的初始点上。现在你可以选若干点开始轰炸。

你轰炸的点x上如果有一辆没有被轰炸过的坦克，你的攻击会使这个坦克受损，并且这辆坦克会向x-1或者x+1两点逃窜，当然如果它在x=1处被轰炸，它就只能向x=2处逃窜，x=n的时候同理；如果你轰炸的点上有一辆受损的坦克，你的攻击会使这个坦克被销毁，此时坦克就不会再移动了。

现在给出线段的长度n，问你需要至少多少次轰炸才能让所有坦克都被销毁，也就是任意位置的坦克、无论逃窜到何处，都需要被轰炸两次。并输出一个合理的轰炸方案。

## 输入

包括一行，一个整数n如题。

## 输出

输出两行，第一行一个整数m，表示你需要m次轰炸。

第二行m个数，表示这m次轰炸你选择的轰炸位置。

## 输入样例1

```
2
```

## 输出样例1

```
3
1 2 1
```

## 输入样例2

```
3
```

## 输出样例2

```
4
2 1 3 2
```

## 样例解释

对于样例1，在两个位置都可能有坦克，轰炸1之后，2处可能有完整的坦克和受损的坦克，在轰炸2之后，2处不会有未被销毁的坦克，而1处可能会有2处逃窜来的受损坦克，所以需要再轰炸1一次。一共三次。当然，如果你选择轰炸2 1 2也是正确的答案。

对于样例2，在2处轰炸后只会在1、3处有坦克，对13轰炸后，只会在2处有受损的坦克，再对2进行轰炸。一共四次。

## 数据范围

保证2≤n≤100000。

## 思路

首先轰炸次数是1.5n向下取整

具体来说就是从1到n，从n到1，再从1到n来回3次单程，每一次都是以2位间隔进行轰炸

然后根据n是偶数还是奇数，具体决定轰炸的坐标

不过说回来，助教们搞的这个SPJ真的还是很用心的，真的辛苦助教了

# `Q` 合数分解

时间限制：1000ms  内存限制：65536kb

通过率：29/32 `(90.63%) `  正确率：29/63 `(46.03%)`

## 题目描述

给出一个数n，尝试把n分解成最多的合数之和，如果n不能被分解为合数之和，输出-1。

## 输入

包括一行，一个数n。

## 输出

输出一个整数m，表示n最多能被分解为m个合数之和，或者m=-1表示n不能被这样分解。

## 输入样例1

```
12
```

## 输出样例1

```
3
```

## 输入样例2

```
5
```

## 输出样例2

```
-1
```

## 样例解释

对于样例1，12=4+4+4，这是12的最多合数分解。

对于样例2，数字5不可能被分解为合数之和。

## 数据范围

保证1≤n≤10000000000。

## 思路

合数最多的情况，必然是分成4 6 9，然后分类讨论就行

# `R` 最长平衡子串

时间限制：1000ms  内存限制：65536kb

通过率：20/39 `(51.28%) `  正确率：20/150 `(13.33%)`

## 题目描述

对于一个只由0和1组成的串，定义平衡串为：0和1的个数相同的串。

现在给出一个长度为n的01串，求它的连续子串中最长平衡子串的长度。

## 输入

包括两行，第一行一个整数n，表示串长。

第二行，用空格隔开的n个数，0或1。

## 输出

输出一个整数，这个串中最长平衡子串的长度。

## 输入样例1

```
5
1 1 0 1 0
```

## 输出样例1

```
4
```

## 输入样例2

```
7
1 0 1 1 1 1 0
```

## 输出样例2

```
2
```

## 样例解释

对于样例1，取后四位1010，是最长平衡子串。

对于样例2，取[1,2]或者[2,3]或者[6,7]，都是长度为2的平衡子串。

## 数据范围

保证1≤n≤100000。

# `S` 试毒

时间限制：1000ms  内存限制：65536kb

通过率：19/28 `(67.86%) `  正确率：19/89 `(21.35%)`

## 题目描述

现有n瓶水，其中有且仅有一瓶有毒。用小白鼠去试毒。小白鼠在喝到有毒的水后，会在1天内死亡。现在你只有一天的时间，需要通过死亡情况来判断有毒的水的编号。

可以认为每瓶水都是无限的，每一只小白鼠都可以喝任意多瓶水且不消耗时间。

你需要输出最少需要用多少只小白鼠才能完成这件事情。并且输出一个可以判断的试毒方案。注意，水的编号是从

## 输入

包括一行，一个整数n，表示一共有n瓶水。

## 输出

输出k+1行，第一行一个数k，表示你需要k只小白鼠。 以下第i+1行，代表第i只小白鼠要喝的水。开头一个数字m，表示第i只小白鼠要喝m瓶水，后面m个数字，说明这m瓶水的编号。

## 输入样例

```
3
```

## 输出样例

```
2
1 1
1 2
```

## 样例解释

对于样例，一共有三瓶水，需要两只小白鼠。令1号小白鼠喝1,2号小白鼠喝2，如果都没有死亡说明3号水有毒。 当然，如果你选择1号小白鼠喝1和2,2号小白鼠喝1，也是可以的。也就是输出

```
2
2 1 2
1 1 
```

这样的合理策略有很多。你只需要输出其中的一种。

## 数据范围

保证1≤n≤10000。

## 思路

非常经典的二进制问题

假如说判断13有没有毒，13的二进制是1101，从低到高位进行表示，只要让1号3号4号老鼠喝下去即可

然后死掉的所有老鼠进行二进制表示

假如说1号3号4号5号老鼠死了，表示出来就是11101，那么就能看出来是29号有毒

**所以答案就是n-1表示成二进制有多少位**

**注意:答案不是n有多少二进制位!比如说8瓶的话，不需要准备4只老鼠，只要3只老鼠都没毒死，就可以确认8号瓶子有毒了**

