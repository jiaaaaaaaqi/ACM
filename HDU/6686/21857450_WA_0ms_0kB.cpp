/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sun 22 Sep 2019 12:27:09 AM CST
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

vector<int> vv[maxn];
int step[maxn];
int pre[maxn];
int cnt[maxn];
bool vis[maxn];
multiset<int> st;

void bfs(int now, int &st, int &d) {
	for(int i=1; i<=n; i++)
		pre[i] = i, vis[i] = 0;
	queue<int> q;
	q.push(now);
	pre[now] = -1;
	vis[now] = true;
	while(!q.empty()) {
		int u = q.front(); 
		st = u;
		q.pop();
		for(auto v : vv[u]) {
			if(vis[v])	continue;
			pre[v] = u;
			vis[v] = true;
			q.push(v);
		}
	}
	int cnt = 0;
	int x = st;
	while(x != -1) {
		step[++cnt] = x;
		x = pre[x];
	}
	d = cnt;
}

int dfs(int u, int fa) {
	int ans = 0;
	for(auto v : vv[u]) {
		if(v == fa)	continue;
		ans = max(ans, dfs(v, u));
	}
	return ans+1;
}

int a[maxn];
int node[maxn<<2], lazy[maxn<<2];

void build(int l, int r, int rt) {
	node[rt] = lazy[rt] = 0;
	if(l == r)	return ;
	int mid = l+r>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void pushup(int rt) {
	node[rt] = max(node[rt<<1], node[rt<<1|1]);
}

void pushdown(int rt) {
	if(lazy[rt]) {
		lazy[rt<<1] = max(lazy[rt<<1], lazy[rt]);
		lazy[rt<<1|1] = max(lazy[rt<<1|1], lazy[rt]);
		node[rt<<1] = max(node[rt<<1], lazy[rt]);
		node[rt<<1|1] = max(node[rt<<1|1], lazy[rt]);
		lazy[rt] = 0;
	}
}

void update(int l, int r, int pl, int pr, int val, int rt) {
	if(pl<=l && r<=pr) {
		node[rt] = max(node[rt], val);
		lazy[rt] = max(lazy[rt], val);
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt);
	if(pl <= mid)	update(l, mid, pl, pr, val, rt<<1);
	if(pr > mid)	update(mid+1, r, pl, pr, val, rt<<1|1);
	pushup(rt);
}

void query(int l, int r, int rt) {
	if(l == r) {
		a[l] = node[rt];
		return ;
	}
	int mid = l+r>>1;
	pushdown(rt);
	query(l, mid, rt<<1);
	query(mid+1, r, rt<<1|1);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	vv[i].clear();
		for(int i=1; i<n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			vv[u].pb(v);
			vv[v].pb(u);
		}
		int d1, d2, d;
		bfs(1, d1, d);
		bfs(d1, d2, d);
		swap(d1, d2);
		int mx = 0;
		for(int i=1; i<=d; i++) {
			cnt[i] = 0;
			for(auto v : vv[step[i]]) {
				if(v == step[i-1] || v == step[i+1])	continue;
				cnt[i] = max(cnt[i], dfs(v, step[i]));
			}
			mx = max(mx, cnt[i]);
		}
		// for(int i=1; i<=d; i++)	printf("%d%c", step[i], i==d ? '\n' : ' ');
		build(1, d, 1);
		{
			st.clear();
			for(int i=1; i<=d; i++) {
				st.insert(d-i+1 + cnt[i]);
			}
			for(int i=1; i<d; i++) {
				st.erase(st.find(d-i+1 + cnt[i]));
				update(1, d, i, i+cnt[i], *(--st.end()), 1);
			}
		}
		{
			st.clear();
			for(int i=1; i<=d; i++) {
				st.insert(i+cnt[i]);
			}
			for(int i=d; i>1; i--) {
				st.erase(st.find(i+cnt[i]));
				update(1, d, d-i+1, d-i+1+cnt[i], *(--st.end()), 1);
			}
		}
		for(int i=1; i<=n; i++)	a[i] = 0;
		query(1, d, 1);
		if(a[d] == 0)	a[d] = mx*2;
		// for(int i=1; i<=d; i++) {
		//     printf("%d%c", a[i], i==d ? '\n' : ' ');
		// }
		ll ans = 0;
		for(int i=1; i<=d; i++)	ans += a[i];
		printf("%lld\n", ans);
	}
	return 0;
}

