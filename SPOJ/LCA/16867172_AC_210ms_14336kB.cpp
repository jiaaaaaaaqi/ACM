#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
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
const int    maxn = 1e3 + 10;
const int    maxm = 1e6 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int u, v;
	int next;
} node[maxm];
int head[maxn];
int deep[maxn];
int fa[maxn];

void init() {
	tol = 1;
	mes(fa, -1);
	mes(deep, 0);
	mes(head, -1);
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int d) {
	deep[u] = d;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(fa[v] != -1)	continue;
		fa[v] = u;
		dfs(v, d+1);
	}
}

int lca(int u, int v) {
	if(deep[u] < deep[v])
		swap(u, v);
	while(deep[u] > deep[v])
		u = fa[u];
	while(u != v) {
		u = fa[u];
		v = fa[v];
	}
	return u;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int u=1; u<=n; u++) {
			int v;
			scanf("%d", &m);
			while(m--) {
				scanf("%d", &v);
				addnode(u, v);
			}
		}
		fa[1] = 1;
		dfs(1, 1);
		scanf("%d", &m);
		printf("Case %d:\n", cas++);
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", lca(u, v));
		}
	}
	return 0;
}
