/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年12月05日 星期四 15时25分06秒
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
#define  pid        pair<int, double>

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
	return x>0 ? 1 : -1;
}
struct Point {
	double x, y, z;
};
struct Circle {
	Point p;
	double r;
};

double calc(Point a, Point b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

double get(double t) {
	return acos(t)*180.0/pi;
}

double solve(Point a, Point b, Point c, double r) {
	double ab2 = calc(a, b);
	double ac2 = calc(a, c);
	double bc2 = calc(b, c);
	double ab = sqrt(ab2), ac = sqrt(ac2), bc = sqrt(bc2);
	if(sgn(bc2) == 0)	return bc;
	double cos_abc = (bc2+ab2-ac2)/(2*bc*ab);
	double cos_acb = (bc2+ac2-ab2)/(2*bc*ac);
	if(cos_abc<=0||cos_acb<=0)	return bc;
	double be = ab*cos_abc;
	double R = ab2-be*be;
	if(sgn(R-r*r)>=0)	return bc;
	double bp = sqrt(ab2-r*r), cq = sqrt(ac2-r*r);
	double cos_bap = r/ab, cos_caq = r/ac;
	double cos_bac = (ac2+ab2-bc2)/(2*ab*ac);
	double angle = get(cos_bac)-get(cos_bap)-get(cos_caq);
	return pi*r*angle/180+bp+cq;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		double x, y, z, r;
		scanf("%lf%lf%lf%lf", &x, &y, &z, &r);
		Circle cr = {{x, y, z}, r};
		scanf("%lf%lf%lf", &x, &y, &z);
		Point s = {x, y, z};
		scanf("%lf%lf%lf", &x, &y, &z);
		Point e = {x, y, z};
		double ok = solve(cr.p, s, e, cr.r);
		printf("%.8f\n", ok);
	}
    return 0;
}

