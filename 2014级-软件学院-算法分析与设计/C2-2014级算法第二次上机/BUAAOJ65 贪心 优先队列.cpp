#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, k;
int res;
int input;
int curTop;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int> q;//大顶堆

    while (cin >> n) {
        res = 0;
        while (!q.empty())q.pop();
        while (n--) {
            cin >> input;
            q.push(input);
        }
        cin >> k;
        while ((curTop = q.top()) > res) {
            q.pop();
            q.push(curTop - k + 1);
            res++;
        }
        cout << res << endl;
    }

         return 0;
}
