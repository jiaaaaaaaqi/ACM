/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月16日 星期四 14时59分43秒
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
const int    maxn = 1e2 + 10;
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
int dfn[maxn], low[maxn], maps[maxn], fath[maxn];
bool vis[maxn];
int cnt;

void init() {
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
	cnt = 0;
	mes(dfn, 0), mes(low, 0), mes(vis, 0), mes(maps, 0), mes(fath, 0);
}

void dfs(int u, int fa) {
	int v;
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	fath[u] = fa;
	for(auto v : vv[u]) {
		if(!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if(v == fa) {
			continue;
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void tarjan() {
	dfs(1, 0);
}

int solve() {
	mes(vis, 0);
	int sum = 0;
	for(int v=1; v<=n; v++) {
		int u = fath[v];
		if(u==1)	sum++;
		else if(low[v] >= dfn[u]) {
			vis[u] = true;
		}
	}
	if(sum > 1)	vis[1] = true;
	int ans = 0;
	for(int i=1; i<=n; i++) {
		if(vis[i])	ans++;
	}
	return ans;
}

int main() {
	while(scanf("%d", &n), n) {
		init();
		int u, v;
		char ch;
		while(scanf("%d", &u), u) {
			while(1) {
				scanf("%d%c", &v, &ch);
				vv[u].push_back(v);
				vv[v].push_back(u);
				if(ch == '\n')	break;
			}
		}
		tarjan();
		int ans = solve();
		cout << ans << endl;
	}
	return 0;
}

