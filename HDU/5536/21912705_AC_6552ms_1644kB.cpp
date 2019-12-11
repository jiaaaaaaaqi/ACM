/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年09月25日 星期三 13时44分48秒
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

int a[maxn];
int node[maxn*40][2];
int cnt[maxn*40];

void insert(ll x, int val) {
	int root = 0;
	for(int i=33; i>=1; i--) {
		int k = (x&(1ll<<(i-1))) ? 1 : 0;
		if(node[root][k] == 0) {
			mes(node[tol], 0);
			cnt[tol] = 0;
			node[root][k] = tol++;
		}
		root = node[root][k];
		cnt[root] += val;
	}
}

ll dfs(int p, ll x, int root) {
	if(p == 0)	return 0;
	int k = (x&(1ll<<(p-1))) ? 1 : 0;
	if(k == 0) {
		if(node[root][1]!=0 && cnt[node[root][1]]) {
			return dfs(p-1, x, node[root][1]) + (1ll<<(p-1));
		} else if(node[root][0]!=0 && cnt[node[root][0]]) {
			return dfs(p-1, x, node[root][0]);
		} else {
			return 0;
		}
	} else {
		if(node[root][0]!=0 && cnt[node[root][0]]) {
			return dfs(p-1, x, node[root][0]) + (1ll<<(p-1));
		} else if(node[root][1]!=0 && cnt[node[root][1]]) {
			return dfs(p-1, x, node[root][1]);
		} else {
			return 0;
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		tol = 1;
		mes(node[0], 0);
		cnt[0] = 0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			insert(a[i], 1);
		}
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			insert(a[i], -1);
			for(int j=1; j<=n; j++) {
				if(i==j)	continue;
				insert(a[j], -1);
				ll x = dfs(33, a[i]+a[j], 0);
				ans = max(ans, x);
				insert(a[j], 1);
			}
			insert(a[i], 1);
		}
		printf("%lld\n", ans);
	}
    return 0;
}

