/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sun 13 Oct 2019 12:04:34 AM CST
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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

double dp1[15][maxn];
double dp2[15][maxn];

double fpow(double a, int b) {
	double ans = 1.0;
	while(b) {
		if(b&1)	ans = ans*a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}

void init(int id, int n, double p) {
	int mx = 100;
	double tp = p;
	for(int i=1; i<=mx; i++) {
		dp1[id][i] = fpow(1.0-tp, n);
		dp2[id][i] = 1.0-dp1[id][i];
		tp = tp*p;
	}
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			int k;
			double p;
			scanf("%d%lf", &k, &p);
			init(i, k, p);
		}
		if(n == 1) {
			printf("%.6f\n", 1.0);
			continue;
		}
		int mx = 100;
		for(int i=1; i<=n; i++) {
			double ans = 0;
			for(int j=1; j<=mx; j++) {
				double p = dp2[i][j]-dp2[i][j+1];
				for(int k=1; k<=n; k++) {
					if(k == i)	continue;
					p = p*dp1[k][j];
				}
				ans += p;
			}
			printf("%.6f%c", ans, i==n ? '\n':' ');
		}
	}
	return 0;
}

