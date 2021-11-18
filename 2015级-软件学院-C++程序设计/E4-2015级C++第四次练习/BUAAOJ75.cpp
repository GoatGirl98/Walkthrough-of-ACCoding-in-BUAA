#include<cstdio>
#include<cstring>
#include<cctype>
char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower[27] = "abcdefghijklmnopqrstuvwxyz";
char input[1025];
int sizela;
bool flag;
int main() {
    while (scanf("%d", &sizela) != EOF) {
        flag = false;
        scanf("%s", input);
        for (int i = 1; i < sizela-1; ++i) {
            if (isupper(input[i]) && islower(input[i - 1]) && islower(input[i + 1])) { flag = true; break; }
        }
        printf("%s\n", (flag ? "Yes" : "No"));
    }

}
