/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月19日 星期二 01时50分55秒
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
const int    maxn = 21;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn], b[maxn];
int dp[1<<maxn];

int main() {
	while(~scanf("%d", &n)) {
		mes(dp, -1);
		n--;
		dp[0] = 100;
		int mx = (1<<n)-1;
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &a[i], &b[i]);
		}
		scanf("%d", &m);
		for(int i=0; i<=mx; i++) {
			if(dp[i] == -1)	continue;
			for(int j=1; j<=n; j++) {
				if(i & (1<<(j-1)))	continue;
				if(dp[i] < a[j])	continue;
				int now = i | (1<<(j-1));
				dp[now] = max(dp[now], dp[i] - a[j] + b[j]);
				dp[now] = min(dp[now], 100);
			}
		}
		if(dp[mx] < m)	printf("try again\n");
		else	printf("clear!!!\n");
	}
	return 0;
}

