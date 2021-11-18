#include <cstdio>
#include <cctype>
int num[10], low[26], upp[26];
int main(){
    char ch;
    while((ch = getchar()) != EOF){
        if(isdigit(ch)) ++ num[ch - '0'];
        if(islower(ch)) ++ low[ch - 'a'];
        if(isupper(ch)) ++ upp[ch - 'A'];
    }
    int i;
    for(i = 0; i < 10; ++ i) printf("%d%c", num[i], " \n"[i == 9]);
    for(i = 0; i < 26; ++ i) printf("%d%c", low[i], " \n"[i == 25]);
    for(i = 0; i < 26; ++ i) printf("%d%c", upp[i], " \n"[i == 25]);
    return 0;
}
