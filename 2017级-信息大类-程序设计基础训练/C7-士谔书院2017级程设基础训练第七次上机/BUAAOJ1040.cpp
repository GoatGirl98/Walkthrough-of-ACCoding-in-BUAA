#include<iostream>
#include<string>
using namespace std;
bool lalala = true;
string a;
int main() {
    cin>>a;
    for(int i = 0; i <= (a.length()-1)/2;++i)
        if(a[i]!=a[a.length()-1-i])
            lalala = false;
    cout << lalala;
}
