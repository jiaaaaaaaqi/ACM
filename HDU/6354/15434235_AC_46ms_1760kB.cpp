#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100;
const int maxm = 200010;
const int mod = 998244353;
const double eps = 1e-8;
using namespace std;

int n, m;
int T, tol;

double dis(double x, double y) {
	return x*x + y*y;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		double x, y;
		double r, R;
		scanf("%d%lf", &m, &R);
		double ans = 2 * pi * R;
		while(m--) {
			scanf("%lf%lf%lf", &x, &y, &r);
			double d = dis(x, y);
			d = sqrt(d);
			if(d + r < R || d - r >= R)	continue;
			if(d + r == r) {
				ans += 2 * pi * r;
			} else {
				double p = (double)(r*r + x*x + y*y - R*R) / (2 * r * d);
				p = acos(p) * 2;
				ans += p * r;
				p = (double)(R*R + x*x + y*y - r*r) / (2 * R * d);
				p = acos(p) * 2;
				ans -= p * R;
			}
		}
		printf("%.20f\n", ans);
	}
	return 0;
}
