/*************************************************************** 
	> File Name		: b.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Wed 13 Nov 2019 10:57:31 PM CST
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
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

vector<int> vv[maxn];
bool vis[maxn][2], view[maxn];

void dfs(int u, int fa, int f, int &cnt, int &col) {
	if(vis[u][f])	return ;
	if(!view[u]) {
		cnt++;
		view[u] = true;
	}
	if(f == 1)	col++;
	vis[u][f] = 1;
	for(auto v : vv[u]) if(v != fa)	{
		dfs(v, u, !f, cnt, col);
	}
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)	vv[i].clear();
	for(int i=1, u,v ;i<=m; i++) {
		scanf("%d%d", &u, &v);
		vv[u].pb(v), vv[v].pb(u);
	}
	int flag = 0, sz = 0;
	for(int i=1; i<=n; i++) {
		if(!view[i]) {
			sz++;
			int cnt = 0, col = 0;
			dfs(i, 0, 1, cnt, col);
			// cout << cnt << " " << col << endl;
			if(cnt!=1 && cnt==col)	flag = 1;
		}
	}
	printf("%d\n", sz-flag);
	return 0;
}

