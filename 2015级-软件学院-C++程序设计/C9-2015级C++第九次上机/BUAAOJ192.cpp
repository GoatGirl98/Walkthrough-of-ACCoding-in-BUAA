#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
using namespace std;
struct Sheet {
    int studentId;
    int chi, mat, eng;
    int sum;
    bool operator <(const Sheet& o)const {
        if (sum != o.sum)return sum > o.sum;
        else if (chi != o.chi)return chi > o.chi;
        else return studentId < o.studentId;
    }
}students[maxn];
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(students, 0, sizeof(students));
        for (int i = 1; i <= n; ++i) {
            students[i].studentId = i;
            scanf("%d%d%d", &students[i].chi, &students[i].mat, &students[i].eng);
            students[i].sum = students[i].chi + students[i].mat + students[i].eng;
        }
        sort(students + 1, students + n + 1);
        for (int i = 1; i <= 5; ++i) {
            printf("%d %d\n", students[i].studentId, students[i].sum);
        }
    }
}
