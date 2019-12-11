#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}

long long int min_(long long int a, long long int b)
{
	return a<b ? a:b;
}

long long int num[200005]={0};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0; i<n; i++)
			scanf("%lld",&num[i]);
		qsort(num, n, sizeof(num[0]), cmp);
		int x=n/2;
		long long int min=num[x]-num[0];
		for(i=1; i<n-x; i++)
		{
			min=min_(min, num[i+x]-num[i]);
		}
		printf("%lld\n",min);
	}
	return 0;
}