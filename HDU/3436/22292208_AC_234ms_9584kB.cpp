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

struct Node {
	char s[10];
	int v;
} node[maxn];
struct Edge {
	int l, r;
} edge[maxn];

vector<int> vv;
int root, tot;
int ch[maxn][2];
int sz[maxn], fa[maxn], val[maxn];
int rk[maxn];
//由于这里我们用到了l - 1和r + 1号节点，所以对于节点1 ~ n的，如果查询1 ~ n这个区间，
//就会用到0, n + 1这两个节点，所以开始要多加入两个哨兵节点 -inf 和 inf。
void init() {
	mes(edge, 0);
	tol = root = tot = 0;
	vv.clear();
} 

int newnode(int x, int f) {
	mes(ch[++tot], 0);
	val[tot] = x;
	fa[tot] = f;
	sz[tot] = edge[val[x]].r - edge[val[x]].l;
	return tot;
}

void pushup(int x) {
	if(x) {
		sz[x] = edge[val[x]].r-edge[val[x]].l+1;
		if(ch[x][0])	sz[x] += sz[ch[x][0]];
		if(ch[x][1])	sz[x] += sz[ch[x][1]];
	}
}

int get(int x) {
	return ch[fa[x]][1] == x;// 1为右, 0为左
}

void rotate(int x) {
	int f = fa[x], gf = fa[f], k = get(x), w = ch[x][k ^ 1];
	ch[f][k] = w, fa[w] = f;
	ch[gf][get(f)] = x, fa[x] = gf;
	ch[x][k ^ 1] = f, fa[f] = x;
	pushup(f), pushup(x);// 先pushup下面的节点! 
}

void splay(int x, int goal = 0) {// 不传goal, 说明旋转成根节点
	int f, gf;
	while (fa[x] != goal) {
		f = fa[x], gf = fa[f];
		if (gf != goal) {
			if(get(x) == get(f)) rotate(f);
			else rotate(x);
		}
		rotate(x);
	}
	if (!goal) root = x;
}

int kth(int x) {// 得到排名为 x 的数
	int cur = root;
	while (true) {
		if (ch[cur][0] && sz[ch[cur][0]] >= x) {
			cur = ch[cur][0];
		} else {
			x -= sz[ch[cur][0]];
			int have = edge[val[cur]].r - edge[val[cur]].l + 1;
			// printf("cur=%d x=%d have=%d\n", cur, x, have);
			// printf("l=%d r=%d\n", edge[val[cur]].l, edge[val[cur]].r);
			if (x <= have) return edge[val[cur]].l+x-1;
			x -= have;
			cur = ch[cur][1];
		}
	}
}

int build(int l, int r, int f) {
	if(l > r)	return 0;
	int mid = l+r>>1;
	int now = newnode(mid, f);
	rk[mid] = now;
	ch[now][0] = build(l, mid-1, now);
	ch[now][1] = build(mid+1, r, now);
	pushup(now);
	return now;
}

int find(int x) {
	int l = 1, r = tol;
	while(l <= r) {
		int mid = l+r>>1;
		if(edge[mid].l<=x && x<=edge[mid].r)	return mid;
		if(edge[mid].r < x)	l = mid+1;
		else	r = mid-1;
	}
	return -1;
}

void del() {
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

void insert(int &x, int k, int f) {
	if(x == 0) {
		x = newnode(k, f);
		rk[k] = x;
		pushup(x);
		return ;
	}
	insert(ch[x][0], k, x);
	pushup(x);
}

void Top(int x) {
	int k = rk[find(x)];
	splay(k);
	del();
	insert(ch[root][0], find(x), root);
	splay(tot);
}

int Query(int x) {
	int k = rk[find(x)];
	splay(k);
	return sz[ch[root][0]] + x-edge[val[k]].l+1;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		printf("Case %d:\n", cas++);
		init();
		scanf("%d%d", &n, &m);
		for(int i=1; i<=m; i++) {
			scanf("%s%d", node[i].s+1, &node[i].v);
			if(node[i].s[1] == 'T')	vv.pb(node[i].v);
			if(node[i].s[1] == 'Q')	vv.pb(node[i].v);
		}
		sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		int len = vv.size();
		if(vv.size() == 0) {
			tol++;
			edge[tol].l = 1;
			edge[tol].r = n;
		} else {
			if(vv[0] == 1) {
				tol++;
				edge[tol].l = edge[tol].r = 1;
			} else {
				tol++;
				edge[tol].l = 1;
				edge[tol].r = vv[0]-1;
				tol++;
				edge[tol].l = edge[tol].r = vv[0];
			}
			for(int i=1; i<len; i++) {
				if(vv[i] - vv[i-1] > 1) {
					tol++;
					edge[tol].l = vv[i-1]+1;
					edge[tol].r = vv[i]-1;
				}
				tol++;
				edge[tol].l = edge[tol].r = vv[i];
			}
			if(vv[len-1] != n) {
				tol++;
				edge[tol].l = vv[len-1]+1;
				edge[tol].r = n;
			}
		}
		root = build(1, tol, 0);
		// cout << endl;
		// for(int i=1; i<=tol; i++) {
		//     printf("edge.l=%d edge.r=%d\n", edge[i].l, edge[i].r);
		// }
		// for(int i=1; i<=tot; i++) {
		//     printf("val[%d]=%d lson=%d rson=%d\n", i, val[i], ch[i][0], ch[i][1]);
		// }
		for(int i=1; i<=m; i++) {
			if(node[i].s[1] == 'R') {
				printf("%d\n", kth(node[i].v));
			} else if(node[i].s[1] == 'Q') {
				printf("%d\n", Query(node[i].v));
			} else {
				Top(node[i].v);
			}
		}
	}
	return 0;
}

