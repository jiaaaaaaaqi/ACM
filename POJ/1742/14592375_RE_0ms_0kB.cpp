#include<map>
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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 105;
const int maxm = 100005;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int dp[maxm];
int a[maxn];
int c[maxn];

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		for(int i=1; i<=n; i++)	scanf("%d", &c[i]);
		memset(dp, -1, sizeof dp);
		dp[0] = 0;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=m; j++) {
				if(dp[j] >= 0)
					dp[j] = c[i];
				else if(dp[j-a[i]] <= 0 || j < a[i])
					dp[j] = -1;
				else
					dp[j] = dp[j-a[i]] - 1;
			}
		}
		int ans = 0;
		for(int j=1; j<=m; j++) {
			if(dp[j] >= 0) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
