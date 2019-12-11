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
const int    maxn = 1e3 + 200;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[110][12];
struct AC {
    int dp[105][maxn];
    string dps[105][maxn];
    int node[maxn][27], cnt[maxn], fail[maxn];
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
    void insert(char *s, int val) {
        int len = strlen(s+1);
        int rt = root;
        for(int i=1; i<=len; i++) {
            int k = s[i]-'a'+1;
            if(node[rt][k] == 0) {
                node[rt][k] = newnode();
            }
            rt = node[rt][k];
        }
        cnt[rt] += val;
    }
    void build() {
        queue<int> q;
        while(!q.empty())	q.pop();
        fail[root] = root;
        for(int i=1; i<=26; i++) {
            if(node[root][i] == 0) {
                node[root][i] = root;
            } else {
                fail[node[root][i]] = root;
                q.push(node[root][i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=1; i<=26; i++) {
                if(node[u][i] == 0) {
                    node[u][i] = node[fail[u]][i];
                } else {
                    fail[node[u][i]] = node[fail[u]][i];
                    q.push(node[u][i]);
                }
            }
        }
    }
    string query(int len) {
        dp[0][1] = 0, dps[0][1] = "";
        for(int i=2; i<=sz; i++) {
            dp[0][i] = -inf;
            dps[0][i] = 'z'+1;
        }
        int mx = 0;
        string ans = "";
        for(int i=1; i<=len; i++) {
            for(int j=1; j<=sz; j++) {
                dp[i][j] = -inf;
            }
            for(int j=1; j<=sz; j++) {
                if(dp[i-1][j] == -inf)	continue;
                for(int k=1; k<=26; k++) {
                    int nst = node[j][k];
                    if(dp[i][nst] < dp[i-1][j] + cnt[nst]) {
                        dp[i][nst] = dp[i-1][j] + cnt[nst];
                        dps[i][nst] = dps[i-1][j] + (char)('a'+k-1);
                    } else if(dp[i][nst] == dp[i-1][j] + cnt[nst]) {
                        if(dps[i][nst] > dps[i-1][j] + (char)('a'+k-1)) {
                            dps[i][nst] = dps[i-1][j] + (char)('a'+k-1);
                        }
                    }
//                    cout << dp[i][nst] << endl;
//                    cout << dps[i][nst] << endl;
                    if(mx < dp[i][nst]) {
                        mx = dp[i][nst];
                        ans = dps[i][nst];
                    }
                    if(mx == dp[i][nst]) {
                        if(ans.size() > dps[i][nst].size()) {
                            ans = dps[i][nst];
                        } else if(ans.size() == dps[i][nst].size()) {
                            if(ans > dps[i][nst]) {
                                ans = dps[i][nst];
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
} ac;

int main() {
    cin >> T;
    while(T--) {
        scanf("%d%d", &m, &n);
        ac.init();
        for(int i=1; i<=n; i++) {
            scanf("%s", s[i]+1);
        }
        for(int i=1, val; i<=n; i++) {
            scanf("%d", &val);
            ac.insert(s[i], val);
        }
        ac.build();
        string ans = ac.query(m);
        cout << ans << endl;
    }
    return 0;
}

