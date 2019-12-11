#include<stdio.h>
#include<string.h>
#include<math.h> 
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct Node {
	double x;
	double y;
}node[505];
int n,m;
double maps[505][505];
double dis[505];
bool vis[505];

void init(int m) {
	memset(vis, false, sizeof(vis));
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=m; j++) {
			maps[i][j] = inf;
		}
		dis[i] = inf;
	}
}

double Prim(int n, int m) {
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++)
			if(!vis[i] && dis[p]>dis[i])
				p=i;
		vis[p] = true;
		for(int i=1; i<=n; i++)
			if(!vis[i] && dis[i]>maps[p][i])
				dis[i] = maps[p][i];
	}
	sort(dis+1, dis+n+1);
	return dis[n-m+1];
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d",&n, &m);
		init(m);
		for(int i=1; i<=m; i++) {
			scanf("%llf%llf",&node[i].x, &node[i].y);
		}
		double d;
		for(int i=1; i<=m; i++) {
			for(int j=i+1; j<=m; j++) {
				double x1 = node[i].x;
				double x2 = node[j].x;
				double y1 = node[i].y;
				double y2 = node[j].y;
				d=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
				maps[i][j] = maps[j][i] = d;
			}
			maps[i][i] = 0;
		}
		/*
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=m; j++) {
				printf("%lf  ",maps[i][j]);
			}
			puts("");
		}
		*/
		double ans=Prim(m, n);
		printf("%.2f\n", ans);
	}
	return 0;
}