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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1000000007;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll dp[maxn];
int a[maxn], last[maxn];

int main() {
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			last[a[i]] = 0;
		}
		dp[0] = 1;
		for(int i=1; i<=n; i++) {
			dp[i] = dp[i-1]*2%mod;
			if(last[a[i]])	dp[i] = ((dp[i]-dp[last[a[i]]-1])%mod+mod)%mod;
			last[a[i]] = i;
		}
		dp[n] = ((dp[n]-1)%mod+mod)%mod;
		printf("%lld\n", dp[n]);
	}
	return 0;
}

