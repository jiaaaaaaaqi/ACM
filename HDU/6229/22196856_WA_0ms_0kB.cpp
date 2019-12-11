/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Sat 12 Oct 2019 04:37:11 PM CST
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
const int    maxn = 1e4 + 10;
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
	int x, y;
} node[maxn];
bool maps[maxn][maxn];
int dis[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int V(int x, int y) {
	if(x<0 || y<0 || x>=n || y>=n)	return 0;
	if(maps[x][y])			return 0;
	if(x==0 && y==0)		return 3;
	if(x==0 && y==n-1)		return 3;
	if(x==n-1 && y==0)		return 3;
	if(x==n-1 && y==n-1)	return 3;
	if(x==0 || y==0 || x==n-1 || y==n-1)	return 4;
	return 5;
}

int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &node[i].x, &node[i].y);
		}
		ll ans1 = 12;
		ans1 += 16ll*(n-2);
		ans1 += 5ll*(n-2)*(n-2);
		ll ans2 = ans1 + 6 + 5*(n-2);
		ans2 /= 2;
		for(int i=1; i<=m; i++) {
			ans1 -= V(node[i].x, node[i].y);
			if(node[i].x + node[i].y >= n-1)	ans2 -= V(node[i].x, node[i].y);
			maps[node[i].x][node[i].y] = 1;
			// printf("*  %lld\n", ans1);
		}
		for(int i=1; i<=m; i++) {
			for(int j=0; j<4; j++) {
				int x = node[i].x + dis[j][0];
				int y = node[i].y + dis[j][1];
				if(V(x, y))	ans1--;
				if(x+y>=n-1 && V(x, y))	ans2--;
			}
			// printf("!  %lld\n", ans1);
		}
		// printf("%lld %lld\n", ans1, ans2);
		if(ans2 == 0) {
			ans1 = 1;
		} else {
			ll g = __gcd(ans1, ans2);
			ans1 /= g, ans2 /= g;
		}
		printf("Case #%d: %lld/%lld\n", cas++, ans2, ans1);
		for(int i=1; i<=m; i++) {
			maps[node[i].x][node[i].y] = 0;
		}
	}
	return 0;
}

