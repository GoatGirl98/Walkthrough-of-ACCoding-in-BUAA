#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    
    ios::sync_with_stdio(false);
    int a;
    scanf("%d", &a);

    int on = a / 1000;
    int target = a % 10000;

    if (on) {
        
        int b = a % 10;
        int c = ((a % 100) / 10);
        int d = ((a % 1000) / 100);
        int e = ((a % 10000) / 1000);

        printf("%d", a - target + b * 1000 + c * 100 + d * 10 + e);

    }
    else {
        int b = a % 10;
        int c = ((a % 100) / 10);
        int d = ((a % 1000) / 100);
        int e = ((a % 10000) / 1000);
        printf("%d", 1000 * b + 100 * c + 10 * d + e);
    }
    
    return 0;

}
