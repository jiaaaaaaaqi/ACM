#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		int ans=1;
		int n;
		scanf("%d",&n);
		int x=n;
		while(n>0)
		{
			if(n%2==1)	ans=(ans*x)%10;
			x=(x*x)%10;
			n/=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}