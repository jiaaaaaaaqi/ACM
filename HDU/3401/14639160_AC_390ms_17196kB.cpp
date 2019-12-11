#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 2005;
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
struct Node {
    int ap;
    int bp;
    int as;
    int bs;
};
Node node[maxn];
int dp[maxn][maxn];
deque< pair<int, int> > q;

void init() {
    memset(dp, -inf, sizeof dp);
    memset(node, 0, sizeof node);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        int k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i=1; i<=n; i++)	scanf("%d%d%d%d", &node[i].ap, &node[i].bp, &node[i].as, &node[i].bs);
        for(int i=1; i<=n; i++)	dp[i][0] = 0;
        for(int i=1; i<=k+1; i++) {
            for(int j=1; j<=node[i].as; j++) {
                dp[i][j] = - j * node[i].ap;
            }
        }
        for(int i=2; i<=k+1; i++) {
            for(int j=1; j<=m; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
        for(int i=k+2; i<=n; i++) {
            q.clear();
            for(int j=0; j<=m; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                while(!q.empty() && q.back().second <= dp[i-k-1][j] + node[i].ap * j)	q.pop_back();
                q.push_back(make_pair(j, dp[i-k-1][j] + node[i].ap * j));
                while(!q.empty() && q.front().first + node[i].as < j)	q.pop_front();
                dp[i][j] = max(dp[i][j], q.front().second - j * node[i].ap);
            }
            q.clear();
            for(int j=m; j>=0; j--) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                while(!q.empty() && q.back().second <= dp[i-k-1][j] + node[i].bp * j)	q.pop_back();
                q.push_back(make_pair(j, dp[i-k-1][j] + node[i].bp * j));
                while(!q.empty() && j + node[i].bs < q.front().first)	q.pop_front();
                dp[i][j] = max(dp[i][j], q.front().second - j * node[i].bp);
            }
        }
        int ans = -inf;
        for(int i=0; i<=m; i++)	ans = max(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}
