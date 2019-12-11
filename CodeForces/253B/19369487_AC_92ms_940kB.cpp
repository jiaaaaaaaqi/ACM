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

int a[maxn];
int c[maxn];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	mes(c, 0);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		c[a[i]]++;
    }
    int ans = inf;
    for(int i=1; i<=5000; i++) {
		c[i] = c[i-1] + c[i];
    }
    for(int i=1; i<=5000; i++) {
		ans = min(ans, c[i-1]+n-c[2*i]);
    }
    printf("%d\n", max(0, ans));
    return 0;
}

