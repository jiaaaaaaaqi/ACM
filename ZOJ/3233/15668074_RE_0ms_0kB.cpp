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

ull n, m;
int T, tol;
ull a[20];
ull b[505];
ull ans;

void init() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
}

ull gcd(ull a, ull b) {
	return b == 0 ? a : gcd(b, a%b);
}

ull lcm(ull a, ull b) {
	return a / gcd(a, b) * a;
}

void dfs(int idx, bool flag, ull sum, ull x, ull lc) {
	if(flag)	ans += x / sum - x / lcm(sum, lc);
	else		ans -= x / sum - x / lcm(sum, lc);
	for(int i=idx+1; i<=n; i++) {
		dfs(i, !flag, lcm(sum, a[i]), x, lc);
	}
	return ;
}

int main() {
	ull l, r;
	while(cin >> n >> m >> l >> r) {
		init();
		if(n + m + l + r == 0)	break;
		for(int i=1; i<=n; i++)	cin >> a[i];
		ull g = 0;
		for(int i=1; i<=m; i++) {
			cin >> b[i];
			g = gcd(g, b[i]);
		}
		ull lc = g;
		for(int i=1; i<=m; i++) {
			lc *= (b[i] / g);
		}
		ull sum = 0;
		ans = 0;
		for(int i=1; i<=n; i++) {
			dfs(i, 1, a[i], r, lc);
		}
		sum += ans;
		ans = 0;
		for(int i=1; i<=n; i++) {
			dfs(i, 1, a[i], l-1, lc);
		}
		sum -= ans;
		cout << sum << endl;
	}
	return 0;
}