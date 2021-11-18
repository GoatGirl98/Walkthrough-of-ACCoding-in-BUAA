#include<iostream>
#define MAXN 10010
using namespace std;
int result[MAXN];
int counter;
int main() {

    ios::sync_with_stdio(false);

    int n;


    while (cin >> n) {
        if (n > 1) {
            int k = 2;
            counter = 0;
            while (k <= n) {
                if (!(n % k)) {
                    n /= k;
                    result[counter++] = k;
                    continue;
                }
                k++;
            }
            for (int i = 0; i < counter - 1; ++i)cout << result[i] << "*";
            cout << result[counter - 1] << endl;
        }
        else { cout << "1" << endl; }
    }
    return 0;
}
