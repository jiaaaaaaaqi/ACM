/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月15日 星期三 03时11分08秒
 ***************************************************************/

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

ll n, m, p;
int cas, tol, T;

int a[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld", &n, &p);
		ll ans = 1;
		for(int i=1, id; i<=n; i++) {
			scanf("%d%d", &id, &a[i]);
			if(id == 1) {
				ans = ans*a[i]%mod;
				printf("%lld\n", ans);
			} else {
				ans = ans%(a[a[i]]*p)/a[a[i]];
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}

