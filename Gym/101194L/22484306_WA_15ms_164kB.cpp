/*************************************************************** 
	> File Name		: a.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Sat 26 Oct 2019 07:57:43 PM CST
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

int a[5];
bool vis[20][20][20][20];

void dfs(int u, int v) {
	if(u == 4) {
		vis[a[1]][a[2]][a[3]][a[4]] = 1;
		return ;
	}

	a[u] += 3;
	if(v == 4) {
		dfs(u+1, u+2);
	} else {
		dfs(u, v+1);
	}
	a[u] -= 3;
	
	a[u] ++, a[v]++;
	if(v == 4) {
		dfs(u+1, u+2);
	} else {
		dfs(u, v+1);
	}

	a[u]--, a[v]--;
	a[v] += 3;
	if(v == 4) {
		dfs(u+1, u+2);
	} else {
		dfs(u, v+1);
	}
	a[v] -= 3;
}

int main() {
	// freopen("in", "r", stdin);
	dfs(1, 2);
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);	
		if(vis[a][b][c][d]) {
			int mx = 0;
			mx = max(mx, a);
			mx = max(mx, b);
			mx = max(mx, c);
			mx = max(mx, d);
			int cnt = 0;
			if(a==mx)	cnt++;
			if(b==mx)	cnt++;
			if(c==mx)	cnt++;
			if(d==mx)	cnt++;
			if(cnt == 1) {
				printf("Case #%d: Yes\n", cas++);
			} else {
				printf("Case #%d: No\n", cas++);
			}
		} else {
			printf("Case #%d: Wrong Scoreboard\n", cas++);
		}
	}
	return 0;
}


