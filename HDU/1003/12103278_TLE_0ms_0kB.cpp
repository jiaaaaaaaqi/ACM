#include<stdio.h>
#include<string.h>
int num[10005]={0};
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
		if(time!=n)
		{

			long long int  a,b,sum;
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
			printf("%lld %lld %lld\n\n",maxsum, a, b);
		}
		else
		{
			long long int max=1;
			for(i=2; i<=n; i++)
				max=num[max]>num[i] ? max:i;
			printf("%d %lld %lld\n\n",num[max], max, max);
		}
	}
	return 0;
}