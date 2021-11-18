#pragma G++ optimize(2)
#include<cstdio>
#define print 1
char chess[9][9];
int nx[8] = { -1,-1,-1,0,0,1,1,1 };
int ny[8] = { -1,0,1,-1,1,-1,0,1 };
int cnt;
inline bool isLegal(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && chess[x][y] == 'L');
}

inline void DFS(int x, int y, int i)
{
    int dx = x + nx[i];
    int dy = y + ny[i];
    if (isLegal(dx,dy)) {
        cnt++;
        DFS(dx, dy, i);
    }
    else if (chess[dx][dy] != 'D')
        cnt = 0;
}
int main()
{
    int cas;
    int i, j, k;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        getchar();
        int maxt = 0;
        for (i = 0; i < 8; i++)
            scanf("%s", chess[i]);
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (chess[i][j] == '*')
                {
                    int ans = 0;
                    for (k = 0; k < 8; k++)
                    {
                        cnt = 0;
                        DFS(i, j, k);
                        ans += cnt;
                    }
                    if (maxt < ans)
                        maxt = ans;
                }
            }
        }
        printf("Case %d: %d\n", ca, maxt);
    }
}