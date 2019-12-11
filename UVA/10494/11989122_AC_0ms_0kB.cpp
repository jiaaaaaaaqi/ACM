#include<stdio.h>
#include<string.h>
#include<ctype.h>
char num1[1000]={0};
char num2[100]={0};
char num3[1000]={0};
char ans[1000]={0};
int cmp(char a[], char b[], int len1, int len2)
{
	if(len1<len2)
		return -1;
	if(len1==len2)
	{
		if(strcmp(a,b)==0)
			return 0;
		if(strcmp(a,b)>0)
			return 1;
		if(strcmp(a,b)<0)
			return -1;
	}
	if(len1>len2)
		return 1;
}
void numswap(char a[], int n)
{
	int temp;
	for(int i=0; i<=n/2-1; i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
}
void sub(char num1[], char num2[], int len1, int len2)
{
	numswap(num1, len1);
	numswap(num2, len2);
	int i,j; 
	for(i=0; i<len1; i++)
	{
		if(i<len2)
			num1[i]-=num2[i];
		if(i>=len2)
			num1[i]=num1[i]-48;
	}
	for(i=0; i<len1; i++)
		if(num1[i]<0)
		{
			num1[i]+=10;
			num1[i+1]-=1;
		}
	for(i=0; i<len1; i++)
		num1[i]+=48;
	int time=0;
	i=len1-1;
	while(num1[i]=='0')
	{
		time++;
		i--;
	}
	if(time!=len1)
	{
		for(i=0; i<time; i++)
			num1[len1-1-i]='\0';
	}
	else
		num1[0]='0',num1[1]='\0';
	numswap(num1, strlen(num1));
	numswap(num2, len2);
}
int main()
{
	char c;
	while(scanf("%s %c %s",num1, &c, num2)!=EOF)
	{
		int i,j,len3;
		int len1=strlen(num1);
		int len2=strlen(num2);
		 ///////////////////////////////////////////////////
		if(cmp(num1, num2, len1, len2)<0)	//不用计算部分 
		{
			ans[0]='0';
		}
		
		if(cmp(num1, num2, len1, len2)==0)
		{
			ans[0]='1';
			memset(num1, 0 ,sizeof(num1));
			num1[0]='0';
		}
		 //////////////////////////////////////////////////
		if(cmp(num1, num2, len1, len2)>0)
		{
			int l_=0;
			strcpy(num3, num2);
			for(i=len2; i<len1; i++) //补0 
			{
				l_++;
				num3[i]='0'; 
			}
			j=0;
			int flag=0;
			for(i=0; i<=l_; i++)
			{
				int b=0;
				len1=strlen(num1);
				len3=strlen(num3);
				if(cmp(num1, num2, len1, len2)<0)	
				{
					ans[j++]='0';
					continue;
				}
				while(cmp(num1, num3, len1, len3)>=0)
				{
					sub(num1, num3, len1, len3);
					len1=strlen(num1);
					len3=strlen(num3);
					b++;
					if(b!=0)
						flag=1;
				}
				if(flag)
					ans[j++]=b+48;
				num3[len3-1]='\0';
			}
		}
		if(c=='/')
			printf("%s\n",ans);
		if(c=='%')
			printf("%s\n",num1);
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(num3, 0, sizeof(num3));
	memset(ans, 0, sizeof(ans));
	}
	return 0;
}