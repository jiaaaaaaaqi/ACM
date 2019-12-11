/***************************************************************
    > File Name    : c.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月21日 星期日 19时30分31秒
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

struct Node{
	int a, b, h;
	bool operator < (Node x) const {
		return x.a<b && b<=x.b;
	}
} node[maxn];

bool ok(Node i, Node j) {
	// printf("%d %d %d %d\n", i.a, i.b, j.a, j.b);
	if(i.b <= j.b && i.b>j.a)
		return true;
	return false;
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d%d%d", &node[i].a, &node[i].b, &node[i].h);
	}
	sort(node+1, node+1+n);
	// for(int i=1; i<=n; i++) {
	//     printf("!!!%d %d %d\n", node[i].a, node[i].b, node[i].h);
	// }
	ll ans = 0, res = 0;
	for(int i=1; i<=n; i++) {
		if(i==1) {
			ans = 1ll*node[i].h;
			continue;
		} else {
			if(ok(node[i-1], node[i])) {
				ans += 1ll*node[i].h;
			} else {
				res = max(res, ans);
				ans = 1ll*node[i].h;
			}
		}
		// printf("%d %d\n", i, ans);
	}
	printf("%lld\n", max(res, ans));
	return 0;
}

