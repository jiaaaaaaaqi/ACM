/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月18日 星期一 14时35分30秒
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

int a[20];
ll dp[35][16][5][2];

int main() {
	mes(a, 0);
	mes(dp, 0);
	for(int i=0; i<16; i++) {
		for(int j=1; j<=4; j++) {
			if(i & (1<<(j-1)))	a[i]++;
		}
	}
	dp[1][1][1][0] = 1;
	dp[1][2][2][0] = 1;
	dp[1][4][3][0] = 1;
	dp[1][8][4][0] = 1;
	for(int i=2; i<=31; i++) {
		for(int j=0; j<16; j++) {
			for(int k=1; k<=4; k++) {
				for(int z=1; z<=4; z++) {
					int now = j | (1<<(z-1));
					dp[i][now][z][1] += dp[i-1][j][k][1];
					if(abs(k-z) == 3) {
						dp[i][now][z][1] += dp[i-1][j][k][0];
					} else {
						dp[i][now][z][0] += dp[i-1][j][k][0];
					}
				}
			}
		}
	}
	for(int i=2; i<=31; i++) {
		ll ans = 0;
		for(int j=0; j<16; j++) {
			if(a[j] < 3)	continue;
			for(int k=1; k<=4; k++) {
				ans += dp[i][j][k][1];
			}
		}
		printf("N=%d: %lld\n", i, ans);
	}
}

