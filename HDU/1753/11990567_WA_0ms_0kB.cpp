#include<stdio.h>
#include<string.h>
#include<ctype.h>
char num_1[1000]={0};
char num_2[1000]={0};
char num1[1000]={0};
char num2[1000]={0};
char num3[1000]={0};
char num4[1000]={0};
char ans1[1000]={0};
char ans2[1000]={0};
void numswap(char a[], int n)
{
	int temp,i;
	for(i=0; i<=n/2-1; i++)
	{
		temp=a[i];
		a[i]=a[n-1-i];
		a[n-i-1]=temp;
	}
}
int main()
{
	int flag2;
	int i,j;
	while(scanf("%s%s",num_1,num_2)!=EOF)
	{
		flag2=0;
		num3[0]='0';
		num4[0]='0';
		int len_1=strlen(num_1);
		int len_2=strlen(num_2);
		j=0;
		int flag=0;
		for(i=0; i<len_1; i++)
		{
			if(num_1[i]=='.')
			{
				j=0,i++;
				flag=1;
			}
			if(!flag)
				num1[j++]=num_1[i];
			if(flag)
				num3[j++]=num_1[i];
		}
		j=0,flag=0;
		for(i=0; i<len_2; i++)
		{
			if(num_2[i]=='.')
			{
				j=0,i++;
				flag=1;
			}
			if(!flag)
				num2[j++]=num_2[i];
			if(flag)
				num4[j++]=num_2[i];
		}

		int lenmax,lenmin;
		int len3=strlen(num3);
		int len4=strlen(num4);
		int i_add,j_add,x_add,up_add;
		lenmax=len3>=len4 ? len3:len4;
		lenmin=len3<=len4 ? len3:len4;
		int x=lenmax-lenmin;
		for(i=0; i<x; i++)
		{
		if(len3<len4)
			num3[len3+i]='0';
		if(len4<len3)
			num4[len4+i]='0';	
		}
		numswap(num3,lenmax);
		numswap(num4,lenmax);
		up_add=0;
		for(i_add=0; i_add<lenmax; i_add++)
		{
			x_add=num3[i_add]+num4[i_add]+up_add-96;
			ans2[i_add]=x_add%10;
			up_add=x_add/10;
		}
		if(up_add)
		{
			ans2[lenmax]=up_add;
			lenmax++;
			flag2=1;
		}
		for(i=0; i<lenmax; i++)
			ans2[i]+=48;
		numswap(ans2,lenmax);
		///////////////////////////
		int len1=strlen(num1);
		int len2=strlen(num2);
		lenmax=len1>=len2 ? len1:len2;
		lenmin=len1<=len2 ? len1:len2;
		numswap(num1,len1);
		numswap(num2,len2);
		up_add=0;
		for(i_add=0; i_add<lenmax; i_add++)
		{
			if(i_add<lenmin)
				x_add=num1[i_add]+num2[i_add]+up_add-96;
			else
			{
				if(len1>len2)
					x_add=num1[i_add]+up_add-48;
				if(len2>len1)
					x_add=num2[i_add]+up_add-48;
			}
			ans1[i_add]=x_add%10;
			up_add=x_add/10;
		}
		if(up_add)
		{
			ans1[lenmax]=up_add;
			lenmax++;
		}
		for(i=0; i<lenmax; i++)
			ans1[i]+=48;
		numswap(ans1,lenmax);
		
		if(flag2==0)
		{
			int len=strlen(ans2);
			i=len-1;
			while(ans2[i]=='0')
				ans2[i]='\0',i--;
			printf("%s.%s\n",ans1,ans2);
		}
		if(flag2==1)
		{
			i=lenmax-1;
			ans1[i]+=ans2[0]-48;
			for(; i>=0; i--)
			{
				if(ans1[i]>'9')
					{
						ans1[i]-=10;
						ans1[i-1]+=1;
					}
			}
			for(i=0; ans2[i]!='\0'; i++)
				ans2[i]=ans2[i+1];
			int len=strlen(ans2);			
			i=len-1;
			int time=0;
			while(ans2[i]=='0')
				ans2[i]='\0',time++,i--;
			if(time==len)
				printf("%s\n",ans1);
			else
				printf("%s.%s\n",ans1,ans2);
		}
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(num3,0,sizeof(num3));
		memset(num4,0,sizeof(num4));
		memset(ans1,0,sizeof(ans1));
		memset(ans2,0,sizeof(ans2));
	}	
	return 0;
}