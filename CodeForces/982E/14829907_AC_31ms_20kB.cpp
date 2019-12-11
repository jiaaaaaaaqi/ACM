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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 500005;
const int maxm = 305;
using namespace std;

int n, m, tol, T;

ll e_gcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		ll d = e_gcd(b, a%b, x, y);
		ll tmp = y;
		y = x - a/b*y;
		x = tmp;
		return d;
	}
}

int main() {
    int x,y,vx,vy;
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &vx, &vy);
    if(vx == 0 && vy == 0) {
		printf("-1\n");
		return 0;
    }
    if(vx == 0) {
		if(x == n || x == 0) {
			if(vy == 1) 
				printf("%d %d\n", x, m);
			else 
				printf("%d %d\n", x, 0);
		} else {
			printf("-1\n");
		}
		return 0;
    }
    if(vy == 0) {
		if(y == m || y == 0) {
			if(vx == 1) 
				printf("%d %d\n", n, y);
			else
				printf("%d %d\n", 0, y);
		} else {
			printf("-1\n");
		}
		return 0;
    }
    bool fx = false;
    bool fy = false;
    if(vx == -1) {
		fx = true;
		x = n - x;
    }
    if(vy == -1) {
		fy = true;
		y = m - y;
    }
    ll a = n;
    ll b = m;
    ll c = x - y;
    ll xx, yy;
    ll d = e_gcd(a, b, xx, yy);
    if(c % d) {
		printf("-1\n");
		return 0;
    }
    ll r = b / d;
    ll cx = ((c/d) * xx % r + r + r - 1) %r + 1;
    ll cy = (cx * n - c) / m;
	ll ansx, ansy;
	if(cx & 1) {
		ansx = n;
	} else {
		ansx = 0;
	}
	if(cy & 1) {
		ansy = m;
	} else {
		ansy = 0;
	}
	if(fx)	ansx = (ll)n - ansx;
	if(fy)	ansy = (ll)m - ansy;
	printf("%lld %lld\n", ansx, ansy);
    return 0;
}
