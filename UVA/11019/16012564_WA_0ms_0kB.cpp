#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)	x & (-x)
#define  mes(a, b)	memset(a, b, sizeof a)
#define  fi 		first
#define  se 		second
#define  INOPEM		freopen("in.txt", "r", stdin)
#define  OUTOPEN	freopen("out.txt", "w", stdout)

typedef unsigned int ull;
typedef long long int ll;
const int    maxn = 1e3 + 10;
const int    maxm = 1e2 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
int x, y;
ull hashx = 27;
ull hashy = 36;
int hx[maxn];
int hy[maxn];
ull h[maxn][maxn];
char m1[maxn][maxn];
char m2[maxm][maxm];

void init() {
	mes(m1, 0);
	mes(m2, 0);
	mes(h, 0);
}

void handle() {
	hx[0] = 1;
	hy[0] = 1;
	for (int i = 1; i < maxn; i++) {
		hx[i] = hx[i - 1] * hashx;
		hy[i] = hy[i - 1] * hashy;
	}
}

int main() {
	handle();
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", m1[i] + 1);
		scanf("%d%d", &x, &y);
		for (int i = 1; i <= x; i++)
			scanf("%s", m2[i] + 1);
		ull ans = 0;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				ans += m2[i][j] * hx[x - i] * hy[y - j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				h[i][j] = h[i - 1][j - 1] * hashx * hashy
				          + m1[i][j]
				          + (h[i - 1][j] - h[i - 1][j - 1] * hashy) * hashx
				          + (h[i][j - 1] - h[i - 1][j - 1] * hashx) * hashy;
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (i + x - 1 > n)
				break;
			for (int j = 1; j <= m; j++) {
				if (j + y - 1 > m)
					break;
				int x1 = i - 1;
				int y1 = j - 1;
				int x2 = i + x - 1;
				int y2 = j + y - 1;
				ull tmp = h[x2][y2]
				          - h[x1][y1] * hx[x] * hy[y]
				          - (h[x2][y1] - h[x1][y1] * hx[x]) * hy[y]
				          - (h[x1][y2] - h[x1][y1] * hy[y]) * hx[x];
				if (tmp == ans)
					res++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}