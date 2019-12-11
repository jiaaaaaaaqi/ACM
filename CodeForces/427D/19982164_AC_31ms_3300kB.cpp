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
const int    maxn = 1e4 + 10;
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
        int next[30];
        int fa, len;
        int left, right;
        void init() {
            mes(next, 0);
            fa = len = 0;
        }
    } node[maxn<<1];
    int dp[maxn<<1];
    bool vis[maxn<<1];
    vector<int> vv[maxn<<1];
    int last, sz;
    void init() {
        last = sz = 1;
        mes(dp, 0);
        node[sz].init();
    }
    void insert(int k, int id) {
        int p = last, np = last = ++sz;
        dp[np] = 1;
        node[np].init();
        node[np].len = node[p].len + 1;
        node[np].left = node[np].right = id;
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
		if(vis[u])	return ;
		vis[u] = true;
		for(auto v : vv[u]) {
			dfs(v);
			dp[u] += dp[v];
			node[u].right = max(node[u].right, node[v].right);
		}
    }
	void handle() {
		for(int i=1; i<=sz; i++)	vv[i].clear();
		for(int i=2; i<=sz; i++)	vv[node[i].fa].push_back(i);
		mes(vis, 0);
		dfs(1);
//		for(int i=1; i<=sz; i++) {
//			printf("dp[%d] = %d\n", i, dp[i]);
//			printf("left[%d] = %d\n", i, node[i].left);
//			printf("right[%d] = %d\n", i, node[i].right);
//		}
	}
	void solve(int slen) {
		int ans = inf;
		for(int u=2; u<=sz; u++) {
			if(dp[u]==2 && node[u].left<=slen && node[u].right>slen) {
				ans = min(ans, node[node[u].fa].len+1);
			}
		}
		if(ans == inf)	ans = -1;
		printf("%d\n", ans);
	}
} sam;
char s[maxn], t[maxn];

int main() {
	scanf("%s%s", s+1, t+1);
	int slen = strlen(s+1), tlen = strlen(t+1);
	sam.init();
	for(int i=1; i<=slen; i++)	sam.insert(s[i]-'a'+1, i);
	sam.insert(27, 1+slen);
	for(int i=1; i<=tlen; i++)	sam.insert(t[i]-'a'+1, i+slen+1);
	sam.handle();
	sam.solve(slen);
    return 0;
}
/*
alkdjflkjilkjdkjgnlkenlkngn
alkndnlgkneinlnlkaknlkng
*/
