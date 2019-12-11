/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019/4/12 0:30:44
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
	int x, y, z;
	bool operator < (Node a) const {
		return (x>a.x&&y>a.y) || (x>a.y&&y>a.x); 
	}
} node[maxn];
ll dp[maxn];

bool ok(int i, int j) {
	if(node[i].x > node[j].x && node[i].y>node[j].y)	return true;
	if(node[i].x > node[j].y && node[i].y>node[j].x)	return true;
	return false;
}

void dfs(int id) {
	if(dp[id])	return ;
	for(int i=1; i<=n; i++) {
		if(id == i)	continue;
		if(ok(id, i)) {
			dfs(i);
			dp[id] = max(dp[id], dp[i]+node[id].z);
		}
	}
	dp[id] = max(dp[id], 1ll*node[id].z);
}

int main() {
	cas = 1;
	while(scanf("%d", &m), m) {
		n = 0;
		node[++n].x = inf, node[n].y = inf, node[n].z = 0;
		for(int i=1, x, y, z; i<=m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			node[++n].x = x, node[n].y = y, node[n].z = z;
			node[++n].x = x, node[n].y = z, node[n].z = y;
			node[++n].x = z, node[n].y = y, node[n].z = x;
		}
		mes(dp, 0);
		dp[1] = 0;
		dfs(1);
		printf("Case %d: maximum height = %d\n", cas++, dp[1]);
	}
	return 0;
}

