/***************************************************************
    > File Name    : F.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月15日 星期三 01时58分32秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[2][maxn];
vector<int> vv;

bool ok(int mid) {
	vv.clear();
	for(int i=1; i<=n; i++) {
		if(a[0][i] > mid)	vv.push_back(a[0][i]);
	}
	if(vv.size() & 1)	return false;
	for(int i=1; i<vv.size(); i++) {
		if((i&1) && vv[i] != vv[i-1])	return false;
	}
	vv.clear();
	for(int i=1; i<=n; i++) {
		if(a[1][i] > mid)	vv.push_back(a[1][i]);
	}
	if(vv.size() & 1)	return false;
	for(int i=1; i<vv.size(); i++) {
		if((i&1) && vv[i] != vv[i-1])	return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	int mx = 0;
	for(int i=0; i<=1; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &a[i][j]);
			mx = max(mx, a[i][j]);
		}
	}
	int l = 0, r = mx, ans = 0;
	while(l <= r) {
		int mid = l+r >> 1;
		if(ok(mid))	r = mid-1, ans = mid;
		else	l = mid+1;
	}
	printf("%lld\n", ans);
	return 0;
}

