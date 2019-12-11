/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月17日 星期日 16时49分38秒
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
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int val[maxn];
vector< pii > vv[maxn];

void init() {
	for(int i=1; i<=n; i++) {
		vv[i].clear();
	}
}

bool dfs(int u, int f, int limit) {
	for(auto i : vv[u]) {
		int v = i.fi, w = i.se;
		if(v == f)	continue;
		if(vv[v].size() == 1) {
			if(w > limit)	return false;
			else	val[u] += w;
		}
		else {
			if(w > limit) {
				if(!dfs(v, u, limit))
					return false;
				else
					val[u] += val[v];
			} else {
				if(dfs(v, u, limit))
					val[u] += min(val[v], w);
				else
					val[u] += w;
			}
		}
	}
	if(val[u] > m)	return false;
	return true;
}

bool ok(int x) {
	mes(val, 0);
	return dfs(1, 0, x);
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		int l = 1, r = 0;
		for(int i=2, u, v, w; i<=n; i++) {
			scanf("%d%d%d", &u, &v, &w);
			r = max(r, w);
			vv[u].push_back(make_pair(v, w));
			vv[v].push_back(make_pair(u, w));
		}
		int ans = 0;
		while(l <= r) {
			int mid = l+r >> 1;
			if(ok(mid))	r = mid-1, ans = mid;
			else	l = mid+1;
		}
		cout << ans << endl;
	}
	return 0;
}

