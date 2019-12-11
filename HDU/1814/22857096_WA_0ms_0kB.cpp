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
const int    maxn = 2e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int ans[maxn], step[maxn];
vector<int> vv[maxn];

bool dfs(int u, int &cnt) {
	if(ans[u]) {
		if(ans[u] == 1)	return true;
		else	return false;
	}
	ans[u] = 1;
	ans[u&1 ? u+1:u-1] = 2;
	step[++cnt] = u;
	step[++cnt] = u&1 ? u+1:u-1;
	for(auto v : vv[u]) {
		if(!dfs(v, cnt))	return false;
	}
	return true;
}

bool solve() {
	for(int i=1; i<=2*n; i+=2) {
		if(ans[i])	continue;
		int cnt = 0;
		if(dfs(i, cnt))	continue;
		while(cnt)	ans[step[--cnt]] = 0;
		if(dfs(i+1, cnt))continue;
		return false;
	}
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d%d", &n, &m)) {
		for(int i=1; i<=2*n; i++)
			vv[i].clear(), ans[i] = 0;
		for(int i=1, u, v; i<=m; i++) {
			scanf("%d%d", &u, &v);
			vv[u].pb(v&1 ? v+1:v-1);
			vv[v].pb(u&1 ? u+1:u-1);
		}
		if(solve())	{
			for(int i=1; i<=2*n; i++) {
				if(ans[i] == 1)	printf("%d\n", i);
			}
		} else {
			printf("NIE\n");
			continue;
		}
	}
	return 0;
}

