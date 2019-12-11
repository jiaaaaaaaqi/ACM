#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,n,c;
		scanf("%d%d%d",&x,&n,&c);
		int ans=1;
		x=x%c;
		while(n>0)
		{
			if(n%2==1)	
				ans=(ans*x)%c;
			x=(x*x)%c;
			n/=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}