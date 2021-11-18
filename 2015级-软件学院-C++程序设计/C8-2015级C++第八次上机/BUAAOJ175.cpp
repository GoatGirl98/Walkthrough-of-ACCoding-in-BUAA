#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<string>
#include<cctype>
#define maxn 1010
using namespace std;
struct stu {
    unsigned long long name;
    vector<int> score;
    double average;
}student[maxn];
int n, m;
int tmp;
bool compareName(string a, string b) {
    if (a.size() != b.size())return a.size() > b.size();
    else {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])return a[i] > b[i];
        }
        return false;
    }
}
bool compare(stu a, stu b) {
    if (a.average != b.average)
        return a.average > b.average;
    else return a.name > b.name;
        //return compareName(a.name,b.name);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            student[i].score.clear();
            cin >> student[i].name;
            double sum = 0;
            for (int j = 0; j < m; ++j) {
                cin >> tmp;
                sum += tmp;
                student[i].score.push_back(tmp);
            }
            student[i].average = sum / m;
        }
        sort(student, student + n, compare);
        for (int i = 0; i < n; ++i) {
            cout << student[i].name << " ";
            //for (int lala : student[i].score) cout << lala << " ";
            cout << fixed << setprecision(3) << student[i].average << endl;
        }
    }
}
