#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int num1[1005]={0};
	int dp[1005]={0};
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int i,j;
		for(i=1; i<=N; i++)
		{
			scanf("%d",&num1[i]);
			dp[i]=1;
		}
		for(i=2; i<=N; i++)
			for(j=1; j<i; j++)
				if(num1[i]>num1[j])
					dp[i]=max(dp[i], dp[j]+1);
		printf("%d\n",dp[N]);
		memset(num1, 0, sizeof(num1));
		memset(dp, 0, sizeof(dp));
	}
	return 0;
} 
