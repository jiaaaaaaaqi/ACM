#include<stdio.h>
#include<string.h>
int num[100005]={0};
int dp[100005]={0};
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
			scanf("%d",&num[i]);
		for(i=1; i<=n; i++)
			dp[i]=1;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<i; j++)
			{
				if(num[i]>num[j])
					dp[i]=max(dp[i], dp[j]+1);
			}
			max_=max(max_, dp[i]);
		}
		printf("%d\n",max_);
	}
	return 0;
}