#include<stdio.h>
#include<string.h>
int num[100010]={0};
int dp[100010]={0};
int max(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		int max_=1;
		for(i=1 ;i<=n; i++)
		{
			scanf("%d",&num[i]);
			dp[i]=1;
		}
		int len=0;
		for(i=1; i<=n; i++)
		{
			if(num[i]>dp[len])
				dp[++len]=num[i];
			else
			{
				int l=1,h=len,m;
				while(l<=h)
				{
					m=(l+h)/2;
					if(dp[m]>num[i])
						l=m+1;
					else
						h=m-1;
				}
				dp[l]=num[i];
			}
		}
		printf("%d\n",len);
		memset(dp, 0, sizeof(dp)); 
	}
	return 0;
}