#include<stdio.h>
#include<string.h>
int dp[105]={0};
int va[105]={0};
int v[105]={0};
int num[105]={0};
int n,m;
int max(int a, int b)
{
	return a>b ? a:b;
}
void cppack(int v, int va)
{
	int i;
	for(i=v; i<=m; i++)
		dp[i]=max(dp[i],dp[i-v]+va);
}
void zopack(int v, int va)
{
	int i;
	for(i=m; i>=v; i--)
		dp[i]=max(dp[i],dp[i-v]+va);
}
int main()
{	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,k;
		scanf("%d%d",&m,&n);
		for(i=1; i<=n; i++)
			scanf("%d%d%d",&v[i],&va[i],&num[i]);
		for(i=1; i<=n; i++)
		{
			if(v[i]*num[i]>=m)
				cppack(v[i],va[i]);
			else
			{
				for(k=1; k<num[i]; k*=2)
				{
 					zopack(k*v[i], k*va[i]);
					num[i]-=k;
				}
				zopack(v[i]*num[i], va[i]*num[i]);
			}
		}
		printf("%d\n",dp[m]);
		memset(dp, 0, sizeof(dp));
		
	}
	return 0;
}
