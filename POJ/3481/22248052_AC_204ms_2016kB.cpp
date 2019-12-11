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

struct Splay {
	int root, sz;
	struct Tree {
		int ch[2];
		int fa, val, cnt;
		int id;
		void init() {
			mes(ch, 0);
			fa = val = cnt = id = 0;
		}
	} t[maxn];
	void init() {
		root = sz = 0;
		t[0].init();
	}
	int newnode(int fa, int val, int id) {
		t[++sz].init();
		t[sz].fa = fa;
		t[sz].val = val;
		t[sz].id = id;
		t[sz].cnt = 1;
		return sz;
	}
	void rotate(int x) {
		int y = t[x].fa, z = t[y].fa;
		int k = t[y].ch[1]==x;
		t[z].ch[t[z].ch[1]==y] = x;
		t[x].fa = z;
		t[y].ch[k] = t[x].ch[k^1];
		t[t[x].ch[k^1]].fa = y;
		t[x].ch[k^1] = y;
		t[y].fa = x;
	}
	void splay(int x, int goal) {
		while(t[x].fa != goal) {
			int y = t[x].fa, z = t[y].fa;
			if(z != goal)	(t[z].ch[0]==y)^(t[y].ch[0]==x) ? rotate(x) : rotate(y);
			rotate(x);
		}
		if(goal == 0)	root = x;
	}
	void insert(int val, int id) {
		int u = root, fa = 0, k;
		while(u && t[u].val!=val) {
			fa = u;
			k = val>t[u].val;
			u = t[u].ch[k];
		}
		if(u)	t[u].cnt++;
		else {
			u = newnode(fa, val, id);
			t[fa].ch[val>t[fa].val] = u;
		}
		splay(u, 0);
	}
	int find(int val) {
		int u = root;
		while(1) {
			if(t[u].val ==val) {
				splay(u, root);
				return u;
			}
			int k = val>t[u].val;
			if(!t[u].ch[k])return 0;
			u=t[u].ch[k];
		}
	}
	int Next(int x, int f) {
		find(x);
		int u = root;
		if(t[u].val>x && f)		return u;
		if(t[u].val<x && !f)	return u;
		u = t[u].ch[f];
		while(t[u].ch[f^1])	u = t[u].ch[f^1];
		return u;
	}
	void Delete(int x) {
		if(t[x].cnt > 1) {
			t[x].cnt--;
			return ;
		}
		if(x == root) {
			if(!t[x].ch[0] && !t[x].ch[1]) {
				init();
			} else {
				int k = t[x].ch[0] ? 0 : 1;
				t[t[x].ch[k]].fa = 0;
				root = t[x].ch[k];
			}
		} else {
			int y, k;
			y = t[x].fa;
			k = t[y].ch[1]==x;
			t[y].ch[k] = t[x].ch[k^1];
			t[t[x].ch[k^1]].fa = y;
			splay(y, 0);
		}
	}
	void lowest() {
		int x = root;
		if(x == 0) {
			printf("0\n");
		} else {
			while(t[x].ch[0])	x = t[x].ch[0];
			printf("%d\n", t[x].id);
			Delete(x);
		}
	}
	void highest() {
		int x = root;
		if(x == 0) {
			printf("0\n");
		} else {
			while(t[x].ch[1])	x = t[x].ch[1];
			printf("%d\n", t[x].id);
			Delete(x);
		}
	}
} splay;

int main() {
	// freopen("in", "r", stdin);
	splay.init();
	while(scanf("%d", &m), m) {
		if(m == 1) {
			int k, p;
			scanf("%d%d", &k, &p);
			splay.insert(p, k);
		} else if(m == 2) {
			splay.highest();
		} else if(m == 3) {
			splay.lowest();
		} else	break;
	}
	return 0;
}

