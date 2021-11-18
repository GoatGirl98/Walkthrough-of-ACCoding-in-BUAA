#include<iostream>
#include<algorithm>

using namespace std;

const bool win = true;
const bool lose = false;

int a, b;
bool result;
/*
博弈论题型的思想：
如果有一个能使对手进入必败状态的取数字方法，则我方必胜
当我方拿到的条件上手就直接输掉，或者我方的下一步怎么走，对方都必胜的话，则我方必败
如此这题就是入门级别的了
*/
bool judge(int a, int b) {

    if (a < b) {
        swap(a, b);//默认b是最小的那个
    }
    
    if (b == 0)return lose;//如果此时这个人拿到了0，就说明这个人必然会输

    for (int i = a / b; i > 0; i--) {
        if (judge(a - i * b, b) == lose) return win;//看一下下一层对方会如何，如果对方有一种必败的可能性，则我方必胜
    }

    return lose;

}
int main() {
    ios::sync_with_stdio(false);

    while (scanf("%d%d", &a, &b) == 2) {
        result = judge(a, b);
        if (result)printf("Nova\n");
        else printf("LaoWang\n");
    }
}
