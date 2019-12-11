/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年09月25日 星期三 13时13分16秒
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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
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

int c[60][60];

int main() {
    // freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		mes(c, 0);
		scanf("%d%d", &n, &m);
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%d", &c[i][j]);
				if(c[i][j] != 0)	ans++;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				ll tmp = 4ll*c[i][j];
				tmp -= min(c[i][j], c[i-1][j]);
				tmp -= min(c[i][j], c[i+1][j]);
				tmp -= min(c[i][j], c[i][j-1]);
				tmp -= min(c[i][j], c[i][j+1]);
				ans += tmp;
			}
		}
		printf("%lld\n", ans);
	}
    return 0;
}

