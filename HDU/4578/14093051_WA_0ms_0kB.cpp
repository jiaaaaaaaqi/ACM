#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int mod = 10007;

int n, m;
ll sum1[maxn << 2];
ll sum2[maxn << 2];
ll sum3[maxn << 2];
ll lazy1[maxn << 2];//add
ll lazy2[maxn << 2];//mul
ll lazy3[maxn << 2];//set

void init() {
	memset(sum1, 0, sizeof(sum1));
	memset(sum2, 0, sizeof(sum2));
	memset(sum3, 0, sizeof(sum3));
}

void pushup(int root) {
	sum1[root] = sum1[root << 1] + sum1[root << 1 | 1];
	sum2[root] = sum2[root << 1] + sum2[root << 1 | 1];
	sum3[root] = sum3[root << 1] + sum3[root << 1 | 1];
	sum1[root] %= mod;
	sum2[root] %= mod;
	sum3[root] %= mod;
}

void pushdown(int root, ll lnum, ll rnum) {
	if(lazy3[root]) {
		ll x = lnum % mod;
		ll y = rnum % mod;
		lazy1[root << 1] = lazy1[root << 1 | 1] = 0;
		lazy2[root << 1] = lazy2[root << 1 | 1] = 1;
		lazy3[root << 1] = lazy3[root << 1 | 1] = lazy3[root];
		ll tmp = lazy3[root] % mod;
		sum1[root << 1] = tmp * x % mod;
		sum1[root << 1 | 1] = tmp * y % mod;
		tmp = lazy3[root] * lazy3[root] % mod;
		sum2[root << 1] = tmp * x % mod;
		sum2[root << 1 | 1] = tmp * y % mod;
		tmp = (lazy3[root] * lazy3[root] % mod) * lazy3[root] % mod;
		sum3[root << 1] = tmp * x % mod;
		sum3[root << 1 | 1] = tmp * y % mod;
		lazy3[root] = 0;
	}
	if(lazy2[root] != 1) {
		lazy2[root << 1] *= lazy2[root];
		lazy2[root << 1] %= mod;
		lazy2[root << 1 | 1] *= lazy2[root];
		lazy2[root << 1 | 1] %= mod;
		if(lazy1[root << 1]) {
			lazy1[root << 1] *= lazy2[root];
			lazy1[root << 1] %= mod;
		}
		if(lazy1[root << 1 | 1]) {
			lazy1[root << 1 | 1] *= lazy2[root];
			lazy1[root << 1 | 1] %= mod;
		}
		ll tmp = lazy2[root] % mod;
		sum1[root << 1] = (sum1[root << 1] * tmp) % mod;
		sum1[root << 1 | 1] = (sum1[root << 1 | 1] * tmp) % mod;
		tmp = lazy2[root] * lazy2[root] % mod;
		sum2[root << 1] = sum2[root << 1] * tmp % mod;
		sum2[root << 1 | 1] = sum2[root << 1 | 1] * tmp % mod;
		tmp = tmp * lazy2[root] % mod;
		sum3[root << 1] = sum3[root << 1] * tmp % mod;
		sum3[root << 1 | 1] = sum3[root << 1 | 1] * tmp % mod;
		lazy2[root] = 1;
	}
	if(lazy1[root]) {
		lazy1[root << 1] += lazy1[root];
		lazy1[root << 1] %= mod;
		lazy1[root << 1 | 1] += lazy1[root];
		lazy1[root << 1 | 1] %= mod;
		ll x = lnum % mod;
		ll y = rnum % mod;
		ll tmp = (lazy1[root] * lazy1[root]) % mod * lazy1[root] % mod;
		sum3[root << 1] = (sum3[root << 1] + x * tmp % mod + 3 * lazy1[root]
		                   * ((sum2[root << 1] + sum1[root << 1] * lazy1[root]) % mod)) % mod;
		sum3[root << 1 | 1] = (sum3[root << 1 | 1] + y * tmp % mod + 3 * lazy1[root]
		                       * ((sum2[root << 1 | 1] + sum1[root << 1 | 1] * lazy1[root]) % mod)) % mod;
		tmp = lazy1[root] * lazy1[root] % mod;
		sum2[root << 1] = (sum2[root << 1] + tmp * x % mod
		                   + 2 * sum1[root << 1] * lazy1[root] % mod ) % mod;
		sum2[root << 1 | 1] = (sum2[root << 1 | 1] + tmp * y % mod
		                       + 2 * sum1[root << 1 | 1] * lazy1[root] % mod) % mod;
		tmp = lazy1[root] % mod;
		sum1[root << 1] = (sum1[root << 1] + x * tmp) % mod;
		sum1[root << 1 | 1] = (sum1[root << 1 | 1] + y * tmp) % mod;
		lazy1[root] = 0;
	}
}

void build(int left, int right, int root) {
	lazy1[root] = lazy3[root] = 0;
	lazy2[root] = 0;
	if(left == right) {
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root);
	return ;
}

void update(int left, int right, int prel, int prer, int val, int root, int id) {
	if(prel <= left && right <= prer) {
		ll num = right - left + 1;
		if(id == 3) {
			lazy3[root] = val;
			lazy2[root] = 1;
			lazy1[root] = 0;
			ll tmp = val;
			sum1[root] = num * tmp % mod;
			tmp = val * val % mod;
			sum2[root] = num * tmp % mod;
			tmp = val * val % mod * val % mod;
			sum3[root] = num * tmp % mod;
		} else if(id == 2) {
			lazy2[root] = val % mod;
			if(lazy1[root])
				lazy1[root] = (lazy1[root] * val) % mod;
			ll tmp = val;
			sum1[root] = (sum1[root] * tmp) % mod;
			tmp = val * val % mod;
			sum2[root] = (sum2[root] * tmp) % mod;
			tmp = val * val % mod * val % mod;
			sum3[root] = (sum3[root] * tmp) % mod;
		} else if(id == 1) {
			lazy1[root] += val;
			ll tmp = val * val % mod * val % mod;
			sum3[root] = (sum3[root] + num * tmp % mod + 3 * val *
			              (sum2[root] + sum1[root] * val)) % mod;
			tmp = val * val % mod;
			sum2[root] = (sum2[root] + num * tmp % mod + 2 * val * sum1[root]) % mod;
			tmp = val;
			sum1[root] = (sum1[root] + tmp * num % mod) % mod;
		}
		return ;
	}
	int mid = (left + right) >> 1;
	pushdown(root, mid - left + 1, right - mid);
	if(prer <= mid)
		update(left, mid, prel, prer, val, root << 1, id);
	else if(prel > mid)
		update(mid + 1, right, prel, prer, val, root << 1 | 1, id);
	else {
		update(left, mid, prel, prer, val, root << 1, id);
		update(mid + 1, right, prel, prer, val, root << 1 | 1, id);
	}
	pushup(root);
	return ;
}

ll query(int left, int right, int prel, int prer, int root, int p) {
	if(prel <= left && right <= prer) {
		if(p == 1)
			return sum1[root] % mod;
		else if(p == 2)
			return sum2[root] % mod;
		else if(p == 3)
			return sum3[root] % mod;
	}
	int mid = (left + right) >> 1;
	pushdown(root, mid - left + 1, right - mid);
	if(prer <= mid)
		return query(left, mid, prel, prer, root << 1, p);
	else if(prel > mid)
		return query(mid + 1, right, prel, prer, root << 1 | 1, p);
	else
		return (query(left, mid, prel, prer, root << 1, p)
		        + query(mid + 1, right, prel, prer, root << 1 | 1, p)) % mod;
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		build(1, n, 1);
		while(m--) {
			int id, prel, prer, val;
			scanf("%d%d%d%d", &id, &prel, &prer, &val);
			if(id != 4) {
				update(1, n, prel, prer, val, 1, id);
			} else if(id == 4) {
				int ans = query(1, n, prel, prer, 1, val);
				printf("%lld\n", ans % mod);
			}
		}
	}
	return 0;
}
