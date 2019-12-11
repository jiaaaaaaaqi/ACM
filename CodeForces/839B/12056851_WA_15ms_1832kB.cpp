#include<stdio.h>
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int i;
		int num[105]={0};
		for(i=0; i<k; i++)
			scanf("%d",&num[i]);
		int time;
		int x=0,y=0;
		for(i=0; i<k; i++)
		{
			x+=num[i]/2;
			y+=num[i]%2;
		}
		int flag;
		int seat;
		seat=n*4-x;
		if(seat>=0)
		{
			if(y>seat)
				flag=0;
			else
				flag=1;
		}
		else
			flag=0;
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
