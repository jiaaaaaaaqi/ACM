#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
}