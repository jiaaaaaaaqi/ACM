#include<stdio.h>
long long int c=2147493647ll;
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
void fast_mat(long long int a[7][7], long long int b[7][7])
{
	int i,j,k;
	long long int ans[7][7]={0};
	for(i=0; i<7; i++)
		for(j=0; j<7; j++)
			for(k=0; k<7; k++)
			{
				ans[i][j]+=fast_mul(a[i][k], b[k][j]);
				ans[i][j]%=c;
			}
	for(i=0; i<7; i++)
		for(j=0; j<7; j++)
			a[i][j]=ans[i][j];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int num[7]={0,0,16,8,4,2,1};
		long long int n,i,j;
		long long int f[7][7]={
								{1,1,0,0,0,0,0},
								{2,0,0,0,0,0,0},
								{1,0,1,0,0,0,0},
								{4,0,4,1,0,0,0},
								{6,0,6,3,1,0,0},
								{4,0,4,3,2,1,0}, 
								{1,0,1,1,1,1,1},
							};
		long long int ans[7][7]={0};
		for(i=0; i<7; i++)
			for(j=0; j<7; j++)
				ans[i][j]=(i==j);

		scanf("%lld%lld%lld",&n,&num[1],&num[0]);

		if(n==2)
			printf("%lld\n",num[0]);

		if(n==1)
			printf("%lld\n",num[1]);

		else
		{
			n-=2;
			while(n)
			{
				if(n%2)
					fast_mat(ans, f);
				fast_mat(f,f);
				n/=2;
			}
			long long int ans_=0;
			for(i=0; i<7; i++)
			{
				ans_+=fast_mul(ans[i][0], num[i]);
				ans_%=c;
			}
			printf("%lld\n",ans_);
		}
	}
	return 0;
}