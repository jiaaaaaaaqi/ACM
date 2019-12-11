#include<stdio.h>
#include<string.h>
int min_(int a, int b)
{
	return a<b ? a:b;
}
struct node{
	int x;
	int y;
	int cnt;
};
node que[1005];
int n,m;
int ans;
int sumgrass;
int vis[15][15]={0};
char str[15][15]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int head;
int rear;
void bfs(int begin1x, int begin1y, int begin2x, int begin2y)
{
	memset(que, 0, sizeof(que));
	memset(vis, 0, sizeof(vis));
	head=0;
	rear=2;
	que[0].x=begin1x;
	que[0].y=begin1y;
	que[0].cnt=0;
	que[1].x=begin2x;
	que[1].y=begin2y;
	que[1].cnt=0;
	vis[begin1x][begin1y]=1;
	vis[begin2x][begin2y]=1;
	int sum=2;
	while(head<rear)
	{
		for(int i=0; i<4; i++)
		{
			int newx=que[head].x+dis[i][0];
			int newy=que[head].y+dis[i][1];
			if(newx<0||newy<0||newx>=n||newy>=m)
				continue;
			if(vis[newx][newy]||str[newx][newy]=='.')
				continue;
			sum++;
			que[rear].x=newx;
			que[rear].y=newy;
			que[rear].cnt=que[head].cnt+1;
			vis[newx][newy]=1;
			rear++;
		}
		head++;
	}
	if(sum==sumgrass)
	{
		if(ans!=-1)
			ans=min_(que[rear-1].cnt, ans);
		else
			ans=que[rear-1].cnt;
		return ;
	}

}
int main()
{
	int T;
	int cas=1;;
	scanf("%d",&T);
	while(T--)
	{
		ans=-1;
		sumgrass=0;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
		{
			scanf("%s",str[i]);
			for(int j=0; j<m; j++)
				if(str[i][j]=='#')
					sumgrass++;
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(str[i][j]=='#')
				{
					for(int q=0; q<n; q++)
					{
						for(int p=0; p<m; p++)
						{
							if(str[q][p]=='#')
							{
								bfs(i, j, q, p);
							}
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", cas++, sumgrass==1 ? 0:ans);
	}
	return 0;
}
