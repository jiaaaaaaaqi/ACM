/***************************************************************
    > File Name    : i.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月08日 星期一 18时22分00秒
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

int n, m;
int cas, tol, T;

int a[maxn], b[maxn];

int main() {
	while(~scanf("%d", &n)) {
		ll ans = 0;
		for(int i=0; i<=n; i++) {
			scanf("%d", &a[i]);
			if(n&1) {
				if(a[i] == 0)	b[i] = n;
				else if(a[i]==n)b[i] = 0;
				else if(a[i]&1)	b[i] = a[i]+1;
				else	b[i] = a[i]-1;
			} else {
				if(a[i] == 0)	b[i] = 0;
				else if(a[i]&1)	b[i] = a[i]+1;
				else	b[i] = a[i]-1;
			}
			ans += a[i]^b[i];
		}
		printf("%lld\n", ans);
		for(int i=0; i<=n; i++) {
			printf("%d%c", b[i], i==n ? '\n' : ' ');
		}
	}
	return 0;
}

