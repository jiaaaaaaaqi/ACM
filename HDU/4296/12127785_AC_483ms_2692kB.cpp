#include<stdio.h>
#include<stdlib.h>
struct floor{
	int w;
	int s;
	int x;
};
struct floor fl[100010];
int cmp(const void*a, const void*b)
{
	return (*(floor*)a).x-(*(floor*)b).x;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &fl[i].w, &fl[i].s);
			fl[i].x=fl[i].w+fl[i].s;
		}
		qsort(fl, n, sizeof(fl[0]), cmp);
		long long int sum=fl[0].w;
		long long int max=0;
		for(i=1; i<n; i++)
		{
			if(sum-fl[i].s>max)
			{
				max=sum-fl[i].s;
			}
			sum+=fl[i].w;
		}
		if(max<0)
			max=0;
		printf("%lld\n",max);
	}
	return 0;
}