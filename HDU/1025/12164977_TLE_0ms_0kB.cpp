#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct city{
	int r;
	int p;
};
int dp[5005]={0};
struct city ci[5005];
int cmp(const void*a, const void*b)
{
	return (*(city*)a).r-(*(city*)b).r;
}
int main()
{
	int n;
	int cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		memset(ci, 0, sizeof(ci));
		for(i=1; i<=n; i++)
			scanf("%d%d",&ci[i].r, &ci[i].p);
		
		qsort(ci+1, n, sizeof(city), cmp);
		
		int len=0;
		for(i=1; i<=n; i++)
		{
			if(ci[i].p>dp[len])
				dp[++len]=ci[i].p;
			else
			{
				int left=0, right=len, mid;
				while(left<=right)
				{
					mid=(left+right)/2;
					if(dp[mid]>ci[i].p)
						right=mid-1;
					else
						left=mid+1;
				}
				dp[left]=ci[i].p;
			}
		}
		printf("Case %d:",cas++);
		printf("My king, at most %d road can be built.\n",len);
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}