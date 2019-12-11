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

inline int cmp1(Point a, Point b) {
	ll d = a.x*b.y-b.x*a.y;
	if(d==0)	return a.x<b.x;
	else	return d>0;
}

inline int Qua(Point a) {
	if(a.x>0 && a.y>=0)	return 1;
	if(a.x<=0 && a.y>0)	return 2;
	if(a.x<0 && a.y<=0)	return 3;
	if(a.x>=0 && a.y<0)	return 4;
}

inline ll area(Point a, Point b, Point c) {
	ll x1 = b.x-a.x, y1 = b.y-a.y;
	ll x2 = c.x-a.x, y2 = c.y-a.y;
	ll ans = x1*y2 - x2*y1;
	return abs(ans);
}

inline ll solve() {
	int L = 1, R = 2;
	ll ans = 0;
	for(; L<=n; L++) {
		for(; R<=2*n; R++) {
			if(area(p[0], p[L], p[R])<area(p[0], p[L], p[R-1])) {
				R--;
				break;
			}
		}
		ans = max(ans, area(p[0], p[L], p[R]));
	}
	return ans;
}

inline int cmp(Point a, Point b) {
	a = a-p[0], b = b-p[0];
	if(Qua(a) == Qua(b))	return cmp1(a, b);
	else	return Qua(a)<Qua(b);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1, x, y; i<=n; i++) {
		scanf("%d%d", &x, &y);
		be[i] = Point{1ll*x, 1ll*y};
	}
	int id = 1;
	for(int i=2; i<=n; i++) {
		if(be[i]<be[id])	id = i;
	}
	be[0] = be[id];
	sort(be+1, be+1+n, cmp);
	int top = 0;
	if(n == 1) {
		p[++top] = be[1];
	} else if(n == 2) {
		p[++top] = be[1];
		p[++top] = be[2];
		if(be[1] == be[2])	top--;
	} else {
		p[++top] = be[1];
		p[++top] = be[2];
		for(int i=3; i<=n; i++) {
			while(top>1 && ((p[top]-p[top-1]) ^ (be[i]-p[top-1])) <= 0)
				top--;
			p[++top] = be[i];
		}
		if(top==2 && p[1]==p[2])	top--;
	}

	n = top;
	for(int i=1; i<=n; i++)	be[i] = p[i];
	ll ans = 0;
	tol = 0;
	for(int i=1; i<=n; i++) {
		p[0] = be[i];
		for(int j=1; j<=n; j++)	p[j] = be[j];
		sort(p+1, p+1+n, cmp);
		for(int j=1; j<=n; j++)	p[j+n] = p[j];
		// printf("p[0] = %lld %lld\n", p[0].x, p[0].y);
		// for(int j=1; j<=n; j++) {
		//     printf("%lld %lld\n", p[j].x, p[j].y);
		// }
		ans = max(ans, solve());
	}
	if(ans&1)	printf("%lld.50000\n", ans/2);
	else	printf("%lld.00000\n", ans/2);
	return 0;
}

