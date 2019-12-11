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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int b[maxn];

void init() {
    mes(a, 0);
    mes(b, 0);
}

int solve() {
	int p = 4;
    for(int i=1; i<=n + 1; i++) {
        while(b[i] > 0) {
			while(p <= n+1 && b[p] >= 0)	p++;
			if(p > n+1)	return false;
			if(p < i+3)	return false;
            if(b[p] < 0) {
                int x = min(b[i], -b[p]);
                b[i] -= x;
                b[p] += x;
            }
        }
        if(b[i] != 0)	return 0;
    }
    return 1;
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i] - a[i-1];
        }
        b[n+1] = -a[n];
//        for(int i=1; i<=n; i++)
//			printf("%d%c", b[i], i==n ? '\n' : ' ');
        int flag = solve();
        printf("Case #%d: %s\n",cas++, flag ? "Yes" : "No");
    }
    return 0;
}
