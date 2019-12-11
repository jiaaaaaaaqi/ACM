#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<queue>
#define mod 999991
using namespace std;

struct node{
	int pre[4][8];
	int cnt;
};

int ans[4][8]={
	{11,12,13,14,15,16,17,0},
	{21,22,23,24,25,26,27,0},
	{31,32,33,34,35,36,37,0},
	{41,42,43,44,45,46,47,0}
};
int num[4][8];
bool vis[1000000];
int res;

int gethash(int a[4][8])
{
	long long int ans=0;
	for(int i=0; i<4; i++)
		for(int j=0; j<8; j++)
			ans=(ans<<1)+a[i][j];
	return ans%mod;
}

bool isans(int a[4][8])
{
	for(int i=0; i<4; i++)
		for(int j=0; j<8; j++)
			if(a[i][j]!=ans[i][j])
				return false;
	return true;
}

void bfs()
{
	queue<node> q;
	node now,nex;
	for(int i=0; i<4; i++)
		for(int j=0; j<8; j++)
			now.pre[i][j]=num[i][j];
	int prehash=gethash(now.pre);
	vis[prehash]=1;
	now.cnt=0;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(isans(now.pre))
		{
			res=now.cnt;
			return ;
		}
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<8; j++)
			{
				nex=now;
				if(now.pre[i][j]==0)
				{
					if(nex.pre[i][j-1]%10 == 7)
						continue;
					if(nex.pre[i][j-1] == 0)
						continue;
					for(int ii=0; ii<4; ii++)
						for(int jj=0; jj<8; jj++)
							if(nex.pre[ii][jj]==nex.pre[i][j-1]+1)
								nex.pre[ii][jj]=0;
					nex.pre[i][j]=nex.pre[i][j-1]+1;
					prehash=gethash(nex.pre);
					if(!vis[prehash])
					{
						vis[prehash]=true;
						nex.cnt++;
						q.push(nex);
					}
				}
			}
		}
	}
}

void handle()
{
	for(int i=0; i<4; i++)
	{
		num[i][0]=(i+1)*10+1;
		for(int j=1; j<8; j++)
		{
			if(num[i][j]%10==1)
			{
				num[i][j]=0;
				continue;
			}
		}
	}
}

void init()
{
	memset(num, 0, sizeof(num));
	memset(vis, false, sizeof(vis));
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		for(int i=0; i<4; i++)
			for(int j=1; j<8; j++)
				scanf("%d",&num[i][j]);
		handle();
		res=-1;
		bfs();
		printf("%d\n", res);
	}
	return 0;
}