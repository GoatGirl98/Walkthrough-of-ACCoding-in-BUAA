#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
struct Data{
	int high;
	int num;
}d[100100];
int n;
bool vis[100100];
int h[100100];
long long ans;
int cmp(const Data & a,const Data & b)
{
	return a.high>b.high;//cmp函数等于的情况要么特判，要么不管，不然re（a.high>=b.high)，我不知道为什么，有知道的大牛是否能告知呢
}
string in;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	getline(cin, in);
	for (int i = 0; i < in.length(); ++i)
		if (!isdigit(in[i]))
			in[i] = ' ';
	stringstream s1(in);
	while (s1 >> h[n])++n;
	for(int i=0;i<n;i++)
	{
		d[i].high=h[i];
		d[i].num=i;
	}
	sort(d,d+n,cmp);
	for(int i=0;i<n-1;i++)
	{
		int left = min(d[i].num,d[i+1].num);
		int right= max(d[i].num,d[i+1].num);//找到待修改区间的左右端点，端点处不用算，贡献面积为0
		int hh=min(h[right],h[left]);//液面高度
		vis[right]=vis[left]=true;
		for(left+=1;left<right;left++)
		{
			if(!vis[left])
			{
				vis[left]=true;
				ans+=hh-h[left];
			}
		}
	}
	cout << ans << endl;
	return 0;
}