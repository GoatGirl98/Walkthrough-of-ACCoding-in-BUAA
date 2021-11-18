#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Info{
    char name[20];
    int studentId;
    int average;
    int gpa;
    bool operator < (const Info& o)const {
        if (average != o.average) {
            return average > o.average;
        }
        else {
            if (gpa != o.gpa)return gpa > o.gpa;
            else return studentId < o.studentId;
        }
    }
};
Info info[1010];
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s%d%d%d", info[i].name, &info[i].studentId, &info[i].average, &info[i].gpa);
        }
        sort(info, info + n);
        for (int i = 0; i < n; ++i) {
            printf("%s %d %d %d\n", info[i].name, info[i].studentId, info[i].average, info[i].gpa);
        }
    }
}
