#include<stdio.h>
int main()
{
	long long int a,p;
	while(scanf("%lld%lld",&p,&a),a||p)
	{
		int flag=0;
		for(int i=2; i*i<=p; i++)
			if(p%i==0)
				{
				flag=1;
				break;
				}
		if(flag)
		{
		int ans=1;
		long long int c=p,x=a,n=p;
		x=x%c;
		while(n>0)
		{
			if(n%2==1)
				ans=ans*x%c;
			x=x*x%c;
			n/=2;
		}//ans 
		if(ans==a)
			flag=1;
		else
			flag=0;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}