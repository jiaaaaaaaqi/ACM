/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sat 12 Oct 2019 04:15:45 PM CST
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
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int cnt[maxn];
vector<int> vv;

ll calc(int x) {
	// printf("x = %d\n", x);
	vv.clear();
	int n = x;
	for(int i=2; i*i<=n; i++) {
		if(n%i == 0) {
			vv.pb(i);
			while(n%i == 0)	n /= i;
		}
	}
	if(n != 1)	vv.pb(n);
	n = vv.size();
	int mx = (1<<n)-1;
	int ans = 0;
	for(int i=1; i<=mx; i++) {
		int res = 1, f = 0;
		for(int j=1; j<=n; j++) {
			if(i&(1<<(j-1))) {
				f ^= 1;
				res = res*vv[j-1];
			}
		}
		if(f)	ans += cnt[res];
		else	ans -= cnt[res];
	}
	// printf("ans = %d\n", ans-1);
	return ans-1;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		mes(cnt, 0);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			for(int j=1; j*j<=a[i]; j++) {
				if(a[i] % j == 0) {
					cnt[j]++;
					if(j*j != a[i])	cnt[a[i]/j]++;
				}
			}
		}
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			if(a[i] == 1)	continue;
			ll x = calc(a[i]);
			ans += x*(n-x-1);
		}
		ans = 1ll*n*(n-1)*(n-2)/6 - ans/2;
		printf("%lld\n", ans);
	}
	return 0;
}

