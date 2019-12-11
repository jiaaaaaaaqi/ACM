#include<stdio.h>
#include<string.h>
void mul(int a[2][2], int b[2][2])
{
	int ans_[2][2]={0};
	memset(ans_, 0, sizeof(ans_));
	int i,j,k;
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			for(k=0; k<2; k++)
				ans_[i][j]+=a[i][k]*b[k][j];
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			a[i][j]=ans_[i][j];
}
int main()
{
	int n;
	while(scanf("%d",&n),n!=-1)
	{
		int fib[2][2];
		int ans[2][2];
		fib[0][0]=1,fib[0][1]=1,fib[1][0]=1,fib[1][1]=0;
		int i,j;
		for(i=0; i<2; i++)
			for(j=0; j<2; j++)
				ans[i][j]=(i==j);
		while(n)
		{
			if(n%2)
				mul(ans,fib);
			mul(fib,fib);
			n/=2;
		}
		printf("%d\n",ans[0][1]);
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}