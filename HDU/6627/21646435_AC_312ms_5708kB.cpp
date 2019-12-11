/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Thu 05 Sep 2019 09:34:08 PM CST
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
ll C;
int cas, tol, T;

struct Node {
	int a, b;
	Node() {
	}
	Node(int aa, int bb) {
		a = aa, b = bb;
	}
	bool operator < (Node x) const {
		return 1ll*b*x.a > 1ll*a*x.b; 
	}
	bool operator <= (Node x) const {
		return 1ll*a*x.b <= 1ll*b*x.a;
	}
} node[maxn], vv[maxn], vs[maxn];
ll prea[maxn], preb[maxn];
ll sufa[maxn], sufb[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%lld", &n, &C);
		for(int i=1, a, b; i<=n; i++) {
			scanf("%d%d", &a, &b);
			node[i] = Node(a, b);
		}
		node[++n] = Node(1, inf);
		node[++n] = Node(1, -inf);
		sort(node+1, node+1+n);
		prea[1] = preb[1] = 0;
		for(int i=2; i<n; i++) {
			prea[i] = prea[i-1] + node[i].a;
			preb[i] = preb[i-1] + node[i].b;
		}
		sufa[n] = sufb[n] = 0;
		for(int i=n-1; i>=2; i--) {
			sufa[i] = sufa[i+1] + node[i].a;
			sufb[i] = sufb[i+1] + node[i].b;
		}
		int flag = false;
		int cnt = 0;
		for(int i=1; i<n; i++) {
			if(sufa[i+1] == prea[i]) {
				if(C == (preb[i]-sufb[i+1])) {
					flag = true;
					break;
				}
				continue;
			}
			Node ans;
			ans.a = C-(preb[i]-sufb[i+1]);
			ans.b = (prea[i]-sufa[i+1]);
			if(ans.a) {
				int g = __gcd(abs(ans.a), abs(ans.b));
				ans.a /= g, ans.b /= g;
			} else {
				ans.a = 0, ans.b = 1;
			}
			if(ans.b < 0)	ans.a *= -1, ans.b *= -1;
			if(Node(-node[i].b, node[i].a)<=ans && ans<=Node(-node[i+1].b, node[i+1].a))
				vs[++cnt] = ans;
		}
		if(flag)	printf("-1\n");
		else {
			int ans = 0;
			for(int i=1; i<=cnt; i++) {
				if(ans && vv[ans].a==vs[i].a&&vv[ans].b==vs[i].b)
					continue;
				vv[++ans] = vs[i];
			}
			printf("%d", ans);
			for(int i=1; i<=ans; i++) {
				printf(" %d/%d", vv[i].a, vv[i].b);
			}
			printf("\n");
		}
	}
	return 0;
}

