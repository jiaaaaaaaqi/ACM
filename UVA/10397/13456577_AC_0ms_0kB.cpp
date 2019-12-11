#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

const int maxn = 800;
int n;
double x[maxn];
double y[maxn];
double maps[maxn][maxn];
double dis[maxn];
bool vis[maxn];

void init(int n) {
	memset(x, 0, sizeof x);
	memset(y, 0, sizeof y);
	memset(vis, false, sizeof vis);
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			maps[i][j] = 10000000000.0;
		}
		dis[i] = 10000000000.0;
	}
}

double Prim() {
	double ans = 0;
	for(int i=1; i<=n; i++)
		dis[i] = maps[1][i];
	dis[1] = 0;
	vis[1] = true;
	for(int r=2; r<=n; r++) {
		int p = 0;
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[p]>dis[i]) {
				p = i;
			}
		}
		vis[p] = true;
		ans += dis[p];
		for(int i=1; i<=n; i++) {
			if(!vis[i] && dis[i] > maps[p][i]) {
				dis[i] = maps[p][i];
			}
		}
	}
	return ans;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i=1; i<=n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				double dis = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				dis = sqrt(dis);
				maps[i][j] = maps[j][i] = dis;
			}
			maps[i][i] = 0;
		}
		int m;
		scanf("%d", &m);
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			maps[v][u] = maps[u][v] = 0.0;
		}
		/*
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%.2lf\t",maps[i][j]);
			}
			printf("\n");
		}
		*/
		double ans = Prim();
		printf("%.2lf\n", ans);
	}
	return 0;
}
