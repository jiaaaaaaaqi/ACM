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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, A, B;
int cas, tol, T;

struct Node{
	int v, w;
	int next;
} node[maxn];
int dis[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char s[100][100];
int head[maxn];
int dep[maxn];

int getid(int x, int y) {
	return (x-1)*m+y;
}

void init() {
	tol = 0;
	mes(head, -1);
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	mes(dep, -1);
	dep[src] = 0;
	queue<int> q;
	while(!q.empty())	q.pop();
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(dep[v] == -1 && node[i].w) {
				dep[v] = dep[u]+1;
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
		if(dep[v] == dep[src]+1 && node[i].w) {
			int tmp = dfs(v, des, min(node[i].w, flow-ans));
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
	int ans = 0, tmp;
	while(bfs(src, des)) {
		while((tmp = dfs(src, des, inf)) > 0) {
			ans += tmp;
		}
	}
	return ans;
}

int main() {
	init();
	scanf("%d%d%d%d", &n, &m, &A, &B);
	int src = 0, des = n*m+1;
	for(int i=1; i<=n; i++) {
		scanf("%s", s[i]+1);
		for(int j=1; j<=m; j++) {
			if(s[i][j] == '.') {
				addnode(src, getid(i, j), B);
				addnode(getid(i, j), src, 0);
			} else {
				addnode(getid(i, j), des, B);
				addnode(des, getid(i, j), 0);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=0; k<4; k++) {
				int x = i+dis[k][0];
				int y = j+dis[k][1];
				if(x<1 || y<1 || x>n || y>m)	continue;
				addnode(getid(i, j), getid(x, y), A);
				addnode(getid(x, y), getid(i, j), 0);
			}
		}
	}
	int ans = dinic(src, des);
	printf("%d\n", ans);
	return 0;
}
