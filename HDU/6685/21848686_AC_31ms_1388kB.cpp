/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sat 21 Sep 2019 04:37:03 PM CST
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

int a[maxn], bag[maxn];
bool dp[130];

int solve(int c1, int c2, int c3) {
	int cnt = 0;
	for(int i=1; i<=c1; i++)	bag[++cnt] = 10;
	for(int i=1; i<=c2; i++)	bag[++cnt] = 20;
	for(int i=1; i<=c3; i++)	bag[++cnt] = 50;
	mes(dp, 0);
	dp[0] = 1;
	for(int i=1; i<=cnt; i++) {
		for(int j=120; j>=bag[i]; j--) {
			dp[j] |= dp[j-bag[i]];
		}
	}
	int hun = 0;
	for(int i=1; i<=n; i++) {
		if(dp[a[i]%100+100]) {
			hun = max(hun, a[i]/100-1);
		} else if(dp[a[i]%100]) {
			hun = max(hun, a[i]/100);
		} else {
			hun = inf;
		}
	}
	return hun;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int flag = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			if(a[i] % 10)	flag = 1;
		}
		if(flag) {
			printf("-1\n");
			continue;
		}
		int ans = inf;
		for(int i=0; i<=1; i++) {
			for(int j=0; j<=3; j++) {
				for(int k=0; k<=1; k++) {
					ans = min(ans, i+j+k+solve(i, j, k));
				}
			}
		}
		if(ans == inf)	printf("-1\n");
		else	printf("%d\n", ans);
	}
	return 0;
}

