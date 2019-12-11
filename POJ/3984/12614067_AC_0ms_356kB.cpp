#include<stdio.h>
int num[5][5];
struct node{
	int x;
	int y;
	int pre;
};
struct node queue[50];
int front=0,rear=0;
int vis[5][5]={0};
int dire[4][2]={1,0,-1,0,0,1,0,-1};
void bfs(int beginx, int beginy, int endx, int endy)
{
	queue[0].x=beginx,queue[0].y=beginy,queue[0].pre=-1;
	rear=rear+1;
	vis[beginx][beginy]=1;
	while(front<rear)
	{
		for(int i=0; i<4; i++)
		{
 			int newx=queue[front].x+dire[i][0];
			int newy=queue[front].y+dire[i][1];
			if(newx<0||newy<0||newx>5||newy>5||num[newx][newy]==1||vis[newx][newy]==1)
				continue;
			queue[rear].x=newx;
			queue[rear].y=newy;
			queue[rear].pre=front;
			rear++;
			vis[newx][newy]=1;
			if(newx==endx&&newy==endy)
				return;
		}
		front++;
	}
}
void print(struct node now)
{
	if(now.pre==-1)
		printf("(%d, %d)\n",now.x, now.y);
	else
	{
		print(queue[now.pre]);
		printf("(%d, %d)\n",now.x, now.y);
	}	
}
int main()
{
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			scanf("%d",&num[i][j]);
	bfs(0, 0, 4, 4);
	print(queue[rear-1]);
	return 0;
}