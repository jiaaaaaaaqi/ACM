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
	int rt, cnt;
	int ch[100005][2];    //左右儿子
	int fa[100005];       //父节点
	int sz[100005];       //字树和
	int cn[100005];       //当前点出现了多少次
	int val[100005];      //当前点权值
	int id[maxn];
	void init() {
		cnt = rt = 0;
	}
	void clear(int x) {
		sz[x] = fa[x] = ch[x][0] = ch[x][1] = cn[x] = val[x] = 0;
	}

	bool ws(int x) {  //which son
		return ch[fa[x]][1] == x;  // 右儿子1 左儿子0
	}

	void update(int x) {
		if(x) {
			sz[x] = cn[x];
			if(ch[x][0]) sz[x] += sz[ch[x][0]];
			if(ch[x][1]) sz[x] += sz[ch[x][1]];
		}
	}

	void setfa(int x, int f, int d) {
		if(x != 0) fa[x] = f;
		if(f != 0) ch[f][d] = x;
	}

	void rot(int x) {
		int f = fa[x]; int ff = fa[f]; int s1 = ws(x); int s2 = ws(f);
		int p = ch[x][s1 ^ 1];
		setfa(p, f, s1);
		setfa(f, x, s1 ^ 1);
		setfa(x, ff, s2);
		update(f);
		update(x);
	}

	void splay(int x) {
		for(; fa[x]; rot(x))
			if(fa[fa[x]] && ws(x) == ws(fa[x])) rot(fa[x]);
		rt = x;
	}

	void insert(int x, int d) {
		if(rt == 0) {
			cnt++; ch[cnt][0] = ch[cnt][1] = fa[cnt] = 0;
			val[cnt] = x;
			cn[cnt] = 1;
			sz[cnt] = 1;
			id[cnt] = d;
			rt = cnt;
			return;
		}

		int now = rt, f = 0;
		while(1) {
			if(val[now] == x) {
				cn[now]++; update(now); update(f);
				splay(now);
				break;
			}

			f = now;
			now = ch[now][val[now] < x];
			if(now == 0) {
				cnt++;
				val[cnt] = x;
				cn[cnt] = sz[cnt] = 1;
				fa[cnt] = f;
				ch[f][val[f] < x] = cnt;
				ch[cnt][1] = ch[cnt][0] = 0;
				id[cnt] = d;
				update(f);
				splay(cnt);
				break;
			}
		}
	}

	int find(int x) {     //查询 排名=有多少比他小的 + 1
		int now = rt, res = 0;
		while(1) {
			if(x < val[now]) now = ch[now][0]; //左
			else {
				if(ch[now][0]) res += sz[ch[now][0]];
				if(x == val[now]) {
					splay(now);
					return res + 1;
				}
				res += cn[now];
				now = ch[now][1];
			}
		}
	}

	int ffind(int x) {  //查询排名为x的数
		int now = rt, res = 0;
		while(1) {
			if(ch[now][0] && x <= res + sz[ch[now][0]]) now = ch[now][0];
			else {
				if(ch[now][0]) res += sz[ch[now][0]];
				res += cn[now];

				if(res >= x) return val[now];
				now = ch[now][1];
			}
		}
	}

	int pre() {  //前驱
		int now = ch[rt][0];
		while(ch[now][1]) now = ch[now][1];
		return now;
	}

	int nex() {
		int now = ch[rt][1];
		while(ch[now][0]) now = ch[now][0];
		return now;
	}

	void del(int x) {
		int no = find(x);
		if(cn[rt] > 1) {
			cn[rt]--;
			return;
		}

		if(!ch[rt][0] && !ch[rt][1]) {  //没孩子
			clear(rt);
			rt = 0;
			return;
		}
		if(!ch[rt][0]) {
			int oldrt = rt;
			rt = ch[rt][1]; fa[rt] = 0;
			clear(oldrt);
			return;
		}

		if(!ch[rt][1]) {
			int oldrt = rt;
			rt = ch[rt][0]; fa[rt] = 0;
			clear(oldrt);
			return;
		}
		// two children
		int lrt = pre();
		int oldrt = rt;
		splay(lrt);
		fa[ch[oldrt][1]] = lrt;
		ch[rt][1] = ch[oldrt][1];
		clear(oldrt);
		update(rt);
	}
} splay;

void highest() {
	if(splay.rt == 0) {
		printf("0\n");
	} else {
		int x = splay.rt;
		while(splay.ch[x][1])	x = splay.ch[x][1];
		printf("%d\n", splay.id[x]);
		splay.del(splay.val[x]);
	}
}

void lowest() {
	if(splay.rt == 0) {
		printf("0\n");
	} else {
		int x = splay.rt;
		while(splay.ch[x][0])	x = splay.ch[x][0];
		printf("%d\n", splay.id[x]);
		splay.del(splay.val[x]);
	}
}

int main() {
	freopen("in", "r", stdin);
	splay.init();
	while(scanf("%d", &m), m) {
		if(m == 1) {
			int k, p;
			scanf("%d%d", &k, &p);
			splay.insert(p, k);
		} else if(m == 2) {
			highest();
		} else if(m == 3) {
			lowest();
		} else	break;
	}
	return 0;
}
