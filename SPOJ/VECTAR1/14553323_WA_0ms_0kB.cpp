#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const int maxm = 1<<11;
const int mod = 1000000007;
using namespace std;

int n, m, tol;

int main() {
	ll n;
	while(~scanf("%lld", &n)) {
		n %= mod;
		ll ans =(n * n) % mod;
		ans = (ans - n + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
