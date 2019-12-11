/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Wed 23 Oct 2019 11:05:24 PM CST
 ***************************************************************/
#pragma GCC optimize(2)
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

inline void init() {
	tol = 0;
	for(register int i=1; i<=n+1; i++) {
		for(register int j=0; j<=20; j++)	pfa[i][j] = 0;
		head[i] = -1;
		rev[i] = fa[i] = 0;
		ch[i][0] = ch[i][1] = 0;
	}
}

inline void pushdown(register int x) {
	if(x) {
		if(rev[x]) {
			swap(ch[x][0], ch[x][1]);
			if(ch[x][0])	rev[ch[x][0]] ^= rev[x];
			if(ch[x][1])	rev[ch[x][1]] ^= rev[x];
			rev[x] = 0;
		}
	}
}

inline void pushup(register int x) {
	if(x) {
		// 当维护的信息和左右子树顺序有关时
		// if(ch[x][0])	pushdown(ch[x][0]);
		// if(ch[x][1])	pushdown(ch[x][1]);
		sz[x] = 1;
		if(ch[x][0]) {
			sz[x] += sz[ch[x][0]];
		}
		if(ch[x][1]) {
			sz[x] += sz[ch[x][1]];
		}
	}
}

// 判断x节点是不是其所在树的root
// 1 不是root，0 是root
inline bool notroot(register int x) {
	return ch[fa[x]][0]==x || ch[fa[x]][1]==x;
}

inline int get(register int x) {
	return ch[fa[x]][1] == x;
}

// rotate 和 splay 函数与普通的splay有所不同
inline void rotate(register int x) {
	register int f = fa[x], gf = fa[f], k = get(x), w = ch[x][k ^ 1];
	if(notroot(f))	ch[gf][get(f)] = x;
	ch[x][k^1] = f, ch[f][k] = w;
	if(w)	fa[w] = f;
	fa[f] = x, fa[x] = gf;
	pushup(f), pushup(x);
}

inline void splay(register int x) {
	register int y = x,  stasz = 0;
	sta[++stasz] = y;
	while(notroot(y))	sta[++stasz] = y = fa[y];
	while(stasz)	pushdown(sta[stasz--]);
	while(notroot(x)) {
		register int f = fa[x], gf = fa[f];
		if(notroot(f)) {
			if(get(x) == get(f)) rotate(f);
			else rotate(x);
		}
		rotate(x);
	}
	pushup(x);
}

// 访问 x 节点,让 x 和树根在同一颗 splay 中,并且以 x 为最后一个节点
inline void access(register int x) { 
	for(register int y=0; x; x=fa[y=x]) {
		splay(x), ch[x][1] = y, pushup(x);
	}
}

// 给整棵树换根
inline void makeroot(register int x) {
	access(x), splay(x);
	rev[x] ^= 1;
}

// 找 x 所在 splay 树的真实树根节点
inline int findroot(register int x) {
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
inline void split(register int x, register int y) {
	makeroot(x);
	access(y), splay(y);
}

// 维护森林时判断两个点是否在同一颗树内
inline bool judge(register int x, register int y) {
	while(fa[x])	x = fa[x];
	while(fa[y])	y = fa[y];
	return x==y;
}

// 添加一条 x 和 y 之间的边
inline void link(register int x, register int y) {
	makeroot(x);
	if(findroot(y) != x)	fa[x] = y;
}

// 断掉 x 和 y 之间的边
inline void del(register int x, register int y) {
	makeroot(x);
	if(findroot(y)==x && fa[y]==x && !ch[y][0]) {
		fa[y] = ch[x][1] = 0;
		pushup(x);
	}
}

inline void addnode(register int u, register int v) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].next = head[u];
	head[u] = tol++;
}

inline void dfs(register int u, register int d) {
    deep[u] = d;
    for(register int i=head[u]; ~i; i=node[i].next) {
        register int v = node[i].v;
        if(v==1 || pfa[v][0])	continue;
        pfa[v][0] = u;
        dfs(v, d+1);
    }
}

inline void update() {
	for(register int j=1; (1<<j)<=n; j++) {
		for(register int i=1; i<=n; i++) {
			pfa[i][j] = pfa[pfa[i][j-1]][j-1];
		}
	}
}

inline int find(register int x, register int k) {
	for(register int i=0; (1<<i)<=k; i++) {
		if(x == 0)	break;
		if(k&(1<<i)) {
			x = pfa[x][i];
		}
	}
	return x==0 ? n+1 : x;
}

inline int read() {
    char ch = getchar(); register int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}

inline void write(register int x) {
    if(x<0) {
        putchar('-');
        x = -x;
    }
    if(x>9) write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
	// freopen("in", "r", stdin);
	T = read();
	while(T--) {
		n = read();
		init();
		for(register int i=2, v; i<=n; i++) {
			v = read();
			addnode(v, i), addnode(i, v);
		}
		pfa[1][0] = 0;
		dfs(1, 1);
		update();
		for(register int i=1; i<=n; i++) {
			a[i] = read();
			register int v = find(i, a[i]);
			// prregister intf("link%d %d\n", i, v); 
			link(i, v);
		}
		m = read();
		register int id, x, y;
		while(m--) {
			id = read();
			if(id == 1) {
				x = read();
				split(n+1, x);
				write(sz[ch[x][0]]);
				puts("");
			} else {
				x = read(), y = read();
				{
					register int v = find(x, a[x]);
					del(x, v);
				}
				a[x] = y;
				{
					register int v = find(x, a[x]);
					link(x, v);
				}
			}
		}
	}
	return 0;
}