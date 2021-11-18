#include<iostream>
#include<algorithm>
#include<climits>
#include<stack>
#include<ctime>

using namespace std;



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
    while (scanf("%d", &n) != EOF) {

        //scanf("%d", &n);
        //输入n之后，就要开始构造汉诺塔了

        HanoiTower[0].name = 'A';
        //所有圆盘从大到小按顺序放在A上，序号从1到n
        for (int i = 0; i < n; ++i) {
            HanoiTower[0].tower.push(n - i);
        }
        //偶数的时候，则按照顺时针的方向依次摆放A B C
        if (n % 2 == 0) { HanoiTower[1].name = 'B'; HanoiTower[2].name = 'C'; }
        //奇数的时候，则按照逆时针的方向依次摆放A C B
        else { HanoiTower[1].name = 'C'; HanoiTower[2].name = 'B'; }
        //构造结束

        step = ((long long)1 << n) - 1;
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
            if (!(n % 2))printf("%d:%d:%d\n", HanoiTower[0].tower.size(), HanoiTower[1].tower.size(), HanoiTower[2].tower.size());
            else printf("%d:%d:%d\n", HanoiTower[0].tower.size(), HanoiTower[2].tower.size(), HanoiTower[1].tower.size());


            ++i;
            if (i > 3)i %= 3;//此处不能无脑模，i-1如果为-1就越界了，gg

            //step 2 另外两根柱子将可移动的圆盘移动到新柱子上，首先要没用完移动次数

            if (current < step) {
                //非空柱子上的圆盘挪到空柱子上，两根都非空则先挪序号较小的圆盘
                if (HanoiTower[(i + 1) % 3].tower.empty() ||
                    (!HanoiTower[(i - 1) % 3].tower.empty()) &&
                    HanoiTower[(i + 1) % 3].tower.top() > HanoiTower[(i - 1) % 3].tower.top()) {

                    curPlace = HanoiTower[(i - 1) % 3].tower.top();
                    HanoiTower[(i - 1) % 3].tower.pop();
                    HanoiTower[(i + 1) % 3].tower.push(curPlace);
                    ++current;
                    /*
                    printf("step %lld : ", current);
                    printf("Move ");
                    printf("Number %d ", curPlace);
                    printf("from %c to %c\n", HanoiTower[(i-1)%3].name, HanoiTower[(i+1)%3].name);
                    */
                    if (!(n % 2))printf("%d:%d:%d\n", HanoiTower[0].tower.size(), HanoiTower[1].tower.size(), HanoiTower[2].tower.size());
                    else printf("%d:%d:%d\n", HanoiTower[0].tower.size(), HanoiTower[2].tower.size(), HanoiTower[1].tower.size());

                }
                else {
                    curPlace = HanoiTower[(i + 1) % 3].tower.top();
                    HanoiTower[(i + 1) % 3].tower.pop();
                    HanoiTower[(i - 1) % 3].tower.push(curPlace);
                    ++current;
                    /*
                    printf("step %lld : ", current);
                    printf("Move ");
                    printf("Number %d ", curPlace);
                    printf("from %c to %c\n", HanoiTower[(i+1) % 3].name, HanoiTower[(i-1) % 3].name);
                    */
                    if (!(n % 2))printf("%d:%d:%d\n", HanoiTower[0].tower.size(), HanoiTower[1].tower.size(), HanoiTower[2].tower.size());
                    else printf("%d:%d:%d\n", HanoiTower[0].tower.size(), HanoiTower[2].tower.size(), HanoiTower[1].tower.size());
                }
            }
        }
        printf("\n");
        for (i = 0; i < 3; ++i) {
            while (!HanoiTower[i].tower.empty())
                HanoiTower[i].tower.pop();
        }
    }


}
