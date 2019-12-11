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
	int calc() {
		return node[last].len - node[node[last].fa].len;
	}
} sam;
char s[maxn];
int dp[maxn][maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s+1);
		int len = strlen(s+1);
		mes(dp, 0);
		for(int i=1; i<=len; i++) {
			sam.init();
			for(int j=i; j<=len; j++) {
				sam.insert(s[j]-'a'+1);
				dp[i][j] = dp[i][j-1] + sam.calc();
			}
		}
		scanf("%d", &n);
		for(int i=1, l, r; i<=n; i++) {
			scanf("%d%d", &l, &r);
			printf("%d\n", dp[l][r]);
		}
	}
	return 0;
}
