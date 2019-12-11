#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>
#define mod 100000007

typedef long long int ll;
using namespace std;

ll m, k, b, r;
set<pair<ll,ll> > s;
ll x[510];
ll y[510];

ll fast_mul(ll a, ll b) {
	ll ans = 0;
	while(b) {
		if(b&1) {
			ans = (ans + a);
			if(ans > mod)
				ans -= mod;
		}
		a = (a + a);
		if(a > mod)
			a -= mod;
		b >>= 1;
	}
	return ans;
}

ll fast_pow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1)
			ans = fast_mul(ans, a);
		a = fast_mul(a, a);
		b >>= 1;
	}
	return ans;
}

ll count(ll maxn) {
	ll c = m;
	for(ll i=1; i<=b; i++) {
		if(x[i] != maxn && !s.count(make_pair(x[i]+1, y[i])))
			c++;
		if(x[i] == 1)
			c--;
	}
	ll ans = fast_mul(fast_pow(k, c), fast_pow(k-1, (ll)maxn*m-b-c));
	return ans;
}

void e_gcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
	} else {
		e_gcd(b, a%b, x, y);
		ll temp = y;
		y = x - a/b*y;
		x = temp;
	}
}

ll inv(ll a, ll n) {
	ll x, y;
	e_gcd(a, n, x, y);
	return (x+n) % n;
}

ll log_pow(ll a, ll b) {
	ll m, v, e, i;
	m = (ll)sqrt(mod+0.5);
	v = inv(fast_pow(a, m), mod-2);
	map<ll, ll> x;
	x[1] = 0;
	e = 1;
	for(i = 1 ; i < m ; i++) {
		e = fast_mul(e,a);
		if(!x.count(e))
			x[e] = i;
	}
	for(i = 0; i < m; i++) {
		if(x.count(b))
			return i*m + x[b];
		b = fast_mul(b, v);
	}
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		s.clear();
		scanf("%lld%lld%lld%lld", &m, &k, &b, &r);
		ll maxn = 1;
		for(ll i=1; i<=b; i++) {
			scanf("%lld%lld", &x[i], &y[i]);
			if(maxn < x[i])
				maxn = x[i];
			s.insert(make_pair(x[i],y[i]));
		}
		ll pre = count(maxn);
		if(pre == r) {
			printf("Case %d: %lld\n",cas++, maxn);
		}	 else {
			ll c = 0;
			for(ll i=1; i<=b; i++) {
				if(x[i] == maxn) {
					c++;
				}
			}
			maxn ++;
			pre = fast_mul(pre, fast_pow(k, c));
			pre = fast_mul(pre, fast_pow(k-1, m-c));
			if(pre == r) {
				printf("Case %d: %lld\n",cas++, maxn);
			} else {
				ll p = fast_pow(k-1, m);
				pre = inv(pre, mod);
				ll cnt = fast_mul(pre, r);
				ll ans = log_pow(p, cnt) + maxn;
				printf("Case %d: %lld\n",cas++, ans);
			}
		}
	}
	return 0;
}