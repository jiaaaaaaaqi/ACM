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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m, k;
int cas, tol, T;

ll solve(ll n, ll m, ll k) {
	/*
	一共n个人，每次出k个人，第m轮出的是谁。
	*/
    if(k==1)    return m;
    ll x = (k-1)%(n+1-m);
    for(ll i=n+1-m; i<n; ) {
        ll y = min((i-x+k-2) / (k-1), n-i);
        i += y;
        x = (x+y*k) % i;
    }
    return x+1;
}    

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		printf("Case #%d: %lld\n", cas++, solve(n, m, k));
	}
	return 0;
}
