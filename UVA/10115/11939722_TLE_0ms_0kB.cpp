#include<stdio.h>
#include<string.h>
#include<ctype.h>
	char str1[1000][1000];
	char str2[1000][1000];
	char str[8000];
	char s[10000];
int main()
{
	int N;
	while(scanf("%d",&N),N!=0)
	{
		getchar();
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		memset(str,0,sizeof(str));
		int num;
		int i_swap,j_swap;
		int i,j,r,c,m,len;
		for(i=0; i<N; i++)
		{
			gets(str1[i]);
			gets(str2[i]);
		}
		gets(str);
		memset(s,0,sizeof(s));
		strcpy(s,str);
//////////////////////////////////////////////////////////////		
		for(i=0; i<N; i++)
		{
			int flag=0; 
			int len1=strlen(str1[i]);
			int len2=strlen(str2[i]);
			len=0;
			for(int z=0; s[z]!=0; z++)
				len++;
			for(r=0; r<len; r++)
			{
				num=0,m=r,j=0;
				while(s[m]==str1[i][j])
				{
					num++,m++,j++;
					if(num==len1)
						break;
				}
				if(num==len1)
				{
					int x=len1-len2;
					if(x>0)
					{
						for(i_swap=r+len1; i_swap<len; i_swap++)
						{
							s[i_swap-x]=s[i_swap];
							s[i_swap]=0;
						}
					}
					if(x<0)
					{
						for(i_swap=len-1; i_swap>=r+len1; i_swap--)
							s[i_swap-x]=s[i_swap];
					}
					for(j_swap=0; j_swap<len2; j_swap++)
					{
						s[r]=str2[i][j_swap];
						r++;
					}
					flag=1;
					break;
				}		
			}
			if(flag==1)
			{
				i=-1;
				continue;
			}
		}
		printf("%s\n",s);
	}
	return 0;
} 