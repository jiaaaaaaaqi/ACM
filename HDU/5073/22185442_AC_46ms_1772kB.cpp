/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 11 Oct 2019 11:52:55 PM CST
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

ll d[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		m = n-m;
		for(int i=1; i<=n; i++) {
			scanf("%lld", &d[i]);
		}
		if(m == 0) {
			printf("0\n");
			continue;
		}
		sort(d+1, d+1+n);
		double s, ans;
		ll s1, s2;
		s1 = s2 = s = 0;
		for(int i=1; i<=m; i++) {
			s1 += d[i]*d[i];
			s2 += d[i];
		}
		s = 1.0*s2 / m;
		ans = s1 - 2*s2*s + m*s*s;
		for(int i=m+1; i<=n; i++) {
			s1 -= d[i-m]*d[i-m];
			s2 -= d[i-m];
			s1 += d[i]*d[i];
			s2 += d[i];
			s = 1.0*s2 / m;
			ans = min(ans, 1.0*s1 - 2.0*s2*s + 1.0*m*s*s);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}

