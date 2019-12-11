/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年10月13日 星期日 13时47分16秒
 ***************************************************************/

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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 3e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, k;
int cas, tol, T;

struct Node {
	int v, w;
	int next;
} node[maxm];
int head[maxn];
int dep[maxn];

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
	queue<int> q;
	mes(dep, -1);
	dep[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int i=head[u]; ~i; i=node[i].next) {
			int v = node[i].v;
			if(dep[v]==-1 && node[i].w) {
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
		while((tmp=dfs(src, des, inf)) > 0) ans += tmp;
	}
	return ans;
}

int main() {
    // freopen("in", "r", stdin);
	init();
	scanf("%d%d%d", &n, &m, &k);
	int src = 0, des = n+m+2;
	int potion = n+m+1;
	addnode(src, potion, k);
	addnode(potion, src, 0);
	for(int i=1; i<=n; i++) {
		int sz;
		scanf("%d", &sz);
		addnode(src, i, 1);
		addnode(i, src, 0);
		addnode(potion, i, 1);
		addnode(i, potion, 0);
		for(int j=1; j<=sz; j++) {
			int v;
			scanf("%d", &v);
			addnode(i, v+n, 1);
			addnode(v+n, i, 0);
		}
	}
	for(int i=1; i<=m; i++) {
		addnode(i+n, des, 1);
		addnode(des, i+n, 0);
	}
	int ans = dinic(src, des);
	printf("%d\n", ans);
    return 0;
}

