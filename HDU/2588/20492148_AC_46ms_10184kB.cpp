/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月16日 星期二 19时53分42秒
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

void handle() {
	mes(pri, 0), mes(ispri, 1);
	phi[1] = 1;
	tol = 0;
	int mx = 1e6;
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
}

ll calc(ll x) {
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

ll getphi(int i) {
	if(i <= 1000000)	return phi[i];
	else	return calc(i);
}

int main() {
	handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &n, &m);
		ll ans = 0;
		for(ll i=1; i*i<=n; i++) {
			if(n%i)	continue;
			if(i >= m) {
				ans += getphi(n/i);
			}
			if(i*i!=n && n/i>=m) {
				ans += getphi(i);
			}
		}
		printf("%lld\n", ans);
	}
    return 0;
}
