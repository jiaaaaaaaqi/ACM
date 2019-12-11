#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

struct Node{
	int x;
	int y;
}node[105];
double maps[105][105];
double dis[105];
bool vis[105]; 

void init(int n) {
	memset(vis, false, sizeof(vis));
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			maps[i][j] = 1000000000.0;
		}
		dis[i] = 1000000000.0;
	}
}

double Prim(int n) {
	double ans=0;
	vis[1] = true;
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i]) {
				p=i;
			}
		}
		if(p == 0)
			return -1;
		ans += dis[p];
		vis[p] = true;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i]>maps[p][i]) {
				dis[i] = maps[p][i];
			}
		}
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d",&n);
		init(n);
		for(int i=1; i<=n; i++) {
			int x,y;
			scanf("%d%d",&x, &y);
			node[i].x = x;
			node[i].y = y;
		}
		double d;
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				d=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x) + (node[i].y-node[j].y)*(node[i].y-node[j].y));
				if(d>=10 && d<=1000)
					maps[i][j] = maps[j][i] = d*100;
			}
			maps[i][i] = 0;
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%.1lf  ",maps[i][j]);
			}
			printf("\n");
		}
		*/
		double ans=Prim(n);
		if(ans == -1)
			printf("oh!\n");
		else
			printf("%.1lf\n", ans);
	}
	return 0;
}
