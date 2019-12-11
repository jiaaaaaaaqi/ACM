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
const int    maxn = 1e3 + 10;
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
    bool vis[maxn<<1];
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
        if(p==0) {
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
        int ans = 0;
        for(int i=2; i<=sz; i++) {
            ans += node[i].len - node[node[i].fa].len;
        }
        return ans;
    }
} sam;
char s[maxn];
#include<assert.h>
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s+1);
        sam.init();
        int len = strlen(s+1);
        for(int i=1; i<=len; i++) {
			assert(s[i]>='A' && s[i]<='Z');
            sam.insert(s[i]-'A'+1);
        }
        printf("%d\n", sam.solve());
    }
    return 0;
}
