#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))
#define fi		first
#define	se		second
#define INOPEM  freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5;
const int    maxm = 1e9+10;
const int    mod  = 1e9+7;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int T, tol;
ull dp[25][25][25];

int main() {
    int a, b;
    while(~scanf("%d%d%d", &n, &a, &b)) {
		dp[0][0][0] = 1;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=a; j++) {
				for(int k=0; k<=b; k++) {
					for(int jj=0; jj<=j; jj++) {
						for(int kk=0; kk<=k; kk++) {
							dp[i][j][k] += dp[i-1][jj][kk];
						}
					}
				}
			}
		}
		ull ans = 0;
		for(int i=0; i<=a; i++)	for(int j=0; j<=b; j++)	ans += dp[n][i][j];
		cout << ans << endl;
    }
    return 0;
}
