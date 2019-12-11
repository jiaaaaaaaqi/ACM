#include<stdio.h>
#include<string.h>
#include<ctype.h>
char bull[5000]={0};
int score[5000]={0};
char str1[5000]={0};
char str2[5000]={0};
int dp[2][5000]={0};
int max_(int a, int b)
{
	return a>b ? a:b;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	    getchar();
		int i,j;
		scanf("%s", bull);
		
		for(i=1; i<=n; i++)
			scanf("%d", &score[bull[i-1]-'a']);	
        getchar();

		scanf("%s",str1);
		scanf("%s",str2);

		int len1= strlen(str1);
		int len2= strlen(str2);
		for(i=len1-1; i>=0; i--)
			str1[i+1]=str1[i];
		for(i=len2-1; i>=0; i--)
			str2[i+1]=str2[i];
		str1[0]=0;
		str2[0]=0;

		int flag=1;
		for(i=1; i<=len1; i++)
		{
			flag=1-flag;
			for(j=1; j<=len2; j++)
			{
				if(str1[i]==str2[j])
					dp[flag][j]=dp[1-flag][j-1]+score[str1[i]-'a'];
				else
					dp[flag][j]=max_(dp[flag][j-1], dp[1-flag][j]);
			}
		}
		printf("%d\n",dp[flag][n]);
		memset(bull, 0, sizeof(bull));
		memset(score, 0, sizeof(score));
		memset(dp, 0, sizeof(dp));
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
	}
	return 0;
}
