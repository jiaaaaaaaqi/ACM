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

int n, m, k;
int cas, tol, T;

struct Sam {
    struct Node {
        int next[55];
        int fa, len;
        void init() {
            mes(next, 0);
            fa = len = 0;
        }
    } node[maxn];
    ll dp[maxn], cnt[maxn];
    int sz, last;
    void init() {
        last = sz = 1;
        mes(dp, 0);
        node[sz].init();
    }
    void insert(int k) {
        int p = last, np = last = ++sz;
        dp[np] = 1;
        node[np].init();
        node[np].len = node[p].len+1;
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
    int tax[maxn], gid[maxn];
    void handle() {
		for(int i=0; i<=sz; i++)	tax[i] = cnt[i] = 0;
		for(int i=1; i<=sz; i++)	tax[node[i].len]++;
		for(int i=1; i<=sz; i++)	tax[i] += tax[i-1];
		for(int i=1; i<=sz; i++)	gid[tax[node[i].len]--] = i;
		for(int i=sz; i>=1; i--) {
			int u = gid[i];
			int fa = node[u].fa;
			dp[fa] += dp[u];
		}
    }
    void solve(char *s, int k) {
		int len = strlen(s+1);
		int res = 0, p = 1;
		ll ans = 0;
		for(int i=1; i<=len; i++) {
			int nst;
			if('a'<=s[i] && s[i]<='z')	nst = s[i]-'a'+1;
			else	nst = s[i]-'A'+1+26;
			while(p && !node[p].next[nst]) {
				p = node[p].fa;
				res = node[p].len;
			}
			if(p == 0) {
				p = 1;
				res = 0;
			} else {
				p = node[p].next[nst];
				res++;
			}
			if(res >= k) {
				ans += dp[p]*(res - max(node[node[p].fa].len+1, k) + 1);
				if(node[node[p].fa].len >= k)
					cnt[node[p].fa]++;
			}
		}
		for(int i=sz; i>=1; i--) {
			int u = gid[i];
			ans += dp[u]*cnt[u]*(node[u].len - max(node[node[u].fa].len+1, k) + 1);
			if(node[node[u].fa].len >= k)
				cnt[node[u].fa] += cnt[u];
		}
		printf("%lld\n", ans);
    }
} sam;
char s[maxn], t[maxn];

int main() {
    while(~scanf("%d", &k)) {
        sam.init();
        scanf("%s%s", s+1, t+1);
        int slen = strlen(s+1);
        for(int i=1; i<=slen; i++) {
			int nst;
			if('a'<=s[i] && s[i]<='z')	nst = s[i]-'a'+1;
			else	nst = s[i]-'A'+1+26;
            sam.insert(nst);
        }
		sam.handle();
		sam.solve(t, k);
    }
    return 0;
}
