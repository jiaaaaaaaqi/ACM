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
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

char s[maxn];

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1)
			ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	int len = strlen(s+1);
	ll ans = 0;
	ll cnt = 0;
	for(int i=1; i<=len; i++) {
		ans = ans*10+(s[i]-'0');
		ans %= m;
		if(i!=len && ans == 0)	cnt++;
	}
	if(ans) {
		printf("0\n");
	} else {
		printf("%lld\n", fpow(2, cnt));
	}
	return 0;
}