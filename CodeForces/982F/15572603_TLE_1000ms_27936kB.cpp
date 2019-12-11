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

using namespace std;
const int mx = 5e5 + 5;
vector <int> mat[mx];
int n, m, tol;
int vis[mx];
int mark[mx];
int path[mx];
int path2[mx];
int maxn;

double TIME() {
	return 1.0*clock()/CLOCKS_PER_SEC;
}

void dfs(int st, int u, int x) {
	if(TIME() > 0.7)	return;
	if(vis[u]) {
		if(u == st) {
			if(maxn == 0)	tol++;
			if(maxn && x > maxn)	return ;
			else {
				memset(path2, 0, sizeof path2);
				for(int i=0; i<=x; i++)	path2[i] = path[i];
				maxn = x;
			}
		}
		return ;
	}
	if(maxn && x > maxn)	return ;
	vis[u] = true;
	int len = mat[u].size();
	for(int i=0; i<len; i++) {
		int v= mat[u][i];
		path[x] = v;
		dfs(st, v, x+1);
	}
	vis[u] = false;
	return ;
}

int low[mx];
int dfn[mx];
int sta[mx];
int cnt1=0;
int top=0, d=0;;
int stasize = 0;

void DFS(int u) {
	int v;
	dfn[u] = low[u] = ++cnt1;
	sta[stasize++] = u;
	vis[u] = true;
	int len = mat[u].size();
	for(int i=0; i<len; i++) {
		v = mat[u][i];
		if(!dfn[v]) {
			DFS(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		top++;
		if(sta[stasize-1] != u)	d++;
		do {
			v = sta[--stasize];
			vis[v] = false;
		} while(u != v);
	}
}

void tarjan() {
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) {
			DFS(i);
		}
	}
}

int main() {
	tol = 0;
	scanf("%d%d", &n, &m);
	int u, v;
	while(m--) {
		scanf("%d%d", &u, &v);
		mat[u].push_back(v);
	}
	memset(vis, 0, sizeof vis);
	tarjan();
	if(d != 1) {
		printf("-1\n");
		return 0;
	}
	bool flag = true;
	while(flag) {
		if(TIME() > 0.7)	break;
		flag = false;
		maxn = 0;
		for(int i = 1; i <= n; i++) {
			if(!mark[i]) {
				memset(vis, 0, sizeof vis);
				path[0] = i;
				dfs(i, i, 1);
			}
		}
		if(maxn) {
			flag = true;
			for(int i=maxn-2; i>=0; i--) {
				mark[path2[i]]++;
			}
		}
	}
	int ans = 1;
	for(int i=1; i<=n; i++)
		if(mark[ans] <  mark[i])
			ans = i;
	if(mark[ans] >= tol)	printf("%d\n", ans);
	else	printf("-1\n");
	return 0;
}