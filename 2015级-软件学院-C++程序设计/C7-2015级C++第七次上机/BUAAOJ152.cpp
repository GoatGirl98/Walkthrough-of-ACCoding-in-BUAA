#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15
using namespace std;
struct student {
    char name[25];
    int id;
    int yy, mm, dd;
    bool operator < (const student& o)const {
        return id < o.id;
    }
    inline void read() {
        scanf("%s%d%d%d%d", name, &id, &yy, &mm, &dd);
    }
    inline void print() {
        printf("Name:%s\n", name);
        printf("StudentId:%d\n", id);
        printf("Birth:%d.%d.%d\n", yy, mm, dd);
    }
}sheet[maxn];
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(sheet, 0, sizeof(sheet));
        for (int i = 0; i < n; ++i)sheet[i].read();
        sort(sheet, sheet + n);
        for (int i = 0; i < n; ++i)sheet[i].print();
    }
}
