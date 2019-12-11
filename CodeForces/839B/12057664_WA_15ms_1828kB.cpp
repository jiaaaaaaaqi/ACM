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
		int time=0;
		int x=0,y=0;
		int seat=n*8;
		for(i=0; i<k; i++)
		{
			x+=num[i]/4;
			num[i]=num[i]%4;
		}
		seat-=x*4;
		if(x>=n)
		{
			for(i=0; i<k ;i++)
			{
				if(num[i]==3)
					seat-=4;
				if(num[i]==1||num[i]==2)
					seat-=2;
			}
		}
		if(x<n)
		{
			seat-=n-x;
			int y=n-x;
			int y_num=0;
			for(i=0; i<k ;i++)
			{
				if(num[i]==3)
					seat-=4;
				if(num[i]==2)
					seat-=2;
				if(num[i]==1)
				{
					if(y_num<y)
						seat-=1;
					else
						seat-=2;
				}
			}
		}
		if(seat>=0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}