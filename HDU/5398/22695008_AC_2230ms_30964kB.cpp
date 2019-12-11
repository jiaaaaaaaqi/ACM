/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Wed 23 Oct 2019 11:05:24 PM CST
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
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
	int u, v;
	int cost;
} node[maxn];
int a[maxn];
int ch[maxn][2], fa[maxn], sz[maxn], rev[maxn];
int val[maxn];
int sta[maxn];
vector<int> vv[maxn];

void init() {
	for(int i=1; i<=n; i++) {
		rev[i] = fa[i] = 0;
		ch[i][0] = ch[i][1] = 0;
	}
}

void pushdown(int x) {
	if(x) {
		if(rev[x]) {
			swap(ch[x][0], ch[x][1]);
			if(ch[x][0])	rev[ch[x][0]] ^= rev[x];
			if(ch[x][1])	rev[ch[x][1]] ^= rev[x];
			rev[x] = 0;
		}
	}
}

void pushup(int x) {
	if(x) {
		// 当维护的信息和左右子树顺序有关时
		// if(ch[x][0])	pushdown(ch[x][0]);
		// if(ch[x][1])	pushdown(ch[x][1]);
		sz[x] = 1;
		val[x] = x;
		if(ch[x][0]) {
			sz[x] += sz[ch[x][0]];
			if(a[val[x]] > a[val[ch[x][0]]])	val[x] = val[ch[x][0]];
		}
		if(ch[x][1]) {
			sz[x] += sz[ch[x][1]];
			if(a[val[x]] > a[val[ch[x][1]]])	val[x] = val[ch[x][1]];
		}
	}
}

// 判断x节点是不是其所在树的root
// 1 不是root，0 是root
bool notroot(int x) {
	return ch[fa[x]][0]==x || ch[fa[x]][1]==x;
}

int get(int x) {
	return ch[fa[x]][1] == x;
}

// rotate 和 splay 函数与普通的splay有所不同
void rotate(int x) {
	int f = fa[x], gf = fa[f], k = get(x), w = ch[x][k ^ 1];
	if(notroot(f))	ch[gf][get(f)] = x;
	ch[x][k^1] = f, ch[f][k] = w;
	if(w)	fa[w] = f;
	fa[f] = x, fa[x] = gf;
	pushup(f), pushup(x);
}

void splay(int x) {
	int y = x, top = 0;
	sta[++top] = y;
	while(notroot(y))	sta[++top] = y = fa[y];
	while(top)	pushdown(sta[top--]);
	while(notroot(x)) {
		int f = fa[x], gf = fa[f];
		if(notroot(f)) {
			if(get(x) == get(f)) rotate(f);
			else rotate(x);
		}
		rotate(x);
	}
	pushup(x);
}

// 访问 x 节点,让 x 和树根在同一颗 splay 中,并且以 x 为最后一个节点
void access(int x) { 
	for(int y=0; x; x=fa[y=x]) {
		splay(x), ch[x][1] = y, pushup(x);
	}
}

// 给整棵树换根
void makeroot(int x) {
	access(x), splay(x);
	rev[x] ^= 1;
}

// 找 x 所在 splay 树的真实树根节点
int findroot(int x) {
	access(x), splay(x);
	while(ch[x][0]) {
		pushdown(x);
		x = ch[x][0];
	}
	splay(x);
	return x;
}

// 提取 x 到 y 的路径
// 拉出 x-y 的路径作为一颗 splay 树,此时以 y 为根,信息都在 y 中
void split(int x, int y) {
	makeroot(x);
	access(y), splay(y);
}

// 维护森林时判断两个点是否在同一颗树内
bool judge(int x, int y) {
	while(fa[x])	x = fa[x];
	while(fa[y])	y = fa[y];
	return x==y;
}

// 添加一条 x 和 y 之间的边
void link(int x, int y) {
	makeroot(x);
	if(findroot(y) != x)	fa[x] = y;
}

// 断掉 x 和 y 之间的边
void cut(int x, int y) {
	makeroot(x);
	if(findroot(y)==x && fa[y]==x && !ch[y][0]) {
		fa[y] = ch[x][1] = 0;
		pushup(x);
	}
}

void dfs(int x) {
	pushdown(x);
	if(ch[x][0])	dfs(ch[x][0]);
	printf("%d %d\n", x,a[x]);
	if(ch[x][1])	dfs(ch[x][1]);
	printf("x=%d lx=%d rx=%d\n", x, ch[x][0], ch[x][1]);
}

ll ans[maxn];
bool add(int u, int v) {
	if(judge(u, v)) {
		split(u, v);
		int id = val[v]-n;
		if(node[id].cost == v)	return false;
		cut(id+n, node[id].u);
		cut(id+n, node[id].v);
		ans[u] -= node[id].cost;
		node[id].u = u, node[id].v = v, node[id].cost = v;
		a[id+n] = v;
		link(id+n, u);
		link(id+n, v);
	} else {
		tol++;
		node[tol].u = u, node[tol].v = v, node[tol].cost = v; 
		a[tol+n] = v;
		link(tol+n, u);
		link(tol+n, v);
	}
	ans[u] += v;
	return true;
}

void handle() {
	n = 1e5;
	mes(a, inf);
	for(int i=1; i<=n; i++)	vv[i].clear();
	for(int i=1; i<=n; i++) {
		for(int j=i+i; j<=n; j+=i) {
			vv[j].pb(i);
		}
	}
	tol = 0;
	ans[1] = 0;
	for(int i=2; i<=n; i++) {
		ans[i] = ans[i-1];
		for(auto v : vv[i]) {
			add(i, v);
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	while(~scanf("%d", &n))	printf("%lld\n", ans[n]);
	return 0;
}

