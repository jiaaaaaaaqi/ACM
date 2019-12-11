#include<stdio.h>
int main()
{
	long long int a1,a2,a3,a4,a5,a6;
	while(scanf("%lld%lld%lld%lld%lld%lld",&a1,&a2,&a3,&a4,&a5,&a6)!=EOF)
	{
		long long int ans;
		ans=(a1+a2+a3);
		ans*=ans;
		ans-=a1*a1;
		ans-=a3*a3;
		ans-=a5*a5;
		printf("%lld\n",ans);
	}
	return 0;
}