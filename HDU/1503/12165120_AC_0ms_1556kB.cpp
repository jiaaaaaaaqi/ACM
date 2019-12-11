#include<stdio.h>
#include<string.h>
int dp[2][110]={0};
int flag[110][110]={0};
char str1[110]={0};
char str2[110]={0};
void pri(int i, int j)
{
	if(i==0&&j==0)
		return ;
	if(flag[i][j]==0)
	{
		pri(i-1,j-1);
		printf("%c",str1[i-1]);
	}
	else if(flag[i][j]==1)
	{
		pri(i-1, j);
		printf("%c",str1[i-1]);
	}
	else
	{
		pri(i, j-1);
		printf("%c",str2[j-1]);
	}
}
int main()
{
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		int i,j;
		int len1=strlen(str1);
		int len2=strlen(str2);
		
		for(i=0; i<=len1; i++)
			flag[i][0]=1;
		for(i=0; i<=len2; i++)
			flag[0][i]=-1;
			
		int flag_=0;
		for(i=1; i<=len1; i++)
		{
			flag_=1-flag_;
			for(j=1; j<=len2; j++)
			{
				if(str1[i-1]==str2[j-1])
				{
					dp[flag_][j]=dp[1-flag_][j-1]+1;
					flag[i][j]=0;
				}
				else
				{
					if(dp[1-flag_][j]>dp[flag_][j-1])
					{
						dp[flag_][j]=dp[1-flag_][j];
						flag[i][j]=1;
					}
					else
					{
						dp[flag_][j]=dp[flag_][j-1];
						flag[i][j]=-1;
					}
				}
			}
		}
		pri(len1, len2);
		printf("\n");
		memset(dp, 0, sizeof(dp));
		memset(flag, 0, sizeof(flag));
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
	}
	return 0;
}