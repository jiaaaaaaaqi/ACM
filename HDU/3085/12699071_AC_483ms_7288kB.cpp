#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
struct node{
	int x;
	int y;
};
queue<node> q[2];
char str[805][805]={0};
int vis[2][805][805]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int n,m;
int mx,my;
int gx,gy;
int z1x,z2x,z1y,z2y;
int step;

int check(int x, int y)
{
	if(x<0||y<0||x>=n||y>=m)
		return 0;
	if(str[x][y]=='X')
		return 0;
	if((abs(x-z1x)+abs(y-z1y)) <= 2*step)
		return 0;
	if((abs(x-z2x)+abs(y-z2y)) <= 2*step)
		return 0;
	return 1;
}
int bfs(int k)
{
	int sum=q[k].size();
	while(sum--)
	{
		node now;
		now=q[k].front();
		for(int i=0; i<4; i++)
		{
			if(check(now.x, now.y))
			{
				node next;
				int newx=now.x+dis[i][0];
				int newy=now.y+dis[i][1];
				if(check(newx, newy))
				{
					if(vis[k][newx][newy])
						continue;
					if(vis[1-k][newx][newy])
						return 1;
					vis[k][newx][newy]=1;
					next.x=newx;
					next.y=newy;
					q[k].push(next);
				}
			}
		}
		q[k].pop();
	}
	return 0;
}
int solve()
{
	while(!q[0].empty())
		q[0].pop();
	while(!q[1].empty())
		q[1].pop();
	memset(vis, 0, sizeof(vis));
	
	node now;
	now.x=mx;
	now.y=my;
	vis[0][mx][my]=1;
	q[0].push(now);
	
	now.x=gx;
	now.y=gy;
	vis[1][gx][gy]=1;
	q[1].push(now);
	step=0;
	while((!q[0].empty()) || (!q[1].empty()))
	{
		step++;
		if(bfs(0)==1)
			return step;
		if(bfs(0)==1)
			return step;
		if(bfs(0)==1)
			return step;
		if(bfs(1)==1)
			return step;
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n, &m);
		int flag=0;		
		for(int i=0; i<n; i++)
		{
			scanf("%s", str[i]);
			for(int j=0; j<m; j++)
			{
				if(str[i][j]=='M')
					mx=i,my=j;
				if(str[i][j]=='G')
					gx=i,gy=j;
				if(str[i][j]=='Z')
				{
					if(!flag)
						z1x=i,z1y=j,flag=1;
					else
						z2x=i,z2y=j;
				}
			}
		}
		int ans=solve();
		printf("%d\n", ans);
	}
	return 0;
}