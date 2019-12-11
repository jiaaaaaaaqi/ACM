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
const ll     mod  = 2012;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Sam {
    struct Node {
        int next[20];
        int fa, len;
        void init() {
            mes(next, 0);
            fa = len = 0;
        }
    } node[maxn<<1];
    int dp1[maxn<<1], dp2[maxn<<1];
    bool vis[maxn<<1];
    int tax[maxn<<1], gid[maxn<<1];
    int last, sz;
    void init() {
        mes(dp1, 0);
        mes(dp2, 0);
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
    void solve() {
        int ans = 0;
        for(int i=0; i<=sz; i++)    tax[i] = 0;
        for(int i=1; i<=sz; i++)    tax[node[i].len]++;
        for(int i=1; i<=sz; i++)    tax[i] += tax[i-1];
        for(int i=1; i<=sz; i++)    gid[tax[node[i].len]--] = i;
        dp2[1] = 1;
        for(int i=1; i<=sz; i++) {
            int u = gid[i];
			ans = (ans+dp1[u])%mod;
//			printf("%d %d %d\n", u, dp1[u], dp2[u]);
            for(int j=(u==1 ? 1:0); j<=9; j++) {
                if(node[u].next[j+1] == 0)  continue;
                int nst = node[u].next[j+1];
                dp1[nst] = (dp1[nst] + dp1[u]*10 + j*dp2[u])%mod;
                dp2[nst] = (dp2[nst] + dp2[u])%mod;
            }
        }
        printf("%d\n", ans);
    }
} sam;
char s[maxn], t[maxn];

int main() {
    while(~scanf("%d", &T)) {
        mes(s, 0);
        n = 0;
        while(T--) {
            scanf("%s", t+1);
            int tlen = strlen(t+1);
            for(int i=1; i<=tlen; i++) {
                s[++n] = t[i]-'0'+1;
            }
            s[++n] = 11;
        }
        sam.init();
        for(int i=1; i<=n; i++) {
            sam.insert(s[i]);
        }
        sam.solve();
    }
    return 0;
}
