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
const int    maxn = 5e4 + 10;
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
	inline Point(double _x, double _y) {
		x = _x, y = _y;
	}
	inline Point operator - (Point a) const {
		return Point(x-a.x, y-a.y);
	}
	inline double operator ^ (Point a) const {
		return x*a.y - y*a.x;
	}
	inline double distance(Point p) const {
		return hypot(x-p.x, y-p.y);
	}
	inline bool operator < (Point a) const {
		return sgn(y-a.y)==0 ? sgn(x-a.x)<0 : y<a.y;
	}
	inline bool operator == (Point a) const {
		return sgn(x-a.x)==0 && sgn(y-a.y)==0;
	}
	inline double operator * (Point a) const {
		return x*a.x + y*a.y;
	}
};
struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s, e = _e;
	}
	inline bool pointseg(Point p) {
		return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <=0;
	}
};
struct Polygon {
	int n;
	Point p[maxn];
	Line l[maxn];
	inline void add(Point q) {
		p[++n] = q;
	}
	struct cmp {
		Point p;
		cmp(Point _p) {
			p = _p;
		}
		bool operator() (Point _a, Point _b) const {
			Point a = _a, b = _b;
			int d = sgn((a-p)^(b-p));
			if(d == 0) {
				return sgn(a.distance(p) - b.distance(p)) < 0;
			} else {
				return d>0;
			}
		}
	};
	void norm() {
		int id = 1;
		for(int i=2; i<=n; ++i) {
			if(p[i] < p[id])
				id = i;
		}
		swap(p[id], p[1]);
		sort(p+1, p+1+n, cmp(p[1]));
	}
	void Graham(Polygon &convex) {
		norm();
		mes(convex.p, 0);
		int &top = convex.n = 0;
		if(n == 1) {
			convex.p[++top] = p[1];
		} else if(n == 2) {
			convex.p[++top] = p[1];
			convex.p[++top] = p[2];
			if(convex.p[1] == convex.p[2])	top--;
		} else {
			convex.p[++top] = p[1];
			convex.p[++top] = p[2];
			for(int i=3; i<=n; ++i) {
				while(top>1 && sgn((convex.p[top]-convex.p[top-1])^
					(p[i]-convex.p[top-1])) <= 0)
						top--;
				convex.p[++top] = p[i];
			}
			if(top == 2 && convex.p[1] == convex.p[2])
				top--;
		}
	}
	void getline() {
		for(int i=1; i<=n; ++i) {
			l[i] = Line(p[i], p[i%n+1]);
		}
	}
	int inconvex(Point s) {
		/*
		点和凸包的关系
		2	边上
		1	内部
		0	外部
		*/
		Point p1 = p[1];
		Line l1 = Line(p[1], p[2]);
		Line l2 = Line(p[1], p[n]);
		if(l1.pointseg(s) || l2.pointseg(s))
			return 2;
		int l = 2, r = n-1;
		while(l<=r) {
			int mid = l+r>>1;
			int t1 = sgn((s-p1)^(p[mid]-p1));
			int t2 = sgn((s-p1)^(p[mid+1]-p1));
			if(t1 <= 0 && t2 >= 0) {
				int t3 = sgn((s-p[mid]) ^ (p[mid+1]-p[mid]));
				if(t3 < 0)	return 1;
				else if(t3 == 0)	return 2;
				return 0;
			}
			if(t1 > 0)	r = mid-1;
			else	l = mid+1;
		}
		return 0;
	}
} large, small, con;
inline int read() {
	int x = 0, f = 1;
	char s = getchar();
	while (s < '0' || s > '9') {
		if (s == '-')f = -1;
		s = getchar();
	}
	while (s >= '0' && s <= '9') {
		x = x * 10 + s - '0';
		s = getchar();
	}
	return x * f;
}
int main() {
	n = read();
	large.n = small.n = con.n = 0;
	int x, y;
	for(int i=1; i<=n; ++i) {
		x = read(), y =read();
		large.add(Point(1.0*x, 1.0*y));
	}
	m = read();
	for(int i=1; i<=m; ++i) {
		x = read(), y =read();
		small.add(Point(1.0*x, 1.0*y));
	}
	large.norm();
	large.Graham(con);
	int ans = 0;
	for(int i=1; i<=m; ++i) {
		if(con.inconvex(small.p[i])) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
