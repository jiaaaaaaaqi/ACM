#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct bull1{
	char dir;
	int turn;
	int v;
	int x;
};
struct node{
	int x;
	int y;
	int cnt;
};
bull1 bull[105][105];
bool vis[105][105][1005];
int dis[5][2]={1,0,-1,0,0,1,0,-1,0,0};
int n,m,numbull,energe;
int ans;
void bfs()
{
	memset(vis, false, sizeof(vis));
	queue<node> q;
	node now,next;
	now.x=0;
	now.y=0;
	now.cnt=0;
	vis[0][0][0]=true;
	q.push(now);
	while (!q.empty())
	{
		now=q.front();
//		printf("%d  %d  %d\n",now.x, now.y, now.cnt);
		for (int i=0; i<5; i++)
		{
			int newx=now.x+dis[i][0];
			int newy=now.y+dis[i][1];
			int newcnt=now.cnt+1;
			if (newx<0||newy<0||newx>n||newy>m)
				continue;
			if (vis[newx][newy][newcnt]==true||newcnt>energe)
				continue;
			if (bull[newx][newy].x)
				continue;
			next.x=newx;
			next.y=newy;
			next.cnt=newcnt;
			int flag=1;

			newx=next.x;
			newy=next.y;
			while (1)	//nor 
			{
				newx--;
				if (newx<0)
					break; 
				if (bull[newx][newy].x)
				{
					if (bull[newx][newy].dir=='S')
					{
						int distan=next.x-newx;
						if (distan % bull[newx][newy].v)
							break;
						int t=next.cnt-distan / bull[newx][newy].v;
						if(t<0)
							break;
						if(t % bull[newx][newy].turn==0)
						{
							flag=0;
							break;
						}
					}
					break;
				}
			}
			if (!flag)
				continue;
			
			newx=next.x;
			newy=next.y;
			while (1)
			{
				newx++;
				if (newx>n)
					break;
				if (bull[newx][newy].x)	//sou
				{
					if (bull[newx][newy].dir=='N')
					{
						int distan=newx-next.x;
						if (distan % bull[newx][newy].v)
							break;
						int t=next.cnt-distan / bull[newx][newy].v;
						if(t<0)
							break;
						if(t % bull[newx][newy].turn==0)
						{
							flag=0;
							break;
						}
					}
					break;
				}
			}
			if (!flag)
				continue;

			newx=next.x;
			newy=next.y;
			while (1)	//west
			{
				newy--;
				if (newy<0)
					break;
				if (bull[newx][newy].x)
				{
					if (bull[newx][newy].dir=='E')
					{
						int distan=next.y-newy;
						if (distan % bull[newx][newy].v)
							break;
						int t=next.cnt-distan / bull[newx][newy].v;
						if(t<0)
							break;
						if(t % bull[newx][newy].turn==0)
						{
							flag=0;
							break;
						}
					}
					break;				
				}
			}
			if (!flag)
				continue;

			newx=next.x;
			newy=next.y;
			while (1)	//east
			{
				newy++;
				if (newy>m)
					break;
				if (bull[newx][newy].x)
				{
					if (bull[newx][newy].dir=='W')
					{
						int distan=newy-next.y;
						if (distan % bull[newx][newy].v)
							break;
						int t=next.cnt-distan / bull[newx][newy].v;
						if(t<0)
							break;
						if(t % bull[newx][newy].turn==0)
						{
							flag=0;
							break;
						}
					}
					break;
				}
			}
			if (!flag)
				continue;
			newx=next.x;
			newy=next.y;

			vis[newx][newy][newcnt]=true;
			if (newx==n&&newy==m)
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
	while(scanf("%d%d%d%d",&n, &m, &numbull, &energe)!=EOF)
	{
		memset(bull, 0, sizeof(bull));
		for(int i=0; i<numbull; i++)
		{
			char dir;
			int turn,v,x,y;
			getchar();
			scanf("%c%d%d%d%d",&dir, &turn, &v, &x, &y);
			bull[x][y].dir=dir;
			bull[x][y].turn=turn;
			bull[x][y].v=v;
			bull[x][y].x=1;
		}
		ans=-1;
		bfs();
		if(ans==-1)
			printf("Bad luck!\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}