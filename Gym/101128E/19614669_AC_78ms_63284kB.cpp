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
const int    maxn = 2e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 2147483647;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
vector<int> vv;
ll dp[maxn][maxn][2];

int getid(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;
}

int main() {
	mes(dp, 0);
	scanf("%d", &n);
	n++;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		vv.push_back(a[i]);
	}
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	dp[2][getid(a[1])][1] = 1;
	dp[2][getid(a[2])][0] = 1;
	for(int i=3; i<=n; i++) {
		int id = getid(a[i]);
		for(int j=1; j<id; j++) {
			if(dp[i-1][j][1] == 0)	continue;
			dp[i][j][1] += dp[i-1][j][1];
			dp[i][id][0] += dp[i-1][j][1];
			dp[i][j][1] %= mod;
			dp[i][id][0] %= mod;
		}
		for(int j=id+1; j<=vv.size(); j++) {
			if(dp[i-1][j][0] == 0)	continue;
			dp[i][j][0] += dp[i-1][j][0];
			dp[i][id][1] += dp[i-1][j][0];
			dp[i][j][0] %= mod;
			dp[i][id][1] %= mod;
		}
	}
	int tmp = getid(a[n]);
	ll ans = dp[n][tmp][0] + dp[n][tmp][1];
	printf("%lld\n", (ans%mod+mod)%mod);
	return 0;
}
