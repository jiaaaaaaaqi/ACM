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

int block, sz;
double a[maxn];
int bel[maxn];
vector<double> vv[maxn];

int L(int x) {
	return (x-1)*block + 1;
}

int R(int x) {
	return min(n, x*block);
}

void update(int x, double y) {
	vv[bel[x]].clear();
	a[x] = y;
	int l = L(bel[x]), r = R(bel[x]);
	vv[bel[x]].push_back(a[l]);
	for(int i=l+1; i<=r; i++) {
		if(a[i] > vv[bel[x]][vv[bel[x]].size()-1]) {
			vv[bel[x]].push_back(a[i]);
		}
	}
}

int query() {
	int ans = 0;
	double mx = 0;
	for(int i=1; i<=sz; i++) {
		if(vv[i].size() == 0)	continue;
		int p = upper_bound(vv[i].begin(), vv[i].end(), mx) - vv[i].begin() + 1;
		if(vv[i].size() - p + 1 == 0)	continue;
		ans += vv[i].size() - p + 1;
		mx = vv[i][vv[i].size()-1];
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	block = sqrt(1.0*n);
	for(int i=1; i<=n; i++) {
		bel[i] = (i-1)/block + 1;
		sz = bel[i];
	}
	for(int i=1, x, y; i<=m; i++) {
		scanf("%d%d", &x, &y);
		update(x, 1.0*y/x);
//		for(int i=1; i<=sz; i++) {
//			printf("size[%d] = %d\n", i, vv[i].size());
//		}
		int ans = query();
		printf("%d\n", ans);
	}
	return 0;
}
