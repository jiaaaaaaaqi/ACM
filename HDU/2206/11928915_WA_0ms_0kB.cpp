#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str[10000];
int main()
{
	int num1=0;
	int len;
	int i,j,r,c;
	while(gets(str)!=NULL)
	{
		char num[4][200]={0};
		int num1=0;
		int flag=1;
		len=strlen(str);
		for(i=0; i<len; i++)
		{				
			if(!(isdigit(str[i]))&&!(str[i]=='.'))
			{
				flag=0;
				break;
			}
			if(str[i]=='.')
			{
				num1++;
			}
		}
		if(num1!=3)
			flag=0;
		
		if(flag)
		{
		r=0;				//找出数字 
		for(i=0; i<len; i++)
		{
			c=0;
			while(isdigit(str[i]))
			{
				num[r][c]=str[i];
				i++,c++;
			}
			r++;
		}	
		
		for(i=0; i<r; i++)
		{
			int len2=strlen(num[i]);
			if(len2>3)	
			{
				flag=0;
				break;
			}
			if(len2==3)
			{
				if(num[i][0]>50)	
						{flag=0; break;}
				if(num[i][0]==50)
				{
					if(num[i][1]>53)
						{flag=0; break;}
					if(num[i][1]==53)
					{
						if(num[i][2]>53)
						{flag=0; break;}
				}
			}
			}
		}
			
		}
		
		if(flag==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
} 