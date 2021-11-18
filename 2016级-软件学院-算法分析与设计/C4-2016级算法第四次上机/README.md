# C4-2016级算法第四次上机

# AlvinZH的1021实验

时间限制: 100 ms 内存限制: 65536 kb

总通过人数: 170 总提交人数: 172

## 题目描述

听说学弟学妹们这学期有物理实验，不禁让AlvinZH想起了那个靠手速的1021实验，实验开始前需要称量各种实验用品的重量，比如冰块。假设称量的器具只有一个天平和一些砝码，这些砝码有着特殊的重量，分别是1g、3g、9g、27g、81g、243g，每种砝码都只有一个。

有一件神奇的事是：只用这些砝码，你可以称得任意不超过364g的整数克冰块，而且只有一种方法，你来想一想是如何做到的吧！

//听说现在都改为电子秤了，搬走就换新装备系列qwq

## 输入

输入包括多组数据。

每组数据只有一个正整数n，代表要称量的冰块重量（1≤n≤364）。

## 输出

对于每组数据，输出一行字符串，表示称得此重量的方法，数字从高到低排列（具体见样例）。

## 输入样例

```
1
5
364
```

## 输出样例

```
1
9-3-1
243+81+27+9+3+1
```

## 思路

**直接贪心即可，已知了所要用到的就几种砝码之后，就一点点往下递减，因为这几种砝码不互质，所以可以一趟贪心直接算出需要哪些不需要哪些。输出的时候需要注意一下如何输出正负号即可**

# AlvinZH的1021实验plus

时间限制: 100 ms 内存限制: 65536 kb

总通过人数: 139 总提交人数: 144

## 题目描述

AlvinZH凭着惊人的手速，快速做完了1021实验（不快不行sad）。看看时间竟然才过去一个小时，于是他开始继续玩他的砝码。

AlvinZH桌子上已经有一个天平和一些砝码，AlvinZH认为如果在天平两端都放置砝码，需要做减法，那太复杂了，他决定在天平一端只放置物品，另一端只放置砝码。

AlvinZH现在想称得从**[1~m]**之间的每个**整数质量**的物品，但他发现现有的砝码不够用，假设AlvinZH可以从实验箱里找到各种质量的砝码，请你帮他计算一下最少需要寻找多少个砝码。

## 输入

输入包括多组数据。

每组数据第一行为初始砝码数n和想称得的最大质量m（0≤n≤1000，1≤m≤INT32_MAX）。

接下来一行包含n个数字，为现有的砝码的质量 mi （1 ≤ mi ≤ INT32_MAX）。

## 输出

对于每组数据，输出一行，为需要寻找的最小砝码数。

## 输入样例

```
2 6
1 3
3 5
1 2 2
3 20
1 5 10
```

## 输出样例

```
1
0
2
```

## 样例解释

样例一：初始只能称得[1]、[3]、[1+3]，并不能称得[1~6]之间的所有质量，只需要寻找一个质量为2的砝码就可以了。（[1]、[2]、[3]、[1+3]、[2+3]、[1+2+3]）。

样例二：初始可以称得[1]、[2]、[1+2]、[2+2]、[1+2+2]，不需要寻找新的砝码。

样例三：初始可以称得[1]、[5]、[1+5]、[1+10]、[5+10]、[1+5+10]，需要寻找质量为2和4的砝码就ok。

最小数目一定存在，但是方法可能不同。

## 思路

**本题依旧是一个贪心，只不过比上一个稍微难想一些**

**首先需要注意的坑点就是，砝码只能放在一边，这和前一个题不同**

说白了就是最大化的进行范围的覆盖

**我们假设a=当前未被覆盖的最小数字，初始值是1，那么初始覆盖区间为[1,a)**

**目标要求覆盖[1,m] 那么需要上述的a最终大于m，然后需要比较a和数组当中没有遍历过的数字当中的最小值x进行比较（这意味着数据预处理需要排序）**

- **如果a更小，这说明当前没有组合可以覆盖a，所以必须插入a，这个时候覆盖区间为[1,2a)**
- **如果a更大，则说明可以覆盖[1,a),那么算上当前的x之后，覆盖区间变为[1,a+x)**

**最终当a>m之后就结束了**

# Bamboo and the Ancient Spell

时间限制: 1000 ms 内存限制: 65536 kb

总通过人数: 150 总提交人数: 157

## Problem description

The Hogwarts has set up a new course recently, giving you the ancient spells and requiring you to translate them into the modern ones. Every two ancient spells encode one modern spell.

Wizards and witches just point the ancient spells with the magic wands and speak loudly "THE LONGEST COMMON SUBSEQUENCE !", and they'll get the modern spell required：）

Ok, stop trying this muggles...Though we can't get the answers as quickly as they do, we can still decode them by coding ：）

So Bamboo will give you a lot of ancient spells( two in a group)，and hope you just return the LENGTH of the modern spell.

Attention please! The ancient spells may include strange characters '#' and '?'. They are too old to know their exact meanings, so we can just think that '#'s can not match any character while finding the answer, but '?' can match any character in the other ancient spell except '#'.

## Input

The input file consists of several test cases.

Each test case includes 2 lines, one ancient spell per line.

The length of per ancient spell will less than 100 characters，and all characters are in upper case.

## Output

For each case, output one line: the length of the modern spell.

## sample input

```
ABCDE
ZBD
AC#EB
C#BFG
ACE#?
KIKI#A
???
?#?
```

## Sample output

```
2
2
1
2
```

## A TIP

emmmm, Can you guess what 'spell' means here? And what about the modern spells? Pay attention to what wizards and witches say when they use magic.

## Another TIP

In case 2, '#' can not match any character, just like it doesn't exist, so the modern spell is "CB".

In case 3, '?' can match any character except '#', which means '?' can be seen as ‘A~Z' and '?' of course.

## 思路

**经典的LCS，但是需要更改条件，也就是在遇到两者都是#，或者两者都不是#的时候，要么两者相等，要么其中一个是问号，都可以使用LCS状态转移当中dp(i, j)=dp(i-1, j-1)+1这个选项**

