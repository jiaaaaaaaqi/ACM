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
const int    maxn = 5e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int dp[maxn][maxn];

int get(int x) {
	if(x<1)	x+=n;
	if(x>n)	x-=n;	
	return x;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) for(int j=1, x; j<=n; j++) {
		scanf("%d", &dp[i][j]);
	}
	for(int d=2; d<=n; d++) {
		for(int i=1, j=get(i+d); i<=n; i++, j=get(j+1)) {
			for(int x=get(i+1); x!=j; x=get(x+1)) {
				if(i==j && get(x+1)==j) {
					dp[i][j] = max(dp[i][j], dp[i][x]);
					continue;
				}
				int p = i==x ? 0 : dp[i][x];
				int q = get(x+1)==(j==i?get(j-1):j) ? 0 : dp[get(x+1)][j==i?get(j-1):j];
				dp[i][j] = max(dp[i][j], p+q);
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=n; i++)	ans = max(ans, dp[i][i]);
	printf("%d\n", ans);
	return 0;
}

