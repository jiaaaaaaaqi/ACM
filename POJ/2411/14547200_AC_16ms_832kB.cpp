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
        for (int i=1; i<=m; i++) {	//外层for循环遍历每一列
            for (int j=0; j<(1<<n); j++)	//内层for遍历每一个列的所有状态
                if (dp[i][j]) {	//只要dp[i][j]方法数不为空，就执行dfs方法
                    dfs(i,0,j,0);
                }
        }
        printf("%lld\n", dp[m+1][0]);
    }
    return 0;
}
