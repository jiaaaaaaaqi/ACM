#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
typedef unsigned int ui;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100010;
const int maxm = 100010;
const int mod = 1<<30;
const double eps = 1e-8;
using namespace std;

int n, m;
int T, tol;
int tol1, tol2;
struct Node{
	int u, v;
	int next;
};
struct Edge{
	int u, v;
};
Edge edge[maxn];
Node node[maxn];
int head[maxn];
bool vis[maxn];
int fa[maxn];
int ans;

void init() {
	tol1 = tol2 = 0;
	ans = 0;
	memset(fa, -1, sizeof fa);
	memset(vis, 0, sizeof vis);
	memset(node, 0, sizeof node);
	memset(edge, 0, sizeof edge);
	memset(head, -1, sizeof head);
}

void addnode(int u, int v) {
	node[tol1].u = u;
	node[tol1].v = v;
	node[tol1].next = head[u];
	head[u] = tol1++;
}

int find(int x) {
	return fa[x] == -1 ? x : fa[x] = find(fa[x]);
}

void bind(int u, int v) {
	int x = find(u);
	int y = find(v);
	fa[y] = x;
	return ;
}

void dfs(int u) {
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(vis[v])	continue;
		vis[v] = true;
		ans++;
		dfs(v);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		m = n;
		char op[20];
		int id;
		for(int i=1; i<=m; i++) {
			scanf("%d %s", &id, op);
			if(op[0] == 'w') {
				tol2++;
				edge[tol2].u = i;
				edge[tol2].v = id;
			} else {
				addnode(id, i);
				bind(id, i);
			}
		}
		for(int i=1; i<=tol2; i++) {
			int u = edge[i].u;
			int v = edge[i].v;
			if(find(u) != find(v))	continue;
			ans++;
			vis[v] = true;
			dfs(v);
		}
		printf("0 %d\n", ans);
	}
	return 0;
}
