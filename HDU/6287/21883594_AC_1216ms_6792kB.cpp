/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 23 Sep 2019 02:01:34 PM CST
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

int pri[maxn];
bool ispri[maxn];
int a[maxn];
vector<int> vv[maxn];

void handle() {
	int mx = 1e5;
	tol = 0;
	mes(pri, 0), mes(ispri, 1);
	for(int i=2; i<=mx; i++) {
		if(ispri[i])	pri[++tol] = i;
		for(int j=1; j<=tol && pri[j]*i<=mx; j++) {
			ispri[i*pri[j]] = false;
			if(i%pri[j] == 0)	break;
		}
	}
}

void calc(int p) {
	int x = a[p];
	for(int i=1; i<=tol&&pri[i]*pri[i]<=x; i++) {
		if(x%pri[i] == 0) {
			while(x%pri[i] == 0) {
				x /= pri[i];
				vv[pri[i]].pb(p);
			}
		}
	}
	if(x>1)	vv[x].pb(p);
}

bool ok(int l, int r, int n) {
	for(int i=1; i<=tol && pri[i]*pri[i]<=n; i++) {
		if(n%pri[i] == 0) {
			int cnt = 0;
			while(n%pri[i] == 0)	cnt++, n/=pri[i];
			int x = lower_bound(vv[pri[i]].begin(), vv[pri[i]].end(), l)-vv[pri[i]].begin();
			int y = upper_bound(vv[pri[i]].begin(), vv[pri[i]].end(), r)-vv[pri[i]].begin();
			if(cnt > y-x)	return false;
		}
	}
	if(n > 1) {
		int x = lower_bound(vv[n].begin(), vv[n].end(), l)-vv[n].begin();
		int y = upper_bound(vv[n].begin(), vv[n].end(), r)-vv[n].begin();
		if(1 > y-x)	return false;
	}
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=tol; i++) {
			vv[pri[i]].clear();
		}
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			calc(i);
		}
		for(int i=1, l, r, d; i<=m; i++) {
			scanf("%d%d%d", &l, &r, &d);
			ok(l, r, d) ? puts("Yes") : puts("No");	
		}
	}
	return 0;
}

