#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int tian[1005]={0};
		int king[1005]={0};
		for(int i=0; i<n; i++)
			scanf("%d",&tian[i]);
		for(int i=0; i<n; i++)
			scanf("%d",&king[i]);
		qsort(tian, n, sizeof(int), cmp);
		qsort(king, n, sizeof(int), cmp);
		int ts=0, ks=0;
		int tf=n-1, kf=n-1;
		int ans=0;
		for(int i=0; i<n; i++)
		{
			if(tian[tf]>king[kf])
			{
				ans+=200;
				tf--,kf--;
			}
			else if(tian[tf]<king[kf])
			{
				ans-=200;
				ts++,kf--;
			}
			else if(tian[tf]==king[kf])
			{
				if(tian[ts]>king[ks])
				{
					ans+=200;
					ts++,ks++;
				}
				else if(tian[ts]<=king[ks])
				{
					if(tian[ts]<king[kf])
					{
						ans-=200;
						ts++,kf--;
					}
					if(tian[ts]==king[kf])
					{
						ts++,kf--;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}