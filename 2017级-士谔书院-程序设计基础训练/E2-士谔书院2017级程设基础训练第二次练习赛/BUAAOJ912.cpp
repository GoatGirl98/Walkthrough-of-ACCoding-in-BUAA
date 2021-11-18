#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int yy, mm, dd;
    int n;
    cin >> n;
    while (n--) {
        cin >> yy >> mm >> dd;

        if (mm < 3) {
            yy--;
            mm += 12;
        }

        int century = yy / 100;
        int y = yy - century * 100;

        int result = (y + y / 4 + century / 4 - 2 * century + 26 * (mm + 1) / 10 + dd - 1) % 7;
        while (result <= 0) {
            result += 7;
        }
        
        

        cout << result << endl;
    }
    return 0;
}
