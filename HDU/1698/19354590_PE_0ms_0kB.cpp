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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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

int node[maxn<<2], lazy[maxn<<2];
/*
叶子节点：这个点颜色是多少
节点：l, r区间的和是多少
a[1] = 1,n 区间内的和
*/

void pushdown(int lsum, int rsum, int rt) {
	if(lazy[rt] != -1) {
		node[rt<<1] = lsum * lazy[rt];
		node[rt<<1|1] = rsum * lazy[rt];
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		lazy[rt] = -1;
	}
}

void pushup(int rt) {
	node[rt] = node[rt<<1] + node[rt<<1|1];
}

void build(int l, int r, int rt) {
	node[rt] = r-l+1, lazy[rt] = -1;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void update(int l, int r, int pl, int pr, int id, int rt) {
	if(pl<=l && r<=pr) {
		node[rt] = (r-l+1)*id;
		lazy[rt] = id;
		return ;
	}
	int mid = l+r>>1;
	pushdown(mid-l+1, r-mid, rt);
	if(pl <= mid)
		update(l, mid, pl, pr, id, rt<<1);
	if(pr > mid)
		update(mid+1, r, pl, pr, id, rt<<1|1);
	pushup(rt);
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		build(1, n, 1);
		scanf("%d", &m);
		int id, pl, pr;
		while(m--) {
			scanf("%d%d%d", &pl, &pr, &id);
			update(1, n, pl, pr, id, 1);
		}
		printf("Case %d: The total value of the hook is %d.", cas++, node[1]);
	}
	return 0;
}
