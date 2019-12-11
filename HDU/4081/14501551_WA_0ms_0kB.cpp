#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const int maxm = 105;
using namespace std;

int n, m, tol;
struct Node {
    int x;
    int y;
    int w;
};
Node node[maxn];
double maps[maxn][maxn];
double cost[maxn][maxn];
bool used[maxn][maxn];
double dis[maxn];
bool vis[maxn];
int pre[maxn];

void init() {
    memset(node, 0, sizeof node);
    memset(vis, false, sizeof vis);
    memset(used, false, sizeof used);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            maps[i][j] = 100000000.0;
        }
        maps[i][i] = 0;
        dis[i] = 100000000.0;
    }
}

double calc(int i, int j) {
	double ans = (double)(node[i].x - node[j].x) * (node[i].x - node[j].x)+(double)(node[i].y - node[j].y) * (node[i].y - node[j].y);
	return sqrt(ans);
}

double prim() {
    for(int i=1; i<=n; i++)	dis[i] = maps[1][i], pre[i] = 1;
    vis[1] = true;
    pre[1] = 1;
    dis[1] = 0;
    double ans = 0;
    for(int r=2; r<=n; r++) {
        int p = 0;
        for(int i=1; i<=n; i++) {
            if(!vis[i] && dis[p] > dis[i]) {
                p = i;
            }
        }
        vis[p] = true;
        ans += dis[p];
		used[p][pre[p]] = used[pre[p]][p] = true;
		for(int i=1; i<=n; i++) {
			if(vis[i])	cost[i][p] = cost[p][i] = max(cost[i][pre[p]], dis[p]);
			if(!vis[i] && dis[i] > maps[p][i]) {
				dis[i] = maps[p][i];
				pre[i] = p;
			}
		}
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        init();
        for(int i=1; i<=n; i++)	scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].w);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				maps[i][j] = calc(i, j);
			}
		}
		double mst = prim();
		double ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				if(i == j)	continue;
				if(used[i][j]) {
					ans = max(ans, (node[i].w + node[j].w) / (mst - maps[i][j]));
				} else {
					ans = max(ans, (node[i].w + node[j].w) / (mst - cost[i][j]));
				}
			}
		}
		printf("%.2f\n", ans);
    }
    return 0;
}
