#include<stdio.h>
#include<string.h>
char num1[2000]={0};
char num2[2000]={0};
char sum[2000]={0};
char mul[2000][2000]={0};
void numswap(char a[],int n)
{
	char temp;
	for(int i=0; i<=n/2-1; i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-1-i]=temp;
	}
}
int main()
{
	while(scanf("%s%s",num1,num2)!=EOF)
	{
		if(num1[0]=='0'||num2[0]=='0')
			printf("0\n");
		else
		{
		int x_mul,x_add,up_mul,up_add;
		int i,j;
		int len1=strlen(num1);
		int len2=strlen(num2);
		numswap(num1,len1);
		numswap(num2,len2);
		for(i=0; i<len2; i++) 		//乘法 
		{
			up_mul=0;
			int l=len1;
			for(j=0; j<len1; j++)
			{
				x_mul=(num2[i]-48)*(num1[j]-48)+up_mul;
				mul[i][j]=x_mul%10;
				up_mul=x_mul/10;
			}
			if(up_mul)
			{
				mul[i][l]=up_mul;
				l++;
			}
			for(j=0; j<l; j++)
				mul[i][j]+=48;
			numswap(mul[i],l);
			for(int z=0; z<i; z++)
				mul[i][l+z]='0';
		}
		
		for(i=0; i<len2; i++)    //加法 
		{
			int i_add;
			int len3=strlen(sum);
			int len4=strlen(mul[i]);
			numswap(sum,len3);
			numswap(mul[i],len4);
			int lenmax= len3>=len4 ? len3:len4;
			int lenmin= len3<=len4 ? len3:len4;
			up_add=0;
			for(i_add=0; i_add<lenmax; i_add++)
			{
				x_add=0;
				if(i_add<lenmin)
					x_add=sum[i_add]+mul[i][i_add]-96+up_add;
				else
				{
					if(len3>len4)
					{
						x_add=sum[i_add]-48+up_add;
					}
					if(len4>len3)
					{
						x_add=mul[i][i_add]-48+up_add;
					}
				}
				sum[i_add]=x_add%10;
				up_add=x_add/10;
			}
			if(up_add)
			{
				sum[lenmax]=1;
				lenmax++;
			}
			for(i_add=0; i_add<lenmax; i_add++)
				sum[i_add]+=48;
			numswap(sum,lenmax);
		}
		printf("%s\n",sum);
		
		memset(sum,0,sizeof(sum));
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(mul,0,sizeof(mul));
		} 
	}
	return 0;
}