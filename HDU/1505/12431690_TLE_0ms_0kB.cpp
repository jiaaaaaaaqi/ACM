#include<stdio.h>
#include<string.h>
int max_(int a , int b)
{
	return a>b ? a:b;
}
int Maxsum(int a[], int n)
{
	int i,j;
	int ans=0;
	int sum=0;
	for(i=1; i<=n; i++)
	{
		sum+=a[i];
		if(sum>ans)
			ans=sum;
		if(sum<0)
		{
			sum=0;
		}
	}
	return ans;
}
int dp[1005][1005]={0};
int sum[1005]={0};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char c;
		int i,j,k;
		int m,n;
		scanf("%d%d",&n,&m);
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
			{
				scanf("%c",&c);
				if(c=='R')
					dp[i][j]=-4999999;
				else if(c=='F')
					dp[i][j]=3; 
				else
					j--;
			}
		int max=0;
		int ans=0;
		for(i=1; i<=n; i++)
		{
			memset(sum, 0, sizeof(sum));
			for(j=i; j<=n; j++)
			{
				for(k=1; k<=m; k++)
					sum[k]+=dp[j][k];
				max=Maxsum(sum, m);
				ans=max_(ans, max);
			}
		}
		printf("%d\n", ans);
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}