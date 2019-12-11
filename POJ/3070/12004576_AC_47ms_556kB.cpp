#include<stdio.h>
#include<string.h>
int fib[100000]={0};
int main()
{
	long long int n;
	while(scanf("%lld",&n),n!=-1)
	{
		n=n%30000;
		long long int i;
		fib[0]=0,fib[1]=1;
		for(i=2; i<=n; i++)
		{
			fib[i]=(fib[i-1]+fib[i-2])%10000;
		}
		printf("%d\n",fib[n]);
		memset(fib, 0, sizeof(fib));
	}
	return 0;
}