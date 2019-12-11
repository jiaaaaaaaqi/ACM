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
double x1, y1, x2, y2, x3, y3;
double x4, y4, x5, y5, x6, y6;

int sgn(double x) {
	if(fabs(x)<=eps)	return 0;
	else	return x>0 ? 1 : -1;
}
struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) {
		x = _x, y = _y;
	}
	double operator * (Point a) {
		return x*a.x + y*a.y;
	}
	double operator ^ (Point a) {
		return x*a.y - y*a.x;
	}
	Point operator - (Point a) {
		return Point(x-a.x, y-a.y);
	}
};
struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s, e = _e;
	}
	int segcseg(Line v) {
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2 && (d3^d4)==-2)	return 2;
		return (d1==0 && sgn((v.s-s)*(v.s-e)) <= 0) ||
			(d2==0 && sgn((v.e-s) * (v.e-e)) <= 0) ||
			(d3==0 && sgn((s-v.s) * (s-v.e)) <= 0) ||
			(d4==0 && sgn((e-v.s) * (e-v.e)) <= 0);
	}
};
struct Polygon {
	int n;
	Point p[maxn];
	void add(Point q) {
		p[++n] = q;
	}
	double area() {
		double ans = 0.0;
		for(int i=1; i<=n; i++) {
			ans += (p[i]^p[i%n+1]);
		}
		return fabs(ans)/2.0;
	}
};


int solve() {
	Line l1(Point(x1, y1), Point(x2, y2));
	Line l2(Point(x2, y2), Point(x3, y3));
	Line l3(Point(x3, y3), Point(x1, y1));
	Line l4(Point(x4, y4), Point(x5, y5));
	Line l5(Point(x5, y5), Point(x6, y6));
	Line l6(Point(x6, y6), Point(x4, y4));
	if(l1.segcseg(l4))	return 1;
	if(l1.segcseg(l5))	return 1;
	if(l1.segcseg(l6))	return 1;

	if(l2.segcseg(l4))	return 1;
	if(l2.segcseg(l5))	return 1;
	if(l2.segcseg(l6))	return 1;


	if(l3.segcseg(l4))	return 1;
	if(l3.segcseg(l5))	return 1;
	if(l3.segcseg(l6))	return 1;
	
	Polygon po;
	po.n = 0;
	double ans1 = 0.0, ans2 = 0.0;
	po.add(Point(x1, y1));
	po.add(Point(x2, y2));
	po.add(Point(x3, y3));
	ans1 = po.area();

	po.n = 0;
	po.add(Point(x1, y1));
	po.add(Point(x2, y2));
	po.add(Point(x4, y4));
	ans2 += po.area();

	po.n = 0;
	po.add(Point(x2, y2));
	po.add(Point(x3, y3));
	po.add(Point(x4, y4));
	ans2 += po.area();

	po.n = 0;
	po.add(Point(x1, y1));
	po.add(Point(x3, y3));
	po.add(Point(x4, y4));
	ans2 += po.area();

	if(fabs(ans1-ans2) <= eps)	return 2;
	else	return 3;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
		int flag = solve();
		if(flag == 1)	printf("intersect\n");
		else if(flag == 2)	printf("contain\n");
		else	printf("disjoint\n");
	}
	return 0;
}
/*
1
0 0 0 10 10 0 1 1 2 2 1 2
*/
