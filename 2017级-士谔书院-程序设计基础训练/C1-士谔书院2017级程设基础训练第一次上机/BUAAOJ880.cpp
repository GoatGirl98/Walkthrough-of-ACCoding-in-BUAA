#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    long long d;
    scanf("%lld", &d);
    printf("%d",(int)(( 3 * (d % 100000007) + 1) % 100000007));
    return 0;
}
