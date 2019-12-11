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
const int maxn = 1e5+50;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n;
ll m;
int T, tol;
int a[12];
ll ans = 0;

void dfs(int idx, bool flag, ll sum) {
	if(m / sum == 0)	return ;
	if(flag)	ans += m / sum;
	else		ans -= m / sum;
	for(int i=idx+1; i<=n; i++) {
		dfs(i, !flag, sum * a[i] / __gcd(sum, 1ll * a[i]));
	}
	return ;
}

int main() {
    while(~scanf("%d%lld", &n, &m)) {
		memset(a, 0, sizeof a);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		ans = 0;
		for(int i=1; i<=n; i++) {
			dfs(i, 1, 1ll * a[i]);
		}
		printf("%lld\n", ans);
    }
    return 0;
}
