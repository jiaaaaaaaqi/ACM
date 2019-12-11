/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sat 31 Aug 2019 11:33:24 PM CST
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
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn];
ll sum[maxn];
vector<ll> vv;
ll bit[maxn];
ll dp[maxn];

int getid(ll x) {
    return lower_bound(vv.begin(), vv.end(), x)-vv.begin()+1;
}

void update(int x, ll v) {
    for(int i=x; i>=1; i-=lowbit(i)) {
        bit[i] = max(bit[i], v);
    }
}

ll query(int x) {
    ll ans = -INF;
    for(int i=x; i<=tol; i+=lowbit(i)) {
        ans = max(ans, bit[i]);
    }
    return ans;
}

bool ok(ll mid) {
    for(int i=0; i<=max(tol, n); i++) {
        dp[i] = 0;
        bit[i] = -INF;
    }
    update(getid(0), 0); 
    for(int i=1; i<=n; i++) {
        int v = getid(sum[i]-mid);
        ll pre = query(v);
		if(pre == -INF) continue;
        dp[i] = pre+1;
		update(getid(sum[i]), dp[i]);
		if(dp[i] >= m)	return true;
    }
	return false;
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        vv.clear();
        scanf("%d%d", &n, &m);
        sum[0] = 0;
        ll l, r;
        l = r = 0;
        for(int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
            if(a[i] > 0)    r += a[i];
            else    l += a[i];
            sum[i] = sum[i-1]+a[i];
            vv.pb(sum[i]);
        }
        vv.pb(0);
        sort(vv.begin(), vv.end());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		tol = vv.size();
		ll ans;
		while(l<=r) {
			ll mid = l+r>>1;
			if(ok(mid)) ans = mid, r=mid-1;
			else    l=mid+1;
		}
		printf("%lld\n", ans);
    }
    return 0;
}

