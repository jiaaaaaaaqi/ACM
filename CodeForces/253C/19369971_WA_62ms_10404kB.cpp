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

struct Node{
	int x, y;
	int cnt;
	Node () {}
	Node (int xx, int yy, int cc) {
		x = xx, y = yy, cnt = cc;
	}
};
int a[105];
bool vis[105][maxn];
int sx, sy, ex, ey;

Node go(Node u, int id) {
	Node v;
	v.cnt = u.cnt+1;
	if(id == 1) {
		v.x = max(1, u.x-1);
		v.y = min(u.y, a[v.x]);
	} else if(id == 2) {
		v.x = min(n, u.x+1);
		v.y = min(u.y, a[v.x]);
	} else if(id == 3) {
		v.x = u.x;
		v.y = max(1, u.y-1);
	} else if(id == 4) {
		v.x = u.x;
		v.y = max(a[v.x], u.y+1);
	}
	return v;
}

int bfs() {
	if(sx == ex && sy == ey)
		return 0;
	queue<Node> q;
	while(!q.empty())	q.pop();
	Node now, nex;
	now = Node(sx, sy, 0);
	vis[sx][sy] = 1;
	q.push(now);
	while(!q.empty()) {
		now = q.front();
		q.pop();
		for(int i=1; i<=4; i++) {
			nex = go(now, i);
			if(vis[nex.x][nex.y])
				continue;
			if(nex.x == ex && nex.y == ey)
				return nex.cnt;
			vis[nex.x][nex.y] = true;
			q.push(nex);
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	mes(vis, 0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i]++;
	}
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	int ans = bfs();
	printf("%d\n", ans);
    return 0;
}
