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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 2e6+5;
const int maxm = 1005000;
const int mod = 1e9+7;
using namespace std;

ll n, m;
int T, tol;
ll a[20];

ll dfs(ll nn, ll sum, ll cnt) {
    if(cnt < m-1 && nn == 0)	return 0;
    if(cnt == m-1) {
        if(dfs(nn + sum, 0, 0))	return 0;
        return 1;
    }
    for(int i=1; a[i]<=nn; i++) {
        if(dfs(nn/a[i], sum+nn%a[i], cnt+1))	return 1;
    }
    return 0;
}

int main() {
    a[0] = 1;
    for(int i=1; i<=19; i++)	a[i] = a[i-1]*10;
    while(~scanf("%lld%lld", &n, &m)) {
        int ans = dfs(n, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
