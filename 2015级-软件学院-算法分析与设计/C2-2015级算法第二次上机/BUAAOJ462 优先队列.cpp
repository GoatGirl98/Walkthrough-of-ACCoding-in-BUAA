#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 100000 + 7;
struct student {
    int id;
    int sex;
    int grade;
    student(int _id = 0, int _sex = 0, int _grade = 0) {
        id = _id, sex = _sex, grade = _grade;
    }
    bool operator < (const student& o) const {
        if (grade != o.grade)return grade < o.grade;
        if (sex != o.sex) return o.sex < sex;
        return o.id < id;
    }
};
student students[maxn];
priority_queue<student>q;
char Instr[9];
int n, m;
int id, sex, grade;
int op;
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        while (!q.empty())q.pop();
        memset(students, 0, sizeof(students));
        for (int i = 1; i <= n; ++i) {
            students[i].id = read();
            students[i].sex = read();
            students[i].grade = read();
        }
        while (m--) {
            scanf("%s", Instr);
            if (Instr[0] == 'A') {
                op = read();
                q.push(students[op]);
            }
            else if (Instr[0] == 'D')q.pop();
            else {
                student tmp = q.top();
                write(tmp.id), putchar(' ');
                write(tmp.sex), putchar(' ');
                write(tmp.grade), putchar('\n');
            }
        }
    }
}
