#include<cctype>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const string jhljx = "jhljx", xihang = "xihang";
const string jhljxihang = "jhljxihang", head = "0x";
int indexJ,indexX;
bool isHex(char a) {
    return isdigit(a) || (a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F');
}
int hexForm(char a) {
    if(isdigit(a)) return a - '0';
    else if (isupper(a)) return a - 'A' + 10;
    else return a - 'a' + 10;
}
string type, input;
inline int binNum(const string& a) {
    int ret = 0;
    for(int i = 0; i < a.size(); ++i)
        ret = (ret << 1) + a[i] - 48;
    return ret;
}
inline void handleA(const string& a) {
    for(int i = 0; i < a.size(); i += 8)
        putchar(binNum(a.substr(i, 8)));
    putchar('\n');
}
inline bool parseNum(const string& a) {
    return isHex(a[2]) && isHex(a[3]) && (a[4] == '#');
}
struct num {
    int index;
    int value;
    num(int Index = 0, int Value = 0) { index = Index, value = Value; }
};
vector<num> pack;
inline void handleB(const string& a) {
    indexJ = indexX = -1;
    pack.clear();
    int start = 0, pos = -1;
    while((pos = a.find(jhljx, start)) != a.npos) {
        if(pos > a.size() - 10 || a.substr(pos, 10) != jhljxihang)
            indexJ = pos;
        start = pos + 1;
    }
    start = 0, pos = -1;
    if ((pos = a.find(xihang, start)) != a.npos)
        indexX = pos;
    start = 0, pos = -1;
    while((pos = a.find(head, start)) != a.npos) {
        if(parseNum(a.substr(pos, 5)))
            pack.push_back(num(pos, (hexForm(a[pos + 2]) << 4) + hexForm(a[pos + 3])));
        start = pos + 1;
    }
    int namecnt = (indexJ >= 0) + (indexX >= 0);
    int numcnt = pack.size() >> 1;
    int realcnt = min(namecnt, numcnt);
    if(realcnt == 0)
        puts("nothing found!");
    else if (realcnt == 1) {
        printf("%s", indexX >= 0 ? xihang.c_str() : jhljx.c_str());
        printf("(%d,%d)\n",pack[0].value,pack[1].value);
    }
    else {
        printf("%s", indexX < indexJ ? xihang.c_str() : jhljx.c_str());
        printf("(%d,%d) ",pack[0].value,pack[1].value);
        printf("%s", indexX > indexJ ? xihang.c_str() : jhljx.c_str());
        printf("(%d,%d)\n",pack[2].value,pack[3].value);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while(cin >> type >> input)
        type[0] == 'A' ? handleA(input) : handleB(input);
}
