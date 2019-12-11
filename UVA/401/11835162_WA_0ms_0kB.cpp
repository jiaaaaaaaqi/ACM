#include<stdio.h>
#include<string.h> 
char sort(char a)
{
	char b;
	if(a=='E')		b='3';
	else if(a=='L')	b='J';
 	else if(a=='S')	b='2';
	else if(a=='Z')	b='5';
 	else if(a=='2')	b='S';
	else if(a=='3')	b='E';
 	else if(a=='5')	b='Z';
	else if(a=='J')	b='L';
	return b;
}
int main()
{
	char a[1000];
	while(scanf("%s",a)!=EOF)
	{
		char B;
		int b[1000];
		int n,i,len,flag;
		len=strlen(a);
		if(len>1)
		{
		flag=0,n=-1;
		for(i=0; i<len/2; i++)
		{
			if(a[i]!=a[len-i-1])  //是不是回文 
			{
				n++;
				b[n]=i;
				flag=1;	
			}
		}
		if(flag==0)//是回文，0普通，2镜像回文 
		{
		for(i=0; i<len/2; i++)
			if(a[i]!='A'&&a[i]!='T'&&a[i]!='O'&&a[i]!='Y'&&a[i]!='0')
				{flag=2;break;}
		if(flag==2)		printf("%s -- is a regular palindrome.\n",a);
		else			printf("%s -- is a mirrored palindrome.\n",a);
		}	

		if(flag==1)	//不是回文，1不是回文,3镜像 
		{
			for(i=0; i<n+1; i++)
			{
				if(a[b[i]]!='E'&&a[b[i]]!='L'&&a[b[i]]!='S'&&a[b[i]]!='Z'&&
				   a[b[i]]!='2'&&a[b[i]]!='3'&&a[b[i]]!='5'&&a[b[i]]!='J')
					{flag=3;break;}
				else
				{
					B=sort(a[len-b[i]-1]);
					if(B!=a[b[i]])
					{
						flag=3;
						break;
					}
				}
			}
			if(flag==3)	printf("%s -- is not a palindrome.\n",a);
			if(flag==1)	printf("%s -- is a mirrored string.\n",a);
		}
		}
		else//一个字符的时候 
		{
		if(a[0]=='A'||a[0]=='O'||a[0]=='T'||a[0]=='Y')
		printf("%s -- is a mirrored palindrome.\n",a);
		else if(a[0]=='E'||a[0]=='H'||a[0]=='I'||a[0]=='J'||a[0]=='L'||
				a[0]=='M'||a[0]=='O'||a[0]=='S'||a[0]=='T'||a[0]=='U'||
				a[0]=='V'||a[0]=='W'||a[0]=='X'||a[0]=='Y'||a[0]=='Z'||
				a[0]=='1'||a[0]=='2'||a[0]=='3'||a[0]=='5'||a[0]=='8')
			printf("%s -- is a mirrored string.",a);
		else
			printf("%s -- is a regular palindrome.",a);
		}
		printf("\n");
	}
	return 0;
}