/***************************************************************
  > File Name    : a.cpp
  > Author       : Jiaaaaaaaqi
  > Created Time : Mon 14 Oct 2019 07:20:55 PM CST
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
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int root, tot;
int ch[maxn][2];
int sz[maxn], fa[maxn], val[maxn], cnt[maxn];
int add[maxn], rev[maxn];
int a[maxn];

void init() {
	root = tot = 0;
}

int newnode(int x, int f) {
	mes(ch[++tot], 0);
	fa[tot] = f;
	val[tot] = x;
	add[tot] = rev[tot] = 0;
	sz[tot] = cnt[tot] = 1;
	return tot;
}

void pushdown(int x) {
	if(x) {
		if(add[x]) {
			if(ch[x][0]) {
				add[ch[x][0]] += add[x];
				val[ch[x][0]] += add[x];
			} 
			if(ch[x][1]) {
				add[ch[x][1]] += add[x];
				val[ch[x][1]] += add[x];
			}
			add[x] = 0;
		}
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
		sz[x] = cnt[x];
		if(ch[x][0])	sz[x] += sz[ch[x][0]];
		if(ch[x][1])	sz[x] += sz[ch[x][1]];
	}
}

int get(int x) {
	return ch[fa[x]][1] == x;
}

void rotate(int x) {
	int f = fa[x], gf = fa[f], k = get(x), w = ch[x][k ^ 1];
	pushdown(f), pushdown(x);
	ch[f][k] = w, fa[w] = f;
	ch[gf][get(f)] = x, fa[x] = gf;
	ch[x][k ^ 1] = f, fa[f] = x;
	pushup(f), pushup(x);
}

void splay(int x, int goal = 0) {
	int f, gf;
	while (fa[x] != goal) {
		f = fa[x], gf = fa[f];
		pushdown(gf), pushdown(f), pushdown(x);
		if (gf != goal) {
			if(get(x) == get(f)) rotate(f);
			else rotate(x);
		}
		rotate(x);
	}
	if (!goal) root = x;
}

void ViewTree(int x) {
	pushdown(x);
	if(ch[x][0])	ViewTree(ch[x][0]);
	printf("%d ", val[x]);
	if(ch[x][1])	ViewTree(ch[x][1]);
}

int kth(int x) {
	int cur = root;
	while (true) {
		pushdown(cur);
		if (sz[ch[cur][0]] >= x && ch[cur][0]) {
			cur = ch[cur][0];
		} else {
			x -= sz[ch[cur][0]] + cnt[cur];
			if (x <= 0) return cur;
			cur = ch[cur][1];
		}
	}
}

int build(int l, int r, int f) {
	if(l > r)	return 0;
	int mid = l+r>>1;
	int now = newnode(a[mid], f);
	ch[now][0] = build(l, mid-1, now);
	ch[now][1] = build(mid+1, r, now);
	pushup(now);
	return now;
}

void Add(int p, int k, int v, int c) {
	int r = p+k-1;
	if(r > c) {
		int nd = r-c;
		{
			int x = kth(p), y = kth(c+2);
			splay(x), splay(y, x);
			int cur = ch[root][1];
			add[ch[cur][0]] += v;
			val[ch[cur][0]] += v;
			pushup(cur), pushup(root);
		}
		{
			int x = kth(1), y = kth(nd+2);
			splay(x), splay(y, x);
			int cur = ch[root][1];
			add[ch[cur][0]] += v;
			val[ch[cur][0]] += v;
			pushup(cur), pushup(root);
		}
	} else {
		{
			int x = kth(p), y = kth(r+2);
			splay(x), splay(y, x);
			int cur = ch[root][1];
			add[ch[cur][0]] += v;
			val[ch[cur][0]] += v;
			pushup(cur), pushup(root);
		}
	}
}

void Rev(int p, int k, int c) {
	int r = p+k-1;
	if(r > c) {
		int nd = r-c;
		int c1, c2;
		{
			int x = kth(p), y = kth(c+2);
			splay(x), splay(y, x);
			int cur = ch[root][1];
			rev[ch[cur][0]] ^= 1;
			pushup(cur), pushup(root);
			c1 = ch[cur][0];
		}
		{
			int x = kth(1), y = kth(nd+2);
			splay(x), splay(y, x);
			int cur = ch[root][1];
			rev[ch[cur][0]] ^= 1;
			pushup(cur), pushup(root);
			c2 = ch[cur][0];
		}
		int k1 = get(c1), k2 = get(c2);
		int f1 = fa[c1], f2 = fa[c2];
		ch[f1][k1] = c2, fa[c2] = f1;
		ch[f2][k2] = c1, fa[c1] = f2;
		while(c1) {
			pushup(c1);
			c1 = fa[c1];
		}
		while(c2) {
			pushup(c2);
			c2 = fa[c2];
		}
	} else {
		{
			int x = kth(p), y = kth(r+2);
			splay(x), splay(y, x);
			int cur = ch[root][1];
			rev[ch[cur][0]] ^= 1;
			pushup(cur), pushup(root);
		}
	}
}

void Insert(int p, int v) {
	p++;
	int x = kth(p), y = kth(p+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	ch[cur][0] = newnode(v, cur);
	pushup(cur), pushup(root);
	splay(tot);
}

void Delete(int p) {
	p++;
	int x = kth(p-1), y = kth(p+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	ch[cur][0] = 0;
	pushup(cur), pushup(root);
}

int main() {
	// freopen("in", "r", stdin);
	cas = 1;
	int k1, k2;
	while(scanf("%d%d%d%d", &n, &m, &k1, &k2), n||m||k1||k2) {
		init();
		printf("Case #%d:\n", cas++);
		a[1] = -inf, a[n+2] = inf;
		for(int i=2; i<=n+1; i++) {
			scanf("%d", &a[i]);
		}
		int c = n;
		n += 2;
		root = build(1, n, 0);
		int p = 1, x;
		char s[10];
		while(m--) {
			if(p == 0)	p = c;
			if(p > c)	p = 1;
			scanf("%s", s+1);
			if(s[1] == 'a') {
				scanf("%d", &x);
				Add(p, k2, x, c);
			} else if(s[1] == 'r') {
				Rev(p, k1, c);
			} else if(s[1] == 'i') {
				scanf("%d", &x);
				Insert(p, x);
				c++;
			} else if(s[1] == 'd') {
				Delete(p);
				c--;
			} else if(s[1] == 'm') {
				scanf("%d", &x);
				if(x == 1)	p--;
				if(x == 2)	p++;
			} else if(s[1] == 'q') {
				printf("%d\n", val[kth(p+1)]);
			}
		}
	}
	return 0;
}

