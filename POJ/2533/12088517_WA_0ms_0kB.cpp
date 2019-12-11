#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int num1[1005]={0};
	int num2[1005]={0};
	int dp[1005]={0};
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int i,j;
		for(i=1; i<=N; i++)
		{
			scanf("%d",&num1[i]);
			num2[i]=num1[i];
		}
		for(i=1; i<=N; i++)
		{
			for(j=i+1; j<=N; j++)
			{
				if(num2[j]>num2[i])
				{
					if(num1[i]>num1[i-1])
					{
						dp[j]+=1;
						dp[j]=max(dp[j], dp[j-1]);	
					}
					else
					{
						int time=1;
						while(num1[i]<=num1[i-time])
						{
							time++;
							if(time==i+1)
								break;
						}
						dp[j-time]+=1;
						dp[j]=max(dp[j], dp[j-time]);
					}
				}
				printf("''%d\n",dp[j]);
			}
		}
		printf("%d\n",dp[N]);
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		memset(dp, 0, sizeof(dp));
	}
	return 0;
} 