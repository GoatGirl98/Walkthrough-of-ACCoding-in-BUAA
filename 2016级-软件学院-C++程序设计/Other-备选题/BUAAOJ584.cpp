#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
string s;
vector<int>alpha;
vector<string> out;
bool cmp(string a, string b) {
    return a.back() < b.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (getline(cin,s)) {
        if(s.empty())continue;
        alpha.clear();
        for (int i = 0; i < s.size(); ++i)
            if (isalpha(s[i]))alpha.push_back(i);
        int tmp = 0;
        out.clear();
        for (int i = 0; i < alpha.size(); ++i) {
            string ss = s.substr(tmp, alpha[i] - tmp + 1);
            sort(ss.begin(), ss.end());
            out.push_back(ss);
            tmp = alpha[i] + 1;
        }
        sort(out.begin(), out.end(), cmp);
        for (int i = 1; i < out.size(); ++i) {
            if (!out[i-1].empty()&&out[i].back() == out[i - 1].back()) {
                out[i - 1] = out[i - 1].substr(0, out[i - 1].size() - 1) + out[i];
                sort(out[i - 1].begin(), out[i - 1].end());
                out.erase(out.begin() + i);
                --i;
            }
        }

        for (int i = 0; i < out.size(); ++i)cout << out[i];
        cout << endl;
    }
}
