
/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月13日 星期三 15时45分21秒
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int v, f;
	Node(int x, int y) {
		v = x, f = y;
	}
};
vector<Node> vv[maxn];
int dp[maxn], ans, a[maxn];

void dfs1(int u, int fa) {
	for(auto i : vv[u]) {
		if(i.v == fa)	continue;
		dfs1(i.v, u);
		dp[u] += dp[i.v] + i.f;
	}
}

void dfs2(int u, int fa) {
	int tmp = 0;
	if(fa) {
		for(auto i : vv[u])
			if(i.v == fa) {
				tmp = !i.f;
				break;
			}
		dp[u] += dp[fa] - dp[u] - tmp + !tmp;
	}
	ans = min(ans, dp[u]);
	for(auto i : vv[u]) {
		if(i.v == fa)	continue;
		dfs2(i.v, u);
	}
}

int main() {
	scanf("%d", &n);
	ans = inf;
	mes(dp, 0);
	for(int i=1; i<=n; i++)	vv[i].clear();
	for(int i=2, u, v; i<=n; i++) {
		scanf("%d%d", &u, &v);
		vv[u].push_back(Node(v, 0));
		vv[v].push_back(Node(u, 1));
	}
	dfs1(1, 0);
	dfs2(1, 0);
	tol = 0;
	for(int i=1; i<=n; i++) {
		if(dp[i] == ans) {
			a[++tol] = i;
		}
	}
	printf("%d\n", ans);
	for(int i=1; i<=tol; i++) {
		printf("%d%c", a[i], i==tol ? '\n' : ' ');
	}
	return 0;
}
