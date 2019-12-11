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
	Point(double _x, double _y) {
		x = _x, y = _y;
	}
	Point operator - (Point a) const {
		return Point(x-a.x, y-a.y);
	}
	double operator ^ (Point a) const {
		return x*a.y - y*a.x;
	}
	double distance(Point p) const {
		return hypot(x-p.x, y-p.y);
	}
	bool operator < (Point a) const {
		return sgn(y-a.y)==0 ? sgn(x-a.x)<0 : y<a.y;
	}
	bool operator == (Point a) const {
		return sgn(x-a.x)==0 && sgn(y-a.y)==0;
	}
	double operator * (Point a) const {
		return x*a.x + y*a.y;
	}
};
struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s, e = _e;
	}
	bool pointseg(Point p) {
		return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <=0;
	}
};
struct Polygon {
	int n;
	Point p[maxn];
	Line l[maxn];
	void add(Point q) {
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
		for(int i=2; i<=n; i++) {
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
			for(int i=3; i<=n; i++) {
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
		for(int i=1; i<=n; i++) {
			l[i] = Line(p[i], p[i%n+1]);
		}
	}
	int relationpoint(Point q) {
		for(int i=1; i<=n; i++) {
//			printf("p = %f %f\n", p[i].x, p[i].y);
//			printf("q = %f %f\n", q.x, q.y);
			if(p[i] == q)	return 3;
		}
		getline();
		for(int i=1; i<=n; i++) {
			if(l[i].pointseg(q))	return 2;
		}
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			int j = i%n+1;
			int k = sgn((q-p[j]) ^ (p[i]-p[j]));
			int u = sgn(p[i].y-q.y);
			int v = sgn(p[j].y-q.y);
			if(k>0 && u<0 && v>=0)	cnt++;
			if(k<0 && v<0 && u>=0)	cnt--;
		}
		return cnt!=0;
	}
} large, small, con;
bool vis[maxn];

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	large.n = small.n = con.n = 0;
	double x, y;
	for(int i=1; i<=n; i++) {
		scanf("%lf%lf", &x, &y);
		large.add(Point(x, y));
	}
	scanf("%d", & m);
	for(int i=1; i<=m; i++) {
		scanf("%lf%lf", &x, &y);
		small.add(Point(x, y));
	}
	large.norm();
	large.Graham(con);
	int ans = 0;
	mes(vis, 0);
	int T = min(10000, m);
	for(int i=1; i<=T; i++) {
		int id = rand()%m+1;
		if(vis[id]) id = rand()%m+1;
		vis[id] = 1;
		if(con.relationpoint(small.p[id]) != 0) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
