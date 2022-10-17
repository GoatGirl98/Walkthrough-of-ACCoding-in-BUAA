#include <iostream>
#include <map>
typedef unsigned long long ull;
using namespace std;
map<ull, ull> mp;
int main()
{
    int n;
    cin >> n;
    ull ans = 0;
    while (n--)
    {
        ull a;
        cin >> a;
        for (int i = 0; i < 64; i++) 
            if(mp.count((1ull << i) - a))
                ans += mp[(1ull << i) - a];
        mp[a]++;
    }
    cout << ans << endl;
    return 0;
}