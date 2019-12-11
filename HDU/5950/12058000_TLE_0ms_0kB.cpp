#include<stdio.h>
#include<string.h>
long long int c=2147493647;
int fast_mul(int a, int b)
{
	int ans=0;
	while(b)
	{
		if(b%2)
			ans=(ans+a)%c;
		a=(a+a)%c;
		b/=2;
	}
	return ans;
}
int fast_mi(int a, int b)
{
	int ans=1;
	while(b)
	{
		if(b%2)
			ans=fast_mul(ans, a)%c;
		a=fast_mul(a, a)%c;
		b/=2;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int num[10];
		int N,a,b;
		while(scanf("%d%d%d",&N,&a,&b)!=EOF)
		{
			int x,y;
			int z=4;
			int i;
			num[1]=a;
			num[2]=b;
			if(N<=2)
				printf("%d\n",num[N]);
			else
			{
				for(i=3; i<=N; i++)
				{
					x=fast_mul(2,num[1]);
					y=fast_mi(i,z);
					num[3]=(x+num[2])%c;
					num[3]=(num[3]+y)%c;
					num[1]=num[2];
					num[2]=num[3];
				}
			}
			printf("%d\n",num[3]);
		}
		memset(num, 0, sizeof(num));
	}
	return 0;
}
