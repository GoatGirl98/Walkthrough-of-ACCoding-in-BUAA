#include<iostream>

using namespace std;

int main() {
    
    ios::sync_with_stdio;
    
    int n;
    char s;
    int result;

    while (cin >> n) {
        s = '\0';
        result = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            result += s;
        }
        cout << result << endl;
    }
    

}
