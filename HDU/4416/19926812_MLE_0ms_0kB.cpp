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

struct SAM {
	struct Node {
		int next[28];
		int fa, len;
		int left, right;
		void init() {
			mes(next, 0);
			fa = len = 0;
		}
	} node[maxn];
	vector<int> vv[maxn];
	bool vis[maxn];
	int tax[maxn], getid[maxn];
	int last, sz;
	void init() {
		last = sz = 1;
		mes(getid, 0);
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
		for(int i=0; i<=sz; i++)	tax[i] = 0;
		for(int i=1; i<=sz; i++)	tax[node[i].len]++;
		for(int i=1; i<=sz; i++)	tax[i] += tax[i-1];
		for(int i=1; i<=sz; i++)	getid[tax[node[i].len]--] = i;
//		for(int i=1; i<=sz; i++) {
//			printf("right[%d] = %d\n", i, node[i].right);
//		}
//		cout << endl;
//		for(int i=1; i<=sz; i++) {
//			printf("getid[%d] = %d\n", i, getid[i]);
//		}
//		cout << endl;
//		for(int i=1; i<=sz; i++) {
//			printf("father[%d] = %d\n", i, node[i].fa);			
//		}
		for(int i=sz; i>=2; i--) {
			int v = getid[i];
			int u = node[v].fa;
			node[u].right = max(node[u].right, node[v].right);
		}
//		for(int i=1; i<=sz; i++) {
//			printf("%d %d %d\n", i, node[i].left, node[i].right);
//		}
	}
	ll solve(int slen) {
		ll ans = 0;
		for(int i=2; i<=sz; i++) {
			int l = node[i].left, r = node[i].right;
			if(r > slen)	continue;
			ans += (node[i].len - node[node[i].fa].len);
		}
		return ans;
	}
} sam;
char s[maxn>>1], t[maxn>>1];

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
		ll ans = sam.solve(slen);
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
