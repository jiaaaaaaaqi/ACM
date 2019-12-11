#include<stdio.h>
#include<string.h>
int num[260*260]={0};
int flag[260*260]={0};
int dp[260*260]={0};
int solve(int n)
{
	int len=0;
	dp[0]=-1;
	for(int i=0; i<n; i++)
	{
		if(num[i]>dp[len])
			dp[++len]=num[i];
		else
		{
			int l=1,r=len,mid;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(dp[mid]>=num[i])
					r=mid-1;
				else
					l=mid+1;
			}
			dp[l]=num[i];
		}
	}
	return len;
}
int main()
{
	int T;
	scanf("%d",&T);
	int cas=1;
	while(T--)
	{
		int n,p,q;
		scanf("%d%d%d",&n,&p,&q);
		p++,q++;
		int num1;
		for(int i=1; i<=p; i++)
		{
			scanf("%d",&num1);
			flag[num1]=i;
		}
		int j=0;
		for(int i=1; i<=q; i++)
		{
			scanf("%d",&num1);
			if(flag[num1])
				num[j++]=flag[num1];
		}
		int ans=solve(j);
		printf("Case %d: %d\n",cas++, ans);
		memset(flag, 0, sizeof(flag));
		memset(num, 0, sizeof(num));
	}
	return 0;
}