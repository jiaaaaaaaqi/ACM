/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月25日 星期一 16时34分15秒
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

int st, state;
int dis[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int maps[20][20], dp[1<<16][20];
bool vis[20][20];
char s[20][20];
struct Node{
	int x, y;
	int cnt;
	Node() {
	}
	Node(int _x, int _y) {
		x = _x, y = _y;
	}
	Node(int _x, int _y, int _c) {
		x = _x, y = _y, cnt = _c;
	}
} node[20];

void init() {
	tol = 0;
	state = 0;
	mes(s, 0);
}

int bfs(int st, int ed) {
	queue<Node> q;
	while(!q.empty())	q.pop();
	mes(vis, 0);
	Node now, nex;
	now = Node(node[st].x, node[st].y, 0);
	vis[node[st].x][node[st].y] = true;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		if(now.x == node[ed].x && now.y == node[ed].y)	return	now.cnt;
		for(int i=0; i<4; i++) {
			int x = now.x + dis[i][0];
			int y = now.y + dis[i][1];
			if(x < 1 || y < 1)	continue;
			if(x > n || y > m)	continue;
			if(vis[x][y])		continue;
			if(s[x][y] == 'D')	continue;
			vis[x][y] = true;
			nex = Node(x, y, now.cnt+1);
			q.push(nex);
		}
	}
	return inf;
}

void getdis() {
	for(int i=1; i<=tol; i++) {
		maps[i][i] = 0;
		for(int j=1; j<i; j++) {
			maps[i][j] = maps[j][i] = bfs(i, j);
		}
	}
}

bool ok(int mid) {
	mes(dp, -1);
	dp[1<<(st-1)][st] = mid;
	for(int i=0; i<state; i++) {
		for(int u=1; u<=tol; u++) {
			if(dp[i][u] == -1 || !(i&(1<<(u-1))))	continue;
			for(int v=1; v<=tol; v++) {
				if(maps[u][v] == inf)	continue;
				if(i & (1<<(v-1)))		continue;
				if(dp[i][u] - maps[u][v] < 0)	continue;
				if(s[node[v].x][node[v].y] == 'G')
					dp[i|(1<<(v-1))][v] = mid;
				else
					dp[i|(1<<(v-1))][v] = max(dp[i|(1<<(v-1))][v], dp[i][u] - maps[u][v]);
			}
		}
	}
	for(int i=1; i<=tol; i++)	
		if(dp[state][i] != -1)	
			return true;
	return false;
}

int main() {
	while(scanf("%d%d", &n, &m), n||m) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%s", s[i]+1);
			for(int j=1; j<=m; j++) {
				if(s[i][j] == 'F') {
					node[++tol] = Node(i, j);
					st = tol;
					state |= (1<<(tol-1));
				} else if(s[i][j] == 'G') {
					node[++tol] = Node(i, j);
				} else if(s[i][j] == 'Y') {
					node[++tol] = Node(i, j);
					state |= (1<<(tol-1));
				}
			}
		}
		getdis();
		// for(int i=1; i<=tol; i++) {
		//     printf("%d %d\n", node[i].x, node[i].y);
		// }
		// for(int i=1; i<=tol; i++) {
		//     for(int j=1; j<=tol; j++) {
		//         printf("%d%c", maps[i][j], j==tol ? '\n' : ' ');
		//     }
		// }
		int l = 0, r = n*m-1, ans = -1;
		while(l <= r) {
			int mid = l+r >> 1;
			if(ok(mid)) {
				ans = mid;
				r = mid-1;
			} else {
				l = mid+1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

