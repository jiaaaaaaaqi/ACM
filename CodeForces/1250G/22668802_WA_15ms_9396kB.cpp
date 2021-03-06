/*************************************************************** 
	> File Name		: G.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Sun 03 Nov 2019 10:37:18 PM CST
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
const int    maxn = 2e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll a[maxn], b[maxn], k;
ll sa[maxn], sb[maxn], w[maxn], c[maxn];
vector<int> vv;

int findwin() {
	{
		ll A, B;
		A = B = 0;
		for(int i=1; i<=n; i++) {
			A += a[i], B += b[i];
			if(A >= k)	return -1;
			ll x = min(A, B);
			A -= x, B -= x;
		}
	}
	int L = 0;
	int ans = -1;
	for(int i=1; i<=n; i++) {
		while(L<=n && sa[i]-k >= w[L])	L++;
		if(sa[i]-k < w[L] && w[L] <= sb[i]-k) {
			ans = i;
			break;
		}
	}
	if(!L || ans == -1)	return ans;
	int R = ans;
	for(; R>=1; R=L, L--) {
		while(L>=1 && sa[R]-k <= c[L])	L--;
		if(L == 0) {
			if(sa[R]==k)	vv.pb(1);
		} else {
			vv.pb(L);
		}
	}
	return ans;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		vv.clear();
		scanf("%d%lld", &n, &k);
		sa[0] = sb[0] = w[0] = c[0] = 0;
		for(int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
			sa[i] = sa[i-1]+a[i];
		}
		for(int i=1; i<=n; i++) {
			scanf("%lld", &b[i]);
			sb[i] = sb[i-1]+b[i];
			w[i] = min(sa[i], sb[i]);
			c[i] = sa[i-1]<sb[i-1] ? sa[i-1] : 2*sb[i-1]-sa[i-1];
			c[i] = max(c[i-1], c[i]);
		}
		// printf("sa: "); for(int i=1; i<=n; i++) printf("%lld%c", sa[i], i==n?'\n':' ');
		// printf("sb: "); for(int i=1; i<=n; i++) printf("%lld%c", sb[i], i==n?'\n':' ');
		// printf("w : "); for(int i=1; i<=n; i++) printf("%lld%c", w[i], i==n?'\n':' ');
		// printf("c : "); for(int i=1; i<=n; i++) printf("%lld%c", c[i], i==n?'\n':' ');
		int pos = findwin();
		if(pos == -1) {
			printf("-1\n");
		} else {
			if(vv.size() == 0) {
				printf("0\n\n");
			} else {
				sort(vv.begin(), vv.end());
				printf("%d\n", vv.size());
				for(int i=0; i<vv.size(); i++) {
					printf("%d%c", vv[i], i==vv.size()-1?'\n':' ');
				}
			}
		}
	}
	return 0;
}

