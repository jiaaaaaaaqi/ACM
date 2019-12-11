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

struct Sam {
	int node[maxn<<1][27], fa[maxn<<1], step[maxn<<1];
	int sz, last;
	int newnode() {
		mes(node[++sz], 0);
		fa[sz] = step[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		last = newnode();
	}
	void insert(int k) {
		int p = last, np = last = newnode();
		step[np] = step[p]+1;
		for(; p&&!node[p][k]; p=fa[p])
			node[p][k] = np;
		if(p == 0) {
			fa[np] = 1;
		} else {
			int q = node[p][k];
			if(step[q] == step[p]+1) {
				fa[np] = q;
			} else {
				int nq = newnode();
				memcpy(node[nq], node[q], sizeof node[q]);
				fa[nq] = fa[q];
				step[nq] = step[p]+1;
				fa[np] = fa[q] = nq;
				for(; p&&node[p][k]==q; p=fa[p])
					node[p][k] = nq;
			}
		}
	}
} sam;
char s[maxn];
ll dp[maxn];

int main() {
	while(~scanf("%s", s+1)) {
		sam.init();
		int len = strlen(s+1);
		ll p, q;
		scanf("%lld%lld", &q, &p);
		ll ans = 0;
		int l=0, pos=0;
		dp[0] = 0;
		for(int r=1; r<=len; r++) {
			dp[r] = dp[r-1]+q;
			int k = s[r]-'a'+1;
			while(l<r && (!sam.node[pos][k] || l<r-l)) {
				sam.insert(s[++l]-'a'+1);
				while(pos && sam.step[sam.fa[pos]]>=r-l-2)	
					pos = sam.fa[pos];
				if(!pos)	pos = 1;
			}
			pos = sam.node[pos][k];
			while(pos && sam.step[sam.fa[pos]]>=r-l-1)	
				pos = sam.fa[pos];
			if(!pos)	pos = 1;
			dp[r] = min(dp[r], dp[l]+p);
		}
		printf("%lld\n", dp[len]);
	}
	return 0;
}
