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
const int    maxm = 2e5 + 10;
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
	int x, id;
	ll val;
	bool operator < (Node a) const {
		return id < a.id;
	}
} node[maxn];
vector<int> vv[maxn];
int l[maxn], r[maxn];

void dfs(int u) {
	node[u].l = ++tol;
	for(auto v : vv[u]) {
		dfs(v);
	}
	node[u].r = ++tol;
}
ll ans[maxn];
ll sum[maxm];

void update(int pos, ll val) {
	for(int i=pos; i<=tol; i+=lowbit(i))
		sum[i] += val;
}

ll query(int pos) {
	if(pos == 0)	return 0;
	ll ans = 0;
	for(int i=pos; i>0; i-=lowbit(i))
		ans += sum[i];
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
	mes(node, 0);
	int st;
	for(int i=1, u; i<=n; i++) {
		scanf("%d%d%lld", &u, &node[i].id, &node[i].val);
		if(u != -1)
			vv[u].push_back(i);
		if(u == -1)	st = i;
		node[i].x = i;
	}
	tol = 0;
	dfs(st);
	sort(node+1, node+1+n);
	mes(sum, 0);
	mes(ans, 0);
	for(int i=1; i<=n; i++) {
		int be = i, ed;
		for(int j=i; j<=n; j++) {
			if(node[j].id != node[be].id)	continue;
			ed = j;
			int x = node[j].x;
			int l = node[j].l;
			int r = node[j].r;
			int id = node[j].id;
			ans[x] = query(r)-query(l-1);			
		}
		for(int j=i; j<=n; j++) {
			if(node[j].id != node[be].id)	continue;
			int x = node[j].x;
			int l = node[j].l;
			int r = node[j].r;
			int id = node[j].id;
			update(l, node[j].val);
		}
		i = ed;
	}
	for(int i=1; i<=n; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
