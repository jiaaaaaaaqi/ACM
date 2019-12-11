#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int mx = 1005;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;

double d[mx], s[mx];
int n;
double t;

double calc(double mid) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += d[i] / (s[i] + mid);
	}
	return sum;
}

int main() {
	scanf("%d%lf", &n, &t);
	double miny = inf;
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &d[i], &s[i]);
		miny = min(miny, s[i]);
	}
	
	double left = -miny, right = 2000, mid;
	//printf("left = %f\n",  left);
	while ((right - left) > eps) {
		mid = (left + right) / 2;
		if (calc(mid) < t) right = mid;
		else left = mid;
	}
	printf("%.9lf\n", left);
	return 0;
}