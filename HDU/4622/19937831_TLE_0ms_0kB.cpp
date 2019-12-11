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
const int    maxn = 2e3 + 10;
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
		int next[27];
		int fa, len;
		void init() {
			mes(next, 0);
			len = fa = 0;
		}
	} node[maxn<<1];
	int dp[maxn<<1];
	int last, sz;
	void init() {
		last = sz = 1;
		node[sz].init();
	}
	void insert(int k) {
		int p = last, np = last = ++sz;
		node[np].init();
		node[np].len = node[p].len + 1;
		for(; p&&!node[p].next[k]; p=node[p].fa)
			node[p].next[k] = np;
		if(p == 0) {
			node[np].fa = 1;
		} else {
			int q = node[p].next[k];
			if(node[q].len == node[p].len+1) {
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
	void dfs(int u) {
		if(dp[u])	return ;
		dp[u] = 1;
		for(int i=1; i<=26; i++) {
			if(!node[u].next[i])	continue;
			dfs(node[u].next[i]);
			dp[u] += dp[node[u].next[i]];
		}
	}
	int solve() {
		for(int i=1; i<=sz; i++)	dp[i] = 0;
		dfs(1);
		return dp[1]-1;
	}
} sam;
struct ASK {
	int l, r;
	int id;
	bool operator < (ASK a) const {
		return l==a.l ? r<a.r : l<a.l;
	}
} ask[10010];
int res[10010];
char s[maxn];

int read() {	//输入外挂
	int x = 0, f = 1;
	char s = getchar();
	while (s < '0' || s > '9') {
		if (s == '-')f = -1;
		s = getchar();
	}
	while (s >= '0' && s <= '9') {
		x = x * 10 + s - '0';
		s = getchar();
	}
	return x * f;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s+1);
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			ask[i].l = read();
			ask[i].r = read();
			ask[i].id = i;
		}
		sort(ask+1, ask+1+n);
		ask[0].l = 0;
		int last = 0;
		for(int i=1; i<=n; i++) {
			int l = ask[i].l, r = ask[i].r, id = ask[i].id;
			if(ask[i].l == ask[i-1].l) {
				for(int j=last+1; j<=r; j++) {
					sam.insert(s[j]-'a'+1);
				}
				res[id] = sam.solve();
				last = r;
			} else {
				sam.init();
				for(int j=l; j<=r; j++) {
					sam.insert(s[j]-'a'+1);
				}
				res[id] = sam.solve();
				last = r;
			}
//			printf("%d %d %d\n", ask[i].l, ask[i].r, res[ask[i].id]);
		}
		for(int i=1; i<=n; i++) {
			printf("%d\n", res[i]);
		}
	}
	return 0;
}
