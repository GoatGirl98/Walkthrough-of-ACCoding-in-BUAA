#include<iostream>
#include<algorithm>
#include<climits>
#include<stack>
#include<ctime>

using namespace std;

/*
先写一下递归算法的效果：

需要实现的递归函数为hanoi(n,A,B,C) 逆时针
C为中点B为中转 分别经过hanoi(n-1,A,C,B) 顺时针 move A->C hanoi(n-1,B,A,C) 顺时针

将A->B->C->A算为顺时针(L)，A->C->B->A算为逆时针(R)，中间操作算作一般操作(O)

n为奇数的时候，顺时针产生的移动序列为L,O,L,O,...,L 逆时针产生的移动序列为R,O,R,O,...,R
n为偶数的时候，顺时针产生的移动序列为R,O,R,O,...,R 逆时针产生的移动序列为L,O,L,O,...,L

非递归要想实现此效果，在数学上是需要分奇偶情况进行讨论的：
0.n=1，n=2的时候首先要成立
1.当n为奇数的时候，产生的两个n-1递归子程序均属于偶数圆盘逆时针移动的问题，产生的移动序列就是顺时针的
2.当n为偶数的时候，产生的两个n-1递归子程序均属于奇数圆盘逆时针移动的问题，产生的移动序列就是逆时针的
其逆时针递归算法也是相同的，都是等价的

这道题的终点是C，所以要产生的实际逆时针移动的情况
偶数的时候，则按照顺时针的方向依次摆放A B C
奇数的时候，则按照逆时针的方向依次摆放A C B

具体实现思路：
按顺时针方向把圆盘1从现有柱子挪到下一根，然后当n偶数的时候
圆盘1在A则挪到B，在B挪到C，在C挪到A
再将另外两根柱子上可以移动的圆盘移动到新柱子上
也就是将非空柱子上的圆盘移动到空柱子上，两根都非空则移动较小的圆盘
(虽然没有明确规定哪个圆盘，但是可以完成的行动是唯一的)

*/

struct stackWithName {
    stack<int> tower;
    char name;
}HanoiTower[3];

int T;
int n;
long long step;//提前知道要挪的步数就是2^n-1
long long current;//当前走过的步数

int main() {
    //clock_t start, finish;
    
    ios::sync_with_stdio(false);

    //scanf("%d", &T); T--
    while (scanf("%d", &n)!=EOF) {

        //scanf("%d", &n);
        //输入n之后，就要开始构造汉诺塔了

        HanoiTower[0].name = 'A';
        //所有圆盘从大到小按顺序放在A上，序号从1到n
        for (int i = 0; i < n; ++i) {
            HanoiTower[0].tower.push(n - i);
        }
        //偶数的时候，则按照顺时针的方向依次摆放A B C
        if (n % 2 == 0) { HanoiTower[1].name = 'B'; HanoiTower[2].name = 'C';}
        //奇数的时候，则按照逆时针的方向依次摆放A C B
        else { HanoiTower[1].name = 'C'; HanoiTower[2].name = 'B'; }
        //构造结束

        step = ((long long)1 << n) - 1;
        printf("%lld\n", step);
        current = 0;

        int i = 0;//当前的塔
        int curPlace;

        while (current < step) {

            //step 1 按照顺时针方向，把圆盘1从现在的盘子往下挪
            curPlace = HanoiTower[i % 3].tower.top();
            HanoiTower[i % 3].tower.pop();
            //STL当中，出栈仅仅出栈，而不返回对应值
            HanoiTower[(i + 1) % 3].tower.push(curPlace);
            ++current;

            /*
            printf("step %lld : ", current);
            printf("Move ");
            printf("Number %d ", curPlace);
            printf("from %c to %c\n", HanoiTower[i % 3].name, HanoiTower[(i + 1) % 3].name);
            */
            printf("%d ", curPlace);
            printf("%c->%c\n", HanoiTower[i % 3].name, HanoiTower[(i + 1) % 3].name);



            ++i;
            if(i > 3)i %= 3;//此处不能无脑模，i-1如果为-1就越界了，gg

            //step 2 另外两根柱子将可移动的圆盘移动到新柱子上，首先要没用完移动次数

            if (current < step) {
                //非空柱子上的圆盘挪到空柱子上，两根都非空则先挪序号较小的圆盘
                if (HanoiTower[(i + 1) % 3].tower.empty() ||
                    (!HanoiTower[(i - 1) % 3].tower.empty()) &&
                        HanoiTower[(i + 1) % 3].tower.top() > HanoiTower[(i - 1) % 3].tower.top()) {

                    curPlace = HanoiTower[(i-1)%3].tower.top();
                    HanoiTower[(i-1)%3].tower.pop();
                    HanoiTower[(i+1)%3].tower.push(curPlace);
                    ++current;
                    /*
                    printf("step %lld : ", current);
                    printf("Move ");
                    printf("Number %d ", curPlace);
                    printf("from %c to %c\n", HanoiTower[(i-1)%3].name, HanoiTower[(i+1)%3].name);
                    */
                    printf("%d ", curPlace);
                    printf("%c->%c\n", HanoiTower[(i-1)%3].name, HanoiTower[(i+1)%3].name);


                }
                else {
                    curPlace = HanoiTower[(i+1) % 3].tower.top();
                    HanoiTower[(i+1) % 3].tower.pop();
                    HanoiTower[(i-1) % 3].tower.push(curPlace);
                    ++current;
                    /*
                    printf("step %lld : ", current);
                    printf("Move ");
                    printf("Number %d ", curPlace);
                    printf("from %c to %c\n", HanoiTower[(i+1) % 3].name, HanoiTower[(i-1) % 3].name);
                    */
                    printf("%d ", curPlace);
                    printf("%c->%c\n", HanoiTower[(i+1)%3].name, HanoiTower[(i-1)%3].name);

                }
            }
        }
        //printf("Finished!\n");
        for (i = 0; i < 3; ++i) {
            while (!HanoiTower[i].tower.empty())
                HanoiTower[i].tower.pop();
        }
    }


}
