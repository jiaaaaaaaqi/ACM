
/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月11日 星期一 14时46分16秒
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

int ans, S;
int sz[maxn], dis[maxn], hv[maxn];
bool vis[maxn];
vector< pii > vv[maxn];

void dfssz(int u, int f, int &rt) {
	sz[u] = 1;
	hv[u] = 0;
	int len = vv[u].size();
	for(int i=0; i<vv[u].size(); i++) {
		if(vv[u][i].fi == f || vis[vv[u][i].fi])	continue;
		dfssz(vv[u][i].fi, u, rt);
		sz[u] += sz[vv[u][i].fi];
		hv[u] = max(hv[u], sz[vv[u][i].fi]);
	}
	hv[u] = max(hv[u], S-sz[u]);
	if(!rt || hv[u] < hv[rt])	rt = u;
}

void dfsdis(int u, int f, int k) {
	if(k > m)	return ;
	dis[++tol] = k;
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		if(vv[u][i].fi == f || vis[vv[u][i].fi])	continue;
		dfsdis(vv[u][i].fi, u, vv[u][i].se+k);
	}
}

int calc(int rt, int w) {
	tol = 0;
	dfsdis(rt, 0, w);
	sort(dis+1, dis+1+tol);
	int i=1, j=tol, ans=0;
	while(i < j) {
		while(i<j && dis[i]+dis[j]>m)	j--;
		ans += j-i;
		i++;
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
		if(vis[vv[rt][i].fi])	continue;
		ans -= calc(vv[rt][i].fi, vv[rt][i].se);
		dfs(vv[rt][i].fi);
	}
}

int main() {
	// freopen("out.txt", "r", stdin);
	while(scanf("%d%d", &n, &m), n||m) {
		mes(vis, 0), mes(sz, 0);
		for(int i=1; i<=n; i++)	vv[i].clear();
		ans = 0;
		for(int i=1, u, v, w; i<=n-1; i++) {
			scanf("%d%d%d", &u, &v, &w);
			vv[u].push_back(make_pair(v, w));
			vv[v].push_back(make_pair(u, w));
		}
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
