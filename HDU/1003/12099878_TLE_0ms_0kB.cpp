	#include<stdio.h>
#include<string.h>
long long int num[10005]={0};
long long int dp[2][10005]={0};
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
		int time=0;
		scanf("%lld",&n);
		for(i=1; i<=n; i++)
		{
			scanf("%lld", &num[i]);
			if(num[i]<0)
				time++;
		}
		if(time==n)
		{
			for(i=1; i<=n; i++)
			{
				dp[0][i]=-99999; 
				dp[1][i]=-99999;
			} 
		}
		long long int max;
		for(i=1; i<=n; i++)
		{
			max=num[1];
			flag=1;
			b[i]=1;
			for(j=i; j<=n; j++)
			{
				flag=1-flag;
				dp[flag][i]=dp[1-flag][i]+num[j];
				if(dp[flag][i]>=max)
				{
					max=dp[flag][i];
					b[i]=j;
				}
			}
			dp[flag][i]=max;
			i=j;
		}
		long long int max_=1;
		for(i=2; i<=n; i++)
			max_ = dp[flag][i]>dp[flag][max_] ? i:max_;
		printf("%lld %lld %lld\n",dp[flag][max_], max_, b[max_]);
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		memset(b, 0, sizeof(b));
	}
	return 0;
}
