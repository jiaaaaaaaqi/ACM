#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct Node{
	int x;
	int y;
}node[105];
struct Edge{
	int x;
	int y;
	int cnt;
};
int n,m;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
char str[55][55];
int num[55][55];
bool use[55][55];
int maps[105][105];
bool vis[105];
int dis[105];
int tol;

void init() {
	memset(maps, inf, sizeof(maps));
	memset(vis, false, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	memset(node, 0, sizeof(node));
	memset(str, 0, sizeof(str));
	memset(num, -1, sizeof(num));
}

void bfs(int bex, int bey) {
	memset(use, false, sizeof(use));
	int cnt=0;
	queue<Edge> q;
	Edge now,nex;
	now.x = bex;
	now.y = bey;
	now.cnt = 0;
	use[bex][bey] = true;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			nex.x = now.x + dir[i][0];
			nex.y = now.y + dir[i][1];
			nex.cnt = now.cnt + 1;
			if(nex.x<1 || nex.y<1)
				continue;
			if(nex.x>n || nex.y>m)
				continue;
			if(str[nex.x][nex.y] == '#' || use[nex.x][nex.y]) 
				continue;
			use[nex.x][nex.y] = true;
			q.push(nex);
			if(str[nex.x][nex.y] == 'A') {
				maps[num[bex][bey]][num[nex.x][nex.y]] = nex.cnt;
				cnt++;
			}
			if(cnt == tol)
				return ;
		}
	}
}

int Prim() {
	int ans=0;
	for(int i=1; i<=tol; i++) {
		dis[i] = maps[1][i];
	}
	dis[1] = 0;
	vis[1] = true;
	for(int r=2; r<=tol; r++) {
		int p=0;
		for(int i=1; i<=tol; i++) {
			if(!vis[i] && dis[p]>dis[i]) {
				p=i;
			}
		}
		vis[p] = true;
		ans += dis[p];
		for(int i=1; i<=tol; i++) {
			if(!vis[i] && dis[i]>maps[p][i]) {
				dis[i] = maps[p][i];
			}
		}
	}
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		init();
		scanf("%d%d",&m, &n);
		getchar();
		tol=1;
		for(int i=1; i<=n; i++) {
			gets(str[i]);
			for(int j=m; j>=0; j--)
				str[i][j+1] = str[i][j];
			str[i][0] = ' ';
			for(int j=1; j<=m; j++) {
				if(str[i][j] == 'S')
					str[i][j] = 'A';
				if(str[i][j] == 'A') {
					node[tol].x = i;
					node[tol].y = j;
					num[i][j] = tol;
					tol++;
				}
			}
		}
		tol--;
		for(int i=1; i<=tol; i++) {
//			printf("%d  %d\n",node[i].x, node[i].y);
			bfs(node[i].x, node[i].y);
			maps[i][i] = 0;
		}
		/*
		for(int i=1; i<=tol; i++) {
			for(int j=1; j<=tol; j++) {
				printf("%d ",maps[i][j]);
			}
			puts("");
		}
		*/
		int ans = Prim();
		printf("%d\n", ans);
	}
	return 0;
}
