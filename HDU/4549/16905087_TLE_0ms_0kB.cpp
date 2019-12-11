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

struct Mat{
	int mat[3][3];
};

Mat mmul(Mat A, Mat B) {
	Mat ans;
	mes(ans.mat, 0);
	for(int i=1; i<=2; i++) {
		for(int j=1; j<=2; j++) {
			for(int k=1; k<=2; k++) {
				ans.mat[i][j] += A.mat[i][k] * B.mat[k][j];
				ans.mat[i][j] %= (mod - 1);
			}
		}
	}
	return ans;
}

Mat mpow(Mat A, ll b) {
	Mat ans;
	mes(ans.mat, 0);
	for(int i=1; i<=2; i++)
		ans.mat[i][i] = 1;
	while(b) {
		if(b & 1)
			ans = mmul(ans, A);
		A = mmul(A, A);
		b >>= 1;
	}
	return ans;
}

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	ll a, b;
	while(~scanf("%lld%lld%lld", &a, &b, &n)) {
		if(n == 0) {
			printf("%lld\n", a % mod);
			continue;
		}
		if(n == 1) {
			printf("%lld\n", b % mod);
			continue;
		}
		if(n == 2) {
			printf("%lld\n", a % mod * b % mod);
			continue;
		}
		Mat A;
		A.mat[1][1] = A.mat[1][2] = A.mat[2][1] = 1;
		A.mat[2][2] = 0;
		A = mpow(A, n-3);
		ll pb = A.mat[1][1] * 2 + A.mat[1][2];
		pb %= (mod - 1);
		ll pa = A.mat[2][1] * 2 + A.mat[2][2];
		pa %= (mod - 1);
		printf("%lld %lld\n", pa, pb);
		ll ans1 = fpow(a, pa);
		ll ans2 = fpow(b, pb);
		ll ans = (ans1 * ans2) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
