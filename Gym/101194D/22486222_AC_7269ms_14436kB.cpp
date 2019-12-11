/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Sat 26 Oct 2019 09:18:52 PM CST
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
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn];
ll b[maxn];

bool cmp(ll a, ll b) {
	return a>b;
}

bool check(int mid) {
	multiset<ll> st;
	for(int i=1; i<=n; i++) {
		st.insert(a[i]);
	}
	for(int i=1; i<=mid; i++) {
		b[i] = *(--st.end());
		st.erase(--st.end());
	}
	for(int K=2; K<=m; K++) {
		for(int i=1; i<=mid; i++) {
			ll num = b[i]/2;
			auto it = st.upper_bound(num);
			if(it == st.begin())	return 0;
			it--;
			b[i] = *it;
			st.erase(it);
		}
	}
	return 1;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a+1, a+1+n, cmp);
		int l = 1, r = n/m, ans = 0;
		while(l<=r) {
			int mid = l+r>>1;
			if(check(mid)) {
				l = mid+1;
				ans = mid;
			} else {
				r = mid-1;
			}
		}
		printf("Case #%d: %d\n", cas++, ans);
	}
	return 0;
}

