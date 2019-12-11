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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 16005;
const int maxm = 105;
using namespace std;

int n, m, tol;

struct Node {
    int l;
    int p;
    int s;
    bool operator < (Node a) const {
        return s < a.s;
    }
};
Node node[maxm];
int dp[maxm][maxn];

void init() {
    memset(dp, 0, sizeof dp);
    memset(node, 0, sizeof node);
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i=1; i<=m; i++) {
            scanf("%d%d%d", &node[i].l, &node[i].p, &node[i].s);
        }
        sort(node + 1, node + 1 + m);
        for(int i=1; i<=m; i++) {
			memcpy(dp[i], dp[i-1], sizeof dp[i]);
//            for(int j=0; j<node[i].s; j++)	dp[i][j] = dp[i-1][j];
            deque<pair<int, int > > q;
            q.clear();
            for(int j=max(0, node[i].s - node[i].l); j<node[i].s; j++) {
                while(!q.empty() && q.back().second < dp[i - 1][j] - node[i].p * j)	q.pop_back();
                q.push_back(make_pair(j, dp[i - 1][j] - node[i].p * j));
            }
            for(int j=node[i].s; j<=node[i].s + node[i].l - 1; j++) {
				while(!q.empty() && q.front().first + node[i].l < j)	q.pop_front();
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], q.front().second + j * node[i].p));
            }
        }
		int ans = 0;
		for(int i=1; i<=n; i++) {
			ans = max(ans, dp[m][i]);
		}
		printf("%d\n", ans);
    }
    return 0;
}
