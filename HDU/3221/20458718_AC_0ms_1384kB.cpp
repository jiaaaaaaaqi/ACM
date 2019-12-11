/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月15日 星期一 18时35分40秒
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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Mat {
	ll mat[3][3];
	void init() {
		mes(mat, 0);
	}
};

ll phi(ll x) {
	ll ans = x;
	for(ll i=2; i*i<=x; i++) {
		if(x%i == 0) {
			ans = ans/i*(i-1);
			while(x%i == 0)	x /= i;
		}
	}
	if(x > 1)	ans = ans/x*(x-1);
	return ans;
}

Mat mmul(Mat A, Mat B, ll mod) {
	Mat ans;
	ans.init();
	for(int k=1; k<=2; k++) {
		for(int i=1; i<=2; i++) {
			for(int j=1; j<=2; j++) {
				ans.mat[i][j] += A.mat[i][k]*B.mat[k][j]%mod;
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}

Mat mpow(Mat A, ll b, ll mod) {
	Mat ans;
	ans.init();
	ans.mat[1][1] = ans.mat[2][2] = 1;
	while(b) {
		if(b&1)	ans = mmul(ans, A, mod);
		A = mmul(A, A, mod);
		b >>= 1;
	}
	return ans;
}

ll calc(ll f1, ll f2, ll n, ll mod) {
	Mat A;
	A.init();
	A.mat[1][1] = A.mat[1][2] = A.mat[2][1] = 1;
	A = mpow(A, n-2, mod);
	return (A.mat[1][1]*f2%mod + A.mat[1][2]*f1%mod)%mod;
}

ll fpow(ll a, ll b, ll mod) {
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		ll a, b, p, n;
		scanf("%lld%lld%lld%lld", &a, &b, &p, &n);
		ll ans;
		if(n > 3) {
			ll phiP = phi(p);
			ll fa, fb;
			bool flag = false;
			ll f1 = 1, f2 = 0;
			for(int i=3; i<=n; i++) {
				ll tmp = f2;
				f2 = f1+f2;
				f1 = tmp;
				if(f2 >= phiP) {
					flag = true;
					break;
				}
			}
			if(flag)	fa = calc(1, 0, n, phiP) + phiP;
			else	fa = f2;

			flag = false;
			f1 = 0, f2 = 1;
			for(int i=3; i<=n; i++) {
				ll tmp = f2;
				f2 = f1+f2;
				f1 = tmp;
				if(f2 >= phiP) {
					flag = true;
					break;
				}
			}
			if(flag)	fb = calc(0, 1, n, phiP) + phiP;
			else	fb = f2;
			ans = fpow(a, fa, p) * fpow(b, fb, p) % p;
		} else if(n == 1) {
			ans = a%p;
		} else if(n == 2) {
			ans = b%p;
		} else {
			ans = a*b%p;
		}
		printf("Case #%d: %lld\n", cas++, ans);
	}
    return 0;
}

