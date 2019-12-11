#include<map>
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
const int maxn = 1005;
const int maxm = 1<<11;
const int mod = 200;
using namespace std;

int n, m, tol;
double num1[1005];
double num2[1005];
double num3[1005];
double num4[1005];

bool cmp(const double a, const double b) {
	return b < a;
}

int main() {
	double x, y;
	int n;
	while(~scanf("%lf%lf%d", &x, &y, &n)) {
	double ans = 0;
		double x1, y1;
		double x2, y2;
		for(int i=0; i<n; i++) {
			double z;
			scanf("%lf%lf", &x1, &y1);
			x2 = 0, y2 = 0;
			z = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			num1[i] = sqrt(z);
			x2 = 0, y2 = y;
			z = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			num2[i] = sqrt(z);
			x2 = x, y2 = 0;
			z = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			num3[i] = sqrt(z);
			x2 = x, y2 = y;
			z = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			num4[i] = sqrt(z);
		}
		sort(num1, num1 + n, cmp);
		sort(num2, num2 + n, cmp);
		sort(num3, num3 + n, cmp);
		sort(num4, num4 + n, cmp);
		ans = max(ans, num1[1]);
		ans = max(ans, num2[1]);
		ans = max(ans, num3[1]);
		ans = max(ans, num4[1]);
		printf("%.17lf\n", ans);
	}
	return 0;
}
