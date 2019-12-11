/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月30日 星期二 11时09分09秒
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
const int    maxn = 5e2 + 10;
const int    maxm = 7e4 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll in[maxn], out[maxn];
struct Node {
	int v, next;
	ll w;
} node[maxm];
int head[maxn];
int dep[maxn];

void init() {
	tol = 0;
	mes(in, 0), mes(out, 0);
	mes(head, -1);
}

void addnode(int u, int v, ll w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	queue<int > q;
	memset(dep, -1, sizeof(dep));
	dep[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)    return true;
		for(int i = head[u]; ~i; i = node[i].next) {
			int v = node[i].v;
			if(dep[v] == -1 && node[i].w) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

ll dfs(int src, int des, ll flow) {
	if(src == des)    return flow;
	int ans = 0;
	for(int i = head[src]; ~i; i = node[i].next) {
		int v = node[i].v;
		if(dep[v] == dep[src] + 1 && node[i].w) {
			ll tmp = dfs(v, des, min(node[i].w, flow - ans));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)    return ans;
		}
	}
	if(!ans)    dep[src] = -2;
	return ans;
}

ll dinic(int src, int des) {
	ll ans = 0;
	ll tmp;
	while(bfs(src, des)) {
		while((tmp = dfs(src, des, INF)) > 0)
			ans += tmp;
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d", &n, &m)) {
		init();
		int src = 0, des = n+1;
		int u, v, a, b, c;
		ll ans = 0;
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d%d%d", &u, &v, &a, &b, &c);
			ans += 2ll*(a+b+c);
			in[u] += 1ll*a+1ll*b;
			in[v] += 1ll*a+1ll*b;
			out[u] += 1ll*b+1ll*c;
			out[v] += 1ll*b+1ll*c;
			addnode(u, v, 1ll*a+1ll*c-1ll*b-1ll*b);
			addnode(v, u, 0);
		}
		for(int i=1; i<=n; i++) {
			addnode(src, i, 1ll*in[i]);
			addnode(i, src, 0);
			addnode(i, des, 1ll*out[i]);
			addnode(des, i, 0);
		}
		ans -= dinic(src, des);
		ans /= 2;
		printf("%lld\n", ans);
	}
	return 0;
}

