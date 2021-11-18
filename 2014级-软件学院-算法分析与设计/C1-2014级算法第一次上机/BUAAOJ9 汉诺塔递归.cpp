#include <iostream>
#include <algorithm>

using namespace std;

void hanoi(int n, char A, char B, char C) {
    //A is start C is end

    if (n > 0) {
        hanoi(n - 1, A, C, B);
        cout << A << " to " << C << endl;//move n,A,C
        hanoi(n - 1, B, A, C);
    }

}

int main() {
    ios::sync_with_stdio(false);

    int n;

    while (cin >> n) {
        hanoi(n, 'A', 'B', 'C');
        cout << endl;
    }

}
