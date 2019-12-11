/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年11月06日 星期三 18时45分28秒
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

vector<int> vv[maxn];
int sz[maxn], gsz[maxn];

void dfs(int u, int fa) {
	sz[u] = 1;
	gsz[u] = 0;
	for(auto v : vv[u])	if(v != fa) {
		dfs(v, u);
		sz[u] += sz[v];
		gsz[u] = max(gsz[u], sz[v]);
	}
	gsz[u] = max(gsz[u], n-sz[u]);
}

unordered_map<ull, bool> mp;
int psz[maxn];
ull f[maxn], g[maxn];
ull c[2][maxn];

void solve1(int u, int fa) {
	psz[u] = 1;	
	f[u] = 1;
	for(auto v : vv[u])	if(v != fa) {
		solve1(v, u);
		psz[u] += psz[v];
		f[u] += f[v]*psz[v];
	}
}

void solve2(int u, int fa, int id, int &len) {
	if(fa == 0)	g[u] = f[u];
	else	g[u] = g[fa]-f[u]*psz[u]+f[fa]*psz[fa];
	c[id][++len] = g[u];
	for(auto v : vv[u])	if(v != fa)
		solve2(v, u, id, len);
}

bool check(int u) {
	mp.clear();
	ll ans, res;
	int len1, len2;
	{
		int v = vv[u][0];
		solve1(v, 0);
		len1 = 0;
		solve2(v, 0, 0, len1);
		sort(c[0]+1, c[0]+1+len1);
	}
	int len = vv[u].size();
	for(int i=1; i<len; i++) {
		solve1(vv[u][i], 0);
		len2 = 0;
		solve2(vv[u][i], 0, 1, len2);
		sort(c[1]+1, c[1]+1+len2);
		if(len1 != len2)	return false;
		for(int j=1; j<=len1; j++)	if(c[0][j]!=c[1][j])	return false;
	}
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=2,u,v; i<=n; i++) {
		scanf("%d%d", &u, &v);
		vv[u].pb(v);
		vv[v].pb(u);
	}
	dfs(1, 1);
	vector<int> g;
	int t = n;
	for(int i=1; i<=n; i++)	t = min(t, gsz[i]);
	for(int i=1; i<=n; i++)	if(gsz[i] == t)	g.pb(i);
	int ans = -1;
	for(auto v : g) {
		if(check(v))	ans = max(ans, (int)vv[v].size());
	}
	printf("%d\n", ans);
	return 0;
}

