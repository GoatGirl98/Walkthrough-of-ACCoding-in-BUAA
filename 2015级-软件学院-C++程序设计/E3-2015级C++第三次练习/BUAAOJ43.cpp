#include<iostream>
using namespace std;

int main(){
    int a1,a2,b,n;
    ios::sync_with_stdio(false);
    while(cin>>n){
        
        a1 = 2;a2 = 3;
        
        for(b = a1;;)
        {
            if(b == n)
            {
                cout << "Oh,holly shit!" << endl;
                break;
            }
            else if(b > n)
            {
                cout << "Oh,yes!" << endl;
                break;
            }
            else
            {
                a1 = a2;
                a2 = a1 + b;
                b = a1;
            }
        }
    }
} 
