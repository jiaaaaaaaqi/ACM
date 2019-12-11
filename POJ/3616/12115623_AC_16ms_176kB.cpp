#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct cows{
	int st;
	int edd;
	int eff;
};
int cmp(const void*a, const void*b)
{
	return (*(cows*)a).st-(*(cows*)b).st;
}
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int v,n,r;
	while(scanf("%d%d%d",&v,&n,&r)!=EOF)
	{
		int dp[1005]={0};
		v+=2;
		struct cows cow[1005];
		int i,j;
		for(i=1; i<=n; i++)
		{
			scanf("%d%d%d",&cow[i].st,&cow[i].edd,&cow[i].eff);
			cow[i].edd+=r;
		}
		qsort(cow+1, n, sizeof(cow[0]), cmp);		
		int max=0;
		for(i=1; i<=n; i++)
		{
			dp[i]=cow[i].eff;
			for(j=1; j<i; j++)
			{
				if(cow[i].st>=cow[j].edd)
					dp[i]=max_(dp[i], dp[j]+cow[i].eff);
			}
			max=max_(max, dp[i]);
		}
		printf("%d\n",max);
	}
	return 0;
} 