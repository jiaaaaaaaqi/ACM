/*************************************************************** 
	> File Name		: A.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 12:56:23 AM CST
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Point {
	ll x, y;
	bool operator == (Point a) const {
		return x==a.x && y==a.y;
	}
	Point operator - (Point a) const {
		return Point{x-a.x, y-a.y};
	}
} be[maxn], p[maxn];

int cmp1(Point a, Point b) {
	ll d = a.x*b.y-b.x*a.y;
	if(d==0)	return a.x<b.x;
	else	return d>0;
}

int Qua(Point a) {
	if(a.x>0 && a.y>=0)	return 1;
	if(a.x<=0 && a.y>0)	return 2;
	if(a.x<0 && a.y<=0)	return 3;
	if(a.x>=0 && a.y<0)	return 4;
}

ll area(Point a, Point b, Point c) {
	ll x1 = b.x-a.x, y1 = b.y-a.y;
	ll x2 = c.x-a.x, y2 = c.y-a.y;
	ll ans = x1*y2 - x2*y1;
	return abs(ans);
}

ll solve() {
	int L = 2, R = 3;
	ll ans = 0;
	for(; L<=n; L++) {
		if(p[L] == p[0])	continue;
		for(; R<=2*n; R++) {
			if(p[R] == p[L] || p[R]==p[0])continue;
			if(area(p[0], p[L], p[R])<area(p[0], p[L], p[R-1])) {
				R--;
				break;
			}
		}
		R = min(R, 2*n);
		ans = max(ans, area(p[0], p[L], p[R]));
		// if(ans == 592548499721629*2+1) {
		//     printf("%lld %lld\n", p[0].x, p[0].y);
		//     printf("%lld %lld\n", p[L].x, p[L].y);
		//     printf("%lld %lld\n", p[R].x, p[R].y);
		//     return ans;
		// }
	}
	return ans;
}

int cmp(Point a, Point b) {
	a = a-p[0], b = b-p[0];
	if(Qua(a) == Qua(b))	return cmp1(a, b);
	else	return Qua(a)<Qua(b);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(ll i=1, x, y; i<=n; i++) {
		scanf("%lld%lld", &x, &y);
		be[i] = Point{x, y};
		p[i] = Point{x, y};
	}
	ll ans = 0;
	int nn = n;
	for(int i=1; i<=nn; i++) {
		p[0] = be[i];
		for(int j=1; j<=n; j++)	p[j] = be[i+j-1];
		sort(p+1, p+1+n, cmp);
		for(int j=1; j<=n; j++)	p[j+n] = p[j];
		ans = max(ans, solve());
		n--;
		if(n<=2)	break;
	}
	if(ans&1)	printf("%lld.50000\n", ans/2);
	else	printf("%lld.00000\n", ans/2);
	return 0;
}

