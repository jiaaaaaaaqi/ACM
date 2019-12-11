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
const int maxn = 20;
const int maxm = 1005;
using namespace std;

int n, m;
struct Node{
	int u;
	int v;
	int w;
	int next;
}node[maxm << 1];
int dep[maxn];
int head[maxn];
int tol;

void init() {
	tol = 0;
	memset(node, 0, sizeof(node));
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
	queue<int> q;
	while(!q.empty())	q.pop();
	memset(dep, 0, sizeof(dep));
	dep[src] = 1;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		if(u == des)	return true;
		q.pop();
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			int w = node[i].w;
			if(!dep[v] && w) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	if(dep[des])	return true;
	else	return false;
}

int dfs(int src, int des, int flow) {
	if(src == des)	return flow;
	int ans = 0;
	for(int i=head[src]; ~i; i=node[i].next) {
		int v = node[i].v;
		int w = node[i].w;
		if(dep[v] = dep[src] + 1 && w) {
			int tmp = min(flow , w);
			int val = dfs(v, des, tmp);
			node[i].w -= val;
			node[i ^ 1].w += val;
			ans += tmp;
			if(ans == flow)	return tmp;
		}
	}
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	int val;
	while(bfs(src, des)) {
		val = dfs(src, des, inf);
		ans += val;
	}
	return val;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		while(m--) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addnode(u, v, w);
			addnode(v, u, 0);
		}
		int ans = dinic(1, n);
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
} 