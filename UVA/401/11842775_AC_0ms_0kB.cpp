#include<stdio.h>
#include<string.h> 
#include<ctype.h>
char Jing(char a)
{
	char b;
	char al1[50]="A   3  HIL JM O   2TUVWXY5";
	char al2[50]="1SE Z  8 ";
	if(isalpha(a))	
	b=al1[a-'A'];
	else
	b=al2[a-'1'];
	return b;
}
int sort(char a[],int len)
{
	int i,flag=1;
	for(i=0; i<=len/2 ;i++)
	{
		if(a[i]!=Jing(a[len-i-1]))
			flag=0;
	}
	if(flag==1)
	return 1;
	else
	return 0;  //1镜像   0不是镜像 
}
int main()
{
	char a[1000];
	while(scanf("%s",a)!=EOF)
	{
		int i,len,flag;
		len=strlen(a);
		flag=0;
		for(i=0; i<len/2; i++)
			if(a[i]!=a[len-i-1])  //是不是回文 
				{flag=1;break;}	
				//0回文 1不是回文 
		if(sort(a,len)==1)//镜像 
		{
			if(flag==0)
			printf("%s -- is a mirrored palindrome.",a);
			else
			printf("%s -- is a mirrored string.",a);

		}	

		if(sort(a,len)==0) //不是镜像 
		{
			if(flag==0)
			printf("%s -- is a regular palindrome.",a);
			else
			printf("%s -- is not a palindrome.",a);

		}	
		printf("\n\n");
	}
	return 0;
}