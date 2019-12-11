/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 02:54:06 PM CST
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
	double x, y;
};

double calc(Point a, Point b) {
	double x = a.x-b.x, y = a.y-b.y;
	return sqrt(x*x+y*y);
}

double w, g, h, r;
Point st, ed;
double judge(double m) {
	Point t = Point{m, r};
	return calc(st, t)+calc(ed, t);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%lf%lf%lf%lf", &w, &g, &h, &r);
		st = Point{0, g};
		ed = Point{w, h};
		double l = 0, r = w;
		while(r-l>eps) {
			double lmid = (l+r)/2.0;
			double rmid = (lmid+r)/2.0;
			if(judge(lmid) > judge(rmid))	l = lmid;
			else	r = rmid;
		}
		printf("%.8f %.8f\n", calc(st, ed), judge(l));
	}
	return 0;
}

