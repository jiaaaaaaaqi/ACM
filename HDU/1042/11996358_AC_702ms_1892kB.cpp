#include<stdio.h>
#include<string.h>
int a[9000]={0};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		a[0]=1;
		int up;
		int x;
		int digit=1;
		for(i=2; i<=n; i++)
		{
			up=0;
			for(j=0; j<digit; j++)
			{
				x=i*a[j]+up;
				a[j]=x%10000;
				up=x/10000;
			}
			if(up)
			{
				a[digit]=up%10000;
				digit++;
			}
		}
		printf("%d",a[digit-1]);
		for(i=digit-2; i>=0; i--)
		{
			if(a[i]>=1000)
			printf("%d",a[i]);
			else if(a[i]>=100)
			printf("0%d",a[i]);
			else if(a[i]>=10)
			printf("00%d",a[i]);
			else
			printf("000%d",a[i]);

		}
		printf("\n");
		memset(a, 0, sizeof(a));
	} 
} 