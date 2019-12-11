#include<stdio.h>
#include<string.h>
int num[1005]={0};
int pri[1005]={0};
int sum[1005]={0};
int dp[1005]={0};
int min_(int a, int b)
{
	return a<b ? a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&num[i], &pri[i]);
			sum[i]=sum[i-1]+num[i];
		}
		dp[0]=0;
		for(int i=1; i<=n; i++)
		{
			dp[i]=dp[i-1]+(10+num[i])*pri[i];
			for(int j=1; j<i; j++)
				dp[i]=min_(dp[i], dp[j-1]+(sum[i]-sum[j-1]+10)*pri[i]);
		}
		printf("%d\n", dp[n]);
		memset(dp, 0, sizeof(dp));
		memset(pri, 0, sizeof(pri));
		memset(num, 0, sizeof(num));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
}