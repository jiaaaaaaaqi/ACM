#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

struct node{
	int x;
	int y;
	int cnt;
};
int n, m;
int ans;
int bex, bey;
int enx, eny;
bool vis[205][205];
char str[205][205];
int dis[4][2]={1,0,-1,0,0,1,0,-1};

void bfs() {
	queue<node> q;
	node now, nex;
	now.x=bex;
	now.y=bey;
	now.cnt=0;
	vis[bex][bey]=1;
	q.push(now);
	while(!q.empty()) {
		now=q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			nex=now;
			nex.x += dis[i][0];
			nex.y += dis[i][1];
			nex.cnt++;
			if(nex.x<0 || nex.y<0)
				continue;
			if(nex.x>=n || nex.y>=m)
				continue;
			if(vis[nex.x][nex.y] || str[nex.x][nex.y] == '#')
				continue;
			vis[nex.x][nex.y]=1;
			if(str[nex.x][nex.y] == 'x')
				nex.cnt++;
			if(nex.x == enx && nex.y == eny) {
				ans=nex.cnt;
				return ;
			}
			q.push(nex);
		}
	}
}

void init() {
	memset(vis, false, sizeof(vis));
	memset(str, 0, sizeof(str));
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++) {
			scanf("%s", str[i]);
			for(int j=0; j<m; j++) {
				if(str[i][j] == 'r')
					bex=i, bey=j;
				if(str[i][j] == 'a')
					enx=i, eny=j;
			}
		}
		ans=0x3f3f3f3f;
		bfs();
		if(ans == 0x3f3f3f3f)
			printf("Impossible\n");
		else 
			printf("%d\n", ans);
	}
	return 0;
} 