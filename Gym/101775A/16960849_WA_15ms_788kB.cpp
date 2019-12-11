#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;
ll inv[maxn];

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

void handle() {
	mes(inv, 0);
	inv[1] = 1;
	for(int i=2; i<maxn; i++) {
		inv[i] = (mod - mod/i) * inv[mod % i] % mod;
	}
}

ll calc(ll n, ll m) {
	ll ans = 1;
	ll sum = 1;
	for(ll i=1; i<=m; i++) {
		ans = ans * (n - i + 1) % mod * inv[i] % mod;
		sum = (sum + ans) % mod;
	}
	return sum;
}

int main() {
	cas = 1;
	handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		ll all = fpow(2, n);
		m--;
		ll x = calc(n, m);
		ll ans = ((all - x) % mod + mod) % mod;
		printf("Case #1: %lld\n", ans);
	}
	return 0;
}
