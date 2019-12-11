/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月20日 星期三 01时11分42秒
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
const int    maxn = 2e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int f[20], bit[20];
ll dp[13][maxn];

void dfs(int si, int i, int st, int nst) {
	if(i == m+1) {
		dp[si+1][nst] += dp[si][st];
		return ;
	}
	if(bit[i] == 0) {
		if(i+2<=m && bit[i+1] == 0 && bit[i+2] == 0)
			dfs(si, i+3, st, nst);
		dfs(si, i+1, st, nst+2*f[i]);
	} else if(bit[i] == 1) {
		dfs(si, i+1, st, nst);
	} else {
		dfs(si, i+1, st, nst+f[i]);
	}
}

void calc(int state) {
	mes(bit, 0);
	int k = 0;
	while(state) {
		bit[++k] = state%3;
		state /= 3;
	}
}

int main() {
	f[1] = 1;
	for(int i=2; i<=10; i++)
		f[i] = f[i-1]*3;
	while(scanf("%d%d", &m, &n), n||m) {
		if(n*m % 3) {
			printf("0\n");
			continue;
		}
		int mx = 0;
		for(int i=1; i<=m; i++)	mx = mx*3+2;
		mes(dp, 0);
		dp[1][0] = 1;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=mx; j++) {
				if(!dp[i][j])	continue;
				calc(j);
				dfs(i, 1, j, 0);
			}
		}
		cout << dp[n+1][0] << endl;
	}
	return 0;
}

