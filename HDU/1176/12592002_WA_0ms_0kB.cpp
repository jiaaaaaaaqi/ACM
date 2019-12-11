#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct cake1{
	int x;
	int T;
};
struct cake1 cake[100005];
int dp[100005][11]={0};
int cmp(const void *a, const void *b)
{
	return (*(cake1*)a).T-(*(cake1*)b).T;
}
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
		memset(dp, 0, sizeof(dp));
		cake[0].x=5,cake[0].T=0;
		for(int i=1; i<=n; i++)
			scanf("%d%d",&cake[i].x, &cake[i].T);
		qsort(cake+1, n, sizeof(cake[1]), cmp);
		int max=0;
		for(int i=1; i<=n; i++)
		{
			dp[cake[i].T][cake[i].x]=max_(dp[cake[i-1].T][cake[i].x-1], dp[cake[i-1].T][cake[i].x], dp[cake[i-1].T][cake[i].x+1])+1;
			max=max>dp[cake[i].T][cake[i].x] ? max: dp[cake[i].T][cake[i].x];
		}
		printf("%d\n", max);
	}
	return 0;
}