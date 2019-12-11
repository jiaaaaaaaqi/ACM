/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月28日 星期四 14时33分09秒
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
const int    maxn = 17;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];
int dp[1<<maxn];

int ok(int x) {
	int l = 1, r = n;
	while(l<=r) {
		for(; l<=r; l++)	if(x & (1<<(l-1)))	break;
		for(; l<=r; r--)	if(x & (1<<(r-1)))	break;
		if(s[l] != s[r])	return inf;
		l++, r--;
	}
	return 1;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s+1);
		n = strlen(s+1);
		int mx = (1<<n)-1;
		for(int i=0; i<=mx; i++) {
			dp[i] = ok(i);
		}
		// for(int i=0; i<=mx; i++) {
		//     printf("vis[%d] = %d\n", i, vis[i]);
		// }
		dp[0] = 0;
		for(int i=1; i<=mx; i++) {
			for(int j=i; ; j=(j-1)&i) {
				dp[i] = min(dp[i], dp[j]+dp[i^j]);
				if(j==0)	break;
			}
			// printf("dp[%d] = %d\n", i, dp[i]);
		}
		printf("%d\n", dp[mx]);
	}
	return 0;
}

