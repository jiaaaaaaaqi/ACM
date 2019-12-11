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

char s[14][14];
bool vis[14][14];
int gra;
struct Node{
	int x, y;
	int cnt;
};
int dis[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int bfs(int x1, int y1, int x2, int y2) {
	int cnt = 0;
	queue<Node> q;
	while(!q.empty())	q.pop();
	mes(vis, 0);
	Node now, nex;
	now.x = x1, now.y = y1, now.cnt = 0;
	q.push(now);
	now.x = x2, now.y = y2, now.cnt = 0;
	q.push(now);
	vis[x1][y1] = 1;
	vis[x2][y2] = 1;
	int ans = 0;
	while(!q.empty()) {
		now = q.front();
		q.pop();
		cnt++;
		ans = max(ans, now.cnt);
		for(int i=0; i<4; i++) {
			int x = now.x + dis[i][0];
			int y = now.y + dis[i][1];
			if(x<1 || y<1 || x>n || y>m)	continue;
			if(vis[x][y])	continue;
			if(s[x][y] == '.')	continue;
			vis[x][y] = true;
			nex.x = x, nex.y = y, nex.cnt = now.cnt+1;
			q.push(nex);
		}
	}
	if(cnt == gra)	return ans;
	else	return -1;
}

int main() {
	cas = 1;
	scanf("%d", &T);
	while(T--) {
		mes(s, 0);
		scanf("%d%d", &n, &m);
		gra = 0;
		for(int i=1; i<=n; i++) {
			scanf("%s", s[i]+1);
			for(int j=1; j<=m; j++) {
				if(s[i][j] == '#')	gra++;
			}
		}
		int ans = inf;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(s[i][j] != '#')	continue;
				for(int ii=1; ii<=n; ii++) {
					for(int jj=1; jj<=m; jj++) {
						if(s[ii][jj] != '#')	continue;
						int tmp = bfs(i, j, ii, jj);
						if(tmp != -1) {
							ans = min(ans, tmp);
						}
					}
				}
			}
		}
		if(ans == inf)	ans = -1;
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}

