#include<map>
#include<set>
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
const int maxn = 100;
const int maxm = 200010;
const int mod = 998244353;
const double eps = 1e-8;
using namespace std;

ll n, m;
int T, tol;
ll num[70];

ll calc(ll x,  int pos) {
	return (ll)pow((double)x, 1.0/pos);
}

ll solve(ll x) {
	memset(num, 0, sizeof num);
	num[1] = x;
	int pos = 2;
	for(; pos <= 64; pos++) {
		ll tmp = calc(x, pos) - 1;
		if(tmp <= 0)	break;
		num[pos] = tmp;
	}
	pos--;
	for(int i=pos; i>=1; i--) {
		for(int j=2; i*j<=pos; j++) {
			num[i] -= num[i*j];
		}
	}
	//for(int i=1; i<=pos; i++)	printf("%I64d%c", num[i], i==pos ? '\n' : ' ');
	ll ans = 0;
	for(int i=1; i<=pos; i++)	ans += i * num[i];
	return ans;
}

int main() {
    while(scanf("%I64d%I64d", &n, &m), n||m) {
		ll ans = solve(m);
		ans -= solve(n-1);
		printf("%I64d\n", ans);
    }
    return 0;
}
