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
		ll sum = 0;
		for(int i=1; i<=m; i++)		{
			scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].t);
			sum += node[i].b;
		}
		sort(node + 1, node + 1 + m);
		for(int j=1; j<=n; j++)	dp[0][j] = abs(node[1].a - j);
		int flag = 0;
		for(int i=2; i<=m; i++) {
			ll k = (node[i].t - node[i - 1].t) * d;
			if(k > n)	k = n;
			q.clear();
			for(int j=1; j<=k; j++) {
				while(!q.empty() && q.back().second > dp[flag][j]) {
					q.pop_back();
				}
				q.push_back(make_pair(i, dp[flag][j]));
			}
			for(int j=1; j<=n; j++) {
				int left = max((ll)1, j - k);
				int right = j + k;
				while(!q.empty() && q.front().first < left) {
					q.pop_front();
				}
				if(right <= n) {
					while(!q.empty() && q.back().second > dp[flag][right]) {
						q.pop_back();
					}
					q.push_back(make_pair(right, dp[flag][right]));
				}
				dp[flag^1][j] = q.front().second + abs(node[i].a - j);
			}
			flag ^= 1;
		}
		ll ans = inf;
		for(int i=1; i<=n; i++) {
			ans = min(ans, dp[flag][i]);
		}
		sum -= ans;
		printf("%I64d\n", sum);
	}
	return 0;
}
