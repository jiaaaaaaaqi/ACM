#include<stdio.h>
#include<string.h>
#include<ctype.h>
char mul[10000][10000]={0};
char num[1005][10000]={0};
void numswap(char a[],int n)
{
	char temp;
	for(int i=0; i<=n/2-1; i++)
	{
		temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
}
int main()
{
	int m,i,j;
	int N,N1=0;
	while(scanf("%d",&N)!=EOF)
	{
	if(N>=N1)
	{
	num[0][0]='1';
	if(N>1)
	{
	for(m=N1+1; m<N; m++)
	{
		int n=m+1;				//用来乘 
		char num1[1000]={0};
		char num2[1000]={0};
		strcpy(num2, num[m-1]);
		for(i=0; ; i++)
		{
			num1[i]=n%10+48;
			n=n/10;
			if(n==0)
				break;
		}
		int len1=strlen(num1);
		int len2=strlen(num2);
		numswap(num1, len1);
		
		numswap(num1, len1);
		numswap(num2, len2);
		int i_mul,j_mul,x_mul,up_mul;
		for(i_mul=0; i_mul<len2; i_mul++)//乘 
		{
			int l=len1;
			up_mul=0;
			for(j_mul=0; j_mul<len1; j_mul++)
			{
				x_mul=(num1[j_mul]-48)*(num2[i_mul]-48)+up_mul;
				mul[i_mul][j_mul]=x_mul%10;
				up_mul=x_mul/10;
			}
			if(up_mul)
			{
				mul[i_mul][l]=up_mul;
				l++;
			}
			numswap(mul[i_mul], l);
			for(i=0; i<l; i++)
				mul[i_mul][i]+=48;
			for(int z=0; z<i_mul; z++)
				mul[i_mul][l+z]='0';
		}
		
		int i_add,j_add,x_add,up_add;//加 
		for(i=0; i<len2; i++)
		{
			int len3=strlen(mul[i]);
			int len4=strlen(num[m]);
			int lenmax=len3>=len4 ? len3:len4;
			int lenmin=len3<=len4 ? len3:len4;
			numswap(mul[i], len3);
			numswap(num[m], len4);
			up_add=0;
			for(i_add=0; i_add<lenmax; i_add++)
			{
				if(i_add<lenmin)
					x_add=mul[i][i_add]+num[m][i_add]+up_add-96;
				else
				{
					if(len3>len4)
						x_add=mul[i][i_add]-48+up_add;
					if(len3<len4)
						x_add=num[m][i_add]-48+up_add;
				}
				num[m][i_add]=x_add%10;
				up_add=x_add/10;
			}
			if(up_add)
			{
				num[m][lenmax]=1;
				lenmax++;
			}
			for(j=0; j<lenmax; j++)
				num[m][j]+=48;
			numswap(num[m], lenmax);
		}
		memset(mul, 0, sizeof(mul));
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
	}
	}
	N1=N; 
	printf("%s\n",num[N-1]);
	}
	else
	printf("%s\n",num[N-1]);
	}
	return 0;
}