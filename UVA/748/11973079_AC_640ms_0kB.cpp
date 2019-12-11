#include<stdio.h>
#include<string.h>
#include<ctype.h>
char num[10000]={0};
char sum[10000][10000]={0};
char num1[10000]={0}; 
char num2[10000]={0};
char ans[10000]={0};
void numswap(char a[],int n)
{
	int temp;
	for(int i=0; i<=n/2-1; i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
}
int main()
{
	while(scanf("%s%s",num,num2)!=EOF)
	{
		int len_num=strlen(num);
		int i=0,x,y=0,N=0;
		int j=0;
		for(i=0; i<len_num; i++)
		{
			if(num[i]=='.')
				x=j;
			if(isdigit(num[i]))
			{
				num1[j]=num[i];
				j++;
			}
		}
		
		y=len_num-x-1;
		int time=0;
		for(i=0; i<j; i++)
		{
			if(num1[i]=='0')
				time++;
			else
				break;
		}

		for(i=0; i<len_num; i++)
			num1[i]=num1[i+time];		
		for(i=0; num2[i]!='\0'; i++)
			N=N*10+(num2[i]-48);

		y=N*y;

		ans[0]='1';
		while(N--)
		{
			int i_mul,j_mul;
			int x_mul,up_mul;
			int len1=strlen(num1);
			int len2=strlen(ans);
			numswap(ans,len2);
						
			for(i_mul=0; i_mul<len2; i_mul++)	//乘法 
			{
				numswap(num1,len1);
				up_mul=0; 
				int l=len1;
				for(j_mul=0; j_mul<len1; j_mul++)
				{
					x_mul=(num1[j_mul]-48)*(ans[i_mul]-48)+up_mul;
					sum[i_mul][j_mul]=x_mul%10;
					up_mul=x_mul/10;
				}
				if(up_mul)
				{
					sum[i_mul][l]=up_mul;
					l++;
				}
				for(i=0; i<l; i++)
					sum[i_mul][i]+=48;
				numswap(sum[i_mul],l);
				numswap(num1,len1);
				for(i=0; i<i_mul; i++)
					sum[i_mul][l+i]='0';
			}

			memset(ans, 0, sizeof(ans));
			int i_add,j_add,x_add,up_add;
			for(i=0; i<len2; i++)
			{
				int len3=strlen(ans);
				int len4=strlen(sum[i]);
				int lenmax= len3>=len4 ? len3:len4;
				int lenmin= len3<=len4 ? len3:len4;
				numswap(ans,len3);
				numswap(sum[i],len4);
				up_add=0;
				for(i_add=0; i_add<lenmax; i_add++)
				{
					if(i_add<lenmin)
						x_add=ans[i_add]+sum[i][i_add]+up_add-96;
					else
					{
						if(len3>len4)
							x_add=ans[i_add]-48+up_add;
						if(len3<len4)
							x_add=sum[i][i_add]-48+up_add; 
					}
				ans[i_add]=x_add%10;
				up_add=x_add/10;
				}
				if(up_add)
				{
					ans[lenmax]=up_add;
					lenmax++;
				}
				int z;
				for(z=0; z<lenmax; z++)
					ans[z]+=48;
				numswap(ans,lenmax);
			}			
			memset(sum, 0, sizeof(sum));
		}
		
		int len_ans=strlen(ans);
		numswap(ans,len_ans);
		if(y>=len_ans)
		{
			ans[y]='.';
			for(i=len_ans; i<y; i++)
				ans[i]='0';
		}
		if(y<len_ans)
		{
			for(i=len_ans-1; i>=y; i--)
				ans[i+1]=ans[i];
			ans[y]='.';
		}
		len_ans=strlen(ans);
		numswap(ans,len_ans);

		y=len_ans-1-y;
		for(i=len_ans-1; i>=0; i--)
		{
			if(i>y)
			{
				while(ans[i]=='0')
				{
					ans[i]='\0';
					i--;
				}
				break;
			}
		}
		
		printf("%s\n",ans);		
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
	}
	return 0;
}