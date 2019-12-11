/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月16日 星期六 13时17分03秒
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

ll ans, sum;
ll sz[maxn], a[maxn];
vector<int> vv[maxn];

void dfs(int u, int fa) {
	sz[u] = a[u];
	for(int i=0; i<vv[u].size(); i++) {
		int v = vv[u][i];
		if(v == fa)	continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
	ans = min(ans, (sum-2*sz[u]) < 0 ? (2*sz[u]-sum) : (sum-2*sz[u]));
}

int main() {
	cas = 1;
	while(scanf("%d%d", &n, &m), n||m) {
		sum = 0;
		for(int i=1; i<=n; i++)	{
			scanf("%lld", &a[i]);
			sum += a[i];
			vv[i].clear();
		}
		for(int i=1, u, v; i<=m; i++) {
			scanf("%d%d", &u, &v);
			vv[u].push_back(v);
			vv[v].push_back(u);
		}
		ans = INF;
		dfs(1, 0);
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}

