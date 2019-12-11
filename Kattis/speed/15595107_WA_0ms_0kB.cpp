#include <cstdio>
#include <cmath>
#include <algorithm>

#define double long double
using namespace std;
const int mx = 1005;
const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

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
	scanf("%d%Lf", &n, &t);
	double miny = 999999999.0;
	for (int i = 1; i <= n; i++) {
		scanf("%Lf%Lf", &d[i], &s[i]);
		if(miny > s[i])	miny = s[i];
	}

	double left = -miny, right = 20000.0, mid;
	//printf("left = %f\n",  left);
	while ((right - left) > eps) {
		mid = (left + right) / 2.0;
		if ((t-calc(mid)) > eps) right = mid;
		else left = mid+eps;
	}
	printf("%.9Lf\n", left);
	return 0;
}
