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
const int maxn = 13;
const int maxm = 1<<11;
const int mod = 200;
using namespace std;

int n, m, tol;
ll dp[maxn][maxm];

void dfs(int j, int i, int state, int nexstate) {
    if(i == n) {
        dp[j+1][nexstate] += dp[j][state];
        return ;
    }
    if((state & (1 << i)) > 0)
        dfs(j, i+1, state, nexstate);
    if((state & (1 << i)) == 0)
        dfs(j, i+1, state, nexstate | (1 << i));
    if((state & (1 << i)) == 0 && (state & (1 << (i + 1))) == 0 && i + 1 < n)
        dfs(j, i+2, state, nexstate);
}

int main() {
    while(scanf("%d%d", &n, &m), n||m) {
        memset(dp, 0, sizeof dp);
        dp[1][0] = 1;
        for(int j=1; j<=m; j++) {
			for(int k=0; k<(1<<n); k++) {
				if(dp[j][k]) {
					dfs(j, 0, k, 0);
				}
			}
        }
        printf("%lld\n", dp[m+1][0]);
    }
    return 0;
}
