#include<stdio.h>
#include<string.h>
struct node{
	int x;
	int cnt;
};
node que[1000500];
int vis[1000500]={0};
int head,rear;
int begin,end;
void bfs()
{
	memset(que, 0, sizeof(que));
	que[0].x=begin;
	que[0].cnt=0;
	head=0;
	rear=1;
	vis[begin]=1;
	while(head<rear)
	{
		for(int i=0; i<3; i++)
		{
			int newx;
			if(i==0)
				newx=que[head].x+1;
			if(i==1)
				newx=que[head].x-1;
			if(i==2)
				newx=que[head].x*2;
			if(newx<=0||vis[newx]==1||newx>100001)
				continue;
			que[rear].x=newx;
			que[rear].cnt=que[head].cnt+1;
			vis[newx]=1;
			rear++;
			if(newx==end)				
				return;
		}
		head++;
	}
}
int main()
{
	while(scanf("%d%d",&begin,&end)!=EOF)
	{		
		if(begin>=end)
			printf("%d\n",begin-end);	
		else
		{
			bfs();
			printf("%d\n", que[rear-1].cnt);
		}
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}