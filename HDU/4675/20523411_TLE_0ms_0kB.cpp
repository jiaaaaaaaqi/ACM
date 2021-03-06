/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月17日 星期三 17时15分29秒
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
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, k;
int cas, tol, T;

int a[maxn];
bool ispri[maxn];
int pri[maxn], mob[maxn];
ll cnt[maxn], f[maxn], g[maxn];
ll fac[maxn], inv[maxn];

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
	mes(pri, 0), mes(ispri, 1);
	tol = 0;
	int mx = 3e5;
	mob[1] = 1;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			mob[i] = -1;
		}
		for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0) {
				mob[i*pri[j]] = 0;
				break;
			} else {
				mob[i*pri[j]] = -mob[i];
			}
		}
	}
	fac[0] = 1;
	for(int i=1; i<=mx; i++)	fac[i] = fac[i-1]*i%mod;
	inv[mx] = fpow(fac[mx], mod-2);
	for(int i=mx-1; i>=1; i--) {
		inv[i] = (i+1)*inv[i+1]%mod;
	}
	inv[0] = 1;
}

void solve(ll x) {
	cnt[1]++;
	if(x == 1)	return ;
	for(ll i=2; i*i<=x; i++) {
		if(x%i == 0) {
			cnt[i]++;
			if(i*i != x)	cnt[x/i]++;
			while(x%i == 0)	x /= i;
		}
	}
	if(x > 1)	cnt[x]++;
}

ll C(int n, int m) {
	if(m == 0)	return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main() {
	handle();
	while(~scanf("%d%d%d", &n, &m, &k)) {
		mes(f, 0), mes(g, 0), mes(cnt, 0);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			solve(a[i]);
		}
		k = n-k;
		for(int i=1; i<=m; i++) {
			if(cnt[i] >= k) {
				f[i] = C(cnt[i], k) * fpow(m/i-1, cnt[i]-k) * fpow(m/i, n-cnt[i]);
			} else {
				f[i] = 0;
			}
		}
		for(int i=1; i<=m; i++) {
			for(int j=1; i*j<=m; j++) {
				g[i] += mob[j]*f[i*j];
			}
		}
		for(int i=1; i<=m; i++) {
			printf("%lld%c", g[i], i==m ? '\n' : ' ');
		}
	}
    return 0;
}

