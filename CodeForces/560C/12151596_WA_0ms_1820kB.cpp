#include<stdio.h>
int main()
{
	long long int a1,a2,a3,a4,a5,a6;
	while(scanf("%lld%lld%lld%lld%lld%lld",&a1,&a2,&a3,&a4,&a5,&a6)!=EOF)
	{
		long long int a=a1>a2 ? a1:a2;
		long long int b=a1<a2 ? a1:a2;
		long long int c=(a+2*b);
		long long int ans=(c*c-b*b*3);
		printf("%lld\n",ans);
	}
	return 0;
}