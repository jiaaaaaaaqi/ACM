#include<stdio.h>
#include<string.h>
char num[3][2000]={0};
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
	int i,j;
	char c;
	while(scanf("%s %c %s",num[0],&c,num[1])!=EOF)
	{
		if(c=='*')
		{
			if(num[0][0]=='0'||num[1][0]=='0')
				printf("0\n");
			else
			{
				int x_mul,x_add,up_mul,up_add;
				int i,j;
				int len1=strlen(num[0]);
				int len2=strlen(num[1]);
				numswap(num[0],len1);
				numswap(num[1],len2);
				for(i=0; i<len2; i++) 		//乘法 
				{
					up_mul=0;
					int l=len1;
					for(j=0; j<len1; j++)
					{
						x_mul=(num[1][i]-48)*(num[0][j]-48)+up_mul;
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
				numswap(num[0],len1);
				numswap(num[1],len2);
				
				for(i=0; i<len2; i++)    //加法 
				{
					int i_add;
					int len3=strlen(num[2]);
					int len4=strlen(mul[i]);
					numswap(num[2],len3);
					numswap(mul[i],len4);
					int lenmax= len3>=len4 ? len3:len4;
					int lenmin= len3<=len4 ? len3:len4;
					up_add=0;
					for(i_add=0; i_add<lenmax; i_add++)
					{
						x_add=0;
						if(i_add<lenmin)
							x_add=num[2][i_add]+mul[i][i_add]-96+up_add;
						else
						{
							if(len3>len4)
							{
								x_add=num[2][i_add]-48+up_add;
							}
							if(len4>len3)
							{
								x_add=mul[i][i_add]-48+up_add;
							}
						}
						num[2][i_add]=x_add%10;
						up_add=x_add/10;
					}
					if(up_add)
					{
						num[2][lenmax]=1;
						lenmax++;
					}
					for(i_add=0; i_add<lenmax; i_add++)
						num[2][i_add]+=48;
					numswap(num[2],lenmax);
				}
			} 
		}
		
		if(c=='+')
		{
			int i_add,x_add,up_add=0;
			int len1=strlen(num[0]);
			int len2=strlen(num[1]);
			numswap(num[0],len1);
			numswap(num[1],len2);
			int lenmax=len1>=len2 ? len1:len2;
			int lenmin=len1<=len2 ? len1:len2;
			for(i_add=0; i_add<lenmax; i_add++)
			{
				if(i_add<lenmin)
					x_add=num[0][i_add]+num[1][i_add]-96+up_add;
				else
				{
					if(len1>len2)
					x_add=num[0][i_add]-48+up_add;
					if(len2>len1)
					x_add=num[1][i_add]-48+up_add;
				}
				num[2][i_add]=x_add%10;
				up_add=x_add/10; 
			}
			if(up_add)
			{
				num[2][i_add]=1;
				lenmax++;
			}
			for(i_add=0; i_add<lenmax; i_add++)
				num[2][i_add]+=48;
			numswap(num[0],len1);
			numswap(num[1],len2);
			numswap(num[2],lenmax);
		}
		
		int time;
		for(i=0; i<3; i++)
		{
			time=0,j=0;
			while(num[i][j]=='0')
				j++,time++;
			int len_=strlen(num[i]);
			for(j=0; j<len_; j++)
				num[i][j]=num[i][j+time];
		}
	
		printf("%s %c %s\n",num[0],c,num[1]);
	
		char str[11]="2147483649";
		for(i=0; i<3; i++)
		{
			int flag=0;
			int len=strlen(num[i]);
			if(len>10)	flag=1;
			if(len==10)
				if(strcmp(num[i],str)>0)
					flag=1;
			if(flag)
			{
				if(i==0)	printf("first number too big");
				if(i==1)	printf("second number too big");
				if(i==2)	printf("result too big");
				printf("\n");
			}
		}
		
		memset(num[0],0,sizeof(num[0]));
		memset(num[1],0,sizeof(num[1]));
		memset(num[2],0,sizeof(num[2]));
		memset(mul,0,sizeof(mul));
	}
	return 0;
}