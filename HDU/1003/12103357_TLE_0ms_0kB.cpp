#include<stdio.h>
#include<string.h>
int num[10005]={0};
long long int a,b;
long long int Maxsum1(int num[], long long int n)
{
	int i,j;
	long long int  sum;
	long long int  maxsum=0;
	for(i=1; i<=n; )
	{
		sum=0;
		a=i;
		for(j=i; j<=n; j++)
		{
			sum=sum+num[j];
			if(maxsum<sum)
			{
				maxsum=sum;
				b=j;
			}
			if(sum<0)
			{
				i=j+1;
				break;
			}
		}
	i=j+1;			
	}
	return maxsum;	
}
long long int Maxsum2(int num[], long long int n)
{
	a=1;
	int i;
	for(i=2; i<=n; i++)
		a=num[a]>num[i] ? a:i;
	b=a;
	return num[a];
}
int main()
{
	int T;
	int ca=1;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int i,j;
		int time=0;
		for(i=1; i<=n; i++)
		{
			scanf("%d",&num[i]);
			if(num[i]<0)
				time++;
		}
		printf("Case %d:\n",ca++);
		long long int ans;
		if(time!=n)
			ans=Maxsum1(num, n);
		else
			ans=Maxsum2(num, n);
		printf("%lld %lld %lld\n\n",ans, a, b);
		memset(num, 0, sizeof(num));
	}
	return 0;
}