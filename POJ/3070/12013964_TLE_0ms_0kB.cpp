#include<stdio.h>
int main()
{
	int fib[4]={0};
	long long int N;
	while(scanf("%lld",&N),N!=-1)
	{
		long long int i=2;
		fib[0]=0, fib[1]=1;
		if(N<2)	printf("%d",fib[N]);
		else
		{
			for(i=2; i<=N; i++)
			{
				fib[2]=(fib[0]+fib[1])%10000;
				fib[0]=fib[1];
				fib[1]=fib[2];
			}
			printf("%d",fib[2]);
		}
		printf("\n");
	}
	return 0;
}