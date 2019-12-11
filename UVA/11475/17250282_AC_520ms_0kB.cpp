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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int tp[maxn];
int sa[maxn];
int rk[maxn];
char s[maxn];
int tax[maxn];
int dp[maxn][30];
int height[maxn];

void init() {
	mes(s, 0);
	mes(dp, 0);
}

void rsort(int n, int m) {
    for(int i=0; i<=m; i++)		tax[i] = 0;
    for(int i=1; i<=n; i++)		tax[rk[tp[i]]]++;
    for(int i=1; i<=m; i++)		tax[i] += tax[i-1];
    for(int i=n; i>=1; i--)		sa[tax[rk[tp[i]]]--] = tp[i];
}

int cmp(int *f, int x, int y, int w) {
    return f[x] == f[y] && f[x+w] == f[y+w];
}

void SA(int *a, int n, int m) {
    for(int i=1; i<=n; i++)		rk[i] = a[i], tp[i] = i;
    rsort(n, m);
    for(int w=1, p=1, i; p<n; w<<=1, m=p) {
        for(p = 0, i = n - w + 1; i <= n; i++)	tp[++p] = i;
        for(i = 1; i <= n; i++)	if(sa[i] > w)	tp[++p] = sa[i] - w;
        rsort(n, m), swap(rk, tp);
        rk[sa[1]] = p = 1;
        for(i = 2; i <= n; i++)	rk[sa[i]] = cmp(tp, sa[i], sa[i-1], w) ? p : ++p;
    }
    int j, k = 0;
    for (int i = 1; i <= n; height[rk[i ++]] = k)
        for ( k = k ? k - 1 : k, j = sa[rk[i] - 1]; a[i + k] == a[j + k]; k++);
}

void RMQ_INIT(int n) {
	for(int i=1; i<=n; i++)
		dp[i][0] = height[i];
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i<=n; i++) {
			if(i + (1<<j) - 1 <= n) {
				dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
			}
		}
	}
}

int RMQ_QUERY(int x, int y) {
	x = rk[x];
	y = rk[y];
	if(x > y)	swap(x, y);
	x++;
	int k = log(y - x + 1) / log(2.0);
	return min(dp[x][k], dp[y - (1<<k) + 1][k]);
}

int main() {
	init();
    while(~scanf("%s", s+1)) {
        int len = strlen(s+1);
        n = 0;
        for(int i=1; i<=len; i++)	a[++n] = s[i];
        a[++n] = 1;
        for(int i=len; i>=1; i--)	a[++n] = s[i];
        SA(a, n, 255);
		RMQ_INIT(n);
		int last = len + 1;
		for(int i=1; i<=len; i++) {
			int x = i;
			int y = 2 * len + 3 - i;
			int ans = RMQ_QUERY(x, y);
			if(ans >= len - i + 1 && y <= n) {
				last = min(last, 2 * i - len - 1);
			}
		}
		for(int i=1; i<=len; i++) {
			int x = i;
			int y = 2 * len + 2 - i;
			int ans = RMQ_QUERY(x, y);
			if(ans >= len - i + 1 && y <= n) {
				last = min(last, 2 * i - len);
			}
		}
		printf("%s", s+1);
		for(int i=last-1; i>=1; i--)
			printf("%c", s[i]);
		printf("\n");
		init();
    }
    return 0;
}
