#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d", (int)ceil(((double)i / j)));
    //printf("%d", (i + j - 1) / j);

    return 0;
}
