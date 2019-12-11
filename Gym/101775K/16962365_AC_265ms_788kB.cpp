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

ll cnt[maxn];

int main() {
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		mes(cnt, 0);
		ll a, b, k;
		scanf("%lld%lld%lld", &a, &b, &k);
		ll x;
		cnt[0] = 0;
		for(int i=1; i<=a; i++) {
			scanf("%lld", &x);
			cnt[i] = cnt[i-1] + x;
		}
		while(k) {
			if(a == 1 && b == 1)	break;
			int a1 = lower_bound(cnt+1, cnt+1+a, a) - cnt;
			int b1 = a - cnt[a1-1];
			if(a == a1 && b == b1)	break;
			a = a1;
			b = b1;
//			printf("%d %d\n", a1, b1);
			k--;
		}
		printf("Case #%d: %lld-%lld\n", cas++, a, b);
	}
	return 0;
}
