#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
typedef long long int ll;

using namespace std;

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

int main() {
	ll a, b, c, x1, x2, y1, y2;
	scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);
	c = -c;
	if(c<0) {
		c = -c;
		a = -a;
		b = -b;
	}
	if(a<0) {
		a = -a;
		swap(x1, x2);
		x1 = -x1;
		x2 = -x2;
	}
	if(b<0) {
		b = -b;
		swap(y1, y2);
		y1 = -y1;
		y2 = -y2;
	}
	if(a==0 || b==0) {
		if(a == 0 && b == 0) {
			if(c!=0) {
				printf("0\n");
			} else {
				printf("%lld\n", (ll)((x2-x1+1) * (y2-y1+1)));
			}
		} else if(a == 0) {
			if(c%b==0 && c/b<=y2 && c/b>=y1) {
				printf("%lld\n", (ll)x2-x1+1);
			} else {
				printf("0\n");
			}
		} else {
			if(c%a==0 && c/a>=x1 && c/a<=x2) {
				printf("%lld\n", (ll)y2-y1+1);
			} else {
				printf("0\n");
			}
		}
	} else {
		ll x, y;
		ll d = e_gcd(a, b, x, y);
		if(c % d != 0) {
			printf("0\n");
		} else {
			double mulx = b;
			double muly = a;
			x *= c;
			y *= c;
			ll l1 = ceil((double)(x1-x) / mulx);
			ll l2 = ceil((double)(y-y2) / muly);
			ll r1 = floor((double)(x2-x) / mulx);
			ll r2 = floor((double)(y-y1) / muly);
			ll ans = (min(r1, r2) - max(l1, l2) + 1);
			if(ans < 0)
				printf("0\n");
			else
				printf("%lld\n", ans);
		}
	}
	return 0;
}