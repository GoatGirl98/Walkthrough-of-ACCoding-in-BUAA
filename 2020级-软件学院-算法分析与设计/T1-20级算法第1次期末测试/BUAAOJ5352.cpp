#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#define putchar putchar_unlocked
using namespace std;
const int N = 2501;
int T;
int n;
// pow_3[n] = 3^(n - 1)
int pow_3[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};
bitset<N> a[N];
bitset<3> origin[3];
string s;
void init()
{
    for (int i = 0; i < pow_3[n]; ++i)
        a[i].reset();
    for (int i = 0; i < 3; ++i)
        origin[i].reset();
}
void dfs(int n, int x, int y)
{
    if (n == 1)
    {
        a[x].set(y);
        return;
    }
    int len = pow_3[n - 1];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (origin[i].test(j))
                dfs(n - 1, x + i * len, y + j * len);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    getline(cin, s);
    stringstream _T(s);
    _T >> T;
    while (T--)
    {
        init();
        getline(cin, s);
        stringstream _n(s);
        _n >> n;
        for (int i = 0; i < 3; ++i)
        {
            getline(cin, s);
            while (s.back() == '\r')
                s.pop_back();
            for (int j = 0; j < s.length(); ++j)
                if (s[j] == 'o')
                    origin[i].set(j);
        }
        dfs(n, 0, 0);
        int len = pow_3[n];
        for (int i = 0; i < len; ++i, putchar('\n'))
            for (int j = 0; j < len; ++j)
                putchar(a[i].test(j) ? 'o' : ' ');
        putchar('\n');
    }
}