/***************************************************************
    > File Name    : C.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月15日 星期三 00时31分31秒
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
	double l, r;
	double v;
	bool operator < (Node a) const {
		return l < a.l;
	}
} node[maxn];

int main() {
	double x, y;
	scanf("%lf%lf", &x, &y);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lf%lf%lf", &node[i].l, &node[i].r, &node[i].v);
	}
	if(n==0) {
		double ans = x/y;
		printf("%.10f\n", ans);
		return 0;
	}
	sort(node+1, node+1+n);
	double sum = y;
	double tmp = 0;
	for(int i=1; i<=n; i++) {
		sum -= (node[i].r - node[i].l);
		tmp += (node[i].r - node[i].l) * node[i].v;
	}
	// printf("%f %f %f\n", x, sum, tmp);
	double ans = x / (sum + tmp);
	printf("%.10f\n", ans);
	return 0;
}

