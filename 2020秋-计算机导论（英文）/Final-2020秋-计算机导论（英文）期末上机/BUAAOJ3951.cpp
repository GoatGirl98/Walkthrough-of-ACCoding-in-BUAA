#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string, int> a;
string aa[105];
int bb[105];
string input;
int num;
int n;
int x, y;
bool flag;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    while(n--) {
        cin >> x >> y;
        a.clear(), flag = true;
        for(int i = 1; i <= x; ++i) {
            cin >> input >> num;
            a[input] = i;
            aa[i] = input, bb[i] = num;
        }
        while(y--)  {
            cin >> input;
            int i = a[input];
            bb[i]--;
            if(bb[i] < 0) flag = false;
        }
        if(!flag) cout << "Out of stock!" << endl;
        else for(int i = 1; i <= x; ++i) cout << bb[i] << endl;
        cout << endl;
    }
}
