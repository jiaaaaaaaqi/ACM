/***************************************************************
    > File Name    : h.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月08日 星期一 19时21分40秒
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

int a[maxn], b[maxn], c[maxn];
bool vis[maxn];

int main() {
	c[0] = 0;
	for(int i=1; ; i++) {
		if(c[i-1] > 300000)	break;
		c[i] = c[i-1]*2+1;
	}
	while(~scanf("%d", &n)) {
		for(int i=0; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		mes(vis, 0);
		int j = log2(n)+2;
		for(int i=n; i>0; i--) {
			int tmp = i^c[j];
			if(tmp > n) {
				i++, j--;
				continue;
			}
			if(vis[tmp]) {
				i++, j--;
				continue;
			}
			b[i] = tmp;
			vis[tmp] = true;
		}
		int x = 0;
		for(int i=1; i<=n; i++) {
			if(vis[i] == 0)	{
				x = i;
				break;
			}
		}
		b[0] = x;
		b[x] = 0;
		ll ans=0;
		for(int i=0; i<=n; i++) {
			ans += i^b[i];
		}
		printf("%lld\n", ans);
		for(int i=0; i<=n; i++) {
			printf("%d%c", b[a[i]], i==n ? '\n' : ' ');
		}
	}
	return 0;
}

