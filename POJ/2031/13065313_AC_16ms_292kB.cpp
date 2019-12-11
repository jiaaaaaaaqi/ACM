#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct Node{
	double x;
	double y;
	double z;
	double r;
}node[105];
double maps[105][105];
double dis[105];
bool vis[105];

void init(int n) {
	memset(node, 0, sizeof(node));
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			maps[i][j] = inf;
		}
		maps[i][i] = 0.0;
		dis[i] = inf;
	}
	memset(vis, false, sizeof(vis));
}

void addnode(double x, double y, double z, double r, int tol) {
	node[tol].x = x;
	node[tol].y = y;
	node[tol].z = z;
	node[tol].r = r;
}

double Prim(int n) {
	double ans=0;
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	vis[1] = true;
	for(int r=2; r<=n; r++) {
		int p=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i]) {
				p=i;
			}
		}
		vis[p] = true;
		ans += dis[p];
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i]>maps[p][i]) {
				dis[i] = maps[p][i];
			}
		}
	}
	return ans;
}

int main() {
	int n;
	while(scanf("%d", &n), n) {
		init(n);
		for(int i=1; i<=n; i++) {
			double x,y,z,r;
			scanf("%lf%lf%lf%lf",&x, &y, &z, &r);
			addnode(x, y, z, r, i);
		}
		double d;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				double x1 = node[i].x;
				double x2 = node[j].x;
				double y1 = node[i].y;
				double y2 = node[j].y;
				double z1 = node[i].z;
				double z2 = node[j].z;
				double r1 = node[i].r;
				double r2 = node[j].r;
				d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2)) - r1 - r2;
				if(d < 0)
					d=0;
				maps[i][j] = maps[j][i] = d;
			}
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%.2lf  ", maps[i][j]);
			}
			puts("");
		}
		*/
		double ans=Prim(n);
		printf("%.3lf\n", ans);
	}
	return 0;
}