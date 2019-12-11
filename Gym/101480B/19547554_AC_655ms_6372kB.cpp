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
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
ll sum[maxn];
char s[maxn];

int solve(int x) {
	x++;
	int st = 0;
	int ans = 0;
	for(int i=1; i<=tol; ) {
		ans += a[i];
		int p = upper_bound(sum+1, sum+1+tol, st+x)-sum;
		i = p;
		st = sum[p-1];
	}
	return ans-1;
}

int main() {
	char ch;
	tol = 0;
	sum[0] = 0;
	while(scanf("%s%c", s+1, &ch)) {
		int len = strlen(s+1);
		a[++tol] = len+1;
		sum[tol] = sum[tol-1] + a[tol];
		if(ch == '\n')	break;
	}
//	for(int i=1; i<=tol; i++) {
//		printf("%lld%c", sum[i], i==tol ? '\n' : ' ');
//	}
	scanf("%d%d", &n, &m);
	for(int i=n; i<=m; i++) {
		int ans = solve(i);
		printf("%d\n", ans);
	}
	return 0;
}
