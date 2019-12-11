#include<stdio.h>
#include<string.h>
char dun[35][35][35]={0};
int vis[35][35][35]={0};
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct node{
	int x,y,z;
	int cnt;
};
node que[30000]={0};
int n,r,c,flag;
int endx,endy,endz;
int head,rear;
void dfs(int beginx, int beginy, int beginz)
{
	memset(que, 0, sizeof(que));
	head=0;
	rear=1;
	que[0].x=beginx,que[0].y=beginy,que[0].z=beginz;
	que[0].cnt=0;
	vis[beginx][beginy][beginz]=1;
	while(head<rear)
	{
		for(int i=0; i<6; i++)
		{
			int newx=que[head].x+dir[i][0];
			int newy=que[head].y+dir[i][1];
			int newz=que[head].z+dir[i][2];
			if(newx<0||newy<0||newz<0)
				continue;
			if(newx>=n||newx>=r||newz>=c)
				continue;
			if(dun[newx][newy][newz]=='#'||vis[newx][newy][newz]==1)
				continue;
			que[rear].x=newx;
			que[rear].y=newy;
			que[rear].z=newz;
			que[rear].cnt=que[head].cnt+1;
			rear++;
			vis[newx][newy][newz]=1;
			if(newx==endx&&newy==endy&&newz==endz)
			{
				flag=1;
				return;
			}
		}
		head++;
	}
}
int main()
{
	while(scanf("%d%d%d",&n,&r,&c), n||r||c)
	{
		flag=0;
		int bx,by,bz;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<r; j++)
			{
				scanf("%s",dun[i][j]);
				for(int k=0; k<c; k++)
				{
					if(dun[i][j][k]=='S')
					{
						bx=i;
						by=j;
						bz=k;
					}
					if(dun[i][j][k]=='E')
					{
						endx=i;
						endy=j;
						endz=k;
					}
				}
			}
		}
		dfs(bx, by, bz);
		if(flag)
			printf("Escaped in %d minute(s).\n",que[rear-1].cnt);
		else
			printf("Trapped!\n");
		printf("\n");
		memset(vis, 0, sizeof(vis));
		memset(dun, 0, sizeof(dun));
	}
	return 0;
}