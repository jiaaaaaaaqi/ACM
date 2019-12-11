#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct node{
	int x;
	int y;
	int cnt;
};
int bex,bey,enx,eny;
int turn;
int n,m;
char str[105][105]={0};
int vis[105][105]={0};
int step[105][105]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int head,rear;
int flag;

int check(int x, int y, int num)
{
	if(x<1||y<1||x>n||y>m)
		return 0;
	if(str[x][y]=='*')
		return 0;
	if(vis[x][y]&&step[x][y]<num)
		return 0;
	return 1;
}
void bfs ()
{
	memset(vis, 0, sizeof(vis));
	memset(step, 0, sizeof(step));
	queue<node> q;
	node now,next;
	now.x=bex;
	now.y=bey;
	now.cnt=-1;
	vis[bex][bey]=1; 
	step[bex][bey]=0;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		for(int i=0; i<4; i++)
		{
			next.x=now.x+dis[i][0];
			next.y=now.y+dis[i][1];
			next.cnt=now.cnt+1;
			if(next.cnt>turn)
				break;
			while(check(next.x, next.y, next.cnt))
			{
				vis[next.x][next.y]=true;
				step[next.x][next.y]=next.cnt;
				if(next.x==enx&&next.y==eny)
				{
					flag=1;
					return ;
				}
				q.push(next);
				next.x+=dis[i][0];
				next.y+=dis[i][1];
			}
		}
		q.pop();
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
			printf("%s\n", flag ? "yes":"no");
		}
		memset(str, 0, sizeof(str));
	}
	return 0;
}