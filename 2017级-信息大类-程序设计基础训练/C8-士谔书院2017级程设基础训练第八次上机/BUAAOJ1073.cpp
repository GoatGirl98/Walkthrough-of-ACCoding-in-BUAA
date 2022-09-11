#include <iostream>
#include <algorithm>

using namespace std;

void hanoi(int n, char A, char B, char C) {
    //A is start C is end

    if (n > 0) {
        hanoi(n - 1, A, B, C);
        cout << A << " -> " << B << endl;//move n,A,B
        hanoi(n - 1, C, B, A);
        cout << B << " -> " << C << endl;//move n,B,C
        hanoi(n - 1, A, B, C);
    }

}

int main() {
    ios::sync_with_stdio(false);
    int t;
    int n;
    cin >> t;
    while (t--) {
        cin >> n;
        hanoi(n, 'A', 'B', 'C');
        cout << endl;
    }

}
