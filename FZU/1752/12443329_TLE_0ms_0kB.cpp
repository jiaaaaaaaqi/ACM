#include<stdio.h>
unsigned long long int c;
int main()
{
	unsigned long long int a,b;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
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
		printf("%lld\n",ans);
	}
	return 0;
}
