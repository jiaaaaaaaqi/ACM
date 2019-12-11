/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月27日 星期二 14时28分37秒
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

set<int> st;
map<int, int> dp[4005];
map<int, bool> vis;
int a[maxn];
int p[1000005];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		dp[i].clear();
	}
	int ans = 1;
	st.insert(a[1]);
	p[a[1]] = 1;
	for(int i=2; i<=n; i++) {
		for(auto aj : st) {
			int tmp = a[i]-aj;
			int j = p[aj];
			if(dp[j].count(-tmp)) {
				if(!dp[i].count(tmp) || dp[i][tmp]<=dp[j][-tmp]+1) {
					dp[i][tmp] = dp[j][-tmp]+1;
					ans = max(ans, dp[i][tmp]);
					vis[tmp] = 1;
				}
			}
			else {
				if(!vis.count(tmp)) {
					dp[i][tmp] = 2;
					ans = max(ans, dp[i][tmp]);
					vis[tmp] = 1;
				}
			}
		}
		st.insert(a[i]);
		p[a[i]] = i;
	}
	printf("%d\n", ans);
    return 0;
}
