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
typedef unsigned int ui;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = 2e5+10;
const int mod = 1<<30;
const double eps = 1e-8;
using namespace std;

int n, m;
int T, tol;

int main() {
	scanf("%d", &T);
	while(T--) {
		double a, b, x, y;
		scanf("%lf%lf%lf%lf", &a, &b, &x, &y);
		double h = y - b*x/(-a);
		double ja = atan(b/a);
		double sina = sin(ja);
		int cnt = 0;
		double tmp = 8*h*sina;
		double dis = 0.0;
		double all = sqrt(x*x + b*x/(-a) * b*x/(-a));
		while(dis < all) {
			cnt++;
			dis += tmp * cnt;
		}
		printf("%d\n", cnt);		
	}
	return 0;
}
