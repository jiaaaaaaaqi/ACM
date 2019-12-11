/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月12日 星期二 23时37分20秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn], f[maxn], g[maxn], p[maxn];
vector< pair<int, ll> > vv[maxn];
deque<int> q;

void dfsf(int u, int fa) {
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi;
		ll w = vv[u][i].se;
		if(v == fa)	continue;
		p[v] = u;
		dfsf(v, u);
		f[u] = max(f[u], f[v]+w);
	}
}

void dfsg(int u, int fa) {
	int len = vv[fa].size();
	g[u] = g[fa];
	int t = 0;
	for(int i=0; i<len; i++) {
		int v = vv[fa][i].fi;
		ll w = vv[fa][i].se;
		if(v == p[fa])	continue;
		if(u == v)	t = w;
		else {
			g[u] = max(g[u], f[v]+w);
		}
	}
	g[u] += t;
	len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi;
		ll w = vv[u][i].se;
		if(v == fa)	continue;
		dfsg(v, u);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	mes(f, 0), mes(g, 0);
	for(int i=1; i<=n; i++)	vv[i].clear();
	for(int u=2, v; u<=n; u++) {
		ll w;
		scanf("%d%lld", &v, &w);
		vv[u].push_back(make_pair(v, w));
		vv[v].push_back(make_pair(u, w));
	}
	dfsf(1, 0);
	dfsg(1, 0);
	// for(int i=1; i<=n; i++) {
	//     printf("f[%d] = %lld g[%d] = %lld\n", i, f[i], i, g[i]);
	// }
	for(int i=1; i<=n; i++) {
		a[i] = max(f[i], g[i]);
	}
	q.clear();
	int ans = 0;
	for(int i=1; i<=n; i++) {
		while(!q.empty() && a[i]-a[q.front()]>m)	q.pop_front();
		while(!q.empty() && a[i]<a[q.back()])	q.pop_back();
		ans = max(ans, i-q.front()+1);
		q.push_back(i);
	}
	printf("%d\n", ans);
	return 0;
}

