/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月17日 星期日 21时38分37秒
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
const int    maxn = 5e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int sz[maxn], fa[maxn];
vector<int> vv[maxn];

void dfs(int u, int f) {
	sz[u] = 1;
	for(int i=0; i<vv[u].size(); i++) {
		int v = vv[u][i];
		if(v == f)	continue;
		dfs(v, fa[v]=u);
		sz[u] += sz[v];
	}
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	vv[i].clear();
	for(int i=2, u, v; i<=n; i++) {
		scanf("%d%d", &u, &v);
		vv[u].push_back(v);
		vv[v].push_back(u);
	}
	dfs(1, 0);
	vector<int> a;
	a.clear();
	int mx = inf;
	for(int u=1; u<=n; u++) {
		int tmp = n - sz[u];
		for(int i=0; i<vv[u].size(); i++) {
			int v = vv[u][i];
			if(v == fa[u])	continue;
			tmp = max(tmp, sz[v]);
		}
		if(tmp < mx) {
			a.clear();
			a.push_back(u);
			mx = tmp;
		} else if(tmp == mx) {
			a.push_back(u);
		}
	}
	for(int i=0; i<a.size(); i++) {
		printf("%d%c", a[i], i==a.size()-1 ? '\n' : ' ');
	}
	return 0;
}

