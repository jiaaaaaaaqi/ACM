/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月31日 星期六 12时25分47秒
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
const int    maxn = 2e2 + 10;
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
	int id, sum;
	bool operator < (Node a) const {
		return sum<a.sum;
	}
} node[maxn];
int maps[maxn][maxn][maxn];

void floyd() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				maps[k][i][j] = min(maps[k-1][i][j], maps[k-1][i][node[k].id]+maps[k-1][node[k].id][j]);
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	cas = 1;
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) {
			node[i].id = i;
			scanf("%d", &node[i].sum);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d", &maps[0][i][j]);
			}
		}
		sort(node+1, node+1+n);
		floyd();
		printf("Case #%d:\n", cas++);
		int u, v, x;
		while(m--) {
			scanf("%d%d%d", &u, &v, &x);
			int ok = 0;
			for(int i=1; i<=n; i++) {
				if(node[i].sum > x) {
					printf("%d\n", maps[i-1][u][v]);
					break;
				}
				if(i == n)	printf("%d\n", maps[i][u][v]);
			}
		}
	}
    return 0;
}

