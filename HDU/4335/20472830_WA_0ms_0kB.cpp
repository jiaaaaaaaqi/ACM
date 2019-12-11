/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月16日 星期二 10时15分00秒
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

typedef unsigned long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

ll b, P, M;
ll fac[maxn];

ll phi(ll x) {
	ll ans = x;
	for(ll i=2; i*i<=x; i++) {
		if(x%i == 0) {
			ans = ans/i*(i-1);
			while(x%i == 0)	x /= i;
		}
	}
	if(x > 1)	ans = ans/x*(x-1);
	return ans;
}

ll fpow(ll a, ll b, ll mod) {
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%llu%llu%llu", &b, &P, &M);
		if(P == 1) {
			// ll tmp = (ll)18446744073709551615;
			// if(M == tmp)	printf("Case #%d: 18446744073709551616\n", cas++);
			/*else*/	printf("Case #%d: %llu\n", cas++, M+1);
			continue;
		}
		ll ans = 0ll;
		ll phiP = phi(P);
		for(n=0; n<=M; n++) {
			fac[n] = n==0 ? 1 : fac[n-1]*n;
			if(fac[n] > phiP)	break;
			if(fpow(n, fac[n], P) == b)	ans++;
		}
		if(n <= M) {
			for(; n<=M; n++) {
				fac[n] = n==0 ? 1 : fac[n-1]*n;
				fac[n]%=phiP;
				if(fac[n]%phiP == 0)	break;
				if(fpow(n, fac[n]%phiP+phiP, P) == b)	ans++;
			}
			// printf("!!!!%lld %lld %lld %lld\n", ans, n, fac[n], phiP);
			if(n<=M) {
				ll nn = n;
				for(ll i=0; i<=P-1; i++) {
					n = nn + i;
					if(n > M)	break;
					if(fpow(n, phiP, P) == b) {
						ans += max((ll)0, 1ll*(M-n)/P+1);
						// printf("nn+%lld+k*P", i);
					}
				}
			}
		}
		printf("Case #%d: %llu\n", cas++, ans);
	}
    return 0;
}
