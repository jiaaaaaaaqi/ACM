#include<stdio.h>
int main()
{
	int a,b,c,d;
	int z=1;
	while(1)
	{
		int i;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==-1&&b==-1&c==-1&d==-1)
			break;
		else
		{
			for(i=d+1; ; i++)
			{
				if((i-c)%33==0&&(i-a)%23==0&&(i-b)%28==0)
					break;
			}
			printf("Case %d: the next triple peak occurs in %d days.\n",z++,i-d);
		}
	}
	return 0;
} 