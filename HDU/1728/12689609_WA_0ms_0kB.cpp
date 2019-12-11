#include<stdio.h>
#include<string.h>
struct node{
	int x;
	int y;
	int cnt;
	char way;
};
node que[10100];
int bex,bey,enx,eny;
int turn;
int n,m;
char str[105][105]={0};
int vis[105][105]={0};
int dis[4][2]={1,0,-1,0,0,1,0,-1};
char dir[ ]="durl";
int head,rear;
int flag;
void bfs ()
{
	memset(vis, 0, sizeof(vis));
	head=0;
	rear=1;
	que[0].x=bex;
	que[0].y=bey;
	que[0].cnt=-1;
	que[0].way='x';
	vis[bex][bey]=1; 
	while(head<rear)
	{
		for(int i=0; i<4; i++)
		{
			int newx=que[head].x+dis[i][0];
			int newy=que[head].y+dis[i][1];
			if(newx<1||newy<1||newx>n||newy>m)
				continue;
			if(str[newx][newy]=='*'||vis[newx][newy])
				continue;
			que[rear].x=newx;
			que[rear].y=newy;
			que[rear].way=dir[i];
			vis[newx][newy]=1;
			if(que[rear].way==que[head].way)
				que[rear].cnt=que[head].cnt;
			else
				que[rear].cnt=que[head].cnt+1;
			if(newx==enx&&newy==eny)
			{
				flag=1;
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
	while (T--)
	{
		flag=0;
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)
			scanf("%s", str[i]+1);
		scanf("%d%d%d%d%d", &turn, &bey, &bex, &eny, &enx);
		bfs();
		if(flag)
		{
			flag=0;
			if(turn>=que[rear].cnt)
			{
				char ch=que[rear].way;
				if(ch=='u'&&str[enx-1][eny]=='.')
					flag=1; 
				if(ch=='d'&&str[enx+1][eny]=='.')
					flag=1;
				if(ch=='l'&&str[enx][eny-1]=='.')
					flag=1;
				if(ch=='r'&&str[enx][eny+1]=='.')
					flag=1;
				if(!flag&&(!(turn-que[rear].cnt)&1))
					flag=1;
			}
		}
		printf("%s", flag ? "yes\n":"no\n");
		memset(str, 0, sizeof(str));
	}
	return 0;
}
