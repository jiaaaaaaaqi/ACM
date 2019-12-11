/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月26日 星期五 09时17分58秒
 ***************************************************************/

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

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 998244353;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll fac[maxn], facinv[maxn];
ll sum[maxn], inv[maxn], f[maxn];

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
	int mx = 3000;
	fac[1] = 1, inv[1] = 1, sum[1] = 1, f[1] = 0;
	for(int i=2; i<=mx; i++) {
		fac[i] = fac[i-1]*i%mod;
		sum[i] = (sum[i-1]+i)%mod;
		inv[i] = (mod-mod/i) * inv[mod%i]%mod;
		f[i] = f[i-1]*i%mod+fac[i-1]*sum[i-1]%mod;
		f[i] %= mod;
	}
	facinv[mx] = fpow(fac[mx], mod-2);
	for(int i=mx-1; i>=1; i--) {
		facinv[i] = facinv[i+1]*(i+1)%mod;
	}
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	while(~scanf("%d", &n)) {
		ll ans = 0;	
		for(int i=1; i<=n; i++) {
			ll res = 4ll*f[i]*inv[3]%mod*facinv[i]%mod;
			ans = (ans+res)%mod;
		}
		ans = ans*inv[n]%mod;
		printf("%lld\n", ans);
	}
	return 0;
}

