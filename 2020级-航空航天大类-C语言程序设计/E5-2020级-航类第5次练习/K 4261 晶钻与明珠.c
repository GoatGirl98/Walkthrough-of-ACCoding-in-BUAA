#include<stdio.h>

int t,n;
char s[2000005];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		int cnt1=0,ans=0;
		int i;
		for(i=0; i<n; i++)
		{
			switch(s[i])
			{
				case'0':
						if(cnt1>0)
						{
							ans++;
							cnt1--;
						}
					break;
				case'1':
						cnt1++;
					break;
				default:
					ans++;
			}
		}
		printf("%d\n",ans+cnt1/2);
	}
	return 0;
}