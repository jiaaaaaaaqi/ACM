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

struct Node {
	int a, p;
	bool operator < (Node x) const {
		return a==x.a ? p<x.p : a<x.a;
	}
} node[maxn];

int root, tot;
int ch[maxn][2];
int sz[maxn], fa[maxn], val[maxn], cnt[maxn];
int rev[maxn];
//由于这里我们用到了l - 1和r + 1号节点，所以对于节点1 ~ n的，如果查询1 ~ n这个区间，
//就会用到0, n + 1这两个节点，所以开始要多加入两个哨兵节点 -inf 和 inf。
void init() {
	root = tot = 0;
} 

void pushdown(int x) {
	if(rev[x]) {
		swap(ch[x][0], ch[x][1]);
		if(ch[x][0])	rev[ch[x][0]] ^= 1;
		if(ch[x][1])	rev[ch[x][1]] ^= 1;
		rev[x] = 0;
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
	return ch[fa[x]][1] == x;// 1为右, 0为左
}

void rotate(int x) {
	int f = fa[x], gf = fa[f], k = get(x), w = ch[x][k ^ 1];
	pushdown(gf), pushdown(f), pushdown(x);
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

void insert(int x) {// cur是节点编号, 树上都是按编号操作, 不是按权值操作
	int cur = root, f = 0;
	while (cur && val[cur] != x) {
		f = cur;
		cur = ch[cur][x > val[cur]];
	}
	if (cur) {
		cnt[cur]++;
	} else {
		cur = ++tot;
		if (f) ch[f][x > val[f]] = cur;
		ch[cur][0] = ch[cur][1] = 0;
		sz[cur] = cnt[cur] = 1;
		fa[cur] = f, val[cur] = x;
	}
	splay(cur);
}

void change(int x) {// 寻找最大的比这个节点小或等于的节点，并将其splay至根节点
	if (!root) return;
	int cur = root;
	while(ch[cur][x > val[cur]] && val[cur] != x) 
		cur = ch[cur][x > val[cur]];
	splay(cur);
}

int getfa(int x) {// 得到 x 的前驱
	change(x);
	if (x > val[root]) return root;
	int cur = ch[root][0];
	while (ch[cur][1]) cur = ch[cur][1];
	return cur;
}

int getsuc(int x) {// 得到 x 的后继
	change(x);
	if (x < val[root]) return root;
	int cur = ch[root][1];
	while (ch[cur][0]) cur = ch[cur][0];
	return cur;
}

void del(int x) {// 删除一个数，如果出现多次，只删除一次
	int fa = getfa(x), suc = getsuc(x);
	splay(fa), splay(suc, fa);
	int cur = ch[suc][0];
	if (cnt[cur] > 1) {
		cnt[cur]--;
		splay(cur);
	} else {
		ch[suc][0] = 0;
		pushup(suc), pushup(root);
	}
}

int rank(int x) {// 得到 x 的排名
	int ans = 0, cur = root;
	while(1) {
		if(x < val[cur]) {
			cur = ch[cur][0];
		} else {
			ans += ch[cur][0] ? sz[ch[cur][0]] : 0;
			if(x == val[cur]) {
				splay(cur);
				return ans+1;
			}
			ans += cnt[cur];
			cur = ch[cur][1];
		}
	}
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

int build(int l, int r, int f) {
	if(l > r)	return 0;
	int mid = l+r>>1;
	rev[mid] = 0;
	fa[mid] = f;
	sz[mid] = cnt[mid] = 1;
	ch[mid][0] = build(l, mid-1, mid);
	ch[mid][1] = build(mid+1, r, mid);
	pushup(mid);
	return mid;
}

void reverse(int l, int r) {
	int x = kth(l-1), y = kth(r+1);
	splay(x), splay(y, x);
	rev[ch[ch[root][1]][0]] ^= 1;
}

int solve(int i) {
	splay(node[i].p);
	int ans = sz[ch[root][0]];
	reverse(i, ans+1);
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	while(scanf("%d", &n), n) {
		init();
		for(int i=2; i<=n+1; i++) {
			scanf("%d", &node[i].a);
			node[i].p = i;
		}
		node[1].a = -inf, node[1].p = 1;
		node[n+2].a = inf, node[n+2].p = n+2;
		n += 2;
		sort(node+1, node+1+n);
		root = build(1, n, 0);
		for(int i=2; i<=n-1; i++) {
			printf("%d%c", solve(i), i==n-1 ? '\n':' ');
		}
	}	
	return 0;
}
