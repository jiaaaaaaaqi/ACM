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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 5e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

double maps[maxn][maxn];
double a, b, c, k, l;

void solve(int x1, int y1, int x2, int y2) {
    a = y2-y1;
    b = x1-x2;
	c = y1*(x2-x1)+x1*(y1-y2);
    double tmp = sqrt(a*a+b*b);
    a /= tmp;
    b /= tmp;
	c /= tmp;
    k = 1.0*(y2-y1)/(x2-x1);
    l = y1-k*x1;
}

int get(double x) {
	return k*x+l;
}

int ok(int x, int y) {
	double dis = fabs(1.0*a*x+b*y+c);
	double r = maps[x][y];
	if(r >= dis)	return 1;
	else	return 0;
}

int calc(int i, int y1, int y2) {
	int ans = 0;
	for(int j=y1; j<=y2; j++) {
		if(maps[i][j] < eps)	continue;
		ans += ok(i, j);
	}
	return ans;
}

int main() {
	for(int i=0; i<=501; i++) {
		for(int j=0; j<=501; j++) {
			maps[i][j] = 0.0;
		}
	}
	scanf("%d", &n);
	for(int i=1, x, y; i<=n; i++) {
		scanf("%d%d", &x, &y);
		scanf("%lf", &maps[x][y]);
	}
	scanf("%d", &T);
	int x1, y1, x2, y2;
	while(T--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1>x2 || (x1==x2 && y1>y2)) {
			swap(x1, x2);
			swap(y1, y2);
		}
		int ans = 0;
		if(x1 == x2) {
			for(int i=y1; i<=y2; i++) {
				if(maps[x1][i] > eps)	ans++;
			}
			printf("%d\n", ans);
		} else if(y1 == y2) {
			for(int i=x1; i<=x2; i++) {
				if(maps[i][y1] > eps)	ans++;
			}
			printf("%d\n", ans);
		} else {
			solve(x1, y1, x2, y2);
			if(y1 < y2) {
				ans += calc(x1, y1, ceil(get(x1+1)+eps));
				for(int x=x1+1; x<x2; x++) {
					ans += calc(x, floor(get(x-1)-eps), ceil(get(x+1)+eps));
				}
				ans += calc(x2, floor((get(x2-1)-eps)), y2);
				printf("%d\n", ans);
			} else {
				ans += calc(x1, floor((get(x1+1)-eps)), y1);
				for(int x=x1+1; x<x2; x++) {
					ans += calc(x, floor(get(x+1)-eps), ceil(get(x-1)+eps));
				}
				ans += calc(x2, y2, ceil((get(x2-1)+eps)));
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
