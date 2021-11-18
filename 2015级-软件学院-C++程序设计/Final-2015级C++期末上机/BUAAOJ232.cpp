#include<iostream>
using namespace std;
typedef long long ll;
ll dp[100];
inline void buildDP(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 6;
    for(int i = 6; i < 99; ++i)dp[i] = dp[i-1]+dp[i-3];
    
}
int x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    buildDP();
    while(cin >> x && x)cout << dp[x] << endl;
}
