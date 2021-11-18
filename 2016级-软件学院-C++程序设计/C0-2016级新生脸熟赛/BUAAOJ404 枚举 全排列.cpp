#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
PII star[20];
PII target[5];
PII ans[5];
bool occur[5];
bool isStar;
int res;
int n;
bool realStar() {
    return (ans[0].y > ans[4].y) && (ans[4].y == ans[1].y) && (ans[2].y < ans[4].y) && (ans[3].y < ans[4].y) && (ans[4].x < ans[0].x) && (ans[0].x < ans[1].x) && (ans[4].x < ans[3].x) && (ans[3].x < ans[0].x) && (ans[0].x < ans[2].x) && (ans[2].x < ans[1].x);
}
void dfs(int X) {
    if (X >= 5) {
        if (realStar())isStar = true;
        return;
    }
    for (int i = 0; i < 5; ++i) {
        if (!occur[i]) {
            ans[X] = target[i];
            occur[i] = true;
            dfs(X + 1);
            occur[i] = false;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        cin >> star[i].x >> star[i].y;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    for (int m = l + 1; m < n; ++m) {
                        target[0] = star[i];
                        target[1] = star[j];
                        target[2] = star[k];
                        target[3] = star[l];
                        target[4] = star[m];
                        isStar = false;
                        memset(occur, false, sizeof(occur));
                        dfs(0);
                        if (isStar)res++;
                    }
                }
            }
        }
    }
    printf("%d\n", res);
    
}

