#include<stdio.h>
#include<string.h>
int dp[15][10000]={0};
int min_(int a, int b)
{
	return a<b ? a:b; 
}
int main()
{
	int n;
	while(scanf("%d",&n), n)
	{
		int hire,sala,fire;
		scanf("%d%d%d",&hire,&sala,&fire);
		int num[20]={0};
		int max=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&num[i]);
			max=max>num[i] ? max:num[i];
		}
		for(int i=0; i<=n; i++)
			for(int j=0; j<=max; j++)
				dp[i][j]=99999;
		dp[0][0]=0;
		for(int i=1; i<=n; i++)
			for(int j=num[i]; j<=max; j++)
				for(int k=num[i-1]; k<=max; k++)
					if(k>j)
						dp[i][j]=min_(dp[i][j], dp[i-1][k] + (k-j)*fire + j*sala);
					else
						dp[i][j]=min_(dp[i][j], dp[i-1][k] + (j-k)*hire + j*sala);
		int min=9999999;
		for(int i=1; i<=max; i++)
			min=min_(min, dp[n][i]);
		printf("%d\n",min);
	}
	return 0;
}