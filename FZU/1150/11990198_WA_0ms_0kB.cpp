#include<stdio.h>
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int a=n/k;
		while(!(a<k))
		{
			n+=a;
			a=a/k;
		}
		n+=a; 
		printf("%d\n",n);
	}
	return 0;
}