#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int c;
int la;
struct Stu {
    int id;
    int vote;
    bool operator < (const Stu& o)const {
        if (vote != o.vote)return vote > o.vote;
        return id < o.id;
    }
};
Stu lalala[110];
int main() {
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &c);
        memset(lalala, 0, sizeof(lalala));
        for (int i = 1; i <= n; ++i)lalala[i].id = i;
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &la);
            if (i == c)lalala[la].vote += 3;
            else lalala[la].vote += 2;
        }
        sort(lalala + 1, lalala + n + 1);
        if (lalala[1].id == 1)puts("51 is suspected");
        else puts("51 is innocent");
    }
}
