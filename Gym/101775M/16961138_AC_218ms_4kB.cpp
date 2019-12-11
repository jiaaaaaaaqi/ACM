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

ll n, m;
int cas, tol, T;

ll a[10];

int id(int x) {
	if(x <= 48)	return 1;
	if(x <= 56)	return 2;
	if(x <= 60)	return 3;
	if(x <= 62)	return 4;
	if(x <= 63)	return 5;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		mes(a, 0);
		for(int i=1; i<=5; i++)
			scanf("%lld", &a[i]);
		ll ans = 0;
		scanf("%lld", &m);
		int x;
		while(m--) {
			scanf("%d", &x);
			ans += a[id(x)];
		}
		printf("Case #%d: %lld", cas++, ans);
		printf("0000\n");
	}
	return 0;
}
