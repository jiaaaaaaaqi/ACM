/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月17日 星期三 18时58分13秒
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
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int pri[maxn], mob[maxn], cnt[maxn*3];
bool ispri[maxn];

void handle() {
	mes(pri, 0), mes(ispri, 1);
	int mx = 1e5;
	mob[1] = 1;
	tol = 0;
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
}

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

ll calc(int p, int n) {
	ll ans = 1, res = 0, l = 0;
	for(int i=p-1; l<n; i+=p) {
		ans = ans*fpow(res, cnt[i]-cnt[l])%mod;
		// printf("i=%d l=%d\n", i, l);
		// printf("res=%lld pow=%lld fpow=%lld ans=%lld\n", res, cnt[i]-cnt[l], fpow(res, cnt[i]-cnt[l]), ans);
		l = i;
		res++;
	}
	// printf("ans = %lld\n", ans);
	return ans;
}

int main() {
	handle();
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		mes(cnt, 0);
		scanf("%d", &n);
		int limit = inf;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			limit = min(limit, a[i]);
			cnt[a[i]]++;
		}
		for(int i=1; i<=limit+limit; i++) {
			cnt[i] += cnt[i-1];
		}
		ll ans = 0;
		for(int i=2; i<=limit; i++) {
			ans -= 1ll*mob[i]*calc(i, limit)%mod;
			ans = (ans%mod + mod)%mod;
		}
		printf("Case #%d: %lld\n", cas++, (ans%mod+mod)%mod);
	}
    return 0;
}

