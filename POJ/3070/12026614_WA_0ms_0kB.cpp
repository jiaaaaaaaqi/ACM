#include<stdio.h>
int fast_mul(int a, int b)
{
	int ans=0;
	while(b)
	{
		if(b%2)
			ans=(ans+a)%10000;
		a=(a+a)%1000;
		b/=2;
	}
	return ans;
}
void fast_mat(int a[2][2], int b[2][2])
{
	int ans[2][2]={0};
	int i,j,k;
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			for(k=0; k<2; k++)
			{
				ans[i][j] += fast_mul(a[i][k], b[k][j]);
				ans[i][j] %= 10000;
			}
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			a[i][j]=ans[i][j];
}
int main()
{
	int fib[2][2]={0};
	int n;
	while(scanf("%d",&n),n!=-1)
	{
		int i,j;
		fib[1][1]=0,fib[0][1]=1,fib[1][0]=1,fib[0][0]=1;
		int ans[2][2]={0};
		for(i=0; i<2; i++)
			for(j=0; j<2; j++)
				ans[i][j]=(i==j);
		while(n)
		{
			if(n%2)		fast_mat(ans,fib);
			fast_mat(fib,fib);
			n/=2;
		}
		printf("%d\n",ans[1][0]);
	}
	return 0;
}