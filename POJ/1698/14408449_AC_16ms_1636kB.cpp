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
const int maxn = 25;
const int maxm = 100010;
using namespace std;

int n, m, tol;
struct Node{
	int v;
	int w;
	int next;
};
Node node[maxm];
int dep[maxm];
int maps[25][10];
int head[maxm];

void init() {
	tol = 0;
	memset(maps, 0, sizeof(maps));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
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
		if(u == des)	return true;
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

int dfs(int src, int des, int flow) {
	if(src == des)	return flow;
	int ans = 0;
	for(int i = head[src]; ~i; i = node[i].next) {
		int v = node[i].v;
		if(dep[v] == dep[src] + 1 && node[i].w) {
			int tmp = dfs(v, des, min(node[i].w, flow - ans));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)	return ans;
		}
	}
	if(!ans)	dep[src] = -2;
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	int tmp;
	while(bfs(src, des)) {
		while((tmp = dfs(src, des, inf)) > 0)
			ans += tmp;
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		int src = 0;
		int des;
		int mx = 0;
		int ans1 = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=9; j++) {
				scanf("%d", &maps[i][j]);
			}
			mx = max(mx, maps[i][9]);
			addnode(src, i, maps[i][8]);
			addnode(i, src, 0);
			ans1 += maps[i][8];
		}
		des = n + mx * 7 + 1;
		for(int i=1; i<=n; i++) {
			int x = maps[i][9] * 7;
			for(int j=1; j<=x; j++) {
				if(maps[i][(j - 1) % 7 + 1]) {
					addnode(i, n + j, 1);
					addnode(n + j, i, 0);
				}
			}
		}
		for(int i=n+1; i<des; i++) {
			addnode(i, des, 1);
			addnode(des, i, 0);
		}
		int ans = dinic(src, des);
		if(ans == ans1)	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
