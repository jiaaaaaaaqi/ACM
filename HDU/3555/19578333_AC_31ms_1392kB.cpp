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

ll n, m;
int cas, tol, T;

int bit[40];
ll dp[40][10][2];

ll dfs(int pos, int pre, bool flag, bool lead, bool limit) {
	if(pos==0)	return 1&&flag;
	if(!lead && !limit && dp[pos][pre][flag] != -1)
		return dp[pos][pre][flag];
	int up = limit ? bit[pos] : 9;
	ll ans = 0;
	for(int i=0; i<=up; i++) {
		if(flag) {
			ans += dfs(pos-1, i, flag, lead&&i==0, limit&&i==up);
		} else {
			if(i==9) {
				if(pre == 4)
					ans += dfs(pos-1, i, 1, lead&&i==0, limit&&i==up);
				else
					ans += dfs(pos-1, i, 0, lead&&i==0, limit&&i==up);
			} else {
				ans += dfs(pos-1, i, 0, lead&&i==0, limit&&i==up);
			}
		}
	}
	if(!lead && !limit)	dp[pos][pre][flag] = ans;
	return ans;
}

ll solve(ll x) {
	tol = 0;
	while(x) {
		bit[++tol] = x%10;
		x /= 10;
	}
	return dfs(tol, 0, 0, 1, 1);
}

int main() {
	mes(dp, -1);
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &n);
		ll ans = solve(n);
		printf("%lld\n", ans);
	}
	return 0;
}

/*
1
500
*/
