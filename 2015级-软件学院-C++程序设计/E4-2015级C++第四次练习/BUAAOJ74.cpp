#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower[27] = "abcdefghijklmnopqrstuvwxyz";
bool flag;
int h, m, s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (scanf("%d:%d:%d",&h,&m,&s)!=EOF) {
        flag = (h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59);
        cout << (flag ? "Yes" : "No") << endl;
    }

}
