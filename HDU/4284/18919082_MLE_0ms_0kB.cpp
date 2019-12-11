/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月25日 星期一 19时27分10秒
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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, st;
int cas, tol, T;

struct Node{
	int id;
	int c, d;
} node[20];
int dp[1<<20][20];
int maps[maxn][maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &st);
		mes(maps, inf);
		for(int i=1, u, v, w; i<=m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			maps[u][v] = maps[v][u] = min(w, maps[u][v]);
		}
		for(int i=1; i<=n; i++) {
			maps[i][i] = 0;
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					maps[i][j] = min(maps[i][j], maps[i][k]+maps[k][j]);
				}
			}
		}
		mes(dp, -1);
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &node[i].id, &node[i].c, &node[i].d);
			if(st - maps[1][node[i].id] >= node[i].d) {
				dp[1<<(i-1)][i] = st-maps[1][node[i].id]-node[i].d+node[i].c;
			}
		}
		int mx = (1<<m)-1;
		for(int i=1; i<mx; i++) {
			for(int j=1; j<=m; j++) {
				if(dp[i][j] == -1)	continue;
				if(!(i & (1<<(j-1))))	continue;
				for(int k=1; k<=m; k++) {
					if(i & (1<<(k-1)))		continue;
					int u = node[j].id;
					int v = node[k].id;
					int dis = maps[u][v];
					if(dis == inf)		continue;
					if(dp[i][j] - dis >= node[k].d) {
						dp[i|(1<<(k-1))][k] = max(dp[i|(1<<(k-1))][k], dp[i][j]-dis-node[k].d+node[k].c);
					}
				}
			}
		}
		int flag = false;
		for(int i=1; i<=m; i++) {
			if(dp[mx][i] != -1) {
				int u = node[i].id;
				if(dp[mx][i] - maps[u][1] >= 0) {
					flag = true;
					break;
				}
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}

