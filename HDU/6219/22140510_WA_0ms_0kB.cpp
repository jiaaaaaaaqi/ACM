/*************************************************************** 
    > File Name    : c.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年10月09日 星期三 13时22分13秒
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

int sgn(ll x) {
	if(abs(x) == 0)	return 0;
	return x>0 ? 1 : -1;
}

struct Point {
	ll x, y;
	Point() { }
	Point(ll xx, ll yy) {
		x = xx, y = yy;
	}
	bool operator == (Point a) const {
		return sgn(x-a.x)==0 && sgn(y-a.y)==0;
	}
	bool operator < (Point a) const {
		return sgn(y-a.y)==0 ? sgn(x-a.x)<0 : y<a.y;
	}
	Point operator - (Point a) const {
		return Point(x-a.x, y-a.y);
	}
	ll operator ^ (Point a) const {
		return x*a.y - y*a.x;
	}
	double distance(Point p) {
		return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
	}
};

struct Polygon {
	int n;
	Point p[maxn];
	Polygon() {
		n = 0;
	}
	void add(Point q) {
		p[++n] = q;
	}
	struct cmp {
		Point p;
		cmp(Point pp) {
			p = pp;
		}
		bool operator () (Point _a, Point _b) const {
			Point a = _a, b = _b;
			ll d = sgn((a-p) ^ (b-p));
			if(d == 0) {
				return sgn(a.distance(p)-b.distance(p)) < 0;
			} else {
				return d>0;
			}
		}
	};
	void norm() {
		int id = 1;
		for(int i=2; i<=n; i++) {
			if(p[i] < p[id])	id = i;
		}
		swap(p[id], p[1]);
		sort(p+1, p+1+n, cmp(p[1]));
	}
	void Graham(Polygon &convex) {
		norm();
		mes(convex.p, 0);
		int &top = convex.n = 0;
		if(n == 1)	convex.p[++top] = p[1];
		else if(n == 2) {
			convex.p[++top] = p[1];
			convex.p[++top] = p[2];
			if(convex.p[1] == convex.p[2])	top--;
		} else {
			convex.p[++top] = p[1];
			convex.p[++top] = p[2];
			for(int i=3; i<=n; i++) {
				while(top>1 && sgn((convex.p[top]-convex.p[top-1])^(p[i]-convex.p[top-1])) <= 0)
					top--;
				convex.p[++top] = p[i];
			}
			if(top==2 && convex.p[1]==convex.p[2])	top--;
		}
	}
	ll getarea() {
		ll sum = 0;
		for(int i=1; i<=n; i++) {
			sum += (p[i] ^ p[i%n+1]);
		}
		return abs(sum);
	}
} p, convex;

int main() {
    // freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		p.n = 0;
		for(int i=1; i<=n; i++) {
			ll x, y;
			scanf("%lld%lld", &x, &y);
			p.add(Point(x, y));
		}
		p.Graham(convex);
		ll ans = convex.getarea();
		printf("%d.", ans/2);
		if(ans & 1)	printf("5\n");
		else	printf("0\n");
	}
    return 0;
}

