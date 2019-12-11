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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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

int n, m;
int cas, tol, T;

vector<int> vv[maxn];
int dfn[maxn], low[maxn], sta[maxn], maps[maxn], in[maxn], out[maxn];
bool vis[maxn];
int top, stacksz, cnt;

void init() {
	top = stacksz = cnt = 0;
	mes(dfn, 0), mes(low, 0), mes(sta, 0);
	mes(vis, 0), mes(maps, 0), mes(in, 0);
	mes(out, 0);
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
}

void dfs(int u) {
	int v;
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	sta[stacksz++] = u;
	for(int i=0; i<vv[u].size(); i++) {
		v = vv[u][i];
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		top++;
		do {
			v = sta[--stacksz];
			maps[v] = top;
			vis[v] = false;
		} while(v != u);
	}
}

void tarjan() {
	for(int u=1; u<=n; u++) {
		if(!dfn[u]) {
			dfs(u);
		}
	}
}

int main() {
	scanf("%d", &n);
	init();
	for(int i=1, v; i<=n; i++) {
		vv[i].clear();
		while(scanf("%d", &v), v) {
			vv[i].push_back(v);
		}
	}
	tarjan();
	if(top == 1) {
		printf("%d\n%d\n", 1, 0);
		return 0;
	}
	for(int u=1; u<=n; u++) {
		for(int i=0; i<vv[u].size(); i++) {
			int v = vv[u][i];
			if(maps[u] == maps[v])	continue;
			out[maps[u]]++;
			in[maps[v]]++;
		}
	}
//	for(int i=1; i<=n; i++) {
//		printf("maps[%d] = %d\n", i, maps[i]);
//	}
//	for(int i=1; i<=top; i++) {
//		printf("in[%d] = %d  out[%d] = %d\n", i, in[i], i, out[i]);
//	}
	int ans1, ans2;
	ans1 = ans2 = 0;
	for(int i=1; i<=top; i++) {
		if(in[i]==0)	ans1++;
		if(out[i]==0)	ans2++;
	}
	printf("%d\n%d\n", ans1, max(ans1, ans2));
	return 0;
}
