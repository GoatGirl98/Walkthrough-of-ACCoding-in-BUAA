#include<cstdio>
typedef unsigned long long ull;
ull w(int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) return 1;
    if (x > 10 || y > 10 || z > 10)return w(10, 10, 10);
    if (x < y && y < z)return w(x, y, z-1) + w(x, y-1, z-1)-w(x, y-1, z);
    return w(x-1, y, z) + w(x-1, y-1, z) + w(x-1, y, z-1)-w(x-1, y - 1, z - 1);
}
int x, y, z;
int main() { scanf("%d%d%d", &x, &y, &z); printf("%llu\n", w(x, y, z)); }
