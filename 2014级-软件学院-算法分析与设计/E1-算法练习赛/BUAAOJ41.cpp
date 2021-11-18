#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define INF 10010

using namespace std;
int a[INF], b[INF], c[2 * INF + 5];
string aa,bb;

string bigIntegerMul(string s1, string s2) {
    
    
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));

    int len1 = s1.size(), len2 = s2.size();

    for (int i = 0; i < len1; ++i)a[i] = s1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; ++i)b[i] = s2[len2 - 1 - i] - '0';
    //int lenmax = max(len1, len2);
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            c[i + j] += a[i] * b[j];
            //cout << i << " " << j << " " << a[i] * b[j] << endl;
        }
    }
    for (int i = 0; i < INF * 2; ++i) {
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    string result = "";
    //cout << c[1] << c[0] << endl;
    int temp;
    for (temp = INF * 2; temp >= 0; temp--)
        if (c[temp] != 0)break;
    for (; temp >= 0; temp--)result += (c[temp] + '0');
    return result;
}

int main() {
    
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    while (n--) {
        cin >> aa >> bb;
        cout << bigIntegerMul(aa, bb) << endl;
    }
    
    return 0;
}
