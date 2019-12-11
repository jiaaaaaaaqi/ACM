#include<stdio.h>
#include<string.h>
void numdao(char num[],int n)
{
	int i;
	char temp;
	for(i=0; i<=n/2-1; i++)
	{
		temp=num[i];
		num[i]=num[n-i-1];
		num[n-i-1]=temp;
	}
}
int main()
{
	int i,j;
	char num[200]={0};
	char sum[200]={0};
	int max=0,min=0;
	while(scanf("%s",num))
	{	
		if(num[0]=='0')	break;
		else
		{
			int up=0;
			int len1=strlen(sum);
			int len2=strlen(num);
			numdao(sum, len1);
			numdao(num, len2);
			max=len1>=len2 ? len1:len2;
			min=len1<=len2 ? len1:len2;
			for(i=0 ;i<max; i++)
			{
				int x=0;
				if(i<min)
					x=num[i]+sum[i]-96+up;
				if(i>=min)
				{
					if(len1>len2)
						x=sum[i]-48+up;
					if(len2>len1)
						x=num[i]-48+up;
				}
				sum[i]=x%10;
				up=x/10;
			}
			if(up)
			{
				sum[max]=1;
				max++;
			}
		}
		for(i=0; i<max; i++)
			sum[i]+=48;
		int len3=strlen(sum);
		numdao(sum,len3);	
		memset(num,0,sizeof(num));
	}
	int len3=strlen(sum);
	for(i=0 ;i<len3; i++)
		printf("%d",sum[i]-48);
	printf("\n");
	return 0;
}