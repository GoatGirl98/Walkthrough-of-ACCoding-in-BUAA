#include<cmath>
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T,n,a;
    while(cin >> T){
        
        while(T--){
            
            cin >> n;
            int dis = 0,count = 0;
            
            while(n--){
                cin >> a;
                dis += abs(count);
                count += a;
            }
            
            cout << dis << endl;
            
        }
    }
}
