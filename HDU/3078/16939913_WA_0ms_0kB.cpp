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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
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
} node[maxn << 1];
int head[maxn];
int deep[maxn];
bool vis[maxn];
int fa[maxn];
int a[maxn];
int b[maxn];

void init() {
	tol = 1;
	mes(fa, 0);
	mes(vis, 0);
	mes(deep, 0);
	mes(head, -1);
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int f, int d) {
	deep[u] = d;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(deep[v])	continue;
		fa[v] = u;
		dfs(v, u, d+1);
	}
}

int cmp(int x, int y) {
	return x > y;
}

int lca(int u, int v, int k) {
	int t = 0;
	if(deep[u] < deep[v])
		swap(u, v);
	while(deep[u] > deep[v]) {
		b[++t] = a[u];
		u = fa[u];
	}
	while(u != v) {
		b[++t] = a[u];
		b[++t] = a[v];
		u = fa[u];
		v = fa[v];
	}
	b[++t] = a[u];
	if(t < k)	return -1;
	else {
		nth_element(b+1, b+1+k, b+1+t, cmp);
		return b[k];
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		int u, v, k;
		for(int i=1; i<n; i++) {
			scanf("%d%d", &u, &v);
			addnode(u, v);
			addnode(v, u);
			vis[v] = true;;
		}
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				fa[i] = i;
				dfs(i, i, 1);
				break;
			}
		}
		while(m--) {
			scanf("%d%d%d", &k, &u, &v);
			if(k == 0)	a[u] = v;
			else {
				int ans = lca(u, v, k);
				if(ans == -1)
					printf("invalid request!\n");
				else
					printf("%d\n", ans);
			}
		}
	}
	return 0;
}
