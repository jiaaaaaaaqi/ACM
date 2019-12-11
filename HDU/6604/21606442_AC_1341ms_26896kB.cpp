/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 02 Sep 2019 10:58:19 PM CST
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

int fa[maxn][21];
int a[maxn], ind[maxn], deep[maxn];
vector<int> vv[maxn], rv[maxn], vtree[maxn];

void topu() {
	queue<int> q;
	while(!q.empty())	q.pop();
	q.push(0);
	int sz = -1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		a[++sz] = u;
		for(auto v : vv[u]) {
			ind[v]--;
			if(ind[v] == 0) {
				q.push(v);
			}
		}
	}
}

int lca(int u, int v) {
	bool flag = (u==6&&v==7);
	if(deep[u] < deep[v])	swap(u, v);
	int f = deep[u]-deep[v];
	for(int i=0; (1<<i)<=f; i++) {
		if(f&(1<<i)) {
			u = fa[u][i];
		}
	}
	if(u != v) {
		for(int i=(int)log2(n); i>=0; i--) {
			if(fa[u][i] != fa[v][i]) {
				u = fa[u][i], v = fa[v][i];
			}
		}
		u = fa[u][0];
	}
	return u;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=0; i<=n; i++) {
			ind[i] = 0;
			vv[i].clear();
			rv[i].clear();
			vtree[i].clear();
			for(int j=0; j<=20; j++) {
				fa[i][j] = 0;
			}
		}
		for(int i=1, u, v; i<=m; i++) {
			scanf("%d%d", &v, &u);
			vv[u].pb(v), rv[v].pb(u);
			ind[v]++;
		}
		for(int i=1; i<=n; i++) {
			if(ind[i] == 0) {
				vv[0].pb(i);
				rv[i].pb(0);
				ind[i]++;
			}
		}
		topu();
		deep[0] = 0;
		for(int i=1; i<=n; i++) {
			int x = a[i];
			int y = rv[x][0];
			int len = rv[x].size();
			if(y != 0) {
				for(int j=1; j<len; j++) {
					y = lca(y, rv[x][j]);
				}
			}
			vtree[y].pb(x);
			deep[x] = deep[y]+1;
			fa[x][0] = y;
			for(int j=1; j<=20; j++) {
				fa[x][j] = fa[fa[x][j-1]][j-1];
			}
		}
		// for(int i=0; i<=n; i++) {
		//     printf("u = %d:\n", i);
		//     for(auto v : vtree[i])	printf("%d ", v);
		//     printf("\n");
		// }
		int q;
		scanf("%d", &q);
		while(q--) {
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", deep[u]+deep[v]-deep[lca(u, v)]);
		}
	}
	return 0;
}

