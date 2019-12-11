#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
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
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
	int a, b, c, d;
	bool sort() {
		if (a > b)	swap(a, b);
		if (a > c)	swap(a, c);
		if (b > c)	swap(b, c);
	}
	bool operator == (Node x) const {
		return a == x.a && b == x.b && c == x.c;
	}	
	bool operator != (Node x) const {
		return !(a == x.a && b == x.b && c == x.c);
	}
};

Node getfa(Node a1) {
	int ans = 0;
	while ((a1.b - a1.a) != (a1.c - a1.b)) {
		int l1 = a1.b - a1.a;
		int l2 = a1.c - a1.b;
		if (l1 > l2) {
			int x = (l1 - 1) / l2;
			a1.b -= x * l2;
			a1.c -= x * l2;
			ans += x;
		} else {
			int x = (l2 - 1) / l1;
			a1.a += x * l1;
			a1.b += x * l1;
			ans += x;
		}
		a1.sort();
	}
	a1.d = ans;
	return a1;
}

Node do_k_time(Node a1, int k) {
	while ((a1.b - a1.a) != (a1.c - a1.b)) {
		if (k == 0)	break;
		int l1 = a1.b - a1.a;
		int l2 = a1.c - a1.b;
		if (l1 > l2) {
			int x = (l1 - 1) / l2;
			x = min(x, k);
			a1.b -= x * l2;
			a1.c -= x * l2;
			k -= x;
		} else {
			int x = (l2 - 1) / l1;
			x = min(x, k);
			a1.a += x * l1;
			a1.b += x * l1;
			k -= x;
		}
		a1.sort();
	}
	return a1;
}

int main() {
	Node a1, a2;
	while (~scanf("%d%d%d%d%d%d", &a1.a, &a1.b, &a1.c, &a2.a, &a2.b, &a2.c)) {
		a1.sort();
		a2.sort();
		Node ans1 = getfa(a1);
		Node ans2 = getfa(a2);
		if (ans1 != ans2) {
			printf("NO\n");
			continue;
		} else {
			printf("YES\n");
			int ans = abs(ans1.d - ans2.d);
			if (ans1.d > ans2.d)
				a1 = do_k_time(a1, ans);
			else
				a2 = do_k_time(a2, ans);
			int sum = 0;
			int l = 0, r = min(ans1.d, ans2.d);
			while (l < r) {
				int mid = (l + r) >> 1;
				Node x1 = do_k_time(a1, mid);
				Node x2 = do_k_time(a2, mid);
				if (x1 == x2) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			printf("%d\n", ans + 2 * l);
		}
	}
	return 0;
}