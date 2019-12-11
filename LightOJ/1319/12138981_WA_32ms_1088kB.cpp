#include<stdio.h>
void e_gcd(long long int a,long long int b,long long int &x,long long int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	e_gcd(b, a%b, x, y);
	long long int temp=x;
	x=y;
	y=temp-(a/b)*y;
}
int CRT(long long int a[],long long int b[], int n)
{
	long long int ans=0;
	int i;
	long long int M=1;
	for(i=0; i<n; i++)
		M*=a[i];
	for(i=0; i<n; i++)
	{
		long long  int x,y;
		long long int Mi=M/a[i];
		e_gcd(Mi, a[i], x, y);
		ans=(ans+b[i]*Mi*x)%M;
	}
	if(ans<0)
		ans+=M;
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
		int i;
		long long int p[20]={0},r[20]={0};
		scanf("%d",&n);
		for(i=0; i<n; i++)
			scanf("%lld%lld",&p[i], &r[i]);
		long long int ans=CRT(p, r, n);
		printf("Case %d: %lld\n", ca++, ans);
	}
	return 0;
}