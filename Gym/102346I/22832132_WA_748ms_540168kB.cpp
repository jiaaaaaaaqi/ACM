/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Tue 12 Nov 2019 05:38:31 PM CST
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
const int    maxn = 4e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct E {
	int a, id;
	bool operator < (E x) const {
		return a < x.a;
	}
} e[maxn];
int maps[maxn][maxn];
int dp[2][maxn][maxn][maxn];

void solve() {
	for(int k=1; k<=n; k++)	for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
		dp[0][k][i][j] = dp[1][k][i][j] = maps[i][j];
	{
		int c = 0;
		for(int k=1; k<=n; k++) {
			if(k==1 || e[k].a != e[k-1].a)	c++;
			for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
				dp[0][c][i][j] = min(dp[0][c][i][j], dp[0][c-1][i][j]);
			int id = e[k].id;
			for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
				dp[0][c][i][j] = min(dp[0][c][i][j], dp[0][c][i][id]+dp[0][c][id][j]);
		}
		while(++c<=n) {
			for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
				dp[0][c][i][j] = dp[0][c-1][i][j];
		}
	}
	{
		int c = 0;
		for(int k=n; k>=1; k--) {
			if(k==n || e[k].a != e[k+1].a)	c++;
			for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
				dp[1][c][i][j] = min(dp[1][c][i][j], dp[1][c-1][i][j]);
			int id = e[k].id;
			for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
				dp[1][c][i][j] = min(dp[1][c][i][j], dp[1][c][i][id]+dp[1][c][id][j]);
		}
		while(++c<=n) {
			for(int i=1; i<=n; i++)	for(int j=1; j<=n; j++)
				dp[0][c][i][j] = dp[0][c-1][i][j];
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			for(int k=0; k<=n; k++)	dp[0][i][j][k] = dp[1][i][j][k] = inf;
			maps[i][j] = inf;
		}
	}
	for(int i=1; i<=n; i++) {
		scanf("%d", &e[i].a);
		e[i].id = i;
	}
	sort(e+1, e+1+n);
	for(int i=1; i<=m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		maps[u][v] = maps[v][u] = w;
	}
	solve();
	int q;scanf("%d", &q);
	while(q--) {
		int x, y, id, k;
		scanf("%d%d%d%d", &x, &y, &k, &id);
		if(dp[id][k][x][y] == inf)	printf("-1\n");
		else	printf("%d\n", dp[id][k][x][y]);
	}
	return 0;
}

