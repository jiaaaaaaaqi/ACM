/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年11月07日 星期四 15时26分38秒
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

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

int n, m;
int cas, tol, T;

struct Mat {
	ll x[4][4];
	Mat operator * (Mat a) const {
		Mat ans;
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				ans.x[i][j] = 0;
				for(int k=0; k<4; k++) {
					ans.x[i][j] += x[i][k]*a.x[k][j];
					ans.x[i][j] %= mod;
				}
			}
		}
		return ans;
	}
	void init() {
		mes(x, 0);
		for(int i=0; i<4; i++)	x[i][i] = 1;
	}
};

Mat mpow(Mat a, ll b) {
	Mat ans;
	ans.init();
	while(b) {
		if(b&1)	ans = ans*a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1)	ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}

int main() {
    // freopen("in", "r", stdin);
	scanf("%d", &n);
	if(n == 1)	return 0*puts("2");
	if(n == 2)	return 0*puts("24");
	if(n == 3)	return 0*puts("96");
	Mat A;
	A.x[0][0] = 1, A.x[0][1] = 1, A.x[0][2] = 0, A.x[0][3] = 1;
	A.x[1][0] = 1, A.x[1][1] = 0, A.x[1][2] = 0, A.x[1][3] = 0;
	A.x[2][0] = 1, A.x[2][1] = 1, A.x[2][2] = 1, A.x[2][3] = 1;
	A.x[3][0] = 0, A.x[3][1] = 0, A.x[3][2] = 0, A.x[3][3] = 1;
	Mat B = mpow(A, n-4);
	ll x = (((B.x[2][0]*3%mod + B.x[2][1])%mod + B.x[2][2]*4)%mod + B.x[2][3])%mod;
	B = B*A*A;
	ll y = (((B.x[0][0]*3%mod + B.x[0][1])%mod + B.x[0][2]*4)%mod + B.x[0][3])%mod;
	ll ans = fpow(2, n+1)*y%mod + fpow(2, n+1)*x%mod;
	printf("%lld\n", ans%mod);
	return 0;
}

