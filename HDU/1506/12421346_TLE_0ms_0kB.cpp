#include<stdio.h>
#include<string.h>
long long int rec[100006]={0};
int	max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	long long int n;
	while(scanf("%lld",&n),n)
	{
		long long int ans=0,max=0;
		long long int st;
		long long int i,j,k;
		for(i=1; i<=n; i++)
			scanf("%d",&rec[i]);
		rec[n+1]=-1;
		for(i=1; i<=n; i++)
		{
			st=i;
			for(j=i; rec[j+1]>=rec[j]; j++);
			for(k=j; k>=1;k--)
			{
				max=max_(max, rec[k]*(j-k+1));
			}
			ans=max_(ans, max);
			for(i=st; i<=j; i++)
				rec[i]=rec[j+1];
		}
		printf("%lld\n",ans);
		memset(rec, 0 ,sizeof(rec));
	}
	return 0;
} 