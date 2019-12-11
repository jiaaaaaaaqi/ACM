#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		int i,j;
		char str[2][100];
		for(i=0; i<2; i++)
			gets(str[i]);
		int len1=strlen(str[0]);
		int len2=strlen(str[1]);

		for(i=0; i<len1; i++)		//输出第一行 
		{
			if(str[0][i]!='<'&&str[0][i]!='>')
			printf("%c",str[0][i]);
		}
		printf("\n");
		
		int m=0,n=0;
		char s1[2][100]={0};
		char s2[2][100]={0};
		for(i=0; i<len1; i++)
		{
			int num=0;
			if(str[0][i]=='<')		//两个<> 
			{
				for(j=i+1; str[0][j]!='>'; j++)
				{
					s1[m][num]=str[0][j];
					num++;
				}
				m++;
			}
			
			if(str[0][i]=='>')
			{
				if(n==0)
				{
				for(j=i+1; str[0][j]!='<'; j++)
				{
					s2[n][num]=str[0][j];
					num++;
				}
				n++;
				}
				else
				{
				for(j=i+1; str[0][j]!='\0'; j++)
				{
					s2[n][num]=str[0][j];
					num++;					
				}
				}
			}
		}
		for(i=0; i<len2-3; i++)	
			printf("%c",str[1][i]);
		for(i=0; s1[1][i]!='\0'; i++)
			printf("%c",s1[1][i]);
		for(i=0; s2[0][i]!='\0'; i++)
			printf("%c",s2[0][i]);
		for(i=0; s1[0][i]!='\0'; i++)
			printf("%c",s1[0][i]);
		for(i=0; s2[1][i]!='\0'; i++)
			printf("%c",s2[1][i]);
		printf("\n");
	}
	return 0;
} 