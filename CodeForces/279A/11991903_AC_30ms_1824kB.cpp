#include<stdio.h>
int main()
{
	int x_move[4]={1,0,-1,0};
	int y_move[4]={0,1,0,-1};
	int x,y;
	int x_find,y_find;
	int time;
	while(scanf("%d%d",&x_find,&y_find)!=EOF)
	{
		int z=0;
		int flag=0;
		int n=0;
		int time_=1;
		time=0;
		x=0,y=0;
		if(x_find==0&&y_find==0)
			printf("0\n");
		else
		{
		while(1)
		{
			while(n++<time_)
			{
				x+=x_move[flag];
				y+=y_move[flag];
				if(x==x_find&&y==y_find)
				{
					z=1;
					break;
				}
			}
			if(z)	break;
			time++;
			flag++;
			if((flag)%2==0&&flag!=0)
			{
				time_++;
				if(flag==4)
				flag=0;
			}
			n=0;
		}
		printf("%d\n",time);
		}
	}
	return 0;
}