#include<iostream>
#include<sstream>
#include<string>
#include<ctype.h>
using namespace std;
bool is_palindrome(const string& s)
{
    int lim = s.length() >> 1, len = s.length();
    for (int i = 0; i < lim; ++i)
        if (s[i] ^ s[len - 1 - i])
            return 0;
    return 1;
}
int T;
string s;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    getline(cin, s);
    stringstream S(s);
    S >> T;
    while (T--)
    {
        getline(cin, s);
        while (s.back() == '\r')
            s.pop_back();
        int len = s.length();
        for (int i = 0; i < len; ++i)
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
        cout << (is_palindrome(s) ? "True\n" : "False\n");
    }
}