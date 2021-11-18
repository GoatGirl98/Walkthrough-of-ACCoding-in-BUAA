#pragma GCC optimize(2)
#include<cstdio>
#include<unordered_map>
#include<cstring>
#include<cctype>
using namespace std;
#define maxn 100010
#define mp make_pair
#define x first
#define y second
#define Min(a,b) (((a)<(b))?(a):(b))
typedef pair<int, int> PII;
typedef pair<PII, PII> record;
unordered_map<int, record> m;
int res;
int n, k;
int num1, num2, num3;
char op[10];
char cu[3] = "Cu";
char fe[3] = "Fe";
char au[3] = "Au";
char ag[4] = "Ag";
inline int readNum() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;//*f
}
inline void readOp() {
    int index = 0;
    char c = getchar();
    while (!isalpha(c)) {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (isalpha(c)) {
        op[index++] = c;
        c = getchar();
    }
}
int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        m.clear();
        while (n--) {
            num1 = readNum(); num2 = readNum(); num3 = readNum(); readOp();
            if (!m.count(num1)) m[num1] = mp(mp(0, 0), mp(0, 0));
            if (!m.count(num2)) m[num2] = mp(mp(0, 0), mp(0, 0));
            if (!m.count(num3)) m[num3] = mp(mp(0, 0), mp(0, 0));
            if (!strcmp(op, fe)) {
                m[num1].y.y++, m[num2].y.y++, m[num3].y.y++;
            }
            else if (!strcmp(op, cu)) {
                m[num1].y.x++, m[num2].y.x++, m[num3].y.x++;
            }
            else if (!strcmp(op, ag)) {
                m[num1].x.y++, m[num2].x.y++, m[num3].x.y++;
            }
            else if (!strcmp(op, au)) {
                m[num1].x.x++, m[num2].x.x++, m[num3].x.x++;
            }
        }
        while (k--) {
            num1 = readNum();
            if (!m.count(num1)) {
                printf("0Au 0Ag 0Cu 0Fe\n");
            }
            else {
                printf("%dAu %dAg %dCu %dFe\n", m[num1].x.x, m[num1].x.y, m[num1].y.x, m[num1].y.y);
            }
        }
    }
}
