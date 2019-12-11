/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月15日 星期五 00时21分02秒
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int w[maxn], d[maxn], dis[maxn];
int best[maxn], dp[maxn][maxn];
vector< pii > vv[maxn];

void init() {
	mes(dp, inf);
	mes(best, inf);
	mes(w, 0), mes(d, 0);
	for(int i=1; i<=n; i++)	vv[i].clear();
}

void calc(int u, int fa) {
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi, w = vv[u][i].se;
		if(v == fa)	continue;
		dis[v] = dis[u]+w;
		calc(v, u);
	}
}

void dfs(int u, int fa) {
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi;
		if(v == fa)	continue;
		dfs(v, u);
	}
	mes(dis, inf);
	dis[u] = 0;
	calc(u, 0);
	for(int j=1; j<=n; j++) {
		if(dis[j] > d[u])	continue;
		dp[u][j] = w[j];
		for(int i=0; i<len; i++) {
			int v = vv[u][i].fi;
			if(v == fa)	continue;
			dp[u][j] += min(best[v], dp[v][j]-w[j]);
		}
		best[u] = min(best[u], dp[u][j]);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i=1; i<=n; i++)	scanf("%d", &w[i]);
		for(int i=1; i<=n; i++)	scanf("%d", &d[i]);
		for(int i=2, u, v, w; i<=n; i++) {
			scanf("%d%d%d", &u, &v, &w);
			vv[u].push_back(make_pair(v, w));
			vv[v].push_back(make_pair(u, w));
		}
		dfs(1, 0);
		// for(int i=1; i<=n; i++) {
		//     for(int j=1; j<=n; j++) {
		//         printf("%d%c", dp[i][j], j==n ? '\n' : ' ');
		//     }
		// }
		printf("%d\n", best[1]);
	}
	return 0;
}

