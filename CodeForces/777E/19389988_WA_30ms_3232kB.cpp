/***************************************************************
    > File Name    : c.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月21日 星期日 19时30分31秒
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

struct Node{
	ll a, b, h;
	bool operator < (Node x) const {
		return a!=x.a ? a<x.a : b<x.b;
	}
} node[maxn];
bool vis[maxn];
ll dp[maxn];

bool ok(Node i, Node j) {
	if(i.b <= j.b && i.b>j.a)
		return true;
	return false;
}

void dfs(int u) {
	vis[u] = true;
	if(dp[u])	return ;
	// dp[u] = 0;
	for(int i=u+1; i<=n; i++) {
		if(i==u)	continue;
		if(vis[i])	continue;
		if(u==0 || ok(node[u], node[i])) {
			dfs(i);
			dp[u] = max(dp[u], dp[i]+1ll*node[u].h);
		}
		if(u!=0 && ok(node[i], node[u])) {
			dp[i] = max(dp[i], dp[u]);
		}
	}
	dp[u] = max(dp[u], node[u].h);
	vis[u] = false;
}

int main() {
	mes(dp, 0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lld%lld%lld", &node[i].a, &node[i].b, &node[i].h);
	}
	sort(node+1, node+1+n);
	node[0].h = 0;
	dfs(0);
	printf("%lld\n", dp[0]);
	return 0;
}
