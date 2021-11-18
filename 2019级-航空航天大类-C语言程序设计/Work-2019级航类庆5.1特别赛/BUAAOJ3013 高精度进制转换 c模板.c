#include <stdio.h>
#include <string.h>
#define maxn 10086
int ans;
int t, cnt, len, hi, x, k, i, a[maxn], b[maxn];
char s[maxn];
int main()
{

	k = 2;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf("%s", s + 1);
		len = strlen(s + 1);

		for (i = 1; i <= len; i++)
			a[i] = s[i] - '0';
		cnt = 0, hi = 1;
		while (hi <= len)
		{
			if (!a[hi])
			{ // 当前最高位为 0，直接跳过。
				hi++;
				continue;
			}
			x = 0; // x 表示余数。
			for (i = hi; i <= len; i++)
			{
				a[i] += x * 10; // 把没处理的数“拉”下来，补在 x 后面。
				x = a[i] % k;
				a[i] /= k; // 确定商的这一位。
			}
			b[++cnt] = x; // 最终的余数即为进制转换后数字的新一位。
		}
		for (i = cnt; i; i--) ans += b[i];
			//printf("%d", b[i]); // 倒序输出每一次产生的余数。
		printf("%d\n", ans);

	}

	return 0;
}