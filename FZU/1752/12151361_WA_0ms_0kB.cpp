#include<stdio.h>
long long int c;
long long fast_mul(long long int a, long long int b)
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
	long long int a,b;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
	{
		long long int ans=1;
		while(b)
		{
			if(b%2)
				ans=fast_mul(ans, a);
			a=fast_mul(a, a);
			b/=2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}