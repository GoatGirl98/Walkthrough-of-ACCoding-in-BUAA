#include<cstdio>
#define maxn 1000020
#define RADIX 10
int n;
int m;
int op;
int opA, opB;
int position[maxn];
long long result;
inline int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;//*f
}
inline void write(long long x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x >= RADIX)write(x / RADIX);
    putchar(x % RADIX + 48);
}
inline void init_list() {
    for (int i = 1; i <= n; ++i)position[i] = i;
}
inline void add_itself(int lo, int hi) {
    for (int i = 1; i <= n; ++i) {
        if (position[i] >= lo && position[i] <= hi)++position[i];
    }
}
inline void minus_itself(int lo, int hi) {
    for (int i = 1; i <= n; ++i) {
        if (position[i] >= lo && position[i] <= hi)--position[i];
    }
}
inline void move_left(int fromx, int toy) {
    int originalx = position[fromx];
    int newx;
    if (position[fromx] < position[toy]) {
        newx = position[toy] - 1;
        minus_itself(originalx + 1, newx);
        position[fromx] = newx;
    }
    else {
        newx = position[toy];
        add_itself(newx, originalx - 1);
        position[fromx] = newx;
    }
}
inline void move_right(int fromx, int toy) {
    int originalx = position[fromx];
    int newx;
    if (position[fromx] < position[toy]) {
        newx = position[toy];
        minus_itself(originalx + 1, newx);
        position[fromx] = newx;
    }
    else {
        newx = position[toy] + 1;
        add_itself(newx, originalx - 1);
        position[fromx] = newx;
    }
}
inline void swap(int fromx, int toy) {
    int tmp = position[fromx];
    position[fromx] = position[toy];
    position[toy] = tmp;
}
inline void reverse() {
    for (int i = 1; i <= n; ++i)position[i] = n + 1 - position[i];
}
int main() {
    while (scanf("%d", &n) != EOF) {
        init_list();
        m = read();
        for (int i = 0; i < m; ++i) {
            op = read();
            if (op == 1) {
                opA = read();
                opB = read();
                move_left(opA, opB);
            }
            else if (op == 2) {
                opA = read();
                opB = read();
                move_right(opA, opB);
            }
            else if (op == 3) {
                opA = read();
                opB = read();
                swap(opA, opB);
            }
            else {
                reverse();
            }
        }
        result = 0;
        for (int i = 1; i <= n; ++i)if (position[i] % 2)result += i;
        write(result);
        putchar('\n');
    }

}
