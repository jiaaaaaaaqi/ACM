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
const int INF = 1e18+10;
const int maxn = 1e5+50;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

ll n, m;
int T, tol;
ll a[20];
ll b[505];
ll ans;

void init() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    if(a == -1 || b == -1)	return -1;
    ll g = gcd(a, b);
    if(INF/b < a/g)		return -1;
    return a/g*b;
}

void dfs(int idx, bool flag, ll sum, ll x, ll lc) {
    if(sum == -1)	sum = INF;
    ll tmp = lcm(sum, lc);
    if(tmp == -1)	tmp = INF;
    if(flag)	ans += x / sum - x / tmp;
    else		ans -= x / sum - x / tmp;
    for(int i=idx+1; i<=n; i++) {
        dfs(i, !flag, lcm(sum, a[i]), x, lc);
    }
    return ;
}

int main() {
    ll l, r;
    while(cin >> n >> m >> l >> r) {
        init();
        if(n + m + l + r == 0)	break;
        for(int i=1; i<=n; i++)	cin >> a[i];
        ll lc = 1;
        for(int i=1; i<=m; i++) {
            cin >> b[i];
            lc = lcm(lc, b[i]);
        }
        ll sum = 0;
        ans = 0;
        for(int i=1; i<=n; i++) {
            dfs(i, 1, a[i], r, lc);
        }
        sum += ans;
        ans = 0;
        for(int i=1; i<=n; i++) {
            dfs(i, 1, a[i], l-1, lc);
        }
        sum -= ans;
        cout << sum << endl;
    }
    return 0;
}
