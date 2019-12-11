#include<stdio.h>
#include<string.h>
struct node{
	int x;
	int cnt;
};
node que[200005];
int vis[100005]={0};
int head,rear;
int begin,end;
void bfs( )
{
	memset(que, 0, sizeof(que));
	memset(vis, 0, sizeof(vis));
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
				newx=que[head].x+que[head].x;
			if(newx<=0||vis[newx]||newx>200001)
				continue;
			que[rear].x=newx;
			que[rear].cnt=que[head].cnt+1;
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
		int ans;
		if(begin>=end)
			printf("%d\n",begin-end);	
		else
		{
			bfs();
			printf("%d\n", que[rear-1].cnt);
		}
	}
	return 0;
}