#include<stdio.h>
#include<string.h>
int num[25][1005]={0};
int dp[2][1005]={0};
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,k;
		int n,m;
		scanf("%d%d",&n,&m);
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				scanf("%d",&num[i][j]);
	    for(int i=0; i<=m; i++)
            dp[0][i]=-9999;
        for(int i=0; i<=n; i++)
            dp[i][0]=-9999;

		int flag=0;
		for(i=1; i<=n; i++)
		{
			flag=1-flag;
			for(j=1; j<=m; j++)
			{
				dp[flag][j]=max_(dp[1-flag][j], dp[flag][j-1]);
				for(k=2; k<=m; k++)
				{
					if(j%k==0)
						dp[flag][j]=max_(dp[flag][j], dp[flag][j/k]);
				}
				dp[flag][j]+=num[i][j];
			}
		}
		printf("%d\n",dp[flag][m]);
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}