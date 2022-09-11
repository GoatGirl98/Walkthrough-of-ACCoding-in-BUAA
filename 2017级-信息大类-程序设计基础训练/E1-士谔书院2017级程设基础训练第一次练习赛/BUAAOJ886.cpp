#include<cstdio>
char lala[13][20] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
int n;
int main() {
    while (scanf("%d", &n) != EOF) {
        if (n <= 0 || n >= 13)printf("Wrong month\n");
        else printf("%s", lala[n]);
    }
}
