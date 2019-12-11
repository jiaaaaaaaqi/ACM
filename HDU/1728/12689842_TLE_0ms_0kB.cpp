#include<stdio.h>
#include<string.h>
struct node{
	int x;
	int y;
	int cnt;
};
node que[10100];
int bex,bey,enx,eny;
int turn;
int n,m;
char str[105][105]={0};
int vis[105][105]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int head,rear;
int flag;
int check(int x, int y)
{
	if(x<1||y<1||x>n||y>m)
		return 0;
	if(str[x][y]=='*'||vis[x][y])
		return 0;
	return 1;
}
void bfs ()
{
	memset(vis, 0, sizeof(vis));
	memset(que, 0, sizeof(que));
	head=0;
	rear=1;
	que[0].x=bex;
	que[0].y=bey;
	que[0].cnt=-1;
	vis[bex][bey]=1; 
	while(head<rear)
	{
		for(int i=0; i<4; i++)
		{
			int newx=que[head].x+dis[i][0];
			int newy=que[head].y+dis[i][1];
			while(check(newx, newy))
			{
				que[rear].x=newx;
				que[rear].y=newy;
				que[rear].cnt=que[head].cnt+1;
				if(newx==enx&&newy==eny&&que[rear].cnt<=turn)
				{
					flag=1;
					return ;
				}
				rear++;
				newx=newx+dis[i][0];
				newy=newy+dis[i][1];
			}
		}
		head++;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		flag=0;
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)
			scanf("%s", str[i]+1);
		scanf("%d%d%d%d%d", &turn, &bey, &bex, &eny, &enx);
		if(bex==enx&&bey==eny)
			printf("yes\n");
		else
		{
			bfs();
			printf("%s", flag ? "yes\n":"no\n");
		}
		memset(str, 0, sizeof(str));
	}
	return 0;
}
