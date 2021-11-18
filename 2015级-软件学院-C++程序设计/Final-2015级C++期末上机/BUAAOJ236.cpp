#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<char>a;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(cin >> s){
        a.clear();
        for(int i = 0; i < s.size();++i)a.push_back(s[i]);
        sort(a.begin(),a.end());
        for(char n : a)cout << n;
        cout << endl;
    }
}
