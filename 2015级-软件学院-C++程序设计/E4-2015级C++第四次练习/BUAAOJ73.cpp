#include<cstdio>
#include<cstring>
#include<cctype>
char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower[27] = "abcdefghijklmnopqrstuvwxyz";
char input[1025];
int sizela;
bool flag;
int main() {
    while (scanf("%d",&sizela)!=EOF) {
        flag = false;
        scanf("%s", input);
        for (int i = 0; i < sizela; ++i) {
            if (isalpha(input[i]))printf("%d", input[i]); else printf("%c", input[i]);
        }
        putchar('\n');
    }

}
