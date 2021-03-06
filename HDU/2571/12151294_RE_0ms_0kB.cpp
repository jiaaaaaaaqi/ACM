#include<stdio.h>
#include<string.h>
int max_(int a, int b)
{
	return a>b ? a:b;
}
int num[1005][1005]={0};
int dp[1005][1005]={0};
int main()
{
	int T;
	while(scanf("%d",&T)!=EOF)
	{
		int i,j,k;
		int n,m;
		scanf("%d%d",&n,&m);
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				scanf("%d",&num[i][j]);
		
		int t;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				dp[i][j]=max_(dp[i-1][j], dp[i][j-1]);
				for(k=2; k<m; k++)
				{
					if(j%k==0)
					{
						dp[i][j]=max_(dp[i][j], dp[i][j/k]);
					}
				}
				dp[i][j]+=num[i][j];
			}
		}
		printf("%d\n",dp[n][m]);
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
	}
	return 0;
}