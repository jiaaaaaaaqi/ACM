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
const int maxn = 150005;
const int maxm = 305;
using namespace std;

int n, m, tol;
struct Node {
	int a;
	int b;
	int t;
	bool operator < (Node a) const {
		return t < a.t;
	}
};
Node node[maxm];
ll dp[2][maxn];
deque< pair<int, ll> > q;

int main() {
	int d;
	while(~scanf("%d%d%d", &n, &m, &d)) {
		for(int i=1; i<=m; i++)		{
			scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].t);
		}
		sort(node + 1, node + 1 + m);
		for(int j=1; j<=n; j++)	dp[0][j] = node[1].b - abs(node[1].a - j);
		int flag = 0;
		for(int i=2; i<=m; i++) {
			ll k = (ll)(node[i].t - node[i - 1].t) * d;
			if(k > n)	k = n;
			q.clear();
			for(int j=1; j<=k; j++) {
				while(!q.empty() && q.back().second < dp[flag][j] + node[i].b)	q.pop_back();
				q.push_back(make_pair(j, dp[flag][j] + node[i].b));
			}
			for(int j=1; j<=n; j++) {
				int left = max((ll)1, j - k);
				int right = j + k;
				while(!q.empty() && q.front().first < left)	q.pop_front();
				if(right <= n) {
					while(!q.empty() && q.back().second < dp[flag][right] + node[i].b)	q.pop_back();
					q.push_back(make_pair(right, dp[flag][right] + node[i].b));
				}
				dp[flag^1][j] = q.front().second - abs(node[i].a - j);
			}
			flag ^= 1;
		}
		ll ans = -inf;
		for(int i=1; i<=n; i++) {
			ans = max(ans, dp[flag][i]);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
