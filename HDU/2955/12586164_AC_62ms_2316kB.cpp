#include<stdio.h>
#include<string.h> 
double max_(double a, double b)
{
	return a>b ? a:b;
}
double dp[100005]={0}; 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int va[105]={0};
		double w[105]={0};
		double v;
		int n;
		scanf("%lf%d",&v,&n);
		int sum=0;
		for(int i=1; i<=n; i++)
		{
			double num;
			scanf("%d%lf",&va[i],&num);
			w[i]=1.0-num;
			sum+=va[i];
		}
		dp[0]=1;
		for(int i=1; i<=n; i++)
			for(int j=sum; j>=va[i]; j--)
				dp[j]=max_(dp[j], dp[j-va[i]]*w[i]);
		for(int i=sum; i>=0; i--)
			if(dp[i]>=(1-v))
			{
				printf("%d\n",i);
				break;
			}
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}