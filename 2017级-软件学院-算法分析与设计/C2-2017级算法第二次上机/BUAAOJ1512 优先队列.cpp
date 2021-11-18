#include<cstdio>
#include<queue>
using namespace std;
unsigned long long result;
long long counter;
int n;
int tmpint;

int main() {

    while (scanf("%d", &n) != EOF) {
        result = 0;
        priority_queue<long long, vector<long long>, greater<long long>> lalala;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmpint);
            lalala.push((long long)tmpint);
        }
        while (!lalala.empty()) {
            counter = 0;
            counter += lalala.top();
            lalala.pop();
            if (lalala.empty())break;
            counter += lalala.top();
            lalala.pop();
            result += counter;
            lalala.push(counter);
        }
        printf("%lld\n", result);
    }

}
