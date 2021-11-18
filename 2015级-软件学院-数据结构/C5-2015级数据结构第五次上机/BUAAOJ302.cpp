#include<iostream>
#include<stack>
using namespace std;
int n;
stack<int> a;
int tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(cin>>n){
        while(!a.empty())a.pop();
        while(n--){cin>>tmp;a.push(tmp);}
        while(!a.empty()){cout<<a.top()<<" ";a.pop();}
        cout << endl;
    }
}
