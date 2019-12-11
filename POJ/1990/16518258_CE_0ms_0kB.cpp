#include <bits/stdc++.h>
typedef long long int ll;
const int maxn = 5e5 + 10;
const ll mod = 2147483657;
using namespace std;

int n, m, cas, tol, T;

struct Node {
	ll v, p;
	bool operator < (Node a) const {
		return v < a.v;
	}
} node[maxn];

ll b[maxn];
ll sumpre[maxn];
ll cntpre[maxn];
ll sumsuf[maxn];

void init() {
	memset(sumpre, 0, sizeof(sumpre));
	memset(sumsuf, 0, sizeof(sumsuf));
	memset(cntpre, 0, sizeof(cntpre));
}

int lowbit(int x) {
	return x & (-x);
}

void sum_update_pre(int x, ll val) {
    for (int i = x; i <= n; i += lowbit(i))
        sumpre[i] += val;
}

ll sum_query_pre(int x) {
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += sumpre[i];
    return ans;
}

void sum_update_suf(int x, ll val) {
    for (int i = x; i > 0; i -= lowbit(i))
        sumsuf[i] += val;
}

ll sum_query_suf(int x) {
    ll ans = 0;
    for (int i = x; i <= n; i += lowbit(i))
        ans += sumsuf[i];
    return ans;
}

void cnt_update_pre(int x) {
    for (int i = x; i <= n; i += lowbit(i))
        cntpre[i]++;
}

ll cnt_query_pre(int x) {
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += cntpre[i];
    return ans;
}

int main() {
	while (~scanf("%d", &n)) {
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld", &node[i].v, &node[i].p);
			b[i] = node[i].p;
		}
		sort(b + 1, b + 1 + n);
		sort(node + 1, node + 1 + n);
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ll p = node[i].p, v = node[i].v;
			int pos = lower_bound(b + 1, b + 1 + n, p) - b;
			ll sum = sum_query_pre(pos) % mod;
			ll cnt = cnt_query_pre(pos) % mod;
			ans += ((cnt * p % mod - sum) % mod + mod) % mod * v;
			ans %= mod;
			sum = sum_query_suf(pos) % mod;
			cnt = i - 1 - cnt;
			ans += ((sum - cnt * p) % mod + mod) % mod * v;
			ans %= mod;
			sum_update_pre(pos, p);
			sum_update_suf(pos, p);
			cnt_update_pre(pos);
		}
		printf("%lld\n", ans % mod);
	}
	return 0;
}