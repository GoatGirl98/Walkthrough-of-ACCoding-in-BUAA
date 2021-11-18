#include<cstdio>
#include<stack>
#define maxn 2000010
#define debug 1
using namespace std;
long long time[maxn];
long long width[maxn];//实际上短边一定在int范围内
long long length[maxn];
stack<long long> reverse_width;
stack<long long> reverse_length;

int counter;
int result;
long long input;

//long long current_length;

inline void init() {
    for (int i = 1; i < maxn; ++i) {
        time[i] = (long long)i * (long long)(i + (long long)1);
    }
}

int main() {
    init();
    scanf("%lld", &input);
    input *= 6;
    long long temp = input;
    for (long long i = 1; i < maxn; ++i) {
        temp = input;
        if (temp % time[i]!=0)continue;
        temp /= time[i];
        temp += (i - 1);
        if (temp % 3)continue;
        temp /= 3;
        if (i > temp)continue;
        if (i == temp) {
            ++result;
            width[counter] = i;
            length[counter++] = temp;
        }
        else {
            ++result; ++result;
            width[counter] = i;
            length[counter++] = temp;
            reverse_width.push(temp);
            reverse_length.push(i);
        }
    }
    printf("%d\n", result);
    for (int i = 0; i < counter; ++i)printf("%lld %lld\n", width[i], length[i]);
    while (!reverse_width.empty()) {
        printf("%lld %lld\n", reverse_width.top(), reverse_length.top());
        reverse_width.pop(); reverse_length.pop();
    }

}
