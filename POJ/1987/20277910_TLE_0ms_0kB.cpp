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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)
 
typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;
 
int n, m, S;
int k, ans;
int cas, tol, T;
int sz[maxn], hv[maxn], dis[maxn], vis[maxn];
vector< pii > vv[maxn]; 

void dfssz(int u, int fa, int &rt) {
	hv[u] = sz[u] = 0;
	sz[u]++;
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].first;
		if(v==fa || vis[v])	continue;
		dfssz(v, u, rt);
		sz[u] += sz[v];
		hv[u] = max(hv[u], sz[v]);
	}
	hv[u] = max(hv[u], S-sz[u]);
	if(rt==0 || hv[rt] > hv[u])	rt = u;
}

void dfsdis(int u, int fa, int d) {
	if(d > k)	return ;
	dis[++tol] = d;
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi;
		if(vis[v] || v==fa)	continue;
		dfsdis(v, u, d+vv[u][i].second);
	}
}

int calc(int u, int w) {
	int ans = 0;
	mes(dis, 0);
	tol = 0;
	dfsdis(u, 0, w);
	sort(dis+1, dis+1+tol);
	int l = 1, r = tol;
	while(l<r) {
		while(l<r && dis[l]+dis[r]>k)	r--;
		ans += r-l;
		l++;
	}
	return ans;
}

void dfs(int u) {
	S = sz[u] ? sz[u] : n;
	int rt = 0;
	dfssz(u, 0, rt);
	ans += calc(rt, 0);
	vis[rt] = true;
	int len = vv[rt].size();
	for(int i=0; i<len; i++) {
		int v = vv[rt][i].fi;
		if(vis[v])	continue;
		ans -= calc(v, vv[rt][i].se);
		dfs(v);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		vv[i].clear();
		sz[i] = vis[i] = 0;
	}
	ans = 0;
	for(int i=1, u, v, d; i<=m; i++) {
		char ch[5];
		scanf("%d%d%d%s", &u, &v, &d, ch);
		vv[u].push_back(make_pair(v, d));
		vv[v].push_back(make_pair(u, d));
	}
	scanf("%d", &k);
	dfs(1);
	printf("%d\n", ans);
    return 0;
}
