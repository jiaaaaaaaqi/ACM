#include<stdio.h>
#include<string.h> 
int main()
{
	char a[1000];
	while(scanf("%s",a)!=EOF)
	{
		int b[1000];
		int n,i,len,flag=0;
		n=-1;
		len=strlen(a);
		for(i=0; i<len/2; i++)
		{
			if(a[i]=='O'&&(a[len-i-1]!='0'||a[len-i-1]!='O'))
			{
				n++;
				b[n]=i;
				flag=1;	
			}
			else if(a[i]=='0'&&(a[len-i-1]!='0'||a[len-i-1]!='O'))
			{
				n++;
				b[n]=i;
				flag=1;	
			}		
			else if(a[i]!=a[len-i-1])
			{
				n++;
				b[n]=i;
				flag=1;	
			}
		}
		
		if(flag==0)
		{
		for(i=0; i<len/2; i++)
			if(!(a[i]=='A'||a[i]=='T'||a[i]=='O'||a[i]=='Y'||a[i]=='0'))
				{flag=2;break;}
		if(flag==2)		printf("%s -- is a regular palindrome.\n",a);
		else			printf("%s -- is a mirrored palindrome.\n",a);
		}	

		if(flag==1)	
		{
			for(i=0; i<n; i++)
			{
				if(a[b[i]]!='E'&&a[b[i]]!='L'&&a[b[i]]!='S'&&a[b[i]]!='Z'&&
				   a[b[i]]!='2'&&a[b[i]]!='3'&&a[b[i]]!='5')
					{flag=3;break;}
				else
				{
				if(((a[b[i]]=='E'&&a[len-b[i]-1]=='3')||(a[b[i]]=='L'&&a[len-b[i]-1]=='J')||
					 (a[b[i]]=='S'&&a[len-b[i]-1]=='2')||
					 (a[b[i]]=='Z'&&a[len-b[i]-1]=='5')||(a[b[i]]=='2'&&a[len-b[i]-1]=='S')||
				     (a[b[i]]=='3'&&a[len-b[i]-1]=='E')||(a[b[i]]=='5'&&a[len-b[i]-1]=='Z')))
					 flag=1;		
				else	{flag=3;break;}
				}
			}
			if(flag==3)	printf("%s -- is not a palindrome.\n",a);
			else		printf("%S -- is a mirrored string.\n",a);
		}
	}
	return 0;
}