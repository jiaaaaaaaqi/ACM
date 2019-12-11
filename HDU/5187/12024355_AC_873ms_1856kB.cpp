#include<stdio.h>
long long int fast_mul(long long int a, long long int b,long long int c)
{
	long long int ans=0;
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
		long long int x=2;
		long long int ans=1;
		while(n)
		{
			if(n%2)
				ans=fast_mul(ans, x, p);
			x=fast_mul(x, x, p);
			n/=2;
		}
		ans=((ans-2)%p+p)%p;
		printf("%lld\n",ans);
	}
	return 0;
}