/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月24日 星期六 16时26分42秒
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int mx = 1e6;
int pri[maxn];
bool ispri[maxn];
ll phi[maxn], sum[maxn];
ll inv6, inv2;
unordered_map<int, ll> mp;

ll fpow(ll a, ll b) {
	ll ans = 1ll;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return ans;
}

void handle() {
	mes(ispri, 1);
	phi[1] = 1;
	tol = 0;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			phi[i] = i-1;
		}
		for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0) {
				phi[i*pri[j]] = phi[i]*pri[j];
				break;
			} else {
				phi[i*pri[j]] = phi[i]*(pri[j]-1);
			}
		}
	}
	for(int i=1; i<=mx; i++) {
		sum[i] = sum[i-1] + 1ll*i*phi[i];
		sum[i] %= mod;
	}
}

ll dfs(int n) {
	if(n<=mx)	return sum[n];
	if(mp.count(n))	return mp[n];
	ll ans = 1ll*n*(n+1)%mod*(2ll*n%mod+1)%mod*inv6%mod;
	for(int i=2, j; i<=n; i=j+1) {
		j = min(n, n / (n/i));
		ans -= dfs(n/i) * (i+j)%mod * (j-i+1)%mod * inv2%mod;
		ans = (ans%mod+mod)%mod;
	}
	mp[n] = ans;
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	scanf("%d", &T);
	inv6 = fpow(6, mod-2);
	inv2 = fpow(2, mod-2);
	mp.clear();
	while(T--) {
		scanf("%d%*d%*d", &n);
		ll ans = dfs(n);
		ans = (ans-1)*inv2;
		ans = (ans%mod+mod)%mod;
		printf("%lld\n", ans);
	}
    return 0;
}

