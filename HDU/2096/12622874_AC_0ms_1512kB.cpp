#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",(a%100+b%100)%100);
	}
	return 0;
}