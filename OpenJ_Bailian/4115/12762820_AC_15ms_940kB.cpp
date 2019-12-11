#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

struct node{
	int x;
	int y;
	int cnt;
	int cha;
};

int ans;
int n,m,sum;
int bex,bey;
int enx,eny;
bool vis[15][205][205];
char str[205][205];
int dis[4][2]={1,0,-1,0,0,1,0,-1};

void init() {
	memset(vis, false, sizeof(vis));
	memset(str, 0, sizeof(str));
}

void bfs() {
	queue<node> q;
	node now,nex;
	now.x=bex;
	now.y=bey;
	now.cha=0;
	now.cnt=0;
	vis[0][bex][bey]=1;
	q.push(now);
	while(!q.empty()) {
		now=q.front();
		q.pop();
		if(now.cha > sum)
			return ;
		for(int i=0; i<4; i++) {
			nex=now;
			nex.x+=dis[i][0];
			nex.y+=dis[i][1];
			nex.cnt++;
			if(nex.x<0 || nex.y<0)
				continue;
			if(nex.x>=n || nex.y>=m)
				continue;
			if(str[nex.x][nex.y] == '#')
				nex.cha++;
			if(vis[nex.cha][nex.x][nex.y] || nex.cha>sum)
				continue;
			vis[nex.cha][nex.x][nex.y]=1;
			if(nex.x == enx && nex.y == eny) {
				ans=nex.cnt;
				return ;
			}
			q.push(nex);
		}
	} 
}

int main() {
	while(scanf("%d%d%d", &n, &m, &sum)!=EOF) {
		init();
		for(int i=0; i<n; i++) {
			scanf("%s", str[i]);
			for(int j=0; j<m; j++) {
				if(str[i][j] == '@')
					bex=i, bey=j;
				if(str[i][j] == '+')
					enx=i, eny=j;
			}
		}
		ans=0x3f3f3f3f;
		bfs();
		if(ans == 0x3f3f3f3f)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
} 