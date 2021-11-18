#include<iostream>
#include<unordered_map>
#include<sstream>
#include<string>
using namespace std;
unordered_map<string, string> a;
int n, k;
string input, num, name;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    getline(cin, input);
    stringstream s1(input);
    s1 >> n;
    while(n--) {
        getline(cin, num), getline(cin, name);
        if(num.back() == '\r')num.pop_back();
        if(name.back() == '\r')name.pop_back();
        a[num] = name;
    }
    getline(cin, input);
    stringstream s2(input);
    s2 >> k;
    while(k--) {
        getline(cin,num);
        if(num.back() == '\r')num.pop_back();
        if(a.count(num))puts(a[num].c_str());
        else puts("Not Found!");
    }
    return 0;
}
