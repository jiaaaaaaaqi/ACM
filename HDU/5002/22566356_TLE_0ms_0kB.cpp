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
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int ch[maxn][2], fa[maxn], sz[maxn], rev[maxn];
int Set[maxn], Add[maxn];
int Sax[maxn], Max[maxn], cSax[maxn], cMax[maxn];
int sta[maxn];

void pushdown(int x) {
	if(x) {
		if(rev[x]) {
			swap(ch[x][0], ch[x][1]);
			if(ch[x][0])	rev[ch[x][0]] ^= rev[x];
			if(ch[x][1])	rev[ch[x][1]] ^= rev[x];
			rev[x] = 0;
		}
		if(Set[x] != inf) {
			if(ch[x][0]) {
				Set[ch[x][0]] = Set[x];
				Max[ch[x][0]] = Set[x];
				a[ch[x][0]] = Set[x];
				Sax[ch[x][0]] = -inf;
				cMax[ch[x][0]] = sz[ch[x][0]];
				cSax[ch[x][0]] = 0;
			}
			if(ch[x][1]) {
				Set[ch[x][1]] = Set[x];
				Max[ch[x][1]] = Set[x];
				a[ch[x][1]] = Set[x];
				Sax[ch[x][1]] = -inf;
				cMax[ch[x][1]] = sz[ch[x][1]];
				cSax[ch[x][1]] = 0;
			}
			Set[x] = inf;
		}
		if(Add[x]) {
			if(ch[x][0]) {
				Add[ch[x][0]] += Add[x];
				Max[ch[x][0]] += Add[x];
				Sax[ch[x][0]] += Add[x];
				a[ch[x][0]] += Add[x];
			}
			if(ch[x][1]) {
				Add[ch[x][1]] += Add[x];
				Max[ch[x][1]] += Add[x];
				Sax[ch[x][1]] += Add[x];
				a[ch[x][1]] += Add[x];
			}
			Add[x] = 0;
		}
	}
}

void solve(int x, int y) {
	int M = -inf, cM = 0;
	M = max(M, Max[x]), M = max(M, Sax[x]), M = max(M, Max[y]), M = max(M, Sax[y]);
	if(Max[x]==M)	cM += cMax[x];
	if(Sax[x]==M)	cM += cSax[x];
	if(Max[y]==M)	cM += cMax[y];
	if(Sax[y]==M)	cM += cSax[y];

	int S = -inf, cS = 0;
	S = max(S, Max[x]==M ? -inf:Max[x]);
	S = max(S, Sax[x]==M ? -inf:Sax[x]);
	S = max(S, Max[y]==M ? -inf:Max[y]);
	S = max(S, Sax[y]==M ? -inf:Sax[y]);
	if(Max[x]==S)	cS += cMax[x];
	if(Sax[x]==S)	cS += cSax[x];
	if(Max[y]==S)	cS += cMax[y];
	if(Sax[y]==S)	cS += cSax[y];
	
	Max[x] = M, cMax[x] = cM;
	Sax[x] = S, cSax[x] = cS;
}

void pushup(int x) {
	if(x) {
		// 当维护的信息和左右子树顺序有关时
		// if(ch[x][0])	pushdown(ch[x][0]);
		// if(ch[x][1])	pushdown(ch[x][1]);
		sz[x] = 1;
		Max[x] = a[x], Sax[x] = -inf;
		cMax[x] = 1, cSax[x] = 0;
		if(ch[x][0]) {
			sz[x] += sz[ch[x][0]];
			solve(x, ch[x][0]);
		}
		if(ch[x][1]) {
			sz[x] += sz[ch[x][1]];
			solve(x, ch[x][1]);
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

void ADD(int x, int y, int v) {
	split(x, y);
	Max[y] += v, Sax[y] += v;
	Add[y] += v, a[y] += v;
	pushup(y);
}

void SET(int x, int y, int v) {
	split(x, y);
	Max[y] = v, Sax[y] = -inf;
	cMax[y] = sz[y], cSax[y] = 0;
	Set[y] = v, a[y] = v;
	pushup(y);
}

void dfs(int x) {
	if(ch[x][0])	dfs(ch[x][0]);
	// printf("%d\n", x);
	if(ch[x][1])	dfs(ch[x][1]);
	// printf("l for %d = %d, r for %d = %d\n", x, ch[x][0], x, ch[x][1]);
	// printf("Max[%d]=%d cMax[%d]=%d Sax[%d]=%d cSax[%d]=%d\n", x, Max[x], x, cMax[x], x, Sax[x], x, cSax[x]);
}

void QRY(int x, int y) {
	split(x, y);
	dfs(y);
	if(Sax[y] == -inf)	printf("ALL SAME\n");
	else	printf("%d %d\n", Sax[y], cSax[y]);
}

int main() {
	// freopen("in", "r", stdin);
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			Set[i] = inf, Add[i] = 0;
			Sax[i] = Max[i] = -1;
			cSax[i] = cMax[i] = 0;
		}
		for(int i=1, v, u; i<n; i++) {
			scanf("%d%d", &u, &v);
			link(u, v);
		}
		int id, x, y, u, v;
		printf("Case #%d:\n", cas++);
		while(m--) {
			scanf("%d%d%d", &id, &x, &y);
			if(id == 1) {
				scanf("%d%d", &u, &v);
				del(x, y), link(u, v);
			} else if(id == 2) {
				scanf("%d", &u);
				SET(x, y, u);
			} else if(id == 3) {
				scanf("%d", &u);
				ADD(x, y, u);
			} else if(id == 4) {
				QRY(x, y);
			}
		}
	}
	return 0;
}

/*
 *
 *
 *
 *
 *
 *
 *
 * */
