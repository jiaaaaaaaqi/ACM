/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月26日 星期一 10时17分17秒
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

struct Node {
	int t, x, y;
} node[maxn];

double calc(Node a, Node b) {
	double ans = 1.0*(a.x-b.x)*(a.x-b.x) + 1.0*(a.y-b.y)*(a.y-b.y);
	return sqrt(ans);
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d", &node[i].t, &node[i].x, &node[i].y);
		}
		double ans = 0;
		for(int i=2; i<=n; i++) {
			ans = max(ans, calc(node[i], node[i-1])/(node[i].t-node[i-1].t));
		}
		printf("%.10f\n", ans);
	}
    return 0;
}

