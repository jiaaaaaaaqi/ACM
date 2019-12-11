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
const int maxn = 1e5+5;
const int maxm = 1005000;
const int mod = 1e9+7;
using namespace std;

ll n;
int m;
int T, tol;
ll a[15];
ll ans;

void dfs(int x, bool flag, ll sum) {
    if(flag)	ans += (n-1)/sum;
    else	ans -= (n-1)/sum;
    for(int i=x+1; i<=m; i++) {
		if(a[i] == 0)	continue;
        dfs(i, !flag, sum*a[i]);
    }
}

int main() {
    while(~scanf("%lld%d", &n, &m)) {
		ans = 0;
		memset(a, 0, sizeof a);
        for(int i=1; i<=m; i++)	scanf("%lld", &a[i]);
        for(int i=1; i<=m; i++) {
			if(a[i] == 0)	continue;
			dfs(i, 1, a[i]);
        }
		printf("%I64d\n", ans);
    }
    return 0;
}
