#include<stdio.h>
#include<string.h>
int num[100005]={0};
long long int a,b;
long long int Maxsum(long long int n)
{
	int i;
	long long int c;
	long long int  sum=0;
	long long int  maxsum=num[1];
	a=1,b=1,c=1;
	for(i=1; i<=n; i++)
	{
		sum+=num[i];
		if(maxsum<sum)
		{
			maxsum=sum;
			a=c;
			b=i;
		}
		if(sum<0)
		{
			c=i+1;
			sum=0;
		}
	}
	return maxsum;	
}
int main()
{
	int T;
	int ca;
	scanf("%d",&T);
	for(ca=1; ca<=T; ca++)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=1; i<=n; i++)
			scanf("%d",&num[i]);
		printf("Case %d:\n",ca);
		long long int ans;
		ans=Maxsum(n);
		printf("%lld %lld %lld\n",ans, a, b);
		if(ca!=T)
			printf("\n");
		memset(num, 0, sizeof(num));
	}
	return 0;
}