/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Tue 22 Oct 2019 11:11:10 PM CST
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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, L, R;
int cas, tol, T;

int a[maxn], sum[maxn];
int dp[maxn][maxn][maxn];

void init() {
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				dp[i][j][k] = inf;
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d%d", &n, &L, &R)) {
		init();
		sum[0] = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i-1]+a[i];
		}
		for(int i=1; i<=n; i++) {
			dp[i][i][1] = 0;
		}
		for(int i=1; i<n; i++) {
			dp[i][i+1][2] = 0;
			if(L<=2 && 2<=R)	dp[i][i+1][1] = a[i]+a[i+1];
		}
		// for(int i=1; i<=n; i++) {
		//     for(int j=i; j<=n; j++) {
		//         for(int k=1; k<=j-i+1; k++) {
		//             printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
		//         }
		//     }
		// }
		for(int d=3; d<=n; d++) {
			for(int i=1, j=d; j<=n; i++, j++) {
				for(int k=i; k<j; k++) {
					int bex = max(1, L-(j-k));
					int edx = min(k-i+1, R-1);
					int bey = L-bex;
					int edy = R-bex;
					// printf("k=%d\n", k);
					// printf("bex=%d edx=%d\n", bex, edx);
					// printf("bey=%d edy=%d\n", bey, edy);
					if(bex > edx)	continue;
					multiset<int> st;
					for(int y=bey; y<=edy; y++) {
						if(y > j-k)	break;
						st.insert(dp[k+1][j][y]);
					}
					for(int x=bex; x<=edx; x++) {
						dp[i][j][1] = min(dp[i][j][1], dp[i][k][x]+*(st.begin()));
						if(edy<=j-k)	st.erase(st.find(dp[k+1][j][edy]));
						edy--, bey--;
						if(bey>=1)	st.insert(dp[k+1][j][bey]);
					}
					if(dp[i][j][1] != inf)	dp[i][j][1] += sum[j]-sum[i-1];
				}
				for(int k=2; k<=d; k++) {
					for(int x=i+k-2; x<j; x++) {
						dp[i][j][k] = min(dp[i][j][k], dp[i][x][k-1] + dp[x+1][j][1]);
					}
				}
			}
		}
		if(dp[1][n][1] == inf)	printf("0\n");
		else	printf("%d\n", dp[1][n][1]);
	}
	return 0;
}

