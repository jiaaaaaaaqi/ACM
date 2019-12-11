/***************************************************************
    > File Name    : i.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月08日 星期一 18时46分42秒
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
const ll     mod  = 10000007;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Mat{
	ll mat[15][15];
	void init() {
		mes(mat, 0);
	}
};
ll a[15];

Mat mmul(Mat A, Mat B) {
	Mat ans;
	ans.init();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				ans.mat[i][j] += A.mat[i][k]*B.mat[k][j]%mod;
				ans.mat[i][j] %= mod;
			}
		}
	}
	return ans;
}

Mat mpow(Mat A, int b) {
	Mat ans;
	ans.init();
	for(int i=1; i<=n; i++)
		ans.mat[i][i] = 1;
	while(b) {
		if(b&1)	ans = mmul(ans, A);
		A = mmul(A, A);
		b>>=1;
	}
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i=1; i<=n; i++) {
			scanf("%lld", &a[i+1]);
		}
		n++;
		a[n+1]=23, a[n+2]=3;
		Mat A;
		A.init();
		for(int i=1; i<=n; i++) {
			for(int j=2; j<=i; j++) {
				A.mat[i][j] = 1;
			}
			A.mat[i][n+1]=10;
			A.mat[i][n+2]=1;
		}
		A.mat[n+1][n+1]=10;
		A.mat[n+1][n+2]=1;
		A.mat[n+2][n+2]=1;
		n+=2;
		// for(int i=1; i<=n; i++) {
		//     for(int j=1; j<=n; j++) {
		//         printf("%d%c", A.mat[i][j], j==n ? '\n' : ' ');
		//     }
		// }
		A = mpow(A, m);
		// for(int i=1; i<=n; i++) {
		//     for(int j=1; j<=n; j++) {
		//         printf("%d%c", A.mat[i][j], j==n ? '\n' : ' ');
		//     }
		// }
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			// printf("!!!!%d %d\n", A.mat[n-2][i], a[i]);
			ans += A.mat[n-2][i]*a[i]%mod;
			ans %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

