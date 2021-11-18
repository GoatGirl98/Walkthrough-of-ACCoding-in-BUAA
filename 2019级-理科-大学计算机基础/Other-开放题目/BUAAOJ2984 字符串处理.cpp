#include<iostream>
#include<string>
#include<cctype>
#define OJ 1
using namespace std;
FILE* in, * out;
int n;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    getline(cin, s);
    while (n--) {
                 getline(cin, s); if (s.empty()) { n++; continue; }
                 if(s.back() == '\r')s.pop_back();
        int pos;
        while ((pos = s.find("\t")) != s.npos)
            s.replace(pos, 1, "    ");
        pos = 0;
        while (isspace(s[pos]))++pos;
        if (pos % 4) {
            int needspace = (pos / 4 + 1) * 4 - pos;
            s.insert(s.begin(), needspace, ' ');
        }
        pos = s.find("#");
        if (pos != s.npos) {
            if (pos == s.size() - 1 || s[pos + 1] != ' ')
                s.insert(s.begin() + pos + 1, 1, ' ');
        }
        cout << s;
        if (n)cout << " " << endl;
    }

}
