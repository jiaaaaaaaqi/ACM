#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 1005;
const int maxm = 6005;

struct Node {
	int u;
	int v;
	int nex;
};
int n, m;
int tol, stacksize, cnt, top;
int dfn[maxn];
int low[maxn];
bool vis[maxn];
int head[maxn];
Node node[maxm];
int point[maxn];
int stack[maxn];
int ind[maxn];
vector<int> maps[maxn];

void init() {
	top = tol = stacksize = cnt = 0;
	memset(ind, 0, sizeof(ind));
	memset(dfn, 0, sizeof(dfn));
	memset(vis, 0, sizeof(vis));
	memset(low, 0, sizeof(low));
	memset(node, 0, sizeof(node));
	memset(head, -1, sizeof(head));
	memset(point, 0, sizeof(point));
	memset(stack, 0, sizeof(stack));
	for(int i=0; i<=n; i++) {
		maps[i].clear();
	}
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].nex = head[u];
	head[u] = tol++;
}

void dfs(int u) {
	int v;
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	stack[stacksize++] = u;
	for(int i=head[u]; i!=-1; i=node[i].nex) {
		v = node[i].v;
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
			v = stack[--stacksize];
			point[v] = top;
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

void newmap() {
	for(int u=1; u<=n; u++) {
		for(int i=head[u]; ~i; i=node[i].nex) {
			int v = node[i].v;
			if(point[u] != point[v]) {
				ind[point[v]]++;
				maps[point[u]].push_back(point[v]);
			}
		}
	}
	/*
	for(int i=1; i<=top; i++) {
		printf("%d\n", ind[i]);
	}
	*/
}

bool topu() {
	queue<int> q;
	for(int i=1; i<=top; i++) {
		if(ind[i] == 0) {
			q.push(i);
		}
	}
	int num = 0;
	while(!q.empty()) {
		if(q.size() != 1)
			return false;
		int t = q.front();
		q.pop();
		num++;
		int len = maps[t].size();
		for(int i=0; i<len; i++) {
			ind[maps[t][i]]--;
			if(ind[maps[t][i]] == 0) {
				q.push(maps[t][i]);
			}
		}
	}
	if(num == top)
		return true;
	else
		return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		for(int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addnode(u, v);
		}
		tarjan();
		/*
		for(int i=1; i<=n; i++) {
			printf("%d %d\n", i, point[i]);
		}
		*/
		newmap();
		bool ok = topu();
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
