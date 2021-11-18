#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    double s1, s2, s3, s4, s5, s6, s7, s8, s9, g;
    cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9;
    g = (s9 - s5 - s5 + s1) / 16;
    cout << fixed << setprecision(2) << g << endl;
    return 0;
}
