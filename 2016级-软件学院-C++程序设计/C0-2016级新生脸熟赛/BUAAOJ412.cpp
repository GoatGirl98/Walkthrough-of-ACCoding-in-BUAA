#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef unsigned long long ull;
char s[15];
int main() {
    ull ans;
    ull lala;
    while (scanf("%llu", &ans) != EOF) {
        string a = "";
        ans--;
        do {
            if (a.length() > 0)ans--;
            a = ((char)(ans % 26 + 'A')) + a;
            ans = (ull)((ans - ans % 26) / 26);
        } while (ans);
        printf("%s\n", a.c_str());
    }
}
