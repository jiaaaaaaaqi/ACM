/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月26日 星期一 10时52分27秒
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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int ok[maxn][maxn];
vector<pii> vv[maxn];

bool dfs(int A, int B, int last, int id) {
	if(ok[A][B] != -1)	return ok[A][B];
	int st = id==0 ? A : B;
	for(auto v : vv[st]) {
		if(v.se < last)	continue;
		if(!dfs(id==0 ? v.fi : A, id==1 ? v.fi : B, v.se, !id)) {
			ok[A][B] = 1;
			return true;
		}
	}
	ok[A][B] = 0;
	return false;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)	vv[i].clear();
	mes(ok, -1);
	for(int i=1, u, v; i<=m; i++) {
		char ch[5];
		scanf("%d%d%s", &u, &v, ch+1);
		vv[u].pb(make_pair(v, ch[1]-'A'+1));
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j)	printf("B");
			else	printf("%c", dfs(i, j, 0, 0) ? 'A' : 'B');
			if(j==n)	printf("\n");
		}
	}
    return 0;
}

