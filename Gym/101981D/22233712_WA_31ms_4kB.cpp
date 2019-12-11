/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sun 13 Oct 2019 10:22:23 PM CST
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
const int    maxn = 1e2 + 10;
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
	double x, y, z;
} p[maxn];

double distance(Point a, Point b) {
	double x = a.x-b.x;
	double y = a.y-b.y;
	double z = a.z-b.z;
	return sqrt(x*x+y*y+z*z);
}

void solve() {
	double ans = 1.0*INF;
	Point tmp;
	tmp = p[1];
	double step = 1000;
	while(step > eps) {
		int s = 1;
		for(int i=1; i<=n; i++) {
			if(distance(tmp, p[s]) < distance(tmp, p[i]))	s = i;
		}
		double dis = distance(tmp, p[s]);
		ans = min(ans, dis);
		tmp.x += (p[s].x-tmp.x)/dis*step;
		tmp.y += (p[s].y-tmp.y)/dis*step;
		tmp.z += (p[s].z-tmp.z)/dis*step;
		step *= 0.99;
	}
	printf("%.15f\n", ans);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
	}
	solve();
	return 0;
}

