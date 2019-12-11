#include<stdio.h>
#include<string.h>
char str1[5005]={0};
char str2[5005]={0};
int dp[5005]={0};
int max(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		getchar();
		char c;
		int i=1,j=N;
		while(scanf("%c",&c),c!='\n')
		{
			str1[i++]=c;
			str2[j--]=c;
		}
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
			{
				if(str1[i]==str2[j])
					dp[j]=dp[j-1]+1;
				else
					dp[j]=max(dp[j], dp[j-1]); 
			}
		int ans=0;
		ans=N-dp[N];
		printf("%d\n",ans);
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}