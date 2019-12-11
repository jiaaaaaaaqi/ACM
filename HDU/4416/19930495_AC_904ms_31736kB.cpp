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
        int next[27];
        int fa, len;
        int maxlen;
        void init() {
            mes(next, 0);
            fa = len = maxlen = 0;
        }
    } node[maxn<<1];
    vector<int> vv[maxn<<1];
    bool vis[maxn<<1];
    int last, sz;
    void init() {
        last = sz = 1;
        node[sz].init();
    }
    void insert(int k) {
        int p = last, np = last = ++sz;
        node[np].init();
        node[np].len = node[p].len+1;
        for(; p&&!node[p].next[k]; p=node[p].fa)
            node[p].next[k] = np;
        if(p == 0) {
            node[np].fa = 1;
        } else {
            int q = node[p].next[k];
            if(node[q].len == node[p].len + 1) {
                node[np].fa = q;
            } else {
                int nq = ++sz;
                node[nq] = node[q];
                node[nq].len = node[p].len + 1;
                node[np].fa = node[q].fa = nq;
                for(; p&&node[p].next[k]==q; p=node[p].fa)
                    node[p].next[k] = nq;
            }
        }
    }
    void solve(char *s) {
        int len = strlen(s+1);
        int p = 1, tmpans = 0;
        for(int i=1; i<=len; i++) {
            int k = s[i]-'a'+1;
            while(p && !node[p].next[k]) {
                p = node[p].fa;
                tmpans = node[p].len;
            }
            if(p == 0) {
                p = 1;
                tmpans = 0;
            } else {
                p = node[p].next[k];
                tmpans++;
            }
            node[p].maxlen = max(node[p].maxlen, tmpans);
        }
    }
    ll ans;
    void dfs(int u) {
        if(vis[u])	return ;
        vis[u] = true;
        for(auto v : vv[u]) {
            dfs(v);
            node[u].maxlen = min(node[u].len, max(node[u].maxlen, node[v].maxlen));
        }
        if(node[u].maxlen == 0) {
            ans += node[u].len - node[node[u].fa].len;
        } else {
			ans += node[u].len - node[u].maxlen;
        }
    }
    ll calc() {
        ans = 0;
        for(int i=1; i<=sz; i++)	vv[i].clear();
        for(int i=2; i<=sz; i++) {
            vv[node[i].fa].push_back(i);
        }
        mes(vis, 0);
//        for(int i=1; i<=sz; i++) {
//            printf("maxlen[%d] = %d\n", i, node[i].maxlen);
//        }
        dfs(1);
//        for(int i=1; i<=sz; i++) {
//            printf("maxlen[%d] = %d\n", i, node[i].maxlen);
//        }
        return ans;
    }
} sam;
char s[maxn], t[maxn];

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s", s+1);
        int slen = strlen(s+1);
        sam.init();
        for(int i=1; i<=slen; i++) {
            sam.insert(s[i]-'a'+1);
        }
        for(int i=1; i<=n; i++) {
            scanf("%s", t+1);
            sam.solve(t);
        }
        ll ans = sam.calc();
        printf("Case %d: %lld\n", cas++, ans);
    }
    return 0;
}
