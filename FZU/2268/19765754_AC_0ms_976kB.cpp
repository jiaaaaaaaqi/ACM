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
ll fac[maxn];

int main() {
    cas = 1;
    scanf("%d", &T);
    fac[0] = 1;
    int cnt = 0;
    for(int i=1; ; i++) {
        fac[i] = fac[i-1]*2;
        cnt = i;
        if(fac[i] > 1000000000) break;
    }
    while(T--) {
        ll n;
        scanf("%lld", &n);
        n++;
        int p = lower_bound(fac+1, fac+1+cnt, n) - fac;
        printf("Case %d: %d\n", cas++, p);
    }
	return 0;
}
