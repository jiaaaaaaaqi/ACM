#include<stdio.h>
unsigned long long int c;
unsigned long long fast_mul(unsigned long long int a,unsigned long long int b)
{
		unsigned long long int ans=1;
		while(b)
		{
			if(b&1)
			{
				ans=ans*a;
				while(ans>=c)
					ans-=c;
				b--;
			}
			b=b>>1;
			a=a*a;
			while(a>=c)
				a-=c;
		}
	return ans;
}
int main()
{
	unsigned long long int a,b;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
	{
		printf("%lld\n",fast_mul(a,b));
	}
	return 0;
}
