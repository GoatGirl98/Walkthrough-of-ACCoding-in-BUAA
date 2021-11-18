#include <stdio.h>
int main() {
    int sum = 0, n = 0, failed = 0, score;
    scanf("%d", &score);
    while(score != -1) {
        sum += score;
        n = n + 1;
        if(score < 60)
            ++failed;
        scanf("%d", &score);
    }
    printf("Average:%d\nFailed:%d", sum / n, failed);
}
