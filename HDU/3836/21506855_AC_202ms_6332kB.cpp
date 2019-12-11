/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月26日 星期一 15时04分50秒
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int stasz, cnt, top;
vector<int> vv[maxn];
int dfn[maxn], low[maxn], sta[maxn], maps[maxn];
int ind[maxn], oud[maxn];
bool vis[maxn];

void init() {
	stasz = cnt = top = 0;
	for(int i=1; i<=n; i++)	vv[i].clear();
	mes(ind, 0), mes(oud, 0);
	mes(dfn, 0), mes(low, 0);
	mes(vis, 0);
}

void dfs(int u) {
	int v;
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	sta[stasz++] = u;
	for(auto v : vv[u]) {
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		top++;
		do {
			v = sta[--stasz];
			maps[v] = top;
			vis[v] = false;
		} while(v != u);
	}
}

void tarjan() {
	for(int i=1; i<=n; i++) {
		if(!dfn[i])	dfs(i);
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1, u, v; i<=m; i++) {
			scanf("%d%d", &u, &v);
			vv[u].pb(v);
		}
		tarjan();
		if(top == 1) {
			printf("0\n");
			continue;
		}
		for(int i=1; i<=n; i++) {
			for(auto v : vv[i]) {
				if(maps[i] != maps[v]) {
					ind[maps[v]]++;
					oud[maps[i]]++;
				}
			}
		}
		ll ans1, ans2, ans3;
		ans1 = ans2 = ans3 = 0;
		for(int i=1; i<=top; i++) {
			if(ind[i] && !oud[i])	ans1++;
			if(!ind[i] && oud[i])	ans2++;
			if(!ind[i] && !oud[i])	ans3++;
		}
		printf("%lld\n", ans3+max(ans1, ans2));
	}
    return 0;
}

