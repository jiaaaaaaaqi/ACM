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
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
	int next[2];
	ll val;
	void init() {
		mes(next, 0);
		val = 0;
	}
} node[maxn*15];
int ss[40], t[maxn][40];
int a[maxn];

void init() {
	tol = 0;
	node[0].init();
}

void insert(int *s) {
	int rt = 0;
	for(int i=1, k; i<=30; i++) {
		k = s[i];
		if(!node[rt].next[k]) {
			node[++tol].init();
			node[rt].next[k] = tol;
		}
		node[rt].val++;
		rt = node[rt].next[k];
	}
	node[rt].val++;
}

ll query(int rt, int *s, int pos, bool flag) {
	if(pos == 31) {
		return 1ll*node[rt].val;
	} else {
		if(flag) {
			return node[rt].val;
		} else {
			ll ans = 0;
			if(node[rt].next[0]) {
				if((s[pos]^0) > ss[pos]) {
					ans += query(node[rt].next[0], s, pos+1, true);
				} else if((s[pos]^0) == ss[pos]) {
					ans += query(node[rt].next[0], s, pos+1, false);
				}
			}
			if(node[rt].next[1]) {
				if((s[pos]^1) > ss[pos]) {
					ans += query(node[rt].next[1], s, pos+1, true);
				} else if((s[pos]^1) == ss[pos]) {
					ans += query(node[rt].next[1], s, pos+1, false);
				}
			}
			return ans;
		}
	}
}

int main() {
	a[0] = 0;
	scanf("%d%d", &n, &m);	
	init();
	int mm = m;
	for(int i=30; i>=1; i--, mm>>=1) {
		ss[i] = mm&1;
		t[0][i] = 0;
	}
	ll ans = 0;
	insert(t[0]);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i] ^= a[i-1];
		mm = a[i];
		for(int j=30; j>=1; j--, mm>>=1) {
			t[i][j] = mm&1;
		}
		ans += query(0, t[i], 1, false);
		insert(t[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}