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

int root, tot;
int ch[maxn][2];
int sz[maxn], fa[maxn], val[maxn], cnt[maxn], id[maxn];
int rev[maxn];
ll Min[maxn], add[maxn];
int a[maxn];

void init() {
	root = tot = 0;
} 

int newnode(int x, int f) {
	mes(ch[++tot], 0);
	fa[tot] = f;
	Min[tot] = val[tot] = x;
	sz[tot] = cnt[tot] = 1;
	add[tot] = rev[tot] = 0;
	if(abs(x) != inf)	id[x] = tot;
	return tot;
}

void pushdown(int x) {
	if(add[x]) {
		if(ch[x][0]) {
			val[ch[x][0]] += add[x];
			Min[ch[x][0]] += add[x];
			add[ch[x][0]] += add[x];
		}
		if(ch[x][1]) {
			val[ch[x][1]] += add[x];
			Min[ch[x][1]] += add[x];
			add[ch[x][1]] += add[x];
		}
		add[x] = 0;
	}
	if(rev[x]) {
		swap(Min[ch[x][0]], Min[ch[x][1]]);
		swap(ch[x][0], ch[x][1]);
		if(ch[x][0])	rev[ch[x][0]] ^= 1;
		if(ch[x][1])	rev[ch[x][1]] ^= 1;
		rev[x] = 0;
	}
}

void pushup(int x) {
	if(x) {
		sz[x] = cnt[x];
		Min[x] = val[x];
		if(ch[x][0]) {
			sz[x] += sz[ch[x][0]];
			Min[x] = min(Min[x], Min[ch[x][0]]);
		}
		if(ch[x][1]) {
			sz[x] += sz[ch[x][1]];
			Min[x] = min(Min[x], Min[ch[x][1]]);
		}
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

void ViewTree(int x) {
	pushdown(x);
	if(ch[x][0])	ViewTree(ch[x][0]);
	printf("%d ", val[x]);
	if(ch[x][1])	ViewTree(ch[x][1]);
}

// 无哨兵也可以用
void del() { // 删除 root 节点, 想要删除哪个节点，可以先splay(x), 在del()
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
	ch[root][0] = ch[root][1] = 0;
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

void Add(int x, int y, int d) {
	x++, y++;
	x = kth(x-1), y = kth(y+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	Min[ch[cur][0]] += d;
	val[ch[cur][0]] += d;
	add[ch[cur][0]] += d;
	pushup(cur), pushup(root);
}

void reverse(int x, int y) {
	x++, y++;
	x = kth(x-1), y = kth(y+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	rev[ch[cur][0]] ^= 1;
	pushup(cur), pushup(root);
}

void dfs(int &rt, int k, int f) {
	if(rt == 0) {
		rt = k;
		fa[k] = f;
		pushup(rt);
		return ;
	}
	pushdown(rt);
	dfs(ch[rt][0], k, rt);
	pushup(rt);
}

void CUT(int x, int y, int k) {
	int tmp;
	{
		x = kth(x-1), y = kth(y+1);
		splay(x), splay(y, x);
		int cur = ch[root][1];
		tmp = ch[cur][0];
		ch[cur][0] = 0;
		pushup(cur), pushup(root);
	}
	{
		x = kth(k), y = kth(k+1);
		splay(x), splay(y, x);
		int cur = ch[root][1];
		dfs(ch[cur][0], tmp, cur);	
		pushup(cur), pushup(root);
	}
	splay(tmp);
}

void revolve(int x, int y, int t) {
	x++, y++;
	t = t%(y-x+1);
	if(t == 0)	return ;
	t = (y-x+1) - t;
	CUT(x+1, y, x-1);
}

void insert(int &rt, int k, int f) {
	if(rt == 0) {
		rt = newnode(k, f);
		pushup(rt);
		return ;
	}
	pushdown(rt);
	insert(ch[rt][0], k, rt);
	pushup(rt);
}

void Insert(int k, int d) {
	k++;
	int x = kth(k), y = kth(k+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	insert(ch[cur][0], d, cur);
	pushup(root);
	splay(tot);
}

void Delete(int x) {
	x = kth(x+1);
	splay(x);
	del();
}

void query(int x, int y) {
	x++, y++;
	x = kth(x-1), y = kth(y+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	printf("%d\n", Min[ch[cur][0]]);
}

int main() {
	// freopen("in", "r", stdin);
	init();
	scanf("%d", &n);
	a[1] = inf, a[n+2] = inf;
	for(int i=2; i<=n+1; i++) {
		scanf("%d", &a[i]);
	}
	n += 2;
	root = build(1, n, 0);
	// cout << endl;
	// ViewTree(root);
	// cout << endl;
	scanf("%d", &m);
	char s[10];
	while(m--) {
		scanf("%s", s+1);
		if(s[1] == 'A') {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			Add(x, y, d);
		} else if(s[1] == 'R' && s[4] == 'E') {
			int x, y;
			scanf("%d%d", &x, &y);
			reverse(x, y);
		} else if(s[1] == 'R' && s[4] == 'O') {
			int x, y, t;
			scanf("%d%d%d", &x, &y, &t);
			revolve(x, y, t);
		} else if(s[1] == 'I') {
			int x, d;
			scanf("%d%d", &x, &d);
			Insert(x, d);
		} else if(s[1] == 'D') {
			int x;
			scanf("%d", &x);
			Delete(x);
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
			query(x, y);
		}
		// cout << endl;
		// ViewTree(root);
		// cout << endl;
	}
	return 0;
}

