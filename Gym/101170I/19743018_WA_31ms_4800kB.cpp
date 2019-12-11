/***************************************************************
    > File Name    : I.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月15日 星期三 02时21分19秒
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

int n, m, k;
int cas, tol, T;

bool vis[maxn];
ll dis[3][maxn];
vector<int> ore, coal;
vector<int> vv[2][maxn];
struct Node{
	int u;
	ll cnt;
	Node() {
	}
	Node(int _u, ll _cnt) {
		u = _u, cnt = _cnt;
	}
};

void bfs(vector<int> vec, int p, int id) {
	queue<Node> q;
	mes(vis, 0);
	while(!q.empty())	q.pop();
	Node now, nex;
	for(auto i : vec) {
		q.push(Node(i, 0));
		vis[i] = true;
	}
	while(!q.empty()) {
		now = q.front();
		q.pop();
		int u = now.u;
		ll cnt = now.cnt;
		dis[id][u] = cnt;
		for(auto v : vv[p][u]) {
			if(vis[v])	continue;
			vis[v] = true;
			q.push(Node(v, cnt+1));
		}
	}
}

int solve() {
	for(int i=0; i<=2; i++) {
		for(int j=1; j<=n; j++) {
			dis[i][j] = INF;
		}
	}
	vector<int> tp;
	tp.clear();
	tp.push_back(1);
	bfs(tp, 0, 0);
	bfs(ore, 1, 1);
	bfs(coal, 1, 2);
	ll ans = INF;
	for(int i=1; i<=n; i++) {
		ans = min(ans, dis[0][i] + dis[1][i] + dis[2][i]);
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; i++) {
		vv[0][i].clear();
		vv[1][i].clear();
	}
	ore.clear();
	coal.clear();
	for(int i=1, x; i<=m; i++) {
		scanf("%d", &x);
		ore.push_back(x);
	}
	for(int i=1, x; i<=k; i++) {
		scanf("%d", &x);
		coal.push_back(x);
	}
	for(int i=1, num, v; i<=n; i++) {
		scanf("%d", &num);
		while(num--) {
			scanf("%d", &v);
			vv[0][i].push_back(v);
			vv[1][v].push_back(i);
		}
	}
	ll ans = solve();
	if(ans == INF)	puts("impossible");
	else	printf("%d\n", ans);
	return 0;
}

