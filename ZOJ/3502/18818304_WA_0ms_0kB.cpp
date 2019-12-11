/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月20日 星期三 00时33分02秒
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
const int    maxn = 12;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int p[maxn][maxn], dp[1<<maxn];
string f[1<<maxn];

void init() {
	mes(p, 0);
	mes(dp, 0);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d", &p[i][j]);
			}
		}
		int mx = (1<<n)-1;
		dp[0] = 0, f[0] = "";
		for(int i=0; i<mx; i++) {
			for(int j=1; j<=n; j++) {
				if(i & (1<<(j-1)))	continue;
				char ch = 'A' + j - 1;
				if(i==0 || dp[i | (1<<(j-1))] < p[j][j]+dp[i]) {
					dp[i | (1<<(j-1))] = dp[i] + p[j][j];
					f[i | (1<<(j-1))] = f[i] + ch;
				}
				for(int k=1; k<=n; k++) {
					if(i & (1<<(k-1))) {
						if(dp[i | (1<<(j-1))] < p[k][j]+dp[i]) {
							dp[i | (1<<(j-1))] = dp[i] + p[k][j];
							f[i | (1<<(j-1))] = f[i] + ch;
						}
					}
				}
			}
		}
		// for(int i=0; i<=2; i++) {
		//     printf("dp[%d] = %d\n", i, dp[i]);
		// }
		printf("%.2f\n", dp[mx]*1.0/100);
		cout << f[mx] << endl;
	}
	return 0;
}

