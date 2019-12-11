#include<map>
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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 10005;
const int maxm = 1000;
using namespace std;

int n, m;
map<string, int> maps;
struct Node {
	int u;
	int v;
	int w;
	int next;
};
Node node[maxn];
int flow[maxn];
int head[maxn];
int dep[maxn];
int tol, sumtol;
queue<int > q;

void init() {
	tol = 0;
	sumtol = 1;
	maps.clear();
	memset(node, 0, sizeof(node));
	memset(flow, 0, sizeof(flow));
	memset(dep, 0, sizeof(dep));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	memset(dep, 0, sizeof(dep));
	while(!q.empty()) q.pop();
	dep[src] = 1;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			int w = node[i].w;
			if(!dep[v] && w) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

int dfs(int src, int des, int flow) {
	if(src == des)	return flow;
	int ans = 0;
	for(int i=head[src]; ~i; i=node[i].next) {
		int v = node[i].v;
		int w = node[i].w;
		if(dep[v] == dep[src] + 1 && w) {
			int tmp = dfs(v, des, min(flow - ans, w));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)	return ans;
		}
	}
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	while(bfs(src, des)) {
		ans += dfs(src, des, inf);
	}
	return ans;
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		string tmp, tmp2;
		int src = 0;
		for(int i=1; i<=n; i++) {
			cin >> tmp;
			maps[tmp] = sumtol++;
			addnode(src, maps[tmp], 1);
			addnode(maps[tmp], src, 0);
		}
		scanf("%d", &m);
		int des = n + m + 1;
		for(int i=1; i<=m; i++) {
			cin >> tmp >> tmp2;
			maps[tmp] = sumtol++;
			if(!maps[tmp2]) {
				maps[tmp2] = sumtol++;
			}
			addnode(maps[tmp2], maps[tmp], 1);
			addnode(maps[tmp], maps[tmp2], 0);
			addnode(maps[tmp], des, 1);
			addnode(des, maps[tmp], 0);
		}
		int k;
		scanf("%d", &k);
		for(int i=1; i<=k; i++) {
			cin >> tmp >> tmp2;
			if(!maps[tmp]) {
				maps[tmp] = sumtol++;
			}
			if(!maps[tmp2]) {
				maps[tmp] = sumtol++;
			}
			addnode(maps[tmp2], maps[tmp], inf);
			addnode(maps[tmp], maps[tmp2], 0);
		}
		int ans = dinic(src, des);
		printf("%d\n", m - ans);
	}
	return 0;
}
