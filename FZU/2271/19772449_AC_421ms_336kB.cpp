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

int maps[maxn][maxn];
int G[maxn][maxn];
bool vis[maxn][maxn];

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		int cnt = 0;
		mes(vis, 0);
		mes(G, inf);
		mes(maps, inf);
		scanf("%d%d", &n, &m);
		for(int i=1, u, v, x; i<=m; i++) {
			scanf("%d%d%d", &u, &v, &x);
			if(G[u][v] != inf) {
				cnt++;
			}
			G[u][v] = G[v][u] = min(G[u][v], x);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				maps[i][j] = G[i][j];
			}
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				if(maps[i][k] == inf)	continue;
				for(int j=1; j<=n; j++) {
					if(maps[j][k] == inf)	continue;
					if(maps[i][k]+maps[k][j] <= maps[i][j]) {
						maps[i][j] = maps[i][k] + maps[k][j];
						vis[i][j] = 1;
					}
				}
			}
		}
		int ans = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(vis[i][j] && G[i][j]!=inf) {
					ans++;
				}
			}
		}
		printf("Case %d: %d\n", cas++, ans/2+cnt);
	}
	return 0;
}
