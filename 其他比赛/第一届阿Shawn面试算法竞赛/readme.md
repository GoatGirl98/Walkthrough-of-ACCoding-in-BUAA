# No.1 Shawn's friends' Interview Algorithm Contest

# `A` Who hasn't sign up

时间限制：1000ms  内存限制：65536kb

通过率：9/10 `(90.00%) `  正确率：9/16 `(56.25%)`

## Description

Shawn has several friends who join the leetcode contest weekly.

Now as you know , Shawn holds a contest. He knows each friend's id and he hears one of them haven't join. Could you tell him who hasn't join yet?

Every ID is a unique string which contains uppercase / lowercase / digits. Maximum length is 24.

## Input

First line contains a number N ( $1\le N\le 10^4$ )

Next N lines would contain 1 unique ID , maximum length 24, which indicates the friends' ids

Next N -1 lines would contain 1 unique ID , which indicates the friends who are already joined. ( No one joins twice)

## Output

Output a line which contains the ID which hasn't sign in yet.

## 输入样例

```
4
Yu
Weidong
Nero
Peng
Peng
Yu
Nero
```

## 输出样例

```
Weidong
```

## 思路

直接字符串哈希+异或就行了

# `B` Minimal edit distance to a string's prefix

时间限制：2500ms  内存限制：204800kb

通过率：3/5 `(60.00%) `  正确率：3/13 `(23.08%)`

## Discription

You are given two non-empty string, str1 and str2

Return the minimum number of character edits (insert, delete, change) until str1 becomes str2's prefix.

## Input

One line with 2 strings, separated by space

$1≤str1.length()≤2000$

$1≤str2.length()≤2000$

'a' <= ch <= 'z', for any ch in str1 & str2

## Output

An integer

## Sample input 1

```
abc abc
```

## Sample output1

```
0
```

## Sample input 2

```
ac abcd
```

## Sample output2

```
1
```

## Sample input 3

```
babce abcde
```

## Sample output 3

```
2
```

## 思路

编辑距离变种题

回想一下基础的 $dp[i][j]$ 表示的就是 $A[1,...,i]$ 与 $B[1,...,j]$ 之间的编辑距离，那么这题改一改就有了

# `C` Weidong's minimum working hours

时间限制：1000ms  内存限制：65536kb

通过率：3/3 `(100.00%) `  正确率：3/8 `(37.50%)`

## Description

Weidong has N works need to be finished in next K days. Each work costs Ni hours and should be done in one day. (i.e. you cannot split a work into different days). Also, works should be done in the given order. Weidong wants to know what is minimum maximum working hour that he need to work on next K days.

$1≤N≤10^5,1≤K≤10^9,1≤Ni≤10^5$

## Input

For each test case, input consists of $N+1$ lines.

First line contains two number: $N K$.

In following N lines, each line contains an integer.

## Output

One line contains the result.

## Sample input 1:

```
4 2
1
3
2
2
```

## Sample output 1:

```
4
```

You can finish 0-th and 1st work to first day, then finish 2nd and 3rd work on second day.

## 思路

二分答案，直接根据当前答案搜索，如果可以按照这个贪心分段，即为合法。

找到合法答案的最小值即可

# `D` Longest Increasing Subsequence in a matrix - Easy

时间限制：3000ms  内存限制：65536kb

通过率：3/4 `(75.00%) `  正确率：3/11 `(27.27%)`

## Description

Given a non empty M x N matrix with numbers. Starting from row 0 to row M-1.

You can pick at most one number from each row.

Find the max length of longest increasing sequence. 

## Input

First line contains a number M

Second lines contains a number N

The rest M lines would have N number each line separated by space

## Output

Output a number indicates the answer

## Sample Input 1

```
4
4
2 2 1 4
10 6 4 8
3 7 9 10
3 3 3 9
```

## Sample Output 1

```
4
```

## Hint 1

[2 , 6 , 7 , 9]

## Sample Input 2

```
3
3
1 1 1
1 1 1
1 1 1
```

## Sample Output 2

```
1
```

## Sample Input 3

```
4
3
1 1 1
3 3 3
2 2 2
4 4 4
```

## Sample Output 3

```
3
```

## Hint 3

[1 , 3 , 4] would be the answer

## Constraints

$1≤M∗N≤4000$

$−10^4≤Matrix_{ij}≤10^4$

## 思路

本题是一个二维矩阵上，每一行选择一个元素的最长上升子序列的问题

回想 $O(n\log n)$ 的LIS问题解决方式，我们可以通过类似的方式来完成本题。

在每读取一行之后，我们先直接对其排序，然后在当前的tail数组上进行更新，每一个元素都进行一次二分查找，但是需要注意维护一下当前的LIS长度是多少

如果确认新的一行当中可以让LIS长度加1，那么就将对应的`upper_bound`元素放到tail就好了

然后从LIS长度往下尽可能最小的更新tail数组即可，复杂度 $O(nm\log n)$

# `E` Optimization on matrices multiplication

时间限制：1000ms  内存限制：65536kb

通过率：3/4 `(75.00%) `  正确率：3/5 `(60.00%)`

## Description

In data science, the features can be represented in Matrix format, so it’s common to handle multiple matrices multiplication.

For instance, we have three matrices A1, A2, A3 have dimensions of 10x100, 100x5 and 5x50. If we perform the multiplication from left to right, i.e., (A1A2)A3, the total counts would be 10x100x5+10x5x50=7500, since (A1A2) will have the dimension of 10x5.

Another way of doing this is A1(A2A3), similarly, the counts would be 100x5x50+10x100x50=75000 which is 10x the first method.

So, given the number of matrices(n) and the dimension of each matrix(row col), assuming they are valid), please provide the optimal way in handling the multiplication that returns the minimum counts.

## Input

First line an integer n indicates the number of matrixes.

The rest of n lines has 2 number indicate the dimension

## Output

An integer

## Sample Input 1

```
3
10 100
100 5
5 50
```

## Sample Output 1

```
7500
```

## Sample Input 2

```
6
30 35
35 15
15 5
5 10
10 20
20 25
```

## Sample Output 2

```
15125
```

## Constrains

```
1 <= N <= 100
1 <= A.row <= 100
1 <= A.col <= 100
```

## 思路

矩阵链乘dp经典问题

# `F` Find Good Reverse Tuple

时间限制：1000ms  内存限制：65536kb

通过率：3/5 `(60.00%) `  正确率：3/8 `(37.50%)`

Time limit 1s, space limit 256MB

## Description

Suppose we have a function revNum(num), which can reverse the digits of num. For example, revNum(789) = 987 and revNum(10) = 1.

Now given a list of non-negative integers nums, consider a tuple of indices (i, j, k), where i < j < k, we say the tuple is Good Reverse Tuple if it satisfies nums[i] + nums[j] + nums[k] = revNum(nums[i]) + revNum(nums[j]) + revNum(nums[k]).

Please return the number of Good Reverse Tuple.

## Input

The fine line is a number n (3 <= n <= 1000), means the length of the sequence. The second line contains a sequence of n integers. Each integer is in the range [0, 1000].

## Output

Print the number of Good Reverse Tuple.

## Sample Input 1

```
4
21 17 5 23
```

## Sample Output 1

```
1
```

## Sample Input 2:

```
3
3 24 15
```

## Sample Output 2:

```
0
```

## 思路

本题数据范围较小，直接暴力就完事了

# `G` DS = Data structure of Shawn's

时间限制：1000ms  内存限制：65536kb

通过率：1/1 `(100.00%) `  正确率：1/1 `(100.00%)`

## Description

Shawn has a magical data structure.

Originally it takes an array of Integers (1-based index ) AA whose length is nn , and it supports these operations:

###### Modify a number

` M p x ` means update $A[p]=x$

###### Segment Division

` D L R x ` which enumerate every number index from L to R inclusive , divide each number by xx ( integer division , $3/2=1 , 5/10=0 $)

###### Segment Sum Query

` Q L R ` you need to output the sum for number from L to R inclusive. Basically $A[L]+A[L+1]+...+A[R]$

### Input

First line 1 number $n$.

Second line $n$ numbers $A_i$.

Third line 1 number $m$.

The rest of mm lines , each line contains an operation.

$1≤n,m≤10^5$

$1≤Ai,x≤10^9$

$1≤L,R,p≤n$

### Output

For each query , output a number indicates the answer.

### Sample Input

```
5
1 2 3 4 5
4
Q 1 3
D 1 3 2
M 2 2
Q 1 3
```

### Sample Output

```
6
3
```

## 思路

单点赋值/区间向下取整的除法，第一时间我们可以想到线段树

虽然除法自身不好维护，但是我们可以利用数论中除法分块的性质，维护区间的最大值和最小值，在满足一定条件时，将除法当做减法来处理即可

赋值也可以先查询再减法再加法这样处理，因为没必要为了常数优化再搞一个tag，增加编程成本

最简便的做法是参照 https://github.com/GoatGirl98/Walkthrough-of-ACCoding-in-BUAA/issues/2 中出题人描述的思路，由于每个数字最多被除 32 次就变成 1 ，于是乎我们可以记录每一段最大值，如果 > 1 就暴力更新除法。

# `H` Longest Increasing Subsequence in a matrix - Hard

时间限制：2000ms  内存限制：65536kb

通过率：2/2 `(100.00%) `  正确率：2/2 `(100.00%)`

## Description

Given a non empty M x N matrix with numbers. Starting from row 0 to row M-1.

You can pick at most one number from each row.

Find the max length of longest increasing sequence. 

## Input

First line contains a number M

Second lines contains a number N

The rest M lines contains 3 numbers , for ith line:

Matrixi0Matrixi0 , A , B , C.

Which means the first element of the row Matrixi0Matrixi0 , for the rest of elements ( 1≤j<n1≤j<n )

```
Matrix[i][j] = (Matrix[i][j - 1] * A + B) % C
```

## Output

Output a number indicates the answer

## Sample Input

```
4
6
2 4 9 7
1 3 2 8
4 8 5 33
10 8 7 22
```

## Sample Output

```
4
```

## Hint 1

Original matrix would look like

```
[2, 3, 0, 2, 3, 0]
[1, 5, 1, 5, 1, 5]
[4, 4, 4, 4, 4, 4]
[10, 21, 21, 21, 21, 21]
```

## Constraints

$1≤M,N≤1000$

$1≤Matrix_{i0},A,B,C≤10^4$

## 思路

和上面的题一模一样，直接可以做出来

# `I` Nero's Key Board

时间限制：500ms  内存限制：65536kb

通过率：6/8 `(75.00%) `  正确率：6/16 `(37.50%)`

## Description

Normally when we type in keyboard, character can be either upper-cased or lower-cased. and the way we type upper-cased letter is by pressing CAP or SHIFT.

Assuming we need to type a sequence of character, and we would like to find out the minimum number of clicks to type out sequence of characters.

The rules to calculate clicks is as follows:

- 1. one character + 1
- 2. one CAP + 1
- 3. one SHIFT + 1

General rules:

- 1. at the beginning, we all start by type letters in lower-cased
- 2. one click on CAP will change all the following letters to upper-cased unless press on CAP again
- 3. one SHIFT only will make the next letter to be upper-cased.

Constraints:

- 1. input is always valid, only \[a−zA−Z\]
- 2. input is never empty
- 3. 1 <= length <= 20002000.

## Input format

a single string in each following lines, standing for a single test case

## Output format

an integer

## Sample Input 1

```
aaa
```

## Sample Output 1

```
3
```

## Sample input 2

```
aAa
```

## Sample Output 2

```
4 
```

## Sample Input 3

```
aAAAAAAAa
```

## Sample Output 4

```
11
```

## 思路

切换大小写的时候，如果连续的大写或者小写字符在2以上，按CAP切换，否则直接shift

但是需要记住，有些时候CAP不需要切换回来，这也是本题的Corner case
