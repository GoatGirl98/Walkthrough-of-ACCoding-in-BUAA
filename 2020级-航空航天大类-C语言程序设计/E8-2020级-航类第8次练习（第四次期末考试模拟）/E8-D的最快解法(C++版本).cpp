#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
typedef long long ll;
typedef multiset<ll>::iterator IT;
ll rd() {
    int k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return k;
}
void wr(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
void print_str(const char* s) {
    int len = strlen(s), i = 0;
    while(i < len) putchar(s[i++]);
}
multiset<ll> wine;
int n;
ll sum, v;
int op, x;

int main() {
    sum = v = rd();
    n = rd();
    wine.insert(v);
    for(int i = 1; i <= n; ++i) {
        op = rd();
        if(op == 1) {
            IT it = wine.upper_bound(0);
            if(it != wine.end()) {
                ll target_wine = *it, after = min(target_wine << 1, v);
                sum += (after - target_wine);
                wine.erase(it), wine.insert(after);
            }
            print_str("Day "), wr(i), print_str(": "), wr(sum), putchar('\n');
        }
        else if(op == 2) {
            IT it = wine.end(); --it;
            if(*it == 0) print_str("Day "), wr(i), print_str(": "), puts("Such beautiful flowers, what a pity!");
            else {
                sum--;
                ll after = (*it) - 1;
                wine.erase(it), wine.insert(after);
                print_str("Day "), wr(i), print_str(": "), wr(sum), putchar('\n');
            }
        }
        else {
            wine.insert(v);
            sum += v;
            print_str("Day "), wr(i), print_str(": "), wr(sum), putchar('\n');
        }
    }
}