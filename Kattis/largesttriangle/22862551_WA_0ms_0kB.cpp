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

int sgn(ll x) {
	if(x == 0)	return 0;
	return x<0 ? -1 : 1;
}
struct Point {
	ll x, y;
	bool operator < (Point a) const {
		return y==a.y ? x<a.x : y<a.y;
	}
	bool operator == (Point a) const {
		return x==a.x && y==a.y;
	}
	Point operator - (Point a) const {
		return Point{x-a.x, y-a.y};
	}
	ll operator ^ (Point a) const {
		return x*a.y - a.x*y;
	} 
} be[maxn], p[maxn];

ll distance(Point a, Point b) {
	ll x = a.x-b.x, y = a.y-b.y;
	return x*x+y*y;
}
struct cmp {
	Point p;
	cmp(Point _p) {
		p = _p;
	}
	bool operator () (Point _a, Point _b) const {
		Point a = _a, b = _b;
		ll d = ((a-p)^(b-p));
		if(d==0)	return distance(a, p)<distance(b, p);
		else	return d>0;
	}
};

ll area(Point a, Point b, Point c) {
	ll x1 = b.x-a.x, y1 = b.y-a.y;
	ll x2 = c.x-a.x, y2 = c.y-a.y;
	ll ans = x1*y2 - x2*y1;
	return abs(ans);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(ll i=1, x, y; i<=n; i++) {
		scanf("%lld%lld", &x, &y);
		be[i] = Point{x, y};
	}
	int id = 1;
	for(int i=2; i<=n; i++) {
		if(be[i] < be[id])	id = i;
	}
	swap(be[id], be[1]);
	sort(be+1, be+1+n, cmp(be[1]));
	int top = 0;
	p[++top] = be[1];
	p[++top] = be[2];
	for(int i=3; i<=n; i++) {
		while(top>1 && sgn((p[top]-p[top-1]) ^ (be[i]-p[top-1])) <= 0)
			top--;
		p[++top] = be[i];
	}
	if(top==2 && p[1]==p[2])	top--;
	n = top;
	// cout << n << endl;
	ll ans = 0;
	for(int i=1; i<=n; i++) {
		int t = i+2;
		for(int j=i+1; j<=n; j++) {
			while(t<n && area(p[i], p[j], p[t]) < area(p[i], p[j], p[t+1]))
				t++;
			ans = max(ans, area(p[i], p[j], p[t]));
		}
	}
	printf("%.5f\n", 0.5*ans);
	return 0;
}

