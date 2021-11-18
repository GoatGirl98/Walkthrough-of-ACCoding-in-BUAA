#include <iostream>
#include <algorithm>
#include <string>
#define INF 1010
//coding能力太差了！！！好好练习！！！
using namespace std;
int n, m, q;
int x_1, y_1, x_2, y_2;

int map[INF][INF];
bool flag = false;

int directionX[4] = { -1, 1, 0, 0 };
int directionY[4] = { 0, 0, -1, 1 };

// 0 : up  1 : down 2 : left 3 : right 4 : haven't moved yet
void DFS(int x, int y, int strike, int direction) {
    
    if (strike > 2) return;
    if (x == x_2 && y == y_2) {
        flag = true;
        return;
    }

    if ((x != x_1 || y != y_1) && map[x][y] != 0)return;

    for (int i = 0; i < 4; ++i) {

        int x_next = x + directionX[i];
        int y_next = y + directionY[i];
        if (x_next >= 1 && x_next <= n && y_next >= 1 && y_next <= m) {

            if (direction == 4) {
                DFS(x_next, y_next, 0, i);
            }
            else {
                if (direction == i) DFS(x_next, y_next, strike, i);
                else DFS(x_next, y_next, strike + 1, i);
            }


        }


    }

}


int main() {

    ios::sync_with_stdio(false);

    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> map[i][j];
                //cout << "map " << i << " " << j << " is" << map[i][j] << endl;
            }
        }

        cin >> q;

        while (q--) {
            cin >> x_1 >> y_1 >> x_2 >> y_2;
            flag = false;

            if (map[x_1][y_1] == 0 || map[x_2][y_2] == 0 || map[x_1][y_1] != map[x_2][y_2]) {
                cout << "NO" << endl;
                continue;
            }

            DFS(x_1, y_1, 0, 4);
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;

        }

    }
    return 0;
}
