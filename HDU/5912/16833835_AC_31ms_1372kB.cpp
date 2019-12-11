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
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
ll a[15], b[15];

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	
	while (T--) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
		ll up = b[n], down = a[n];
		for (int i = n-1; i >= 1; i--) {
			ll tmp = down;
			down = a[i]*down + up;
			up = b[i]*tmp;
		}
		printf("Case #%d: %lld %lld\n", ++kase, up/gcd(up,down), down/gcd(up, down));
	}
}
