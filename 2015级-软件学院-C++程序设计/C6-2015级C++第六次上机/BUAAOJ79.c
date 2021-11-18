#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 114514
//需要寻找和特判的关键串 需要特判这俩合在一块的情况
const char jhljx[8] = "jhljx";
const char xihang[8] = "xihang";
const char jhljxihang[13] = "jhljxihang";
const char head[5] = "0x";
//一个字符是不是十六进制
int is_hex(char a) {
    return isdigit(a) || (a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F');
}
//十六进制字符转数字
int hex_form(char a) {
    if (isdigit(a)) return a - '0';
    else if (isupper(a)) return a - 'A' + 10;
    else return a - 'a' + 10;
}


char type[5];//处理类型是A还是B
char s[maxn];//输入的字符串
int len;
//A型处理的子函数 获取s[l...r]的二进制数对应的十进制数
int bin_num(int l, int r) {
    int ret = 0, i;
    for (i = l; i <= r; ++i)
        ret = (ret << 1) + s[i] - 48;
    return ret;
}
//A型处理
void handle_A() {
    int i;
    for (i = 0; i < len; i += 8) putchar((char)bin_num(i, i + 7));
    putchar('\n');
}

//在知道s[l,l+1]是"0x"时,判断s[l...l+4]是否是B类坐标
int parse_num(int l) {
    return is_hex(s[l + 2]) && is_hex(s[l + 3]) && s[l + 4] == '#';
}
//记录坐标出现的地方
typedef struct num {
    int _index;//从 s[_index] 开始是坐标
    int value;//具体值
}num;
num pack[10];
int cnt;//出现了多少次坐标 本题合法的话只会出现0/2/4次
int indexJ, indexX;//jhljx和xihang在字符串中出现的位置
//B型处理
void handle_B() {
    indexJ = indexX = -1;
    cnt = 0;//坐标个数清零

    char* start = s, *pos = NULL;//查找的起点和找到的位置
    //本题保证只出现一次jhljx 就找最后一次jhljx出现位置就好了
    //因为可能出现jhljx和jhljxihang，所以需要多次查找
    while ((pos = strstr(start, jhljx)) != NULL) {
        //需要确认这个是jhljx而不是xihang
        if(pos > s + len - strlen(jhljxihang) || strncmp(pos, jhljxihang, strlen(jhljxihang)) != 0)
            indexJ = pos - s;
        start = pos + 1;
    }
    start = s, pos = NULL;//清零
    if ((pos = strstr(start, xihang)) != NULL)
        indexX = pos - s;
    start = s, pos = NULL;//清零
    //寻找所有坐标，以"0x"为查找目标 再判断是不是坐标
    while ((pos = strstr(start, head)) != NULL) {
        if (parse_num(pos - s)) {
            pack[cnt]._index = pos - s;
            pack[cnt].value = hex_form(s[pos + 2 - s]) * 16 + hex_form(s[pos + 3 - s]);
            cnt++;
        }
        start = pos + 1;
    }
    int name_cnt = (indexJ >= 0) + (indexX >= 0);//看找出了多少个名字
    int num_cnt = cnt >> 1;//看找到了多少个坐标对(两个坐标为一对)
    int real_cnt = name_cnt < num_cnt ? name_cnt : num_cnt;//两者的较小者才是真正找到的有效信息个数

    if (real_cnt == 0)
        puts("nothing found!");//谁都没找到
    else if (real_cnt == 1) {//找到一个
        printf("%s", indexX >= 0 ? xihang : jhljx);
        printf("(%d,%d)\n", pack[0].value, pack[1].value);
    }
    else {//找到两个
        printf("%s", indexX < indexJ ? xihang : jhljx);//需要按照先后顺序进行输出
        printf("(%d,%d) ", pack[0].value, pack[1].value);//这里注意要有个空格
        printf("%s", indexX > indexJ ? xihang : jhljx);
        printf("(%d,%d)\n", pack[2].value, pack[3].value);
    }
}

int main() {
    while (scanf("%s%s", type, s) != EOF) {
        len = strlen(s);
        if (type[0] == 'A') handle_A();
        else handle_B();
    }
}
