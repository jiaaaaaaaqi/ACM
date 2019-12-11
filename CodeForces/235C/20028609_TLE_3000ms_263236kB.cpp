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
const int    maxn = 1e6 + 10;
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
	int next[maxn<<1][27], step[maxn<<1], fa[maxn<<1], tax[maxn<<1], gid[maxn<<1];
	bool vis[maxn<<1];
	ll dp[maxn<<1];
	int last, sz;
	int newnode() {
		mes(next[++sz], 0);
		step[sz] = fa[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		last = newnode();
		mes(dp, 0);
	}
	void insert(int k) {
		int p = last, np = last = newnode();
		dp[np] = 1;
		step[np] = step[p]+1;
		for(; p&&!next[p][k]; p=fa[p])
			next[p][k] = np;
		if(p == 0) {
			fa[np] = 1;
		} else {
			int q = next[p][k];
			if(step[q] == step[p]+1) {
				fa[np] = q;
			} else {
				int nq = newnode();
				memcpy(next[nq], next[q], sizeof next[q]);
				fa[nq] = fa[q];
				step[nq] = step[p]+1;
				fa[q] = fa[np] = nq;
				for(; p&&next[p][k]==q; p=fa[p])
					next[p][k] = nq;
			}
		}
	}
	void handle() {
		for(int i=0; i<=sz; i++)	tax[i] = 0;
		for(int i=1; i<=sz; i++)	tax[step[i]]++;
		for(int i=1; i<=sz; i++)	tax[i] += tax[i-1];
		for(int i=1; i<=sz; i++)	gid[tax[step[i]]--] = i;
		for(int i=sz; i>=1; i--) {
			int u = gid[i];
			dp[fa[u]] += dp[u];
		}
	}
	ll solve(char *s, int len) {
		mes(vis, false);
		int p = 1, res = 0;
		ll ans = 0;
		for(int i=1; i<=len+len; i++) {
			int k = s[i]-'a'+1;
			while(p && !next[p][k]) {
				p = fa[p];
				res = step[p];
			}
			if(p == 0) {
				p = 1;
				res = 0;
			} else {
				p = next[p][k];
				res++;
				if(res >= len) {
					while(!vis[p] && !(step[fa[p]]+1<=len && len<=step[p])) {
						vis[p] = true;
						p = fa[p];
					}
					if(p == 0) {
						p = 1;
					} else {
						if(!vis[p]) {
							vis[p] = true;
							ans += dp[p];
						}
					}
				}
			}
		}
		return ans;
	}
} sam;
char s[maxn], t[maxn<<1];

int main() {
	scanf("%s", s+1);
	int slen = strlen(s+1);
	sam.init();
	for(int i=1; i<=slen; i++) {
		sam.insert(s[i]-'a'+1);
	}
	sam.handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%s", t+1);
		int tlen = strlen(t+1);
		for(int i=1; i<=tlen; i++) {
			t[i+tlen] = t[i];
		}
		t[tlen+tlen+1] = '\0';
		ll ans = sam.solve(t, tlen);
		printf("%lld\n", ans);
	}
	return 0;
}
