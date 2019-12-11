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
const int    maxn = 2e5 + 10;
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
	int l, r;
	int x;
	int id, val;
	bool operator < (Node a) const {
		return id < a.id;
	}
} no[maxn];
vector<int> vv[maxn];
int l[maxn], r[maxn];
ll node[maxn<<2];

void dfs(int u) {
	no[u].l = ++tol;
	for(auto v : vv[u]) {
		dfs(v);
	}
	no[u].r = ++tol;
}
ll ans[maxn];
void update(int l, int r, int p, int val, int rt) {
	if(l == r) {
		node[rt] += val;
		return ;
	}
	int mid = l+r>>1;
	if(p <= mid)	update(l, mid, p, val, rt<<1);
	else	update(mid+1, r, p, val, rt<<1|1);
	node[rt] = node[rt<<1] + node[rt<<1|1];
}
ll query(int l, int r, int pl, int pr, int rt) {
	if(pl<=l && r<=pr) {
		return node[rt];
	}
	int mid = l+r>>1;
	ll ans = 0;
	if(pl <= mid)	ans += query(l, mid, pl, pr, rt<<1);
	if(pr > mid)	ans += query(mid+1, r, pl, pr, rt<<1|1);
	return ans;
}
int main() {
	scanf("%d", &n);
	int st;
	for(int i=1, u; i<=n; i++) {
		scanf("%d%d%d", &u, &no[i].id, &no[i].val);
		if(u != -1)
			vv[u].push_back(i);
		if(u == -1)	st = i;
		no[i].x = i;
	}
	tol = 0;
	dfs(st);
	sort(no+1, no+1+n);
	for(int i=1; i<=n; i++) {
		int id = no[i].x;
		int l = no[i].l;
		int r = no[i].r;
		ans[id] = query(1, tol, no[i].l, no[i].r, 1);
		update(1, tol, no[i].l, no[i].val, 1);
	}
	for(int i=1; i<=n; i++)	printf("%lld\n", ans[i]);
	return 0;
}
