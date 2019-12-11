#include<stdio.h>
#include<string.h>
int dp[200005]={0};
int sum[200005]={0};
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=2; i<=n+1; i++)
		{
			for(int j=2; j<=m+1; j++)
				scanf("%d",&sum[j]);
			for(int j=2; j<=m+1; j++)
				sum[j]=max_(sum[j-1], sum[j-2]+sum[j]);
			dp[i]=sum[m+1];
		}
		for(int i=2; i<=n+1; i++)
			dp[i]=max_(dp[i-1], dp[i-2]+dp[i]);
		printf("%d\n",dp[n+1]);
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
}