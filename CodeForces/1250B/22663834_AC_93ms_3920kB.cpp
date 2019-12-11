/*************************************************************** 
    > File Name        : a.cpp
    > Author           : Jiaaaaaaaqi
    > Created Time     : 2019年11月03日 星期日 15时10分00秒
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

int a[maxn], cnt[maxn];

ll solve(int size) {
	int l = 1, r = m;
	ll ans = 0;
	while(l<=r) {
		if(l == r) {
			ans++;
			break;
		}
		if(cnt[l]+cnt[r] <= size)	l++, r--;
		else r--;
		ans++;
	}
	return ans;
}

int main() {
    // freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	sort(cnt+1, cnt+1+m);
	int up = cnt[(m+1)/2]+cnt[m];
	ll ans = INF;
	for(int i=cnt[m]; i<=up; i++) {
		ans = min(ans, i*solve(i));
	}
	printf("%lld\n", ans);
    return 0;
}
 