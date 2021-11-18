#include <iostream>
#include <stack>
#define maxn 50010
using namespace std;
int n, k;
int a[maxn], l[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long result = 0;
    stack <int> DDStack;//目前没太看懂，貌似放的是下标？
    for (int i = 0; i < n; ++i) {
        while (!DDStack.empty() && a[DDStack.top()] < a[i]) {
            result += 1ll * (i - DDStack.top()) * (DDStack.top() - l[DDStack.top()]) * a[DDStack.top()];
            DDStack.pop();
        }
        if (DDStack.empty())l[i] = -1;
        else l[i] = DDStack.top();
        DDStack.push(i);
    }
    long long r = n;
    while (!DDStack.empty()) {
        result += 1ll * (r - DDStack.top()) * (DDStack.top() - l[DDStack.top()]) * a[DDStack.top()];
        DDStack.pop();
    }

    for (int i = 0; i < n; ++i) {
        while (!DDStack.empty() && a[DDStack.top()] > a[i]) {
            result -= 1ll * (i - DDStack.top()) * (DDStack.top() - l[DDStack.top()]) * a[DDStack.top()];
            DDStack.pop();
        }
        if (DDStack.empty())l[i] = -1;
        else l[i] = DDStack.top();
        DDStack.push(i);
    }
    r = n;
    while (!DDStack.empty()) {
        result -= 1ll * (r - DDStack.top()) * (DDStack.top() - l[DDStack.top()]) * a[DDStack.top()];
        DDStack.pop();
    }
    cout << result;
}
