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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

int sgn(int x) {
	if(abs(x) == 0)	return 0;
	else	return x > 0 ? 1 : -1;
}

struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) {
        x = xx, y = yy;
    }
    Point operator - (Point a) const {
        return Point(x-a.x, y-a.y);
    }
    int operator ^ (Point a) const {
		return x*a.y - y*a.x;
	}
	bool operator < (Point a) const {
		return sgn(y-a.y)==0 ? sgn(x-a.x)<0 : y<a.y;
	}
};

struct Polygon {
    int n;
    Point p[40];
    void add(Point q) {
        p[++n] = q;
    }
    struct cmp{
		Point p;
		cmp(Point pp) {
			p = pp;
		}
		bool operator () (Point _a, Point _b) const {
			Point a = _a, b = _b;
			int d = sgn((a-p) ^ (b-p));
			return d>0;
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
	bool isconvex() {
		bool s[3];
		mes(s, false);
		for(int i=1; i<=n; i++) {
			int j = i%n + 1;
			int k = j%n + 1;
			s[sgn((p[j]-p[i]) ^ (p[k]-p[i])) + 1] = true;
			if(s[0] && s[2])
				return false;
		}
		return true;
	}
} po, ppp;

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        ppp.n = 0;
        for(int i=1, x, y; i<=n; i++) {
            scanf("%d%d", &x, &y);
            ppp.add(Point(x, y));
        }
        ppp.norm();
        int ans = 0;
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                for(int k=j+1; k<=n; k++) {
                    for(int o=k+1; o<=n; o++) {
                        po.n = 0;
                        po.add(Point(ppp.p[i].x, ppp.p[i].y));
                        po.add(Point(ppp.p[j].x, ppp.p[j].y));
                        po.add(Point(ppp.p[k].x, ppp.p[k].y));
                        po.add(Point(ppp.p[o].x, ppp.p[o].y));
                        if(po.isconvex())	ans++;
                    }
                }
            }
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
