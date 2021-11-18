#include<iostream>
#include<vector>
using namespace std;
vector<int>mouse[20];
int n;
int res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int k = i,counter = 1;
        while (k) {
            if (k & 1)mouse[counter].push_back(i);
            k >>= 1;
            counter++;
        }
    }
    for (int i = 1; i < 20; ++i)if (!mouse[i].empty())++res;
    cout << res << endl;
    for (int i = 1; i <= res; ++i) {
        cout << mouse[i].size() << " ";
        for (int i : mouse[i])cout << i << " ";
        cout << endl;
    }
}
