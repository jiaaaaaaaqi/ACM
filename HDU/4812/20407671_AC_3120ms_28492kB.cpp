/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月13日 星期六 15时26分36秒
 ***************************************************************/

#pragma comment(linker,"/STACK:102400000,102400000")
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e6 + 3;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int st, ed, S;
ll a[maxn], inv[maxn*10];
int sz[maxn], hv[maxn];
bool vis[maxn];
vector<int> vv[maxn];

void handle() {
	int mx = 1e6+5;
	inv[1] = 1;
	for(int i=2; i<=mx; i++) {
		inv[i] = (mod-mod/i) * inv[mod%i] % mod;
	}
}

void dfssz(int u, int fa, int &rt) {
	sz[u] = 1, hv[u] = 0;
	for(auto v : vv[u]) {
		if(vis[v] || v==fa)	continue;
		dfssz(v, u, rt);
		sz[u] += sz[v];
		hv[u] = max(hv[u], sz[v]);
	}
	hv[u] = max(hv[u], S-sz[u]);
	if(rt==0 || hv[u]<hv[rt])	rt = u;
}

int id[maxn*10], dis[maxn];

void query(int u, int fa, ll w, int rt) {
	ll need = 1ll*m*a[rt]%mod*inv[w]%mod;
	if(id[need]) {
		int x = u, y = id[need];
		if(x > y)	swap(x, y);
		if(x < st) {
			st = x, ed = y;
		} else if(x == st) {
			st = x, ed = min(y, ed);
		}
	}
	for(auto v : vv[u]) {
		if(vis[v] || v==fa)	continue;
		query(v, u, w*a[v]%mod, rt);
	}
}

void update(int u, int fa, ll w) {
	if(id[w])	id[w] = min(id[w], u);
	else	id[w] = u, dis[++tol] = w;;
	for(auto v : vv[u]) {
		if(vis[v] || v==fa)	continue;
		update(v, u, w*a[v]%mod);
	}
}

void calc(int u, int rt) {
	tol = 0;
	id[a[u]] = u;
	dis[++tol] = a[u];
	for(auto v : vv[u]) {
		if(vis[v])	continue;
		query(v, u, 1ll*a[u]*a[v]%mod, rt);
		update(v, u, 1ll*a[u]*a[v]%mod);
		// printf("v = %d\n", v);
		// for(int i=1; i<=tol; i++)	printf("%d%c", dis[i], i==tol ? '\n' : ' ');
	}
	for(int i=1; i<=tol; i++)	id[dis[i]] = 0;
}

void dfs(int u) {
	S = sz[u] ? sz[u] : n;
	int rt = 0;
	dfssz(u, 0, rt);
	calc(rt, rt);
	vis[rt] = true;
	for(auto v : vv[rt]) {
		if(vis[v])	continue;
		dfs(v);
	}
}

int main() {
	handle();
	while(~scanf("%d%d", &n, &m)) {
		mes(id, 0);
		st = ed = inf;
		for(int i=1; i<=n; i++)  {
			scanf("%lld", &a[i]);
			vv[i].clear();
			sz[i] = vis[i] = 0;
		}
		for(int i=1, u, v; i<n; i++) {
			scanf("%d%d", &u, &v);
			vv[u].push_back(v);
			vv[v].push_back(u);
		}
		dfs(1);
		if(st == inf) {
			printf("No solution\n");
		} else {
			printf("%d %d\n", st, ed);
		}
	}
    return 0;
}

