#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct node{
	int x;
	int y;
	int obs;
	int cnt;
};
int ans;
int n,m,k;
int str[25][25]={0};
bool vis[25][25][25]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};

void bfs()
{
	memset(vis, false, sizeof vis);
	queue<node> q;
	node now,next;
	now.x=0;
	now.y=0;
	now.cnt=0;
	if(str[0][0]==1)
	{
		now.obs=1;
		vis[1][0][0]=true; 
	}
	else
	{
		now.obs=0;
		vis[0][0][0]=true;
	}
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		for(int i=0; i<4; i++)
		{
			next.x=now.x+dis[i][0];
			next.y=now.y+dis[i][1];
			next.cnt=now.cnt+1;
			if(str[next.x][next.y]==1)
			{
				next.obs=now.obs+1;
			}
			else if(str[next.x][next.y]==0)
			{
				next.obs=0;
			} 
			if(next.x<0||next.y<0||next.x>=n||next.y>=m)
				continue;
			if(vis[next.obs][next.x][next.y])
				continue;
			if(next.obs>k)
				continue;

			vis[next.obs][next.x][next.y]=true;
			if(next.x==n-1&&next.y==m-1)
			{
				ans=next.cnt;
				return ;
			}
			q.push(next);
		}
		q.pop();
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n, &m);
		scanf("%d", &k);
		ans=-1;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d",&str[i][j]);
		bfs();
		printf("%d\n", ans);
		memset(str, 0, sizeof str);
	}
	return 0;
}