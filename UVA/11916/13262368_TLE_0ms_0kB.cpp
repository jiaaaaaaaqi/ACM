#include<stdio.h>
#include<string.h>
#include<algorithm>
#define mod 100000007
typedef long long int ll;

using namespace std;

struct Node {
	int x;
	int y;
};
Node node[505];
int m, k, b, r;

ll fast_mul(ll a, ll b) {
	ll ans = 0;
	while(b) {
		if(b&1)
			ans = (ans + a) % mod;
		a = (a + a) % mod;
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

bool find(int i) {
	for(int j=1; j<=b; j++) {
		if(node[j].x-node[i].x == 1 && node[j].y == node[j].y)
			return true;
	}
	return false;
}

ll count(int maxn) {
	ll n = m;
	for(int i=1; i<=b; i++) {
		if(node[i].x != maxn && !find(i))
			n++;
		if(node[i].x == 1)
			n--;
	}
	ll ans = fast_mul(fast_pow(k, n), fast_pow(k-1, maxn*m-b-n));
	return ans;
}

ll log_pow(ll a, ll b) {

}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &m, &k, &b, &r);
		int maxn = 1 ;
		for(int i=1; i<=b; i++) {
			scanf("%d%d", &node[i].x, &node[i].y);
			maxn = max(maxn, node[i].x);
		}
		ll pre = count(maxn);
		if(pre == r) {
			printf("Case %d: %lld\n",cas++, maxn);
		} else {
			int x = 0;
			for(int i=1; i<=b; i++) {
				if(node[i].x == maxn) {
					x++;
				}
			}
			pre = fast_mul(pre, fast_pow(k, x));
			pre = fast_mul(pre, fast_pow(k-1, m-x));
			if(pre == r) {
			printf("Case %d: %lld\n",cas++, maxn+1);
			} else {
				ll p = fast_pow(k-1, m);
				pre = fast_pow(pre, mod-2);
				ll cnt = fast_mul(pre, r);
//				ll ans = log_pow(p, cnt) + maxn;
				for(ll i=1; ; i++) {
					if(fast_pow(p, i) == cnt) {
					printf("Case %d: %lld\n",cas++, maxn+i+1);
						break;
					}
				}
//				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}