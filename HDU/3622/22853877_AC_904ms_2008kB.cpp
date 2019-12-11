/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Wed 13 Nov 2019 07:31:15 PM CST
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
const int    maxn = 1e3 + 10;
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
	double x1, y1;
	double x2, y2;
} node[maxn];
vector<int> vv[maxn];

double distance(double x1, double y1, double x2, double y2) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int cnt, stacksize, top;
int dfn[maxn], low[maxn], sta[maxn], maps[maxn];
bool vis[maxn];
void dfs(int u) {
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	sta[stacksize++] = u;
	for(auto v : vv[u]) {
		if(!dfn[v])	{
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	int v;
	if(dfn[u] == low[u]) {
		top++;
		do {
			v = sta[--stacksize];
			maps[v] = top;
			vis[v] = false;
		} while(v!=u);
	}
}

bool check(double r) {
	cnt = stacksize = top = 0;
	for(int i=1; i<=2*n; i++)
		vv[i].clear(), vis[i] = maps[i] = dfn[i] = low[i] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i == j)	continue;
			if(distance(node[i].x1, node[i].y1, node[j].x1, node[j].y1) <= 4*r*r) {
				vv[i].pb(j+n);
				vv[j].pb(i+n);
			}
			if(distance(node[i].x1, node[i].y1, node[j].x2, node[j].y2) <= 4*r*r) {
				vv[i].pb(j);
				vv[j+n].pb(i+n);
			}
			if(distance(node[i].x2, node[i].y2, node[j].x1, node[j].y1) <= 4*r*r) {
				vv[i+n].pb(j+n);
				vv[j].pb(i);
			}
			if(distance(node[i].x2, node[i].y2, node[j].x2, node[j].y2) <= 4*r*r) {
				vv[i+n].pb(j);
				vv[j+n].pb(i);
			}
		}
	}
	for(int u=1; u<=2*n; u++)	if(!dfn[u])	dfs(u);
	for(int i=1; i<=n; i++)	if(maps[i]==maps[i+n])	return false;
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%lf%lf%lf%lf", &node[i].x1, &node[i].y1, &node[i].x2, &node[i].y2);
		}
		double l = 0, r = 1e10, ans = 0;
		while(r-l>eps) {
			double mid = 0.5*(l+r);
			if(check(mid))	ans = mid, l = mid;
			else	r = mid;
		}
		printf("%.2f\n", ans);
	}
	return 0;
}

