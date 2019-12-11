/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月26日 星期一 16时58分58秒
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

ll n, m;
int cas, tol, T;

int pri[maxn], phi[maxn];
bool ispri[maxn];
ll f[maxn], g[maxn], inv[maxn];

void handle() {
	int mx = 1e6;
	mes(ispri, 1);
	tol = 0;
	phi[1] = 1;
	for(int i=2; i<=mx; i++) {
		if(ispri[i]) {
			pri[++tol] = i;
			phi[i] = i-1;
		}
		for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
			ispri[i*pri[j]] = 0;
			if(i%pri[j] == 0) {
				phi[i*pri[j]] = phi[i]*pri[j];
				break;
			} else {
				phi[i*pri[j]] = phi[i]*(pri[j]-1);
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	inv[1] = 1;
	scanf("%d", &T);
	while(T--) {
		ll p;
		scanf("%lld%lld%lld", &n, &m, &p);
		ll x = min(n, m);
		for(int i=2; i<=x; i++)	inv[i] = (p-p/i)*inv[p%i]%p;
		for(int i=1; i<=x; i++)	f[i] = 1ll*(n/i)*(m/i)%p;
		for(int i=x; i>=1; i--) {
			g[i] = f[i];
			for(int j=2; i*j<=x; j++) {
				g[i] -= g[i*j];
				g[i] = (g[i]%p+p)%p;
			}
		}
		ll ans = 0;
		for(int i=1; i<=x; i++) {
			ans += 1ll*g[i]%p * i%p * inv[phi[i]]%p;
			ans %= p;
		}
		printf("%lld\n", ans);
	}
    return 0;
}

