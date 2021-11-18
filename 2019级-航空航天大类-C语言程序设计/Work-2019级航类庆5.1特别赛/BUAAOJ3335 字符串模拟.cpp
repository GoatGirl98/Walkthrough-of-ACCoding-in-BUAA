#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
struct DigitalWatch {
    string Crystal[7];//7行水晶管
    DigitalWatch(string a = "", string b = "", string c = "", string d = "", string e = "", string f = "", string g = "") {
        Crystal[0] = a, Crystal[1] = b, Crystal[2] = c, Crystal[3] = d, Crystal[4] = e, Crystal[5] = f, Crystal[6] = g;
    }
    DigitalWatch operator + (const DigitalWatch& o) const {
        DigitalWatch ret;
        for (int i = 0; i < 7; ++i)
        ret.Crystal[i] = Crystal[i] + o.Crystal[i];
        return ret;
    }
    bool operator == (const DigitalWatch& o) const {
        for (int i = 0; i < 7; ++i)
        if (Crystal[i] != o.Crystal[i])return false;
        return true;
    }
    DigitalWatch piece(int from, int _size) {
        DigitalWatch ret;
        for (int i = 0; i < 7; ++i)
        ret.Crystal[i] = Crystal[i].substr(from, _size);
        return ret;
    }
    void read() {
        for (int i = 0; i < 7; ++i)
        cin >> Crystal[i];
    }
    void print() {
        for (int i = 0; i < 7; ++i)cout << Crystal[i] << endl;
    }
};

DigitalWatch Number[12];//10个数字的液晶管碎片 下标10对应的是空的小时位
DigitalWatch Colon, Space;//冒号和空格的液晶管碎片
//于是乎,这7行21列的形式就是 数字+空格+数字+空格+冒号+空格+数字+空格+数字
inline void buildPiece() {
    Number[0] = DigitalWatch(
                             ".XX.",
                             "X..X",
                             "X..X",
                             "....",
                             "X..X",
                             "X..X",
                             ".XX."
                             );
    Number[1] = DigitalWatch(
                             "....",
                             "...X",
                             "...X",
                             "....",
                             "...X",
                             "...X",
                             "...."
                             );
    Number[2] = DigitalWatch(
                             ".XX.",
                             "...X",
                             "...X",
                             ".XX.",
                             "X...",
                             "X...",
                             ".XX."
                             );
    Number[3] = DigitalWatch(
                             ".XX.",
                             "...X",
                             "...X",
                             ".XX.",
                             "...X",
                             "...X",
                             ".XX."
                             );
    Number[4] = DigitalWatch(
                             "....",
                             "X..X",
                             "X..X",
                             ".XX.",
                             "...X",
                             "...X",
                             "...."
                             );
    Number[5] = DigitalWatch(
                             ".XX.",
                             "X...",
                             "X...",
                             ".XX.",
                             "...X",
                             "...X",
                             ".XX."
                             );
    Number[6] = DigitalWatch(
                             ".XX.",
                             "X...",
                             "X...",
                             ".XX.",
                             "X..X",
                             "X..X",
                             ".XX."
                             );
    Number[7] = DigitalWatch(
                             ".XX.",
                             "...X",
                             "...X",
                             "....",
                             "...X",
                             "...X",
                             "...."
                             );
    Number[8] = DigitalWatch(
                             ".XX.",
                             "X..X",
                             "X..X",
                             ".XX.",
                             "X..X",
                             "X..X",
                             ".XX."
                             );
    Number[9] = DigitalWatch(
                             ".XX.",
                             "X..X",
                             "X..X",
                             ".XX.",
                             "...X",
                             "...X",
                             ".XX."
                             );
    Number[10] = DigitalWatch(
                              "....",
                              "....",
                              "....",
                              "....",
                              "....",
                              "....",
                              "...."
                              );
    Colon = DigitalWatch(
                         ".",
                         ".",
                         "X",
                         ".",
                         "X",
                         ".",
                         "."
                         );
    Space = DigitalWatch(
                         ".",
                         ".",
                         ".",
                         ".",
                         ".",
                         ".",
                         "."
                         );
}

int n;
DigitalWatch a[110];
DigitalWatch timetable[1550];
inline void getWatchFormTime(int timeline, DigitalWatch &s) {//0到1439
    timeline %= 1440;
    int h = timeline / 60, m = timeline % 60;
    int t1 = h / 10 ? h / 10 : 10, t2 = h % 10, t3 = m / 10, t4 = m % 10;
    s = Number[t1] + Space + Number[t2] + Space + Colon + Space + Number[t3] + Space + Number[t4];
}
inline void initTimeTable() {
    for(int i = 0; i <= 1540; ++i)
    getWatchFormTime(i, timetable[i]);
}

enum result {unknown, notdigital, normal, breakdown_1, breakdown_0};
struct AnswerPack {
    result ans[8][22];
    AnswerPack() {
        memset(ans, 0, sizeof(ans));
        ans[0][0] = ans[0][3] = ans[0][4] =
        ans[0][5] = ans[0][8] = ans[0][9] =
        ans[0][10] = ans[0][11] = ans[0][12] =
        ans[0][15] = ans[0][16] = ans[0][17] = ans[0][20] = notdigital;
        ans[1][1] = ans[1][2] = ans[1][4] =
        ans[1][6] = ans[1][7] = ans[1][9] =
        ans[1][10] = ans[1][11] = ans[1][13] =
        ans[1][14] = ans[1][16] = ans[1][18] = ans[1][19] = notdigital;
        ans[2][1] = ans[2][2] = ans[2][4] =
        ans[2][6] = ans[2][7] = ans[2][9] =
        ans[2][11] = ans[2][13] = ans[2][14] =
        ans[2][16] = ans[2][18] = ans[2][19] = notdigital;
        ans[3][0] = ans[3][3] = ans[3][4] =
        ans[3][5] = ans[3][8] = ans[3][9] =
        ans[3][10] = ans[3][11] = ans[3][12] =
        ans[3][15] = ans[3][16] = ans[3][17] = ans[3][20] = notdigital;
        ans[4][1] = ans[4][2] = ans[4][4] =
        ans[4][6] = ans[4][7] = ans[4][9] =
        ans[4][11] = ans[4][13] = ans[4][14] =
        ans[4][16] = ans[4][18] = ans[4][19] = notdigital;
        ans[5][1] = ans[5][2] = ans[5][4] =
        ans[5][6] = ans[5][7] = ans[5][9] =
        ans[5][10] = ans[5][11] = ans[5][13] =
        ans[5][14] = ans[5][16] = ans[5][18] = ans[5][19] = notdigital;
        ans[6][0] = ans[6][3] = ans[6][4] =
        ans[6][5] = ans[6][8] = ans[6][9] =
        ans[6][10] = ans[6][11] = ans[6][12] =
        ans[6][15] = ans[6][16] = ans[6][17] = ans[6][20] = notdigital;
    }
    //多种可能结果进行对比,如果出现不一样的可能性,一律定为未知
    AnswerPack operator ^ (const AnswerPack & o) const {
        AnswerPack ret = AnswerPack();
        for(int i = 0; i < 7; ++i)
        for(int j = 0; j < 21; ++j)
        ret.ans[i][j] = (this->ans[i][j] == o.ans[i][j]) ? this->ans[i][j] : unknown;
        return ret;
    }
    inline void print() {
        for(int i = 0; i < 7; ++i) {
            for(int j = 0; j < 21; ++j) {
                switch (ans[i][j]) {
                    case unknown:putchar('?'); break;
                    case notdigital:putchar('.'); break;
                    case normal:putchar('W'); break;
                    case breakdown_0:putchar('0'); break;
                    case breakdown_1:putchar('1'); break;
                    default:break;
                }
            }
            putchar('\n');
        }
    }
};

AnswerPack possible[1450];
int legal_size;
//记录所有的可能性的种类
bool breakdown[8][22];//对应晶体管是否出现故障
bool occur[2][8][22];//亮和灭的记录,故障管如果不是永远亮或者灭的那就非法

inline void buildOccur() {
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < 7; ++i) {
            for(int j = 0; j < 21; ++j) {
                int num = a[k].Crystal[i][j] == 'X';
                occur[num][i][j] = true;
            }
        }
    }
}

inline bool parse(int s) {//从timetable的s开始进行对比
    //memset(occur, 0, sizeof(occur));
    memset(breakdown, 0, sizeof(breakdown));

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < 7; ++i) {
            for(int j = 0; j < 21; ++j) {
                if(timetable[k + s].Crystal[i][j] != a[k].Crystal[i][j]) {
                    breakdown[i][j] = true;
                    if(occur[0][i][j] && occur[1][i][j] && breakdown[i][j])
                        return false;
                }
            }
        }
    }
    return true;
}

AnswerPack get_ans() {
    AnswerPack ret = AnswerPack();
    for(int i = 0; i < 7; ++i) {
        for(int j = 0; j < 21; ++j) {
            if(ret.ans[i][j] == notdigital)continue;
            if(breakdown[i][j])
                ret.ans[i][j] = occur[0][i][j] ? breakdown_0 : breakdown_1;
            else if (occur[0][i][j] == occur[1][i][j])
                ret.ans[i][j] = normal;
            else ret.ans[i][j] = unknown;
        }
    }
    return ret;
}
inline void init() {
    for(int i = 0; i <= 100; ++i) a[i] = DigitalWatch();
    memset(possible, 0, sizeof(possible));
    memset(occur, 0, sizeof(occur));
    legal_size = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    buildPiece();
    initTimeTable();
    while(cin >> n) {
        init();
        for(int i = 0; i < n; ++i)
        a[i].read();
        buildOccur();
        for(int i = 0; i < 1440; ++i)
        if(parse(i))
            possible[++legal_size] = get_ans();
        if(legal_size == 0)puts("impossible");
        else {
            for(int i = 2; i <= legal_size; ++i)
            possible[1] = possible[1] ^ possible[i];
            possible[1].print();
        }
    }
}