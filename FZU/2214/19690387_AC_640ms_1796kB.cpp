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
int w[maxn], v[maxn];
ll dp[maxn];

int main() {
	scanf("%d", &T);
	
	while(T--) {
		dp[0] = 0;
		for (int i = 1; i <= 5005; i++) dp[i] = INF;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d%d", &w[i], &v[i]);
		for (int i = 1; i <= n; i++) {
			for (int j = 5000; j >= 1; j--) {
				if (j >= v[i] && dp[j-v[i]] < INF)
					dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
			}
		}
		for (int i = 5000; i >= 0; i--) {
			if (dp[i] <= m) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
