#include<stdio.h>
#include<string.h>
int num[10005]={0};
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int a,b,c;
		int i,j;
		int time=0;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &num[i]);
			if(num[i]<0)
				time++;
		}
		if(time==n)
			printf("0 %d %d\n",num[1], num[n]);
		else
		{
			a=1,b=1,c=1;
			int sum=0;
			int maxsum=num[1];
			for(i=1; i<=n; i++)
			{
				sum+=num[i];
				if(sum>maxsum)
				{
					a=c;
					maxsum=sum;
					b=i;
				}
				if(sum<0)
				{
					sum=0;
					c=i+1;
				}
			} 
			printf("%d %d %d\n",maxsum, num[a], num[b]);
		}
		memset(num, 0, sizeof(num));
	}
	return 0;
} 