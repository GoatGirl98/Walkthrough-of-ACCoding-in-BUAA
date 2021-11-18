#include <iostream>
using namespace std;
int main(){
    int x,count,n;
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    while(cin>>x){
        count=0;
        while(cin>>n){
            count++;
            if(count>100)break;
            else if(n>x)cout<<"greater than actual number"<<endl;
            else if(n<x)cout<<"less than actual number"<<endl;
            else{
                cout<<"you get the number "<<x<<endl;
                break;
            }
        }
        if(count>100)break;
    }
}
