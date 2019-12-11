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
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)	x & (-x)
#define  mes(a, b)	memset(a, b, sizeof a)
#define  fi 		first
#define  se 		second
#define  INOPEM		freopen("in.txt", "r", stdin)
#define  OUTOPEN	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e3 + 5;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int key = 1999;
struct Node {
	int x, y;
	int next;
} node[maxn];
int head[maxn << 1];
int x[maxn];
int y[maxn];

void init() {
	tol = 0;
	mes(node, 0);
	mes(head, -1);
}

void addnode(int k, int x, int y) {
	node[tol].x = x;
	node[tol].y = y;
	node[tol].next = head[k];
	head[k] = tol++;
}

bool find(int x, int y) {
	int k = (x * x + y * y) % key + 1;
	for (int i = head[k]; ~i; i = node[i].next) {
		if (node[i].x == x && node[i].y == y)
			return true;
	}
	return false;
}

int main() {
	while (scanf("%d", &n), n) {
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &x[i], &y[i]);
			int k = (x[i] * x[i] + y[i] * y[i]) % key + 1;
			addnode(k, x[i], y[i]);
		}
		int x1, x2, x3, x4;
		int y1, y2, y3, y4;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				x1 = x[i];
				y1 = y[i];
				x2 = x[j];
				y2 = y[j];
				x3 = x1 + (y1 - y2);
				y3 = y1 + (x2 - x1);
				x4 = x2 + (y1 - y2);
				y4 = y2 + (x2 - x1);
				bool res = find(x3, y3) && find(x4, y4);
				if (res)
					ans++;
				x3 = x1 - (y1 - y2);
				y3 = y1 - (x2 - x1);
				x4 = x2 - (y1 - y2);
				y4 = y2 - (x2 - x1);
				res = find(x3, y3) && find(x4, y4);
				if (res)
					ans++;
			}
		}
		printf("%d\n", ans / 4);
	}
	return 0;
}