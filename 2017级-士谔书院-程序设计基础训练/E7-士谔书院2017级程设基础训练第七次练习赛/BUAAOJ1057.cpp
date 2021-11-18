#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define maxn 110
#define debug 0
using namespace std;
int a[maxn], b[maxn];
string Sub(string s1, string s2) {
    memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
    int len1 = s1.size(), len2 = s2.size();
    int maxLen = max(len1, len2);
    for (int i = 0; i < len1; ++i)a[i] = s1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; ++i)b[i] = s2[len2 - 1 - i] - '0';
    for (int i = 0; i < maxLen; ++i) {
        if (a[i] - b[i] < 0) {
            a[i] = a[i] + 10 - b[i];
            a[i + 1] -= 1;
        }
        else a[i] -= b[i];
    }
    string str = "";
    int i;
    for (i = maxLen - 1; i >= 0; --i)if (a[i])break;
    for (; i >= 0; --i)str += a[i] + '0';
    return str;
}
string bigIntegerSub(string s1, string s2) {
    if (s1 == s2)return "0";
    int len1 = s1.size(), len2 = s2.size();
    if (len1 > len2)return Sub(s1, s2);
    else if (len1 < len2)
        return "-" + Sub(s2, s1);
    else {
        for (int i = 0; i < len1; ++i) {
            if (s1[i] > s2[i])return Sub(s1, s2);
            else if (s1[i] < s2[i])return Sub(s2, s1);
            else continue;
        }
        return "0";
    }
}
int t;
string s1, s2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s1 >> s2;
        cout << bigIntegerSub(s1, s2) << endl;
    }
}
