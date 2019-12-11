/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月26日 星期一 10时26分36秒
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

int a[maxn];
ll dp[maxn], sum[maxn];
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
	int mx = 1e3;
	fac[0] = inv[0] = 1;
	for(int i=1; i<=mx; i++)	fac[i] = fac[i-1]*i%mod;
	inv[mx] = fpow(fac[mx], mod-2);
	for(int i=mx-1; i>=1; i--)	inv[i] = inv[i+1]*(i+1)%mod;
}

ll C(int n, int m) {
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	mes(dp, 0);
	for(int i=n; i>=1; i--) {
		int last = i+a[i];
		if(last>n || a[i]<=0) {
			sum[i] = sum[i+1];
			continue;
		}
		for(int j=last; j<=n; j++) {
			dp[i] += C(j-i-1, a[i]-1)*(sum[j+1]+1)%mod;
			dp[i] %= mod;
		}
		sum[i] = (sum[i+1]+dp[i])%mod;
	}
	ll ans = 0;
	for(int i=1; i<=n; i++)
		ans = (ans+dp[i])%mod;
	printf("%lld\n", ans);
    return 0;
}

