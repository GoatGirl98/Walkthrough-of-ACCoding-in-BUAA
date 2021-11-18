#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
#define maxn 1010
int c;
int n;
int a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> c){
        while (c--) {
            memset(a, 0, sizeof(a));
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            sort(a, a + n);
            cout << a[2] << endl;
        }
    
    }
}
