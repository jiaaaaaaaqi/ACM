/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sun 13 Oct 2019 11:05:25 PM CST
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
}p[maxn];
double X, Y;

double distance(Point a, Point b) {
	double x = a.x-b.x;
	double y = a.y-b.y;
	return sqrt(x*x+y*y);
}

double calc(Point a) {
	double ans = 1.0*INF;
	for(int i=1; i<=n; i++) {
		ans = min(ans, distance(a, p[i]));
	}
	return ans;
}

Point solve() {
	double T = sqrt(X*X+Y*Y)/2.0;
	Point now;
	now.x = 1.0*rand()/RAND_MAX*X;
	now.y = 1.0*rand()/RAND_MAX*Y;
	double ans = calc(now);
	while(T > eps) {
		for(int i=1; i<=10; i++) {
			Point nex;
			double angle = 1.0*rand()/RAND_MAX*2.0*pi;
			nex.x = now.x + 1.0*cos(angle)*T;
			nex.y = now.y + 1.0*sin(angle)*T;
			if(nex.x>=0 && nex.x<=X && nex.y>=0 && nex.y<=Y) {
				double dis = calc(nex);
				if(dis > ans) {
					ans = dis;
					now = nex;
				}
			}
		}
		T = T*0.9;
	}
	return now;
}

int main() {
	// freopen("in", "r", stdin);
	srand(time(0));
	scanf("%d", &T);
	while(T--) {
		scanf("%lf%lf%d", &X, &Y, &n);
		for(int i=1; i<=n; i++) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		double dis = 0.0;
		Point ans;
		for(int i=1; i<=20; i++) {
			Point res = solve();
			if(dis < calc(res)) {
				dis = calc(res);
				ans = res;
			}
		}
		printf("The safest point is (%.1f, %.1f).\n", ans.x, ans.y);
	}
	return 0;
}

