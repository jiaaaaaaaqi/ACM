/*************************************************************** 
	> File Name		: H.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 05:23:41 PM CST
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

int a[maxn], dp[maxn], id[maxn];
vector<int> g[maxn];

int solve(int mx) {
	for(int i=0; i<=n; i++)	dp[i] = 0;
	for(int i=1; i<=n; i++) {
		for(auto v : g[a[i]]) {
			if(v>mx)	break;
			dp[id[v]] = dp[i-1]+1;
		}
		dp[i] = max(dp[i], dp[i-1]);
	}
	return dp[n];
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) for(int j=1, x; j<=n; j++) {
		scanf("%d", &x);
		if(i>j)	continue;
		if(x == 1) {
			g[i].pb(j);
			g[j].pb(i+n);
		}
	}
	for(int i=1; i<=n+n; i++)	sort(g[i].begin(), g[i].end());
	int ans = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1, tot = 0; j<=n; j++) {
			a[++tot] = i+j-1;
			id[i+j-1] = tot;
		}
		ans = max(ans, solve(i+n-1));
	}
	printf("%d\n", ans);
	return 0;
}

