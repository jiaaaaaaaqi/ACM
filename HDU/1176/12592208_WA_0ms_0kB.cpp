#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dp[100005][20]={0};
int max_(int a, int b, int c)
{
	a=a>b ? a:b;
	return a>c ? a:c;
}
int main()
{
	int n;
	while(scanf("%d",&n), n)
	{
		int a,b;
		int maxtime=0;
		for(int i=1; i<=n ;i++)	
		{
			scanf("%d%d",&a, &b);
			dp[b][a+1]=1;
			maxtime=maxtime>b ? maxtime:b;
		}
		dp[0][6]=1;
		for(int i=maxtime-1; i>=0; i--)
			for(int j=11; j>=1; j--)
				dp[i][j]+=max_(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]);
		printf("%d\n", dp[0][6]);
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}