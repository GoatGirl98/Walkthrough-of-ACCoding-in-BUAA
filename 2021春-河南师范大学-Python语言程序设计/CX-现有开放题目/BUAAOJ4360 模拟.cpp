#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;
string in;
int a[1010];
int n;
long long res;
char flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	getline(cin, in);
	for (int i = 0; i < in.length(); ++i)
		if (!isdigit(in[i]))
			in[i] = ' ';
	stringstream s1(in);
	while (s1 >> a[n])++n;

	//while (~scanf("%d", a + n))++n;
	int i;
	flag = 0;
	res = 0;
	for (i = 0; i < n - 2; ++i)
	{
		if (a[i] > a[i + 1])
		{
			flag = 0;
			int j;
			for (j = i + 1; j < n; ++j)
			{
				if (a[j] >= a[i])
				{
					flag = 1;
					int k;
					for (k = i + 1; k < j; ++k)
					{
						res += a[i] - a[k];
					}
					i = j - 1;
					break;
				}
			}
			if (!flag)
			{
				int maxi = 0, maxIndex = 0;
				for (j = i + 1; j < n; ++j)
				{
					if (a[j] > maxi)
					{
						maxi = a[j];
						maxIndex = j;
					}
				}
				for (j = i + 1; j < maxIndex; ++j)
				{
					res += maxi - a[j];
				}
				if (maxIndex == n - 1)
				{
					break;
				}
				else
				{
					i = maxIndex - 1;
				}
			}
		}
	}
	printf("%lld\n", res);
}