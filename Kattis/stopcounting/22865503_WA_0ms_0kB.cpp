/*************************************************************** 
	> File Name		: I.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 03:59:36 PM CST
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
const int    maxn = 5e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, t, d;
int cas, tol, T;

struct P {
	int v; ll w;
	bool operator < (P x) const {
		return w>x.w;
	}
};
vector<P> vv[maxn];
ll maps[maxn][maxn];
bool vis[maxn];

ll bfs() {
	mes(vis, 0);
	priority_queue<P> q;
	P now, nex;
	now = P{1, 0};
	q.push(now);
	while(!q.empty()) {
		now = q.top();
		q.pop();
		if(vis[now.v])	continue;
		vis[now.v] = 1;
		if(now.v == n)	return now.w;
		for(auto v : vv[now.v]) {
			if(vis[v.v])	continue;
			nex = P{v.v, now.w+maps[now.v][v.v]}; 
			q.push(nex);
		}
	}
	return -1;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &t, &d);
	for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)	maps[i][j] = INF;
	vector<int> repair;
	repair.clear();
	for(int i=1, x; i<=t; i++)	scanf("%d", &x), repair.pb(x);
	repair.pb(1), repair.pb(n);
	for(int i=1, u, v; i<=m; i++) {
		ll w;
		scanf("%d%d%d", &u, &v, &w);
		maps[u][v] = maps[v][u] = w;
	}
	for(int k=1; k<=n; k++)	for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
		maps[i][j] = min(maps[i][j], maps[i][k]+maps[k][j]);
	for(int i=1; i<=n; i++)	vv[i].clear();
	for(int i=0; i<repair.size(); i++)	for(int j=i+1; j<repair.size(); j++)
		if(maps[repair[i]][repair[j]] <= d) {
			vv[repair[i]].pb(P{repair[j], maps[repair[i]][repair[j]]});
			vv[repair[j]].pb(P{repair[i], maps[repair[i]][repair[j]]});
		}
	ll ans = bfs();
	if(ans == -1)	return 0*puts("stuck");
	printf("%lld\n", ans);
	return 0;
}

