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
const int    maxn = 5e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, A, B;
int cas, tol, T;

vector<int> vv[maxn];
int sz[maxn], sum[maxn];

void dfs(int u) {
	if(sz[u])	return ;
	for(auto v : vv[u]) {
		dfs(v);
		sz[u] = max(sz[u], sz[v]);
	}
	sz[u]++;
}

int main() {
    scanf("%d%d%d%d", &A, &B, &n, &m);
    for(int i=1; i<=n; i++) {
		vv[i].clear();
    }
	for(int i=1, u, v; i<=m; i++) {
		scanf("%d%d", &u, &v);
		u++, v++;
		vv[v].push_back(u);
	}
	mes(sz, 0);
	for(int i=1; i<=n; i++) {
		if(sz[i] == 0)	dfs(i);
	}
	for(int i=1; i<=n; i++) {
		sum[sz[i]]++;
//		printf("!!!%d %d\n", i, sz[i]);
	}
//	for(int i=1; i<=n; i++) {
//		printf("sum[%d] = %d\n", i, sum[i]);
//	}
	sum[0] = 0;
	for(int i=1; i<=n; i++) {
		sum[i] += sum[i-1];
	}
	int ans1, ans2;
	int p = lower_bound(sum+1, sum+1+n, A)-sum;
	if(sum[p] != A)	p--;
	ans1 = sum[p];
	p = lower_bound(sum+1, sum+1+n, B)-sum;
	if(sum[p] != B)	p--;
	ans2 = sum[p];
	printf("%d\n%d\n%d\n", ans1, ans2, n-ans2);
    return 0;
}
/*
3 4 7 8
1 5
2 3
2 6
6 3
7 5
1 2
3 4
5 6
*/
