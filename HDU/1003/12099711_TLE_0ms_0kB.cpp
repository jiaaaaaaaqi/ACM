#include<stdio.h>
#include<string.h>
long long int num[10005]={0};
long long int dp[2][10005]={0};
long long int a[10005]={0};
long long int b[10005]={0};

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int n;
		long long int i,j,z=1;
		int flag;
		scanf("%lld",&n);
		a[0]=1;
		for(i=1; i<=n; i++)
		{
			scanf("%lld", &num[i]);
			if(num[i]>=0&&num[i-1]<0)
				a[z++]=i;
		}
		int flag_=0;
		if(num[1]>0&&num[n]<0)
		{
			flag_=1;
			z++;
		}
		if(z!=1)
		{
			if(flag_)
				z--;
			long long int max;
			for(i=0; i<z; i++)
			{
				max=0;
				flag=1;
				for(j=a[i]; j<=n; j++)
				{
					flag=1-flag;
					dp[flag][a[i]]=dp[1-flag][a[i]]+num[j];
					if(dp[flag][a[i]]>max)
					{
						max=dp[flag][a[i]];
						b[a[i]]=j;
					}
				}
				dp[flag][a[i]]=max;
			}
			long long int max_=0;
			for(i=1; i<=n; i++)
				max_ = dp[flag][i]>dp[flag][max_] ? i:max_;
			printf("%lld %lld %lld\n",dp[flag][max_], max_, b[max_]);
		}
		else
		{
			if(num[1]<0)
			{
				long long int min=1;
				for(i=2; i<=n; i++)
					min=num[min]>num[i] ? min:i;
				printf("%lld %lld %lld\n",num[min], min, min);
			}
			if(num[1]>0)
			{
				long long int min=0;
				for(i=1; i<=n; i++)
					min+=num[i];
				printf("%lld 1 %lld\n",min, n);
			}
		}
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	return 0;
}
