#include<stdio.h>
#include<string.h> 
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int dp[105]={0}; 
		int va[105]={0};
		int w[105]={0};
		float num;
		int n;
		scanf("%f%d",&num,&n);
		int v=(int)(num*100);
		for(int i=1; i<=n; i++)
		{
			scanf("%d%f",&va[i],&num);
			w[i]=(int)(num*100);
		}
		for(int i=1; i<=n; i++)
			for(int j=v; j>=w[i]; j--)
				dp[j]=max_(dp[j], dp[j-w[i]]+va[i]);
		printf("%d\n",dp[v]);
	}
	return 0;
}