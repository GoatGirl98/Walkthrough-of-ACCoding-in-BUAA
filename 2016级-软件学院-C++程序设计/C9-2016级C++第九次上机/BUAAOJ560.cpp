#include<cstdio>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxn 105
struct op {
    int x_1, x_2, y_1, y_2, color;
}ops[maxn];
int n, w, h;
int x_1, x_2, y_1, y_2, input;
int color;
int main() {
    scanf("%d%d%d", &n, &w, &h);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d%d%d%d", &x_1, &y_1, &x_2, &y_2, &input);
        ops[i].x_1 = Min(x_1, x_2);
        ops[i].x_2 = Max(x_1, x_2);
        ops[i].y_1 = Min(y_1, y_2);
        ops[i].y_2 = Max(y_1, y_2);
        ops[i].color = input;
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            color = 0xFFFFFF;
            for (int k = 0; k < n; ++k) {
                if (i <= ops[k].y_2 && i >= ops[k].y_1 && j <= ops[k].x_2 && j >= ops[k].x_1) {
                    color = ops[k].color;
                }
            }
            printf("#%06X ", color);
        }
        puts("");
    }
}
