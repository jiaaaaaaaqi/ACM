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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

vector<int> vv[maxn];
int root, tot;
int ch[maxn][2];
int sz[maxn], fa[maxn], val[maxn], cnt[maxn];
int a[maxn], rk[maxn];

void init() {
	tol = root = tot = 0;
	for(int i=0; i<=n; i++) {
		vv[i].clear();
	}
} 

int newnode(int x, int f) {
	mes(ch[++tot], 0);
	val[tot] = x;
	rk[x] = tot;
	fa[tot] = f;
	sz[tot] = cnt[tot] = 1;
	return tot;
}

void pushdown(int x) { }

void pushup(int x) {
	if(x) {
		sz[x] = cnt[x];
		if(ch[x][0])	sz[x] += sz[ch[x][0]];
		if(ch[x][1])	sz[x] += sz[ch[x][1]];
	}
}

int get(int x) {
	return ch[fa[x]][1] == x;// 1为右, 0为左
}

void rotate(int x) {
	int f = fa[x], gf = fa[f], k = get(x), w = ch[x][k ^ 1];
	pushdown(f), pushdown(x);// 不能 pushdown gf！
	ch[f][k] = w, fa[w] = f;
	ch[gf][get(f)] = x, fa[x] = gf;
	ch[x][k ^ 1] = f, fa[f] = x;
	pushup(f), pushup(x);// 先pushup下面的节点! 
}

void splay(int x, int goal = 0) {// 不传goal, 说明旋转成根节点
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

void Delete() { // 删除 root 节点, 想要删除哪个节点，可以先splay(x), 在Delete()
	if(ch[root][0]==0 || ch[root][1]==0) {	
		root = ch[root][0] + ch[root][1];
		fa[root] = 0;
		return ;
	}
	int k = ch[root][1];
	while(ch[k][0])	k = ch[k][0];
	splay(k, root);
	int cur = ch[root][1];
	ch[cur][0] = ch[root][0];
	root = cur;
	fa[ch[root][0]] = root;
	fa[root] = 0;
	pushup(root);
}

int kth(int x) {// 得到排名为 x 的数
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

int build(int l, int r, int f) {// 类似线段树的递归建树
	if(l > r)	return 0;
	int mid = l+r>>1;
	int now = newnode(a[mid], f);
	ch[now][0] = build(l, mid-1, now);
	ch[now][1] = build(mid+1, r, now);
	pushup(now);
	return now;
}

void dfs(int u) {
	a[tol++] = u;
	for(auto v : vv[u]) {
		dfs(v);
	}
	a[tol++] = u+n;
}

void Move(int a, int b) {
	if(a == b)	return ;
	int x = rk[a], y = rk[a+n], z = rk[b];
	splay(x), splay(y, x);
	while(z && z!=y) {
		if(ch[y][0] == z)	return ;
		z = fa[z];
	}
	if(ch[x][0]==0 || ch[y][1]==0) {
		fa[ch[x][0]+ch[y][1]] = 0;
	} else {
		int k = ch[y][1];
		while(ch[k][0])	k = ch[k][0];
		splay(k, y);
		int cur = ch[y][1];
		ch[cur][0] = ch[x][0];
		fa[ch[x][0]] = cur;
		fa[cur] = 0;
		pushup(cur);
	}
	ch[x][0] = ch[y][1] = 0;
	// for(int i=1; i<=tot; i++)	printf("i=%d lson=%d rson=%d\n", i, ch[i][0], ch[i][1]);
	if(b == 0)	return ;
	z = rk[b];
	splay(z);
	if(ch[z][1]) {
		z = ch[z][1];
		while(ch[z][0])	z = ch[z][0];
		ch[z][0] = x;
		fa[x] = z;
		pushup(z);
	}
}

void Query(int x) {
	x = rk[x];
	splay(x);
	while(ch[x][0])	x = ch[x][0];
	printf("%d\n", val[x]);
}

int main() {
	// freopen("in", "r", stdin);
	int flag = 0;
	while(~scanf("%d", &n)) {
		if(flag)	printf("\n");
		flag = 1;
		init();
		for(int i=1; i<=n; i++) {
			int x;
			scanf("%d", &x);
			vv[x].pb(i);
		}
		dfs(0);
		tol--;
		// for(int i=1; i<tol; i++)	printf("%d%c", a[i], i==tol-1 ? '\n':' ');
		int st = 1, c = 0;
		for(int i=1; i<tol; i++) {
			if(a[i] <= n)	c++;
			else	c--;
			if(c == 0) {
				build(st, i, 0);
				st = i+1;
			}
		}
		// for(int i=1; i<=tot; i++)	printf("val[%d] = %d\n", i, val[i]);
		scanf("%d", &m);
		char s[10];
		while(m--) {
			int x, y;
			scanf("%s", s+1);
			if(s[1] == 'M') {
				scanf("%d%d", &x, &y);
				Move(x, y);
			} else {
				scanf("%d", &x);
				Query(x);
			}
		}
	}
}

