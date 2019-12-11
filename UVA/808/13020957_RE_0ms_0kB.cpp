#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

struct Node{
	int x;
	int y;
};
Node node[15005];
struct Edge{
	int x;
	int y;
	int cnt;
};
bool vis[2000][2000]; 
int dir[6][2]={{-1,1}, {0,2}, {1,1}, {1,-1}, {0,-2}, {-1,-1}};
int dis[6][2]={{0,-2}, {-1,-1}, {-1,1}, {0,2}, {1,1}, {1,-1}};

void handle() {
	int cnt=1;
	int x=0;
	int y=0;

	node[cnt].x=x;
	node[cnt++].y=y;

	y-=2;
	node[cnt].x=x;
	node[cnt++].y=y;
	for(int k=1; k<=60; k++) {
		for(int i=0; i<5; i++) {
			for(int j=0; j<k; j++) {
				x+=dir[i][0];
				y+=dir[i][1];
				node[cnt].x=x;
				node[cnt++].y=y;
			}
		}

		y-=2;
		node[cnt].x=x;
		node[cnt++].y=y;
		for(int j=0; j<k; j++) {
			x+=dir[5][0];
			y+=dir[5][1];
			node[cnt].x=x;
			node[cnt++].y=y;
		}
	}
}

int bfs(int bex, int bey, int enx, int eny) {
	memset(vis, false, sizeof(vis));
	queue<Edge> q;
	Edge now,nex;
	now.x=bex;
	now.y=bey;
	vis[bex+500][bey+500]=true;
	now.cnt=0;
	q.push(now);
	while(!q.empty()) {
		now=q.front();
		q.pop();
		for(int i=0; i<6; i++) {
			nex.x=now.x+dis[i][0];
			nex.y=now.y+dis[i][1];
			nex.cnt=now.cnt+1;
		//	printf("%d %d %d\n",nex.x, nex.y, vis[nex.x][nex.y]);
			if(vis[nex.x+500][nex.y+500])
				continue;
			vis[nex.x+500][nex.y+500]=true;
			if(nex.x==enx && nex.y==eny)
				return nex.cnt;
			q.push(nex);
		}
	}
}

int main() {
	memset(node, 0, sizeof(node));
	int be,en;
	handle();
	while(scanf("%d%d",&be, &en), be||en){
		int bex=node[be].x;
		int bey=node[be].y;
		int enx=node[en].x;
		int eny=node[en].y;
		int ans=bfs(bex, bey, enx, eny);
		printf("The distance between cells %d and %d is %d.\n",be,en,ans);
	}
	return 0;
} 