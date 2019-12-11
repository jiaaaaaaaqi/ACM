/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月26日 星期一 14时23分57秒
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
const int    maxn = 3e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s1[maxn], s2[maxn];
bool dp[maxn][maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		mes(dp, 0);
		scanf("%s%s", s1+1, s2+1);
		n = strlen(s1+1), m = strlen(s2+1);
		dp[0][0] = 1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(dp[i][j])	continue;
				if(s2[j] == '.') {
					if(dp[i-1][j-1])	dp[i][j] = 1;
				} else if(s2[j] == '*') {
					if(dp[i][j-1]) {
						for(int k=i; k<=n; k++) {
							if(s1[k] != s1[i])	break;
							dp[k][j] = 1;
						}
					}
				} else {
					if(dp[i-1][j-1] && s1[i]==s2[j])	dp[i][j] = 1;
				}
			}
		}
		printf("%s\n", dp[n][m] ? "yes" : "no");
	}
    return 0;
}

