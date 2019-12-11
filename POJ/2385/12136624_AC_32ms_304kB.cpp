#include<stdio.h>
#include<string.h>
int max_(int a, int b)
{
	return a>b ? a:b;
}
int dp[1005][35]={0};
int main()
{
	int t,w;
	while(scanf("%d%d",&t,&w)!=EOF)
	{
		int i,j;
		int app[1005]={0};
		for(i=1; i<=t; i++)
			scanf("%d",&app[i]);
		for(i=1; i<=t; i++)
		{
			for(j=0; j<=w; j++)
			{
				if(j==0)
					dp[i][j]=dp[i-1][j];
				
				dp[i][j]=max_(dp[i-1][j], dp[i-1][j-1]);
				
				if(j%2+1==app[i])
					dp[i][j]++;
			}
		}
		int max=0;
		for(i=0; i<=w; i++)
			max=max>dp[t][i] ? max:dp[t][i];
		printf("%d\n",max);
		memset(dp, 0, sizeof(dp));
		memset(app, 0, sizeof(app));
	}
	return 0;
}