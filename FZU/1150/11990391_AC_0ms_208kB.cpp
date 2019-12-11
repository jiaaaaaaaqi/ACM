#include<stdio.h>
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int m=n;
		int a;
		a=n/k;
		m+=a;
		a+=(n-a*k);
		while(a>=k)
		{
			n=a;
			a=n/k;
			m+=a;
			a+=n-a*k;
		}
		printf("%d\n",m);
	}
	return 0;
}