/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月13日 星期六 10时25分31秒
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

int S;
vector< pii > vv[maxn];
int sz[maxn], hv[maxn], dis[maxn];
bool vis[maxn];

void dfssz(int u, int fa, int &rt) {
	sz[u] = 1, hv[u] = 0;
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi;
		if(v==fa || vis[v])	continue;
		dfssz(v, u, rt);
		sz[u] += sz[v];
		hv[u] = max(hv[u], sz[v]);
	}
	hv[u] = max(hv[u], S-sz[u]);
	if(rt==0 || hv[u]<hv[rt])	rt = u;
}

void dfsdis(int u, int fa, int k) {
	if(k>m)	return ;
	dis[++tol] = k;
	int len = vv[u].size();
	for(int i=0; i<len; i++) {
		int v = vv[u][i].fi;
		if(v==fa || vis[v])	continue;
		dfsdis(v, u, k+vv[u][i].se);
	}
}

int calc(int u, int w) {
	int ans = 0;
	tol = 0;
	dfsdis(u, 0, w);
	sort(dis+1, dis+1+tol);
	int l=1, r=tol;
	while(l<r) {
		while(l<r && dis[l]+dis[r] > m)	r--;
		int tr = r;
		while(l<tr && dis[l]+dis[tr]==m) {
			tr--;
			ans++;
		}
		l++;
	}
	return ans;
}

bool dfs(int u) {
	S = sz[u] ? sz[u] : n;
	int rt = 0;
	dfssz(u, 0, rt);
	int ans = 0;
	vis[rt] = true;
	ans = calc(rt, 0);
	int len = vv[rt].size();
	for(int i=0; i<len; i++) {
		int v = vv[rt][i].fi;
		if(vis[v])	continue;
		ans -= calc(v, vv[rt][i].se);
		if(dfs(v))	return true;
	}
	return ans>0 ? true : false;
}

int main() {
	while(scanf("%d", &n), n) {
		for(int i=1; i<=n; i++) {
			vv[i].clear();
			sz[i] = 0;
		}
		for(int i=1, v, c; i<=n; i++) {
			while(scanf("%d", &v), v) {
				scanf("%d", &c);
				vv[i].push_back(make_pair(v, c));
				vv[v].push_back(make_pair(i, c));
			}
		}
		while(scanf("%d", &m), m) {
			for(int i=1; i<=n; i++)	vis[i] = false;
			bool ok = dfs(1);
			if(ok)	printf("AYE\n");
			else	printf("NAY\n");
		}
		printf(".\n");
	}
	return 0;
}

