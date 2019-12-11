#include<stdio.h>
#include<string.h>
int max_(int a, int b)
{
	return a>b ? a:b;
}
char str1[1000]={0};
char str2[1000]={0};
int dp[2][1000]={0};
int main()
{
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		int i,j;
		int max;
		int flag=1;
		int len1=strlen(str1);
		int len2=strlen(str2);
		
		for(i=len1; i>=1; i--)
			str1[i]=str1[i-1];
		for(i=len2; i>=1; i--)
			str2[i]=str2[i-1];
		str1[0]='0';
		str2[0]='0';

		for(i=1; i<=len1; i++)
		{
			flag=1-flag;
			for(j=1; j<=len2; j++)
			{
				if(str1[i]==str2[j])
					dp[flag][j]=dp[1-flag][j-1]+1;
				else
					dp[flag][j]=max_(dp[1-flag][j], dp[flag][j-1]);
			}
		}
		printf("%d\n",dp[flag][len2]);
		memset(dp, 0, sizeof(dp));
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
	}
	return 0;
} 