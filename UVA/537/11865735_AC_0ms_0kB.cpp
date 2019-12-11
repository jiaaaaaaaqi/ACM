#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int N,z;
	scanf("%d",&N);
	getchar();
	for(z=1; z<=N; z++)
	{
		int flag;
		int i,j;
		char str[100];
		float x,y;
		float I=0,U=0,P=0;
		int flag_I=0;
		int flag_U=0;
		int flag_P=0;
		float mul,num;
		gets(str);
		int len=strlen(str);
		for(i=0; i<len; i++)
		{
			flag=0;
			mul=1,num=1;
			x=0,y=0;
			if(str[i]=='U'&&str[i+1]=='=')		//U 
			{
				num=1;
				x=0,y=0;				
				flag_U=1;
				for(j=i+2; ; j++)
				{
					if(isdigit(str[j]))
					x=x*10+(str[j]-48);
					if(str[j]=='.')
					{
					for(j=j+1; str[j]!='V'&&str[j-1]!='m'&&str[j-1]!='k'&&str[j-1]!='M'; j++)
					{
						if(isdigit(str[j]))
						{
							y=y*10+(str[j]-48);
							num/=10;
						}
					}
					}
					if(str[j]=='V')
					{
						flag=1;
						if(str[j-1]=='m')		mul=0.001;
						else if(str[j-1]=='k')	mul=1000;
						else if(str[j-1]=='M')	mul=1000000;
						else mul=1;
						break; 
					}
					if(flag==1)	break;
				}
			U=x+y*num;
			U=U*mul;
			break;
			}
		}
		for(i=0; i<len; i++)
		{
			flag=0;
			mul=1,num=1;
			x=0,y=0;
			if(str[i]=='I'&&str[i+1]=='=')		//I
			{
				num=1;
				x=0,y=0;						
				flag_I=1;
				for(j=i+2; ; j++)
				{
					if(isdigit(str[j]))
					x=x*10+(str[j]-48);
					if(str[j]=='.')
					{
					for(j=j+1; str[j]!='A'&&str[j-1]!='m'&&str[j-1]!='k'&&str[j-1]!='M'; j++)
					{
						if(isdigit(str[j]))
						{
							y=y*10+(str[j]-48);
							num/=10;
						}
					}
					}
					if(str[j]=='A')
					{
						flag=1;
						if(str[j-1]=='m')		mul=0.001;
						else if(str[j-1]=='k')	mul=1000;
						else if(str[j-1]=='M')	mul=1000000;
						else mul=1;
						break; 
					}
					if(flag==1)	break;
				}
			I=x+y*num;
			I=I*mul;
			break;
			}
		}
		for(i=0; i<len; i++)
		{	
			flag=0;	
			mul=1,num=1;
			x=0,y=0;								
			if(str[i]=='P'&&str[i+1]=='=')		//P
			{
				num=1;
				x=0,y=0;		
				flag_P=1;
				for(j=i+2; ; j++)
				{
					if(isdigit(str[j]))
					x=x*10+(str[j]-48);
					if(str[j]=='.')
					{
					for(j=j+1; str[j]!='W'&&str[j-1]!='m'&&str[j-1]!='k'&&str[j-1]!='M'; j++)
					{
						if(isdigit(str[j]))
						{
							y=y*10+(str[j]-48);
							num/=10;
						}
					}
					}
					if(str[j]=='W')
					{
						flag=1;
						if(str[j-1]=='m')		mul=0.001;
						else if(str[j-1]=='k')	mul=1000;
						else if(str[j-1]=='M')	mul=1000000;
						else mul=1;
						break; 
					}
					if(flag==1)	break;
				}
			P=x+y*num;
			P=P*mul;
			break;
			}
		}	
		printf("Problem #%d\n",z);
		if(flag_I&&flag_U)
		printf("P=%.2fW\n\n",U*I);
		else if(flag_I&&flag_P)
		printf("U=%.2fV\n\n",P/I);
		else if(flag_U&&flag_P)
		printf("I=%.2fA\n\n",P/U); 
	}
	return 0;
}