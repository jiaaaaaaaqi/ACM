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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 2e9;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
	int u, v;
	int next;
} node[maxn*2];
int head[maxn];
int a[maxn], pfa[maxn][30];
int ch[maxn][2], fa[maxn], sz[maxn], rev[maxn];
int deep[maxn];
int sta[maxn];

void init() {
	tol = 0;
	for(int i=1; i<=n+1; i++) {
		for(int j=0; j<=20; j++)	pfa[i][j] = 0;
		head[i] = -1;
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
		sz[x] = sz[ch[x][0]]+sz[ch[x][1]]+1;
/*
		if(ch[x][0]) {
			sz[x] += sz[ch[x][0]];
		}
		if(ch[x][1]) {
			sz[x] += sz[ch[x][1]];
		}
*/
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
	int y = x,  stasz = 0;
	sta[++stasz] = y;
	while(notroot(y))	sta[++stasz] = y = fa[y];
	while(stasz)	pushdown(sta[stasz--]);
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
void del(int x, int y) {
	makeroot(x);
	if(findroot(y)==x && fa[y]==x && !ch[y][0]) {
		fa[y] = ch[x][1] = 0;
		pushup(x);
	}
}

void addnode(int u, int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int d) {
	deep[u] = d;
	// for(auto v : vv[u]) {
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(deep[v])	continue;
		pfa[v][0] = u;
		dfs(v, d+1);
	}
}

void update() {
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i<=n; i++) {
			pfa[i][j] = pfa[pfa[i][j-1]][j-1];
		}
	}
}

int find(int x, int k) {
	for(int i=0; (1<<i)<=k; i++) {
		if(x == 0)	break;
		if(k&(1<<i)) {
			x = pfa[x][i];
		}
	}
	return x==0 ? n+1 : x;
}

inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}

int main() {
	// freopen("in", "r", stdin);
	T = read();
	while(T--) {
		n = read();
		init();
		for(int i=2, v; i<=n; i++) {
			v = read();
			addnode(v, i), addnode(i, v);
		}
		pfa[1][0] = 0;
		dfs(1, 1);
		update();
		for(int i=1; i<=n; i++) {
			a[i] = read();
			int v = find(i, a[i]);
			// printf("link%d %d\n", i, v); 
			link(i, v);
		}
		m = read();
		int id, x, y;
		while(m--) {
			id = read();
			if(id == 1) {
				x = read();
				split(n+1, x);
				printf("%d\n", sz[ch[x][0]]);
			} else {
				x = read(), y = read();
				{
					int v = find(x, a[x]);
					// printf("del%d %d\n", x, v);
					del(x, v);
				}
				a[x] = y;
				{
					int v = find(x, a[x]);
					// printf("link%d %d\n", x, v); 
					link(x, v);
				}
			}
		}
	}
	return 0;
}
