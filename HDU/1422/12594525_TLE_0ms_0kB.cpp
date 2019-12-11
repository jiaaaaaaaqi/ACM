#include<stdio.h>
#include<string.h>
int main()
{
    int diff[200]={0};
    int dp[200]={0};
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
		{
			int num1, num2;
			scanf("%d%d",&num1, &num2);
			diff[i]=num1-num2;
		}
		for(int i=n+1; i<2*n; i++)
			diff[i]=diff[i-n];
		dp[0]=0;
		int ans=0;
		int sum=0;
		int cnt=0;
		for(int i=1; i<2*n; i++)
		{
			sum+=diff[i];
			if(sum>=0)
            {
                cnt++;
                if(cnt>ans)
                    ans=cnt;
                if(cnt==n)
                    break;
            }
			if(sum<0)
			{
				cnt=0;
				sum=0;
			}
		}
		printf("%d\n",ans);
		memset(diff, 0, sizeof(diff));
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}
