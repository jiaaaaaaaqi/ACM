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
const int    maxn = 3e5 + 10;
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
	struct Node{
		int next[27];
		int len, fa;
		void init() {
			mes(next, 0);
			len = fa = 0;
		}
	} node[maxn<<1];
	vector<int> vv[maxn<<1];
	int dp[maxn<<1], anslen[maxn];
	int sz, last;
	void init() {
		sz = last = 1;
		node[sz].init();
		mes(dp, 0);
		mes(anslen, 0);
	}
	void insert(int k) {
		int p = last, np = last = ++sz;
		node[np].init();
		dp[np] = 1;
		node[np].len = node[p].len+1;
		for(; p&&!node[p].next[k]; p=node[p].fa)
			node[p].next[k] = np;
		if(p==0) {
			node[np].fa = 1;
		} else {
			int q = node[p].next[k];
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
	void dfs(int u) {
		for(auto v : vv[u]) {
			dfs(v);
			dp[u] += dp[v];
		}
		anslen[node[u].len] = max(anslen[node[u].len], dp[u]);
	}
	void solve(int len) {
		for(int i=1; i<=sz; i++) {
			vv[i].clear();
		}
		for(int i=2; i<=sz; i++) {
			vv[node[i].fa].push_back(i);
		}
		dfs(1);
		for(int i=len-1; i>=1; i--) {
			anslen[i] = max(anslen[i], anslen[i+1]);
		}
		for(int i=1; i<=len; i++) {
			printf("%d\n", anslen[i]);
		}
	}
} sam;

char s[maxn];

int main() {
	scanf("%s", s+1);
	sam.init();
	int len = strlen(s+1);
	for(int i=1; i<=len; i++) {
		sam.insert(s[i]-'a'+1);
	}
	sam.solve(len);
	return 0;
}
