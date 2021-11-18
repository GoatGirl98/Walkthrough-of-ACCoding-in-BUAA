#include<iostream>
#include<climits>
#include<algorithm>
#define maxn 10010
#define Min(a,b) (((a)<(b))?(a):(b))
using namespace std;
typedef long long ll;
int res;
int n, L;
int set, dir;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> L;
    res = INT_MIN;
    int len;
    while (n--) {
        cin >> set >> dir;
        if (dir == -1) len = set;
        else if (dir == 1) len = L - set;
        if (len > res)res = len;
    }
    cout << res << endl;
}
