#include<iostream>
#include<algorithm>
#define INF 1000010

using namespace std;

int stock[INF];
bool skip[INF];
int n;
long result,current;

int main() {
    
    ios::sync_with_stdio(false);

    while (cin >> n) {

        for (int i = 1; i <= n; ++i) {
            cin >> stock[i];
        }

        result = 0;

        for (int i = 1; i <= n; ++i) {
            if (skip[i]) continue;
            for (int j = i + 1; j <= n; ++j) {
                //cout << "i : " << i << " stock[i] : " << stock[i] << " j : " << j << " stock[j] : " << stock[j] << endl;
                if (stock[j] <= stock[i]) {
                    i = j;
                    continue;
                }
                skip[j] = true;
                current = stock[j] - stock[i];
                if (current > result) {
                    result = current;
                }
            }
        }
        if (result > 0) cout << result << endl;
        else cout << "No solution" << endl;
    }

}
