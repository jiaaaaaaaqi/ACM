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

double sgn(double x) {
	if(fabs(x) <= eps)	return 0;
	else	return x>0 ? 1 : -1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double a, double b) {
		x = a, y = b;
	}
	Point operator-(Point a) const {
		return Point(x-a.x, y-a.y);
	}
	double operator^(Point a) const {
		return x*a.y - y*a.x;
	}
	double operator*(Point a) const {
		return x*a.x + y*a.y;
	}
	double distance(Point p) const{
		return hypot(x-p.x, y-p.y);
	}
};

struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s, e = _e;
	}
	double length() {
		return s.distance(e);
	}
	double dispointtoline(Point p) {
		return fabs((p-s)^(e-s))/length();
	}
	double dispointtoseg(Point p) {
		if(sgn((p-s)*(e-s)) < 0 || sgn((p-e)*(s-e)) < 0)
			return min(p.distance(s), p.distance(e));
		return dispointtoline(p);
	}
};

struct Circle {
	Point p;
	double r;
	Circle() {}
	Circle(double _x, double _y, double _r) {
		p = Point(_x, _y), r = _r;
	}
	int relationseg(Line v) {
		double dst = v.dispointtoseg(p);
		if(sgn(dst-r) < 0)	return 2;
		else if(sgn(dst-r) == 0)	return 1;
		else	return 0;
	}
} circle[maxn];

int read() {
	int x=0, f=1;
	char s = getchar();
	while(s<'0' || s>'9') {
		if(s=='-')	f=-1;
		s = getchar();
	}
	while(s>='0'&&s<='9') {
		x = x*10+s-'0';
		s = getchar();
	}
	return x*f;
}
bool vis[maxn];

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	double x, y, r;
	for(int i=1; i<=n; ++i) {
		x=read(), y=read();
		scanf("%lf", &r);
		circle[i] = Circle(x, y, r);
	}
	scanf("%d", &T);
	while(T--) {
		double x1, y1, x2, y2;
		x1 = read();
		y1 = read();
		x2 = read();
		y2 = read();
		Line l(Point(x1, y1), Point(x2, y2));
		int ans = 0;
		int mx = min(2000, n);
		mes(vis, 0);
		for(int i=1; i<=mx; ++i) {
			int id = rand()%n+1;
			while(vis[id])	id = rand()%n+1;
			vis[id] = 1;
			if(circle[id].relationseg(l))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
