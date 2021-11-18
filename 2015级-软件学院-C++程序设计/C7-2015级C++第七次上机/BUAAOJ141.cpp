#include <iostream>
#include <algorithm>

using namespace std;

struct bridge {
    int line;
    int time;
}bridges[100010];

bool compare_bridge(bridge a, bridge b) {
    if (a.time < b.time) {
        return true;
    }
    else if (a.time > b.time) {
        return false;
    }
    else {
        if (a.line < b.line) {
            return true;
        }
        else {
            return false;
        }
    }
}

int original[10010];
int result[10010];

int main() {

    ios::sync_with_stdio(false);

    int current;
    int c;
    int n, m, l;

    cin >> c;

    for (current = 1; current <= c; ++current) {

        cin >> n >> m >> l;

        for (int i = 0; i < n; ++i) {
            original[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            cin >> bridges[i].line >> bridges[i].time;
        }

        sort(bridges, bridges + m, compare_bridge);

        for (int i = 0; i < m; ++i) {
            int target = bridges[i].line;
            if (i && target == bridges[i - 1].line && bridges[i].time == bridges[i - 1].time);
            else swap(original[target], original[target + 1]);
        }

        for (int i = 0; i < n; ++i) {
            result[original[i]] = i;
        }

        cout << "Case " << current << " #: ";
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }



}
