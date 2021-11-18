#include <iostream>
#include <cstring>
using namespace std;
#define maxn 40
#define CASE 5
#define debug 0
#define tab 0
#define linux 1
#define printWin 1
char chessmap[maxn][maxn];
char t;
int n;
bool result;
char cache[maxn];
/******************************************************************
五子棋，但是并非一般的必胜局面，仅考虑当前下完可以直接获胜
那就是横竖斜4个方向，只要是4个，且不是两端都挡着
再分析之后，只要连续的5个当中，只有一个空的时候就可以赢
所以所有点都逐一排查，当前如果空的，就假设他可以是执棋者的棋子
******************************************************************/
void find() {
    //判断对了就走人，不用管
    //Case1:竖着5个
    for (int i = 1; i <= n - CASE + 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool win = true;
            for (int p = 0; p < CASE; ++p) {
                if (chessmap[i + p][j] != t) {
                    win = false;
                }
            }
            if (win) {result = true; return; }
        }
    }

    //Case2:横着5个
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - CASE + 1; ++j) {
            bool win = true;
            for (int p = 0; p < CASE; ++p) {
                if (chessmap[i][j+p] != t) {
                    win = false;
                }
            }
            if (win) {  result = true; return; }
        }
    }

    //Case3:右斜着5个
    for (int i = 1; i <= n - CASE + 1; ++i) {
        for (int j = 1; j <= n - CASE + 1; ++j) {
            bool win = true;
            for (int p = 0; p < CASE; ++p) {
                if (chessmap[i + p][j + p] != t) {
                    win = false;
                }
            }
            if (win) { result = true; return; }
        }
    }
    
    //Case4:左斜着5个
    for (int i = CASE; i <= n; ++i) {
        for (int j = 1; j <= n - CASE + 1; ++j) {
            bool win = true;
            for (int p = 0; p < CASE; ++p) {
                if (chessmap[i - p][j + p] != t) {
                    win = false;
                }
            }
            if (win) { result = true; return; }
        }
    }
    
}
void printTab() {
    printf("debug printab\n");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%c", chessmap[i][j]);
        }
        putchar('\n');
    }
    printf("printab end\n");
}
int main() {
    ios::sync_with_stdio(false);
    while (cin>>n) {
        memset(chessmap, 0, sizeof(chessmap));
        result = false;
        cin >> t;
        if (debug)printf("t is %c\n", t);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cin >> chessmap[i][j];
        }
        if (tab)printTab();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (chessmap[i][j] == '+') {
                    //模拟把棋子下在这里的过程
                    chessmap[i][j] = t;
                    find();
                    chessmap[i][j] = '+';
                }
                if (result == true)break;
            }
            if (result == true)break;
        }
        printf("%s\n", result ? "YES" : "NO");
    }
}
