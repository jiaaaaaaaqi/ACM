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
const int    maxn = 2e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct AC {
    int node[550][5], fail[550], cnt[550];
    int c[5], dp[550][maxn];
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
    int getid(char ch) {
        if(ch == 'A')	return 1;
        if(ch == 'T')	return 2;
        if(ch == 'C')	return 3;
        if(ch == 'G')	return 4;
    }
    void insert(char *s) {
        int len = strlen(s+1);
        int rt = root;
        for(int i=1; i<=len; i++) {
            int k = getid(s[i]);
            if(node[rt][k] == 0) {
                node[rt][k] = newnode();
            }
            rt = node[rt][k];
        }
        cnt[rt]++;
    }
    void build() {
        queue<int> q;
        while(!q.empty())	q.pop();
        fail[root] = root;
        for(int i=1; i<=4; i++) {
            if(node[root][i] == 0) {
                node[root][i] = root;
            } else {
                fail[node[root][i]] = root;
                q.push(node[root][i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            cnt[u] += cnt[fail[u]];
            q.pop();
            for(int i=1; i<=4; i++) {
                if(node[u][i] == 0) {
                    node[u][i] = node[fail[u]][i];
                } else {
                    fail[node[u][i]] = node[fail[u]][i];
                    q.push(node[u][i]);
                }
            }
        }
    }
    int solve(char *s) {
        mes(c, 0);
        int len = strlen(s+1);
        for(int i=1; i<=len; i++) {
            c[getid(s[i])]++;
        }
        int cx = (c[2]+1)*(c[3]+1)*(c[4]+1);
        int cy = (c[3]+1)*(c[4]+1);
        int cz = (c[4]+1);
        int ct = 1;
        mes(dp, -1);
        dp[1][0] = 0;
        for(int x=0; x<=c[1]; x++) {
            for(int y=0; y<=c[2]; y++) {
                for(int z=0; z<=c[3]; z++) {
                    for(int t=0; t<=c[4]; t++) {
                        int st = x*cx+y*cy+z*cz+t*ct;
                        for(int i=1; i<=sz; i++) {
							if(dp[i][st] == -1)	continue;
							for(int k=1; k<=4; k++) {
                                if(x==c[1] && k==1)	continue;
                                if(y==c[2] && k==2)	continue;
                                if(z==c[3] && k==3)	continue;
                                if(t==c[4] && k==4)	continue;
                                int nst = st;
                                if(k==1)	nst += cx;
                                else if(k==2)	nst += cy;
                                else if(k==3)	nst += cz;
                                else	nst += ct;
                                dp[node[i][k]][nst] = max(dp[node[i][k]][nst], dp[i][st]+cnt[node[i][k]]);
                            }
                        }
                    }
                }
            }
        }
        int all = c[1]*cx+c[2]*cy+c[3]*cz+c[4]*ct;
        int ans = 0;
        for(int i=1; i<=sz; i++) {
			ans = max(ans, dp[i][all]);
        }
        return ans;
    }
} ac;
char s[50];

int main() {
    cas = 1;
    while(scanf("%d", &n), n) {
        ac.init();
        for(int i=1; i<=n; i++) {
            scanf("%s", s+1);
            ac.insert(s);
        }
        ac.build();
        scanf("%s", s+1);
        int ans = ac.solve(s);
		printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
