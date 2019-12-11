#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		ll ans = 0;
		ll x;
		scanf("%d", &n);
		for(int i=0; i<=n; i++) {
			scanf("%lld", &x);
			ans += x;
		}
		ll mx = -inf;
		for(int i=1; i<=n; i++) {
			ll a, b;
			scanf("%lld%lld", &a, &b);
			mx = max(b, mx);
		}
		ans += mx;
		printf("Case #%d: %.6f\n", cas++, (double)ans);
	}
	return 0;
}