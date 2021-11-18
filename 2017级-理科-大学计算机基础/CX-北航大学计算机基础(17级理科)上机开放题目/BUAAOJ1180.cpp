#include<iostream>
using namespace std;
long long ans,a,b,c,d;
int main(){
    ios::sync_with_stdio(false);
    cin >> ans >> a >> b >> c >> d;
    ans *= a;
    ans -= b;
    ans *= c;
    ans += d;
    cout << "The cyphertext is " << ans << ".";
}
