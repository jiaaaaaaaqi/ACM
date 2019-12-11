#include<stdio.h>
#include<string.h>
int max_(int a, int b)
{
	return a>b ? a:b;
}
int min_(int a, int b)
{
	return a<b ? a:b;
}
struct node{
	int x;
	int y;
	int cnt;
};
node que1[40005];
node que2[40005];
int main()
{
	int byx,byy;
	int bmx,bmy;
	int flag1[205][205]={0};
	int flag2[205][205]={0};
	int vis[205][205]={0};
	int dis[4][2]={1,0,-1,0,0,1,0,-1};
	char str[205][205]={0};
	int n,m;
	int T;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%s",str[i]);
			for(int j=0; j<m; j++)
			{
				if(str[i][j]=='Y')
					byx=i,byy=j,str[i][j]='#';
				if(str[i][j]=='M')
					bmx=i,bmy=j,str[i][j]='#';
			}
		}
		memset(vis, 0, sizeof(vis));
		int head=0;
		int rear=1;
		que1[0].x=byx;
		que1[0].y=byy;
		que1[0].cnt=0;
		vis[byx][byy]=1;
		while(head<rear)
		{
			for(int i=0; i<4; i++)
			{
				int newx=que1[head].x+dis[i][0];
				int newy=que1[head].y+dis[i][1];
				if(newx<0||newy<0||newx>=n||newy>=m)
					continue;
				if(vis[newx][newy]||str[newx][newy]=='#')
					continue;
				que1[rear].x=newx;
				que1[rear].y=newy;
				que1[rear].cnt=que1[head].cnt+1;
				flag1[newx][newy]=que1[rear].cnt;
				vis[newx][newy]=1;
				rear++;
			}
			head++;
		}
		memset(vis, 0, sizeof(vis));
		head=0;
		rear=1;
		que2[0].x=bmx;
		que2[0].y=bmy;
		que2[0].cnt=0;
		vis[bmx][bmy]=1;
		while(head<rear)
		{
			for(int i=0; i<4; i++)
			{
				int newx=que2[head].x+dis[i][0];
				int newy=que2[head].y+dis[i][1];
				if(newx<0||newy<0||newx>=n||newy>=m)
					continue;
				if(vis[newx][newy]||str[newx][newy]=='#')
					continue;
				que2[rear].x=newx;
				que2[rear].y=newy;
				que2[rear].cnt=que2[head].cnt+1;
				flag2[newx][newy]=que2[rear].cnt;
				vis[newx][newy]=1;
				rear++;
			}
			head++;
		}
		int min=0x3f3f3f3f;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(str[i][j]=='@')
					min=min_(min,flag1[i][j]+flag2[i][j]);
			}
		}
		printf("%d\n", min*11);
	}
	return 0;
}