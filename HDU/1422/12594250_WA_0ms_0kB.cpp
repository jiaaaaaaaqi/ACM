#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct city1{
	int get;
	int cost;
	int diff;
};
struct city1 city[100005];
int cmp(const void*a, const void*b)
{
	return (*(city1*)b).diff-(*(city1*)a).diff;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&city[i].get, &city[i].cost);
			city[i].diff=city[i].get-city[i].cost;
		}
		qsort(city+1, n, sizeof(city[1]), cmp);
		int sum=0;
		int flag=0;
		for(int i=1; i<=n; i++)
		{
			sum+=city[i].diff;
			if(sum<0)
			{
				sum=i-1;
				flag=1;
				break;
			} 
		}
		if(flag)
			printf("%d\n",sum);
		else
			printf("%d\n",n);
	}
	return 0;
} 