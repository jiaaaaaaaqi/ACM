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

#define ls(x) T[x].ch[0]
#define rs(x) T[x].ch[1]
#define fa(x) T[x].fa
#define root  T[0].ch[1]
	struct Tree {
		int ch[2];
		int id, fa, val, cnt, sz;
	} T[maxn];
	int tot;
	void init() {
		tot = 0;
	}
	int newnode(int val, int fa) {
		mes(T[++tot].ch, 0);
		T[tot].fa = fa;
		T[tot].val = val;
		T[tot].cnt = T[tot].sz = 1;
		return tot;
	}
	void update(int x) {
		T[x].sz = T[ls(x)].sz+T[rs(x)].sz+T[x].cnt;
	}
	int ident(int x) {
		return T[fa(x)].ch[0]==x ? 0:1;
	}
	void setfa(int x, int fa, int k) {
		T[fa].ch[k] = x;
		T[x].fa = fa;
	}
	void rotate(int x) {
		int y = fa(x), z = fa(y);
		int k1 = ident(x), k2 = ident(y);
		setfa(T[x].ch[k1^1], y, k1);
		setfa(y, x, k1^1);
		setfa(x, z, k2);
		update(y), update(x);
	}
	void splay(int x,int to) {
		to = fa(to);
		while(fa(x) != to) {
			int y = fa(x);
			if(T[y].fa == to)	rotate(x);
			else if(ident(x) == ident(y))	rotate(y), rotate(x);
			else	rotate(x),rotate(x);
		}
	}
	void insert(int x, int id) {
		int now = root;
		if(root == 0) {
			root = newnode(x, 0);
			T[root].id = id;
		} else {
			while(1) {
				T[now].sz++;
				if(T[now].val == x) {
					T[now].cnt++;
					splay(now, root);
					return ;
				}
				int k = x<T[now].val ? 0:1;
				if(!T[now].ch[k]) {
					int p = newnode(x, now);
					T[p].id = id;
					T[now].ch[k] = p;
					splay(p, root);
					return ;
				}
				now = T[now].ch[k];
			}       
		}
	}
	int find(int x) {
		int now = root;
		while(1) {
			if(!now)	return 0;
			if(T[now].val == x) {
				splay(now,root);
				return now;
			}
			int k = x<T[now].val ? 0:1;
			now=T[now].ch[k];
		}
	}
	void del(int x) {
		int pos = find(x);
		if(pos == 0)	return ;
		if(T[pos].cnt>1) {
			T[pos].cnt--;
			T[pos].sz--;
		} else {
			if(!T[pos].ch[0] && !T[pos].ch[1]) {
				root = 0;
			} else if(!T[pos].ch[0]) {
				root = T[pos].ch[1];
				T[root].fa = 0;
			} else {
				int left = T[pos].ch[0];
				while(T[left].ch[1])	left=T[left].ch[1];
				splay(left, T[pos].ch[0]);
				setfa(T[pos].ch[1], left, 1); 
				setfa(left, 0, 1);
				update(left);
			}
		}
	}
	int rak(int x) {	// x 的排名
		int now = root, ans = 0;
		while(1) {
			if(T[now].val == x)	
				return ans+T[T[now].ch[0]].sz+1;
			int k = x<T[now].val ? 0:1;
			if(k==1)	ans += T[T[now].ch[0]].sz+T[now].cnt;
			now = T[now].ch[k];
		}
	}
	int kth(int x) {	// 排名为x的数 
		int now = root;
		while(1) {
			int used = T[now].sz-T[T[now].ch[1]].sz;
			if(T[T[now].ch[0]].sz<x && x<=used) {
				splay(now,root);
				return T[now].val;
			}
			if(x<used)	now=T[now].ch[0];
			else	now=T[now].ch[1],x-=used;
		}
	}
	int getpre(int x) {	// x 的前驱
		int now = root, ans = -inf;
		while(now) {
			if(T[now].val<x)	ans=max(ans, T[now].val);
			int k = x<=T[now].val ? 0:1;	//这里需要特别注意 
			now = T[now].ch[k];
		}
		return ans;
	}
	int getsuc(int x) {	// x 的后继
		int now = root, ans = inf;
		while(now) {
			if(T[now].val>x)	ans=min(ans, T[now].val);
			int k = x<T[now].val ? 0:1;
			now = T[now].ch[k];
		}
		return ans;
	}
	void highest() {
		if(root == 0) {
			printf("0\n");
		} else {
			int x = root;
			while(T[x].ch[1])	x = T[x].ch[1];
			printf("%d\n", T[x].id);
			del(T[x].val);
		}
	}
	void lowest() {
		if(root == 0) {
			printf("0\n");
		} else {
			int x = root;
			while(T[x].ch[0])	x = T[x].ch[0];
			printf("%d\n", T[x].id);
			del(T[x].val);
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
