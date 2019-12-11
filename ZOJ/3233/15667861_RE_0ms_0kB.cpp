#include<map>
#include<set>
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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+50;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

ll n, m;
int T, tol;
ll a[55];
ll b[505];
ll ans;

void init() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
}

ll lcm(ll a, ll b) {
	return a*b / __gcd(a, b);
}

void dfs(int idx, bool flag, ll sum, ll x, ll lc) {
	if(flag)	ans += x / sum - x / lcm(sum, lc);
	else		ans -= x / sum - x / lcm(sum, lc);
	for(int i=idx+1; i<=n; i++) {
		dfs(i, !flag, sum*a[i], x, lc);
	}
}

int main() {
	ll l, r;
	while(scanf("%lld%lld%lld%lld", &n, &m, &l, &r)) {
		if(n + m + l + r == 0)	break;
		for(int i=1; i<=n; i++)	scanf("%lld", &a[i]);
		ll g = 0;
		for(int i=1; i<=m; i++) {
			scanf("%lld", &b[i]);
			g = __gcd(g, b[i]);
		}
		ll lc = g;
		for(int i=1; i<=m; i++) {
			lc *= (b[i] / g);
		}
		ll sum = 0;
		ans = 0;
		for(int i=1; i<=n; i++) {
			dfs(i, 1, a[i], r, lc);
		}
		sum += ans;
		ans = 0;
		for(int i=1; i<=n; i++) {
			dfs(i, 1, a[i], l, lc);
		}
		sum -= ans;
		printf("%lld\n", sum);
	}
	return 0;
}
