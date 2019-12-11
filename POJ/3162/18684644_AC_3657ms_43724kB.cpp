/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月12日 星期二 23时37分20秒
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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int v, w;
	int next;
} node[maxn<<1];
int a[maxn], f[maxn], g[maxn], p[maxn], head[maxn];
deque<int> q1, q2;

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfsf(int u, int fa) {
	// printf("!!!!%d\n", u);
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v, w = node[i].w;
		if(v == fa)	continue;
		// printf("%d ", v);
		dfsf(v, p[v]=u);
		f[u] = max(f[u], f[v]+w);
	}
	// printf("\n");
}

void dfsg(int u, int fa) {
	g[u] = g[fa];
	int t = 0;
	for(int i=head[fa]; ~i; i=node[i].next) {
		int v = node[i].v, w = node[i].w;
		if(v == p[fa])	continue;
		if(u == v)	t = w;
		else	g[u] = max(g[u], f[v]+w);
	}
	g[u] += t;
	a[u] = max(g[u], f[u]);
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v, w = node[i].w;
		if(v == fa)	continue;
		dfsg(v, u);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	tol = 0;
	mes(f, 0), mes(g, 0);
	mes(head, -1);
	for(int u=2, v, w; u<=n; u++) {
		scanf("%d%d", &v, &w);
		addnode(u, v, w);
		addnode(v, u, w);
	}
	dfsf(1, 0);
	dfsg(1, 0);
	int ans = 0;
	q1.clear(), q2.clear();
	for(int i=1, j=1; i<=n; i++) {
		while(!q1.empty() && a[i] < a[q1.back()])	q1.pop_back();
		while(!q2.empty() && a[i] > a[q2.back()])	q2.pop_back();
		q1.push_back(i), q2.push_back(i);
		while(a[q2.front()] - a[q1.front()] > m) {
			if(q2.front() < q1.front())	j=q2.front()+1, q2.pop_front();	
			else	j=q1.front()+1, q1.pop_front();
		}
		ans = max(ans, i-j+1);
	}
	printf("%d\n", ans);
	return 0;
}

