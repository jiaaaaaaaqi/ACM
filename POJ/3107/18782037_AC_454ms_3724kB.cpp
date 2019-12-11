/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月17日 星期日 21时38分37秒
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
const int    maxn = 5e4 + 10;
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
	int v, next;
} node[maxn<<1];
int sz[maxn], fa[maxn], head[maxn];

void init() {
	tol = 0;
	mes(node, 0);
	mes(head, -1);
}

void addnode(int u, int v) {
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int f) {
	sz[u] = 1;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(v == f)	continue;
		dfs(v, fa[v]=u);
		sz[u] += sz[v];
	}
}

int main() {
	init();
	scanf("%d", &n);
	for(int i=2, u, v; i<=n; i++) {
		scanf("%d%d", &u, &v);
		addnode(u, v);
		addnode(v, u);
	}
	dfs(1, 0);
	int mx = inf;
	vector<int> a;
	for(int u=1; u<=n; u++) {
		int tmp = n - sz[u];
		for(int i=head[u]; ~i; i=node[i].next) {
			int v =node[i].v;
			if(v == fa[u])	continue;
			tmp = max(tmp, sz[v]);
		}
		if(tmp < mx) {
			a.clear();
			a.push_back(u);
			mx = tmp;
		} else if(tmp == mx) {
			a.push_back(u);
		}
	}
	for(int i=0; i<a.size(); i++) {
		printf("%d%c", a[i], i==a.size()-1 ? '\n' : ' ');
	}
	return 0;
}

