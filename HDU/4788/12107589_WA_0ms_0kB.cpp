#include<stdio.h>
long long int c=2147483647;
long long int fast_mul(long long int a, long long int b)
{
	long long int ans=0;
	while(b)
	{
		if(b%2)
			ans=(ans+a)%c;
		a=(a+a)%c;
		b/=2;
	}
	return ans;
}
long long int fast_mi(long long int a, long long int b)
{
	long long int ans=1;
	while(b)
	{
		if(b%2)
			ans=fast_mul(ans, a);
		a=fast_mul(a, a);
		b/=2;
	}
	return ans;
}
int main()
{
	int T;
	int ca=1;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int num;
		char str[100]={0};
		scanf("%d[%s]",&num, str);
		if(str[0]=='B')			n=0;
		else if(str[0]=='K')	n=1;
		else if(str[0]=='M')	n=2;
		else if(str[0]=='G')	n=3;
		else if(str[0]=='T')	n=4;
		else if(str[0]=='P')	n=5;
		else if(str[0]=='E')	n=6;
		else if(str[0]=='Z')	n=7;
		else if(str[0]=='Y')	n=8;
		long long int a=1000;
		long long int b=1024;
		long long int ans_1=fast_mi(a,n);
		long long int ans_2=fast_mi(b,n);
		double ans=100-((double)ans_1/(double)ans_2)*100;
		printf("Case #%d: %.2lf%%\n",ca++, ans);
	}
	return 0;
}