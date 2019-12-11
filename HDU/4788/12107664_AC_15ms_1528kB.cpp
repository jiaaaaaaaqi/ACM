#include<stdio.h>
double fast_mi(double a, int b)
{
	double ans=1;
	while(b)
	{
		if(b%2)
			ans*=a;
		a*=a;
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
		double a=1000;
		double b=1024;
		double ans=a/b;
		ans=fast_mi(ans, n)*100;
		ans=100-ans;
		printf("Case #%d: %.2lf%%\n",ca++, ans);
	}
	return 0;
}