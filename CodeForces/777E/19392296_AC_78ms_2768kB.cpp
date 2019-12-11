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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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
	ll a, b, h;
	bool operator < (Node x) const {
		return b==x.b ? a>x.a : b>x.b;
	}
} node[maxn];
int q[maxn];

bool ok(Node j, Node i) {
	if(i.b <= j.b && i.b>j.a)
		return true;
	return false;
}

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lld%lld%lld", &node[i].a, &node[i].b, &node[i].h);
	}
	sort(node+1, node+1+n);
//	for(int i=1; i<=n; i++) {
//		printf("%lld %lld\n", node[i].a, node[i].b);
//	}
	int head, tail;
	head = 1, tail = 0;
	ll ans = 0, res = 0;
	for(int i=1; i<=n; i++) {
		while(head<=tail && !ok(node[q[tail]], node[i])) {
			res -= node[q[tail]].h;
			tail--;
		}
		q[++tail] = i;
		res += node[i].h;
		ans = max(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}
/*
15
3 14 531
28 29 17
7 10 512
20 21 264
8 9 52
16 19 759
1 30 391
2 27 861
17 18 357
15 22 428
24 25 588
23 26 221
6 13 413
11 12 667
4 5 513
*/
