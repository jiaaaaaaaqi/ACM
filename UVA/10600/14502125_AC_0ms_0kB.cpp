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
const int maxn = 105;
const int maxm = 105;
using namespace std;

int n, m, tol;
int maps[maxn][maxn];
int cost[maxn][maxn];
bool used[maxn][maxn];
int  dis[maxn];
bool vis[maxn];
int pre[maxn];

void init() {
    memset(used, false, sizeof used);
    memset(vis, false, sizeof vis);
	memset(maps, inf, sizeof maps);
	memset(dis, inf, sizeof dis);
}

int prim() {
    for(int i=1; i<=n; i++)	dis[i] = maps[1][i], pre[i] = 1;
    vis[1] = true;
    pre[1] = 1;
    dis[1] = 0;
    int ans = 0;
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
			if(vis[i] && i != p)	cost[i][p] = cost[p][i] = max(cost[i][pre[p]], dis[p]);
			if(!vis[i] && dis[i] > maps[p][i]) {
				dis[i] = maps[p][i];
				pre[i] = p;
			}
		}
    }
    return ans;
}

int find(int mst) {
	int ans = inf;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i != j && maps[i][j] != inf && !used[i][j])
				ans = min(ans, mst - cost[i][j] + maps[i][j]);
		}
	}
	return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        init();
		for(int i=1; i<=m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			maps[u][v] = maps[v][u] = w;
		}
		int mst = prim();
		int smst = find(mst);
		printf("%d %d\n", mst, smst);
    }
    return 0;
}
