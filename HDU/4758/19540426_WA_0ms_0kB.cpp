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
const int    maxn = 5e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1000000007;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
int dis[3][2] = {0, 0, 0, 1, 1, 0};

struct AC {
    int node[220][3], fail[220], cnt[220];
    int dp[4][110][110][220];
    int sz, root;
    int newnode() {
        mes(node[++sz], 0);
        cnt[sz] = 0;
        return sz;
    }
    void init() {
        sz = 0;
        root = newnode();
    }
    int getid(char cc) {
        if(cc == 'R')	return 1;
        else	return 2;
    }
    void insert(char *s, int id) {
        int len = strlen(s+1);
        int rt = root;
        for(int i=1; i<=len; i++) {
            int k = getid(s[i]);
            if(node[rt][k] == 0)	node[rt][k] = newnode();
            rt = node[rt][k];
        }
        cnt[rt] |= (1<<(id-1));
    }
    void build() {
        fail[root] = root;
        queue<int> q;
        while(!q.empty())	q.pop();
        for(int i=1; i<=2; i++) {
            if(node[root][i] == 0) {
                node[root][i] = root;
            } else {
                fail[node[root][i]] = root;
                q.push(node[root][i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            cnt[u] |= cnt[fail[u]];
            q.pop();
            for(int i=1; i<=2; i++) {
                if(node[u][i] == 0) {
                    node[u][i] = node[fail[u]][i];
                } else {
                    fail[node[u][i]] = node[fail[u]][i];
                    q.push(node[u][i]);
                }
            }
        }
    }
    int solve() {
        for(int sta=0; sta<=3; sta++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					for(int k=1; k<=sz; k++) {
						dp[sta][i][j][k] = 0;
					}
				}
			}
        }
        dp[0][0][0][1] = 1;
		for(int sta=0; sta<=3; sta++) {
			for(int i=0; i<=n; i++) {
				for(int j=0; j<=m; j++) {
					for(int k=1; k<=sz; k++) {
						if(dp[sta][i][j][k] == 0)	continue;
						int nst = node[k][1];
						dp[sta|cnt[nst]][i+1][j][nst] += dp[sta][i][j][k];
						dp[sta|cnt[nst]][i+1][j][nst] %= mod;
						nst = node[k][2];
						dp[sta|cnt[nst]][i][j+1][nst] += dp[sta][i][j][k];
						dp[sta|cnt[nst]][i][j+1][nst] %= mod;
					}
				}
			}
		}
        int ans = 0;
        for(int i=1; i<=sz; i++) {
            ans = (ans + dp[3][n][m][i])%mod;
        }
        return ans;
    }
} ac;
char s[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &m, &n);
        ac.init();
        scanf("%s", s+1);
        ac.insert(s, 1);
        scanf("%s", s+1);
        ac.insert(s, 2);
        ac.build();
        int ans = ac.solve();
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
40 100
RD
DR
*/
