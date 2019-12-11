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
				a[j]=x%10;
				up=x/10;
			}
			while(up)
			{
				digit++;
				a[digit-1]=up%10;
				up=up/10;
			}
		}
		for(i=digit-1; i>=0; i--)
			printf("%d",a[i]);
		printf("\n");
		memset(a, 0, sizeof(a));
	} 
} 