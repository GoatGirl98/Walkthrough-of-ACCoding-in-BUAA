#include <iostream>
#include <algorithm>
#define INF 100011
#define LOOP 20188
using namespace std;
long long result[INF] = {1,2,3};
void init() {
    for (int i = 3; i <= LOOP; ++i) {
        int lala = (result[i - 1] + result[i - 2]) % 100007;
        //if(i <= 1000)cout << i << " : " << lala << endl;
        result[i] = lala;
    }
}
int n;
//int temp1 = 1, temp2 = 1;
long long rua;
int main() {
    ios::sync_with_stdio(false);
    init();
    while (scanf("%d",&n)==1) {
        rua = result[n % LOOP];
        cout << rua << endl;
    }
}
