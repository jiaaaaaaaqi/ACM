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
int n,m;
char str[1005][1005];
bool vis[1005][1005];
int dis[4][2]={1,0,-1,0,0,1,0,-1};

bool check(int x, int y)
{
	if(x<0||y<0||x>=n||y>=m)
		return 0;
	if(str[x][y]=='*')
		return 0;
	return 1;
}
int bfs()
{
	int flag=0;
	memset(vis, false, sizeof vis);
	queue<node> q;
	node now,next;
	now.x=bex;
	now.y=bey;
	now.cnt=-1;
	vis[bex][bey]=true;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		for(int i=0; i<4; i++)
		{
			next.x=now.x+dis[i][0];
			next.y=now.y+dis[i][1];
			next.cnt=now.cnt+1;
			if(next.cnt>2)
				continue;
			while(check(next.x, next.y))
			{
				if(!vis[next.x][next.y])
				{
					vis[next.x][next.y]=true;
					if(next.x==enx&&next.y==eny)
						return 1;
					q.push(next);
				}
				next.x+=dis[i][0];
				next.y+=dis[i][1];
			}
		}
		q.pop();
	}
	return 0;
}
int main()
{
	while (scanf("%d%d",&n, &m)!=EOF)
	{
		memset(str, 0, sizeof str);
		for(int i=0; i<n; i++)
		{
			scanf("%s",str[i]);
			for(int j=0; j<m; j++)
			{
				if(str[i][j]=='S')
					bex=i,bey=j;
				if(str[i][j]=='T')
					enx=i,eny=j;
			}
		}
		int flag;
		if(bex==enx&&bey==eny)
			flag=1;
		else
			flag=bfs();
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}