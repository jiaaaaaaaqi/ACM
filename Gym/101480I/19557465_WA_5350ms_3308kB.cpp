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
const long double pi   = acos(-1.0);
const long double eps  = 1e-5;
using namespace std;

int n, m;
int cas, tol, T;
long double a, b, c;
bool vis[maxn][maxn];
long double vv[maxn][maxn];

int sgn(long double x) {
	if(fabs(x) <= eps)	return 0;
	else	return x>0 ? 1 : -1;
}

void solve(long double x1, long double y1, long double x2, long double y2) {
	a = y2-y1;
	b = x1-x2;
	double tmp = sqrt(a*a+b*b);
	a /= tmp;
	b /= tmp;
	c = -a*x1-b*y1;
}

long double get(long double x) {
	return -(c+a*x)/b;
}

bool ok(long double x, long double y, long double a, long double b, long double c) {
	long double r = vv[(int)x][(int)y] * vv[(int)x][(int)y];
	long double dis = fabs(a*x+b*y+c);
	dis = dis*dis;
	dis /= (a*a+b*b);
	if(sgn(dis-r) <= 0)	return 1;
	else	return 0;
}

int main() {
	for(int i=0; i<=506; i++) {
		for(int j=0; j<=505; j++) {
			vv[i][j] = 0.0;
		}
	}
	scanf("%d", &n);
	double r;
	for(int i=1, x, y; i<=n; i++) {
		scanf("%d%d%lf", &x, &y, &r);
		vv[x][y] = r;
	}
	scanf("%d", &T);
	int x1, y1, x2, y2;
	while(T--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = 0;
		if(x1 == x2) {
			if(y1 > y2)	swap(y1, y2);
			for(int j=y1; j<=y2; j++) {
				if(vv[x1][j] != 0)	ans++;
			}
			printf("%d\n", ans);
		} else if(y1 == y2) {
			if(x1 > x2)	swap(x1, x2);
			for(int i=x1; i<=x2; i++) {
				if(vv[i][y1] != 0)	ans++;
			}
			printf("%d\n", ans);
		} else {
			if(x1 > x2) {
				swap(x1, x2);
				swap(y1, y2);
			}
			mes(vis, 0);
			solve(1.0*x1, 1.0*y1, 1.0*x2, 1.0*y2);
			if(y1 < y2) {
				for(int x=x1; x<=x2; x++) {
					int yl = (int)floor(get(x-1)-eps);
					int yr = (int)ceil(get(x+1)+eps);
					for(int i=x-1; i<=x+1; i++) {
						for(int j=yl; j<=yr; j++) {
							if(vis[i][j] || vv[i][j]==0)	continue;
							if(ok(1.0*i, 1.0*j, a, b, c))
								ans++;
							vis[i][j] = true;
						}
					}
				}
				printf("%d\n", ans);
			} else {
				for(int x=x1; x<=x2; x++) {
					int yl = (int)ceil(get(x-1)+eps);
					int yr = (int)floor(get(x+1)-eps);
					for(int i=x-1; i<=x+1; i++) {
						for(int j=yr; j<=yl; j++) {
							if(vis[i][j] || vv[i][j]==0)	continue;
							if(ok(1.0*i, 1.0*j, a, b, c))
								ans++;
							vis[i][j] = true;
						}
					}
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
