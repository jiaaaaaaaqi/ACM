#include<stdio.h>
int c=2008;
long long int num[100000005]={0};
long long int fast_mi(long long int n)
{
	int a=2;
	long long int ans=1;
	while(n)
	{
		if(n%2)
			ans=ans*a%c;
		a=a*a%c;
		n/=2;
	}
	return ans;
}

long long int ca(long long int n)
{
	if(num[n]!=0)
		return num[n];
	num[n]=fast_mi(n)-2;
	long long int i;
	for(i=2; i*i<=n; i++)
	{
		if(i*i==n)
			num[n]=(num[n]-ca(i)+c)%c;
		else if(n%i==0)
		{
			num[n]=(num[n]-ca(i)+c)%c;
			num[n]=(num[n]-ca(n/i)+c)%c;
		}
	}
	return num[n];
}

int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		num[1]=2;
		num[2]=2;
		if(n<3)
			printf("%lld",num[n]);
		else
		{
			long long int ans=ca(n);
			printf("%lld",ans%c);
		}
		printf("\n");
	}
	return 0;
}