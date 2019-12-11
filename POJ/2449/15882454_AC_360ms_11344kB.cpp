#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)	x & (-x)
#define  mem(a, b)	memset(a, b, sizeof a)
#define  fi 		first
#define  se 		second
#define  INOPEM		freopen("in.txt", "r", stdin)
#define  OUTOPEN	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1050;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Edge {
	int fi;
	int se;
	Edge (int a, int b) {
		fi = a;
		se = b;
	}
};
vector< Edge > maps[maxn];
vector< Edge > rmaps[maxn];
struct Node {
	int u, g, h;
	bool operator < (Node a) const {
		return g + h > a.g + a.h;
	}
	Node (int a, int b, int c) {
		u = a;
		g = b;
		h = c;
	}
};
int dis[maxn];
int cnt[maxn];
bool vis[maxn];

void spfa(int s, int t) {
	memset(dis, inf, sizeof dis);
	memset(vis, 0, sizeof vis);
	queue<int > q;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		int len = rmaps[u].size();
		for (int i = 0; i < len; i++) {
			int v = rmaps[u][i].fi;
			int w = rmaps[u][i].se;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
};

int A_star(int s, int t, int k) {
	priority_queue<Node> q;
	memset(cnt, 0, sizeof cnt);
	q.push(Node(s, 0, dis[s]));
	while (!q.empty()) {
		Node now = q.top();
		q.pop();
		int u = now.u;
		// printf("%d %d %d\n", u, now.g, now.h);
		cnt[u]++;
		if (cnt[u] == k && u == t) {
			return now.g;
		}
		if (cnt[u] > k)	continue;
		int len = maps[u].size();
		for (int i = 0; i < len; i++) {
			int v = maps[u][i].fi;
			int w = maps[u][i].se;
			if (cnt[v] != k) {
				q.push(Node(v, now.g + w, dis[v]));
			}
		}
	}
	return -1;
}

int main() {
	while (cin >> n >> m) {
		for (int i = 0; i <= n; i++) {
			maps[i].clear();
			rmaps[i].clear();
		}
		int s, t, k;
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			maps[u].push_back(Edge(v, w));
			rmaps[v].push_back(Edge(u, w));
		}
		cin >> s >> t >> k;
		if (s == t)	k++;
		spfa(t, s);
		int ans = A_star(s, t, k);
		printf("%d\n", ans);
	}
	return 0;
}