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

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 18750005;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
short cnt[maxn];

int main() {
	int a1, a2, a3, a4, a5;
	while (~scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5)) {
		mes(cnt, 0);
		for (int i = -50; i <= 50; i++) {
			if (i == 0)
				continue;
			for (int j = -50; j <= 50; j++) {
				if (j == 0)
					continue;
				int t = a1 * i * i * i + a2 * j * j * j;
				if(t < 0)
					t += maxn;
				cnt[t]++;
			}
		}
		ll ans = 0;
		for (int i = -50; i <= 50; i++) {
			if (i == 0)
				continue;
			for (int j = -50; j <= 50; j++) {
				if (j == 0)
					continue;
				for (int k = -50; k <= 50; k++) {
					if (k == 0)
						continue;
					int t = -(a3 * i * i * i + a4 * j * j * j + a5 * k * k * k);
					if(t < 0)
						t += maxn;
					ans += cnt[t];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}