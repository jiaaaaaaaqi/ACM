/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 06 Sep 2019 09:17:26 PM CST
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

int tot[2];
int a[maxn], b[maxn], c[maxn];
int node[2][maxn*30][2], cnt[2][maxn*30];

void insert(int x, int id) {
	int rt = 0;
	for(int i=30; i>=1; i--) {
		int f = (x&(1<<(i-1))) ? 1 : 0;
		if(node[id][rt][f] == 0) {
			tot[id]++;
			mes(node[id][tot[id]], 0);
			cnt[id][tot[id]] = 0;
			node[id][rt][f] = tot[id];
		}
		rt = node[id][rt][f];
		cnt[id][rt]++;
	}
}

int dfs(int rt1, int rt2, int p) {
	// printf("rt1=%d rt2=%d\n", rt1, rt2);
	if(p == 0)	return 0;
	bool ok00 = (node[0][rt1][0] && cnt[0][node[0][rt1][0]]);
	bool ok01 = (node[0][rt1][1] && cnt[0][node[0][rt1][1]]);
	bool ok10 = (node[1][rt2][0] && cnt[1][node[1][rt2][0]]);
	bool ok11 = (node[1][rt2][1] && cnt[1][node[1][rt2][1]]);
	if(ok00 && ok10) {
		cnt[0][node[0][rt1][0]]--, cnt[1][node[1][rt2][0]]--;
		return dfs(node[0][rt1][0], node[1][rt2][0], p-1);
	} else if(ok01 && ok11) {
		cnt[0][node[0][rt1][1]]--, cnt[1][node[1][rt2][1]]--;
		return dfs(node[0][rt1][1], node[1][rt2][1], p-1);
	} else if(ok00 && ok11) {
		cnt[0][node[0][rt1][0]]--, cnt[1][node[1][rt2][1]]--;
		return dfs(node[0][rt1][0], node[1][rt2][1], p-1) + (1<<(p-1));
	} else {
		cnt[0][node[0][rt1][1]]--, cnt[1][node[1][rt2][0]]--;
		return dfs(node[0][rt1][1], node[1][rt2][0], p-1) + (1<<(p-1));
	}
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		cnt[0][0] = cnt[1][0] = tot[0] = tot[1] = 0;
		mes(node[0][0], 0), mes(node[1][0], 0);
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]), insert(a[i], 0);
		for(int i=1; i<=n; i++)	scanf("%d", &b[i]), insert(b[i], 1);
		for(int i=1; i<=n; i++)	c[i] = dfs(0, 0, 30);
		sort(c+1, c+1+n);
		for(int i=1; i<=n; i++)	printf("%d%c", c[i], i==n ? '\n' : ' ');
	}
	return 0;
}

