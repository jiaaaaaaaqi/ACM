#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 50005;

int n, m;
int tol;
int sum[maxn << 2];
int lazy[maxn << 2];
int st[maxn];
int ed[maxn];
bool vis[maxn];
vector<int> maps[maxn];

void init() {
	tol = 0;
	memset(st, 0, sizeof(st));
	memset(ed, 0, sizeof(ed));
	memset(vis, 0, sizeof(vis));
	memset(sum, 0, sizeof(sum));
	memset(lazy, 0, sizeof(lazy));
	for(int i=0; i<=n; i++)
		maps[i].clear();
}

void dfs(int u) {
	tol++;
	st[u] = tol;
	int len = maps[u].size();
	for(int i=0; i<len; i++) {
		int v= maps[u][i];
		dfs(v);
	}
	ed[u] = tol;
	return ;
}

void dfsorder() {
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			dfs(i);
			break;
		}
	}
}

void pushdown(int root) {
	if(lazy[root]) {
		sum[root << 1] = sum[root << 1 | 1] = lazy[root];
		lazy[root << 1] = lazy[root << 1 | 1] = lazy[root];
		lazy[root] = 0;
	}
}

void update(int left, int right, int prel, int prer, int val, int root) {
	if(prel <= left && right <= prer) {
		lazy[root] = val;
		sum[root] = val;
		return ;
	}
	pushdown(root);
	int mid = (left + right) >> 1;
	if(prel <= mid)
		update(left, mid, prel, prer, val, root << 1);
	if(prer > mid)
		update(mid + 1, right, prel, prer, val, root << 1 | 1);
}

int query(int left, int right, int pos, int root) {
	if(left == right) {
		return sum[root];
	}
	pushdown(root);
	int mid = (left + right) >> 1;
	if(pos <= mid)
		return query(left, mid, pos, root << 1);
	else
		return query(mid + 1, right, pos, root << 1 | 1);
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d:\n", cas++);
		scanf("%d", &n);
		init();
		for(int i=0; i<n-1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			maps[v].push_back(u);
			vis[u] = true;
		}
		dfsorder();
		scanf("%d", &m);
		while(m--) {
			char str[10];
			scanf("%s", str);
			if(str[0] == 'C') {
				int pos;
				scanf("%d", &pos);
				int ans = query(1, tol, st[pos], 1);
				printf("%d\n", ans - 1);
			} else if(str[0] == 'T') {
				int pos, val;
				scanf("%d%d", &pos, &val);
				update(1, tol, st[pos], ed[pos], val+1, 1);
			}
		}
	}
	return 0;
}
