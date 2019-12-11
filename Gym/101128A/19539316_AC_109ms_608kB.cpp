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
const int    maxn = 5e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, A, B;
int cas, tol, T;

bool vis[maxn];
vector<int> vv[maxn], vvv[maxn];
int sz[maxn], sum[maxn];

int dfs1(int u) {
	vis[u] = 1;
	int ans = 0;
	for(auto v : vv[u]) {
		if(vis[v])	continue;
		ans += dfs1(v);
	}
	return ans+1;
}

int dfs2(int u) {
	vis[u] = 1;
	int ans = 0;
	for(auto v : vvv[u]) {
		if(vis[v])	continue;
		ans += dfs2(v);
	}
	return ans+1;
}

int main() {
    scanf("%d%d%d%d", &A, &B, &n, &m);
    for(int i=1; i<=n; i++) {
		vv[i].clear();
		vvv[i].clear();
    }
	for(int i=1, u, v; i<=m; i++) {
		scanf("%d%d", &u, &v);
		u++, v++;
		vv[u].push_back(v);
		vvv[v].push_back(u);
	}
	int ans1, ans2, ans3;
	ans1 = ans2 = ans3 = 0;
	mes(sz, 0);
	for(int i=1; i<=n; i++) {
		mes(vis, 0);
		sz[i] = dfs1(i);
		if(n-sz[i] < A)	ans1++;
		if(n-sz[i] < B)	ans2++;
	}
	mes(sz, 0);
	for(int i=1; i<=n; i++) {
		mes(vis, 0);
		sz[i] = dfs2(i);
		if(sz[i] > B)	ans3++;
	}
	printf("%d\n%d\n%d\n", ans1, ans2, ans3);
    return 0;
}
