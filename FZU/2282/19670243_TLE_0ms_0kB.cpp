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
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll fac[maxn], inv[maxn], so[maxn];

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

void handle() {
	int mx = 1e4;
	fac[0] = inv[0] = 1;
	for(int i=1; i<=mx; i++) {
		fac[i] = fac[i-1] * i % mod;
	}
	inv[mx] = fpow(fac[mx], mod-2);
	for(int i=mx-1; i>=1; i--) {
		inv[i] = inv[i+1]*(i+1)%mod;
	}
}

ll solve(int n) {
	if(n==0)	return 1;
	ll res = 0;
	for(int i=2; i<=n; i++) {
		ll as = (fac[n]*inv[i])%mod;
		if(i & 1) {
			res = (res-as+mod)%mod;
		} else {
			res = (res+as)%mod;
		}
	}
	return res;
}

ll C(int n, int m) {
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main() {
	handle();
	scanf("%d", &T);
	for(int i=0; i<=10000; i++) {
		so[i] = solve(i);
	}
	while(T--) {
		scanf("%d%d", &n, &m);
		ll ans = 0;
		for(int i=m; i<=n; i++) {
			ans += C(n, i)*so[n-i]%mod;
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
