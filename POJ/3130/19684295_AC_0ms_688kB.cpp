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
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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

int sgn(double x) {
	if(fabs(x) <= eps)	return 0;
	else	return x>0 ? 1 : -1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) {
		x = _x, y = _y;
	}
	Point operator - (Point a) {
		return Point(x-a.x, y-a.y);
	}
	Point operator / (double a) {
		return Point(x/a, y/a);
	}
	double operator ^ (Point a) {
		return x*a.y - y*a.x;
	}
}point[maxn];

struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s, e = _e;
	}
	bool parallel(Line v) {
		return sgn((e-s) ^ (v.e-v.s)) == 0;
	}
	Point crosspoint(Line v) {
		double a1 = (v.e-v.s) ^ (s-v.s);
		double a2 = (v.e-v.s) ^ (e-v.s);
		return Point((s.x*a2-e.x*a1), (s.y*a2-e.y*a1)) / (a2-a1);
	}
};

struct halfplane : public Line {
	double angle;
	halfplane() {}
	halfplane(Point _s, Point _e) {
		s = _s, e = _e;
	}
	halfplane(Line v) {
		s = v.s, e = v.e;
	}
	void calcangle() {
		angle = atan2(e.y-s.y, e.x-s.x);
	}
	bool operator < (halfplane b) const {
		return angle < b.angle;
	}
};

struct halfplanes {
	int n;
	halfplane hp[maxn];
	Point p[maxn];
	int q[maxn];
	int st, ed;
	void push(halfplane tmp) {
		hp[++n] = tmp;
	}
	void unique() {
		int m = 1;
		for(int i=2; i<=n; i++) {
			if(sgn(hp[i].angle - hp[i-1].angle) != 0) {
				hp[++m] = hp[i];
			} else if(sgn((hp[m-1].e-hp[m-1].s) ^ (hp[i].s-hp[m-1].s)) > 0) {
				hp[m] = hp[i];
			}
		}
		n = m;
	}
	bool halfplaneinsert() {
		for(int i=1; i<=n; i++) {
			hp[i].calcangle();
		}
		sort(hp+1, hp+1+n);
		unique();
		q[st=1] = 1;
		q[ed=2] = 2;
		p[2] = hp[1].crosspoint(hp[2]);
		for(int i=3; i<=n; i++) {
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[ed]-hp[i].s))<0)ed--;
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[st+1]-hp[i].s))<0)st++;
			q[++ed] = i;
			if(hp[i].parallel(hp[q[ed-1]]))return false;
			p[ed]=hp[i].crosspoint(hp[q[ed-1]]);
		}
		while(st<ed && sgn((hp[q[st]].e-hp[q[st]].s)^(p[ed]-hp[q[st]].s))<0)ed--;
		while(st<ed && sgn((hp[q[ed]].e-hp[q[ed]].s)^(p[st+1]-hp[q[ed]].s))<0)st++;
		if(st+1>=ed)return false;
		return true;
	}
} half;

int main() {
	while(scanf("%d", &n), n) {
		half.n = 0;
		for(int i=1; i<=n; i++) {
			scanf("%lf%lf", &point[i].x, &point[i].y);
		}
		for(int i=1; i<=n; i++) {
			half.push(halfplane(point[i], point[i%n+1]));
		}
		if(half.halfplaneinsert())	printf("1\n");
		else	printf("0\n");
	}
	return 0;
}
