/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月16日 星期四 15时16分42秒
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
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int cnt;
vector<int> vv[maxn];
int dfn[maxn], low[maxn], fath[maxn];
bool maps[maxn][maxn], vis[maxn];

void init() {
	cnt = 0;
	mes(dfn, 0), mes(low, 0), mes(vis, 0);
	mes(maps, 0), mes(fath, 0);
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
}

void dfs(int u, int fa) {
	int v;
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	fath[u] = fa;
	for(auto v : vv[u]) {
		if(!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if(v == fa) {
			continue;
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void tarjan() {
	for(int u=1; u<=n; u++) {
		if(!dfn[u]) {
			dfs(u, 0);
		}
	}
}

void solve() {
	vector< pii > vec;
	vec.clear();
	for(int v=2; v<=n; v++) {
		int u = fath[v];
		if(u==0)	continue;
		if(low[v] > dfn[u]) {
			vec.push_back(make_pair(min(u, v), max(u, v)));
		}
	}
	sort(vec.begin(), vec.end());
	printf("%d critical links\n", vec.size());
	for(auto i : vec) {
		printf("%d - %d\n", i.fi-1, i.se-1);
	}
	printf("\n");
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		if(n==0) {
			printf("0 critical links\n");
			continue;
		}
		for(int i=1, u, x, v; i<=n; i++) {
			scanf("%d (%d)", &u, &x);
			u++;
			for(int j=1; j<=x; j++) {
				scanf("%d", &v);
				v++;
				maps[u][v] = maps[v][u] = 1;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				if(maps[i][j]) {
					vv[i].push_back(j);
					vv[j].push_back(i);
				}
			}
		}
		tarjan();
		solve();
	}
	return 0;
}

