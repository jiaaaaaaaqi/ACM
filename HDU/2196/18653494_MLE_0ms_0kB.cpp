/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月11日 星期一 00时56分15秒
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

vector< pii > vv[maxn];
int dp1[maxn], dp2[maxn], fa[maxn];

void dfs1(int u, int f) {
	for(auto i : vv[u]) {
		if(i.fi == f)	continue;
		dfs1(i.fi, fa[i.fi]=u);
		dp1[u] = max(dp1[u], dp1[i.fi] + i.se);
	}
}

void dfs2(int u, int f) {
	int tmp = 0;
	dp2[u] = dp2[fa[u]];
	for(auto i : vv[fa[u]]) {
		if(i.fi == u)	tmp = i.se;
		else if(i.fi != fa[fa[u]]) {
			dp2[u] = max(dp2[u], dp1[i.fi]+i.se);
		}
	}
	dp2[u] += tmp;
	for(auto i : vv[u]) {
		if(i.fi == f)	continue;
		dfs2(i.fi, u);
	}
}

int main() {
	while(~scanf("%d", &n)) {
		mes(dp1, 0), mes(dp2, 0), mes(fa, 0);
		for(int u=2, v, w; u<=n; u++) {
			scanf("%d%d", &v, &w);
			vv[u].push_back(make_pair(v, w));
			vv[v].push_back(make_pair(u, w));
		}
		dfs1(1, 0);
		dfs2(1, 0);
		for(int i=1; i<=n; i++) {
			cout << max(dp1[i], dp2[i]) << endl;
		}
	}
	return 0;
}

