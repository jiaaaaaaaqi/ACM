#include<stdio.h>
long long int c=1000000007;

long long int fast_mul(long long int a, long long int b)
{
	long long int ans=0;
	while(b)
	{
		if(b%2)
			ans=(ans+a);
		a=(a+a);
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
			ans=(ans*a)%c;
		a=(a*a)%c;
		b/=2;
	}
	return ans;
}

void fast_mat(long long int a[2][2], long long int b[2][2])
{
	long long int ans[2][2]={0};
	int i,j,k;
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			for(k=0; k<2; k++)
				ans[i][j]+=(a[i][k]*b[k][j])%(c-1);

	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			a[i][j]=ans[i][j];
}

int main()
{
	long long int a,b,n;
	while(scanf("%lld%lld%lld",&a,&b,&n)!=EOF)
	{
		if(n>1)
		{
			n--;
			long long int f[2][2]={{1,1},{1,0}};
			long long int ans[2][2]={0};
			int i,j;
			for(i=0; i<2; i++)
				for(j=0; j<2; j++)
					ans[i][j]=(i==j);
			while(n)
			{
				if(n%2)
					fast_mat(ans, f);
				fast_mat(f, f);
				n/=2;
			}
			long long int ans_a=fast_mi(a, ans[1][0]);
			long long int ans_b=fast_mi(b, ans[0][0]);
			long long int ans_=fast_mul(ans_a, ans_b)%c;
			printf("%lld\n",ans_);
		}
		else if(n==1)
			printf("%lld\n",b%c);
		else
			printf("%lld\n",a%c);
	}
	return 0;
} 