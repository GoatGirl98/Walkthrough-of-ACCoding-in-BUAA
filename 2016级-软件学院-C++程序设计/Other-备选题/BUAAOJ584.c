#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//输入的字符串
char s[50];
//按照某种花色搜索到的卡牌, 记录下他们的数字
char card[50];
int cnt;
int cmp(const void* p1, const void* p2) {
    char* a = (char*)p1, * b = (char*)p2;
    if (*a < *b)return -1;
    else if (*a > *b) return 1;
    else return 0;
}
//传入的s，是以字符串形式传入的卡牌花色 根据这个来找对应卡牌
void print(const char* color) {
    memset(card, 0, sizeof(card));//注意初始化清零
    cnt = 0;
    char* start = s, * pos;//查找起点 需要注意的是同一种花色的卡牌会分散
    while ((pos = strstr(start, color)) != NULL) {
        char* ptr = pos;//备份
        pos--;
        //必须在字符串范围内 而且还是数字 直接往后找就行
        while (pos - s >= 0 && isdigit(*pos)) card[cnt++] = *pos, --pos;
        start = ptr + 1;
    }
    if (cnt == 0) return;//这个花色的啥都没找着
    qsort(card, cnt, sizeof(card[0]), cmp);
    printf("%s%s", card, color);
}
int main() {
    while (scanf("%s", s) != EOF) 
        print("m"), print("p"), print("s"), print("z"), putchar('\n');
}
