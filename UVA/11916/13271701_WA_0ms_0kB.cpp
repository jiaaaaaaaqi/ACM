#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<set>
#include<algorithm>
#define mod 100000007

typedef long long int ll;
using namespace std;

int m, k, b, r;
set<pair<int,int> > s;
int x[510];
int y[510];

ll fast_mul(ll a, ll b, ll md) {
	return a * b % md;
}

ll fast_pow(ll a, ll b, ll md) {
	ll ans = 1;
	while(b) {
		if(b&1)
			ans = fast_mul(ans, a, md);
		a = fast_mul(a, a, md);
		b >>= 1;
	}
	return ans;
}

int count(int maxn) {
	int c = m;
	for(ll i=0; i<b; i++) {
		if(x[i] != maxn && !s.count(make_pair(x[i]+1, y[i])))
			c++;
		if(x[i] == 1)
			c--;
	}
	return fast_mul(fast_pow(k, c, mod), fast_pow(k-1, (ll)maxn*m-b-c, mod),mod);
}

ll e_gcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		ll d = e_gcd(b, a%b, x, y);
		ll temp = y;
		y = x - a/b*y;
		x = temp;
		return d;
	}
}

ll inv(ll a, ll n) {
	ll x, y;
	ll d = e_gcd(a, n, x, y);
	return d == 1 ? (x+n) % n : -1;
}

ll log_pow(ll a, ll b, ll n) {
	ll v, e, i;
	ll m = (int)sqrt(n+0.5);
	v = inv(fast_pow(a, m, n), n);
	map<int, int> x;
	x[1] = 0;
	e = 1;
	for(i = 1 ; i < m ; i++) {
		e = fast_mul(e, a, n);
		if(!x.count(e))
			x[e] = i;
	}
	for(i = 0; i < m; i++) {
		if(x.count(b))
			return i*m + x[b];
		b = fast_mul(b, v, n);
	}
	return -1;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		s.clear();
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		scanf("%d%d%d%d", &m, &k, &b, &r);
		int maxn = 1;
		for(int i=0; i<b; i++) {
			scanf("%d%d", &x[i], &y[i]);
			if(maxn < x[i])
				maxn = x[i];
			s.insert(make_pair(x[i],y[i]));
		}
		int pre = count(maxn);
		if(pre == r) {
			printf("Case %d: %d\n",cas++, maxn);
			continue;
		} else {
			maxn++;
			int c = 0;
			for(int i=0; i<b; i++) {
				if(x[i] == maxn) {
					c++;
				}
			}
			pre = fast_mul(pre, fast_pow(k, c, mod), mod);
			pre = fast_mul(pre, fast_pow(k-1, m-c, mod), mod);
			if(pre == r) {
				printf("Case %d: %d\n",cas++, maxn);
				continue;
			} else {
				printf("Case %d: %lld\n",cas++, log_pow(fast_pow(k-1, m, mod),fast_mul(r, inv(pre, mod), mod), mod) + maxn);
			}
		}
	}
	return 0;
}
/*
int doit(int maxn)
{
    int cnt = count(maxn);
    if(cnt == r) 
		return maxn;
    int c = 0;
    for(int i = 0 ; i < b ; i++)
        if(x[i] == maxn)
			c++;
	maxn++;
	cnt = fast_mul(cnt, fast_pow(k, c, mod), mod);
    cnt = fast_mul(cnt, fast_pow(k-1, m-c, mod), mod);
    if(cnt == r) 
		return maxn;
    return log_pow(fast_pow(k-1, m, mod),fast_mul(r, inv(cnt, mod), mod), mod) + maxn;
}*/
/*
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
        scanf("%d%d%d%d",&m, &k, &b, &r);
        s.clear();
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
		int maxn = 1;
        for(int i = 0 ; i < b ; i++){
            scanf("%d%d", &x[i], &y[i]);
            if(x[i] > maxn) 
				maxn = x[i];
            s.insert(make_pair(x[i], y[i]));
        }
        printf("Case %d: %d\n",cas++,(int)doit(maxn));
    }
    return 0;
}
*/
