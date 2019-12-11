#include <stdio.h>
#include <string.h> 
int bex,bey;
int enx,eny;
struct node{
	int x;
	int y;
	int cnt; 
};
node que[1005];
bool vis[10][10]={0};
int dis[8][2]={{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1}};
int ans;
void bfs()
{
	memset(vis, 0, sizeof(vis));
	int head=0;
	int rear=1;
	vis[bex][bey]=1;
	que[0].x=bex;
	que[0].y=bey;
	que[0].cnt=0;
	while (head<rear)
	{
		for (int i=0; i<8; i++)
		{
			int newx=que[head].x+dis[i][0];
			int newy=que[head].y+dis[i][1];
			if (newx<1||newy<1||newx>8||newy>8)
				continue;
			if (vis[newx][newy])
				continue;
			vis[newx][newy]=1;
			que[rear].x=newx;
			que[rear].y=newy;
			que[rear].cnt=que[head].cnt+1;
			if (newx==enx&&newy==eny)
			{
				ans=que[rear].cnt;
				return ; 
			}
			rear++;
		}
		head++;
	}
}
int main()
{
	char s1[3]={0}, s2[3]={0};
	while (scanf("%s%s",s1, s2)!=EOF)
	{
		ans=0;
		bex = s1[0]-'a'+1;
		bey = s1[1]-'0';
		enx = s2[0]-'a'+1;
		eny = s2[1]-'0';
		printf("%d %d %d %d\n", bex, bey, enx, eny);
		bfs();
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, ans);
	}
	return 0;
}