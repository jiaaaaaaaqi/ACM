#include<stdio.h>
int fast_mul(int a, int b,int c)
{
	int ans=0;
		while(b)
		{
			if(b%2)
				ans=(ans+a)%c;
			a=(a+a)%c;
			b/=2;
		}
	return ans;
}
int main()
{
	long long int n,p;
	while(scanf("%lld%lld",&n,&p)!=EOF)
	{
		int x=2;
		int ans=1;
		if(n!=1)
		{
		while(n)
		{
			if(n%2)
				ans=fast_mul(ans, x, p);
			x=fast_mul(x, x, p);
			n/=2;
		}
		ans=((ans-2)%p+p)%p;
		printf("%d\n",ans);
		}
		else
		printf("1\n");
	}
	return 0;
}