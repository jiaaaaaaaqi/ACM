#include<stdio.h>
#include<string.h>
int num[100001]={0};
int dp[100001]={0};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		dp[0]=-1;
		for(i=0 ;i<n; i++)
			scanf("%d",&num[i]);
		int len=0;
		for(i=0; i<n; i++)
		{
			if(num[i]>dp[len])
				dp[++len]=num[i];
			else
			{
				int left=0,right=len,mid;
				while(left<=right)
				{
					mid=(left+right)/2;
					if(dp[mid]>=num[i])
						right=mid-1;
					else
						left=mid+1;
				}
				dp[left]=num[i];
			}
		}
		printf("%d\n",len);
		memset(dp, 0, sizeof(dp)); 
	}
	return 0;
}