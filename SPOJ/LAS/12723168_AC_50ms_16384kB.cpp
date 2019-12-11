#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct node{
	int x;
	int y;
	int cnt;
};

char str[210][210];
char ans[210][210];
bool vis[210][210];
int step[210][210];
int dire[210][210];
int front_x[210][210];
int front_y[210][210];
int dis[4][2]={1,0,-1,0,0,1,0,-1};
int bex,bey;
int enx,eny;
int n,m;
char bed;

char get_dis(int x, int y, int d1, int d2)
{
	if((d1==0&&d2==2)||(d1==2&&d2==0))
		return '\\';
	if((d1==0&&d2==3)||(d1==3&&d2==0))
		return '/';
	if((d1==1&&d2==2)||(d1==2&&d2==1))
		return '/';
	if((d1==1&&d2==3)||(d1==3&&d2==1))
		return '\\';
	return str[x][y];
}

void get_map( )
{
	memset(ans, 0, sizeof(ans));
	memcpy(ans, str, sizeof(str));
	int tx=enx;
	int ty=eny;
	enx=front_x[tx][ty];
	eny=front_y[tx][ty];
	while(enx!=bex||eny!=bey)
	{
		if(dire[enx][eny]!=dire[tx][ty])
			ans[enx][eny]=get_dis(enx, eny, dire[enx][eny], dire[tx][ty]);
		tx=enx;
		ty=eny;
		enx=front_x[tx][ty];
		eny=front_y[tx][ty];
	}
}

bool check(int x, int y, int num)
{
	if (x<0||y<0||x>=n||y>=m)
		return 0;
	if (str[x][y]=='#')
		return 0;
	if (vis[x][y]&&step[x][y]<=num)
		return 0;
	return 1;
}

void bfs()
{
	memset(vis, false, sizeof(vis));
	memset(step, -1, sizeof(step));
	memset(dire, -1, sizeof(dire));
	memset(front_x, 0, sizeof(front_x));
	memset(front_y, 0, sizeof(front_y));

	queue<node> q;
	node now,nex;
	now.x=bex;
	now.y=bey;
	now.cnt=-1;
	dire[bex][bey]=bed;
	vis[bex][bey]=true;
	front_x[bex][bey]=0;
	front_y[bex][bey]=0;
	step[bex][bey]=-1;

	nex.x=now.x+dis[bed][0];
	nex.y=now.y+dis[bed][1];
	nex.cnt=now.cnt+1;
	int tx=now.x;
	int ty=now.y;
	while(check(nex.x, nex.y, nex.cnt))
	{
		vis[nex.x][nex.y]=true;
		step[nex.x][nex.y]=nex.cnt;
		dire[nex.x][nex.y]=bed;
		front_x[nex.x][nex.y]=tx;
		front_y[nex.x][nex.y]=ty;
		q.push(nex);
		tx=nex.x;
		ty=nex.y;
		nex.x+=dis[bed][0];
		nex.y+=dis[bed][1];
	}
	
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now.x==enx&&now.y==eny)
		{
			get_map( );
			return ;
		}
		for(int i=0; i<4; i++)
		{
			nex.x=now.x+dis[i][0];
			nex.y=now.y+dis[i][1];
			tx=now.x;
			ty=now.y;
			nex.cnt=now.cnt+1;
			while(check(nex.x, nex.y, nex.cnt))
			{
				vis[nex.x][nex.y]=true;
				step[nex.x][nex.y]=nex.cnt;
				dire[nex.x][nex.y]=i;
				front_x[nex.x][nex.y]=tx;
				front_y[nex.x][nex.y]=ty;
				q.push(nex);
				tx=nex.x;
				ty=nex.y;
				nex.x+=dis[i][0];
				nex.y+=dis[i][1];
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n, &m);
		memset(str, 0, sizeof(str));
		for (int i=0; i<n; i++)
		{
			scanf("%s",str[i]);
			for (int j=0; j<m; j++)
			{
				if(str[i][j]=='>' || str[i][j]=='<' || str[i][j]=='^' || str[i][j]=='v')
					bex=i,bey=j;
				if(str[i][j]=='C')
					enx=i,eny=j;
			}
		}
		
		if(str[bex][bey]=='>')
			bed=2;
		if(str[bex][bey]=='<')
			bed=3;
		if(str[bex][bey]=='^')
			bed=1;
		if(str[bex][bey]=='v')
			bed=0;

		if(bex==enx&&bey==eny)
			memcpy(ans, str, sizeof(str));
		else
			bfs();

/*
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				printf("%d%c",dire[i][j], (j==m-1 ? '\n':' '));
*/
		for(int i=0; i<n; i++)
			printf("%s\n", ans[i]);
	}
	return 0;
}