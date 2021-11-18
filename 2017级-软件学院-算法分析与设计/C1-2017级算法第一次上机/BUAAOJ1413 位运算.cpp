#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#define maxn 1000010
using namespace std;
/*******************************
1在s[i]s[j]全1时无效
其余时候为1变0
2在s[i]s[j]全0时无效
其余时候为0变1
3为交换s[i]s[j]
所以当A全为1或0时无法更改
*******************************/
int t;
string a, b;
int diff1, diff2;
int A0Count;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        diff1 = diff2 = 0;
        A0Count = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == '0')++A0Count;
            if (b[i] == '1' && a[i] == '0')++diff1;
            else if (b[i] == '0' && a[i] == '1')++diff2;
        }
        if (A0Count == a.length() || A0Count == 0)cout << -1 << endl;
        else
        {
            if (diff1 > diff2)cout << diff1 << endl;
            else cout << diff2 << endl;
        }
    }

}
