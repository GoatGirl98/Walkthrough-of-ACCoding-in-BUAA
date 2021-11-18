#include <cstdio>
#include <cmath>
int main(){
    int s, i;
    scanf("%d", &s);
    for(i = sqrt(s); s % i; -- i);
    printf("%d\n", 2 * (i + s / i));
    return 0;
}
