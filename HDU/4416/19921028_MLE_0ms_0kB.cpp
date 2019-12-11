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

struct SAM {
	struct Node {
		int next[30];
		int fa, len;
		int left, right;
		void init() {
			mes(next, 0);
			fa = len = 0;
		}
	} node[maxn<<2];
	vector<int> vv[maxn<<2];
	bool vis[maxn<<2];
	int last, sz;
	void init() {
		last = sz = 1;
		node[sz].init();
	}
	void insert(int k, int id) {
		int p = last, np = last = ++sz;
		node[np].init();
		node[np].len = node[p].len+1;
		node[np].left = node[np].right = id;
		for(; p&&!node[p].next[k]; p=node[p].fa)
			node[p].next[k] = np;
		if(p == 0) {
			node[np].fa = 1;
		} else {
			int q= node[p].next[k];
			if(node[q].len == node[p].len + 1) {
				node[np].fa = q;
			} else {
				int nq = ++sz;
				node[nq] = node[q];
				node[nq].len = node[p].len+1;
				node[np].fa = node[q].fa = nq;
				for(; p&&node[p].next[k]==q; p=node[p].fa)
					node[p].next[k] = nq;
			}
		}
	}
	void dfs1(int u) {
		if(vis[u])	return ;
		vis[u] = true;
		for(auto v : vv[u]) {
			dfs1(v);
			node[u].right = max(node[u].right, node[v].right);
		}
	}
	void handle() {
		for(int i=1; i<=sz; i++) {
			vv[i].clear();
		}
		for(int i=2; i<=sz; i++) {
			vv[node[i].fa].push_back(i);
		}
		mes(vis, 0);
		dfs1(1);
	}
	int solve(int slen) {
		int ans = 0;
		for(int i=2; i<=sz; i++) {
			int l = node[i].left, r = node[i].right;
			if(r > slen)	continue;
			ans += (node[i].len - node[node[i].fa].len);
		}
		return ans;
	}
} sam;
char s[maxn], t[maxn];

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		n = 0;
		scanf("%d", &m);
		sam.init();
		scanf("%s", s+1);
		int slen = strlen(s+1);
		for(int i=1; i<=slen; i++) {
			sam.insert(s[i]-'a'+1, ++n);
		}
		for(int j=1; j<=m; j++) {
			scanf("%s", t+1);
			sam.insert(27, ++n);
			int tlen = strlen(t+1);
			for(int i=1; i<=tlen; i++) {
				sam.insert(t[i]-'a'+1, ++n);
			}
		}
		sam.handle();
		int ans = sam.solve(slen);
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}
