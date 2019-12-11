#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node{
	int z;
	int x;
	int y;
	int cnt;
};
int vis[2][15][15]={0};
char str[2][15][15]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int n,m,step;
int flag;

void bfs( )
{
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	node now;
	now.z=0;
	now.x=0;
	now.y=0;
	now.cnt=0;
	vis[0][0][0]=1;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			node next;
			int newx=now.x+dis[i][0];
			int newy=now.y+dis[i][1];
			int newcnt=now.cnt+1;
			if(newx<0||newy<0||newx>=n||newy>=m)
				continue;
			if(str[now.z][newx][newy]!='#')
				if(str[now.z][newx][newy]=='*'||vis[now.z][newx][newy])
					continue;
			if(str[now.z][newx][newy]=='#')
				if(str[1-now.z][newx][newy]=='*'||str[1-now.z][newx][newy]=='#'||vis[1-now.z][newx][newy])
					continue;
			if(newcnt>step)
				continue;
			next.x=newx;
			next.y=newy;
			next.cnt=newcnt;
			if(str[now.z][newx][newy]=='#')
			{
				next.z=1-now.z;
				vis[next.z][newx][newy]=1;
			}
			else
			{
				next.z=now.z;
				vis[next.z][newx][newy]=1;				
			}
			if(str[next.z][newx][newy]=='P')
			{
				flag=1;
				return ;
			}
			q.push(next);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		flag=0;
		scanf("%d%d%d",&n, &m, &step);
		for (int i=0; i<n; i++)
			scanf("%s", str[0][i]);
		for (int i=0; i<n; i++)
			scanf("%s", str[1][i]);
		bfs();
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}