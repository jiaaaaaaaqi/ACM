#include<stdio.h>
#include<string.h>
struct node{
	int x;
	int y;
	int cnt;
};
node que[1000005];
int ji,jj;
int n,m;
int ans;
int vis[1005][1005]={0};
char str[1005][1005]={0};
int flag[1005][1005]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
void bfsf()
{
	memset(vis, 0, sizeof(vis));
	memset(que, 0, sizeof(que));
	memset(flag, 0x3f3f3f3f, sizeof(flag));
	int head=0;
	int numfire=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(str[i][j]=='F')
			{
				que[numfire].x=i;
				que[numfire].y=j;
				que[numfire].cnt=0;
				vis[i][j]=1;
				flag[i][j]=0;
				numfire++;
			}			
		}
	}
	int rear=numfire;
	while(head<rear)
	{
		for(int i=0; i<4; i++)
		{
			int newx=que[head].x+dis[i][0];
			int newy=que[head].y+dis[i][1];
			if(newx<0||newy<0||newx>=n||newy>=m)
				continue;
			if(str[newx][newy]=='#'||vis[newx][newy])
				continue;
			que[rear].x=newx;
			que[rear].y=newy;
			que[rear].cnt=que[head].cnt+1;
			flag[newx][newy]=que[rear].cnt;
			vis[newx][newy]=1;
			rear++;
		}
		head++;
	}
/*	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%d ",flag[i][j]);
		printf("\n");
	}*/
}
void bfsj()
{
	memset(vis, 0, sizeof(vis));
	memset(que, 0, sizeof(que));
	int head=0;
	int rear=1;
	que[0].x=ji,que[0].y=jj,que[0].cnt=0;
	vis[ji][jj]=1;
	while(head<rear)
	{
		for(int i=0; i<4; i++)
		{
			int newx=que[head].x+dis[i][0];
			int newy=que[head].y+dis[i][1];
			if(str[newx][newy]=='#'||vis[newx][newy])
				continue;
			if(que[head].cnt+1>=flag[newx][newy])
				continue;
			vis[newx][newy]=1;
			que[rear].x=newx;
			que[rear].y=newy;
			que[rear].cnt=que[head].cnt+1;
			if(newx==0||newy==0||newx==(n-1)||newy==(m-1))
			{
				ans=que[rear].cnt+1;
				return ;
			}
			rear++;
		}
		head++;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=-1;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
		{
			scanf("%s",str[i]);
			for(int j=0; j<m; j++)
			{
				if(str[i][j]=='J')
				{
					ji=i;
					jj=j;
				}
			}
		}
		if(ji==0||jj==0||ji==(n-1)||jj==(m-1))
			printf("1\n");
		else
		{
			bfsf();
			bfsj();
			if(ans==-1)
				printf("IMPOSSIBLE\n");
			else
				printf("%d\n",ans);
		}
		memset(str, 0, sizeof(str));
	}
	return 0;
}