#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define maxn 1010
#define print 0
char s[maxn];
int t,len;
//[lo,hi)
bool parseW(int lo, int hi) {
    if (print)printf("parse in %d to %d\n", lo, hi);
    if (lo == hi)return true;//空串是W串
    int subW = 0;//W子串个数
    int gap = 0;//左右括号差
    int sublo, subhi;
    sublo = lo + 1;
    for (int i = lo; i < hi; ++i) {
        if (s[i] == '(')++gap; else --gap;
        if (gap < 0) return false;
        if (gap == 0) {
            if (subW == 0 && i != hi - 1) {
                subhi = i + 1;//下一次要递归的点
                //如果是最内层的话不可以，否则就会死循环
            }
            subW++;
        }
    }
    if (gap || subW > 2)return false;
    if (subW == 1)return parseW(lo + 1, hi - 1);
    else return parseW(sublo, subhi - 1) && parseW(subhi + 1, hi - 1);
}
int main() {
    while (~scanf("%d", &t)) {
        while (t--) {
            scanf("%s", s);
            len = strlen(s);
            if (parseW(0, len))puts("Yes");
            else puts("No");
        }
    }
}
