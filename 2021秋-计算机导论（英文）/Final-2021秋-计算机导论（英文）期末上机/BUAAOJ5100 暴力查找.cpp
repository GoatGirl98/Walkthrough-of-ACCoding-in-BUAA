#include<iostream>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
void wr(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
}
struct news
{
    string type;
    int time;
};
vector<news> a;
string _news, occur_time, time_l, time_r;
int str_to_time(const string& s)
{
    int a = s.find(":"), sz = s.size();
    string h = s.substr(0, a), m = s.substr(a + 1, sz - a - 1);
    return stoi(h) * 60 + stoi(m);
}
int n, q, x, y;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    while (n--)
    {
        cin >> _news >> occur_time;
        a.push_back((news){_news, str_to_time(occur_time)});
    }
    while (q--)
    {
        cin >> _news >> time_l >> time_r;
        int ret = 0, L = str_to_time(time_l), R = str_to_time(time_r);
        for (int i = 0; i < a.size(); ++i)
            ret += ((a[i].type == _news) && (a[i].time >= L) && (a[i].time <= R));
        wr(ret), putchar('\n');
    }
}