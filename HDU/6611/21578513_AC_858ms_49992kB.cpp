/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月31日 星期六 10时06分11秒
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
const int    maxn = 4e3 + 100;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Edge {
	int to, cap, cost, rev;
	Edge() {}
	Edge(int to, int _cap, int _cost, int _rev) :to(to), cap(_cap), cost(_cost), rev(_rev) {}
};
struct Mcmf {
	int n, H[maxn], dis[maxn], preV[maxn], preE[maxn];
	vector<Edge> vv[maxn];

	void init(int nn) {
		n = nn;
		for (int i = 0; i <= n; ++i)	vv[i].clear();
	}

	void addnode(int u, int v, int cap, int cost) {
		vv[u].push_back(Edge(v, cap, cost, vv[v].size()));
		vv[v].push_back(Edge(u, 0, -cost, vv[u].size() - 1));
	}

	int MCMF(int src, int des, int f, int& flow) {	//初始 f 传inf
		int res = 0; fill(H, H+1+n, 0);
		while (f) {
			priority_queue<pii, vector<pii>, greater<pii> > q;
			fill(dis, dis+1+n, inf);
			dis[src] = 0;
			q.push(pii(0, src));
			while (!q.empty()) {
				pii now = q.top();
				q.pop();
				int v = now.se;
				if (dis[v] < now.fi)	continue;
				for (int i=0; i<vv[v].size(); i++) {
					Edge& e = vv[v][i];
					if (e.cap > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
						dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
						preV[e.to] = v;
						preE[e.to] = i;
						q.push(pii(dis[e.to], e.to));
					}
				}
			}
			if (dis[des] == inf)	break;
			for (int i=0; i<=n; ++i)	H[i] += dis[i];
			int d = f;
			for (int v=des; v!=src; v=preV[v])	d = min(d, vv[preV[v]][preE[v]].cap);
			f -= d; flow += d; res += d*H[des];
			for (int v=des; v!=src; v=preV[v]) {
				Edge& e = vv[preV[v]][preE[v]];
				e.cap -= d;
				vv[v][e.rev].cap += d;
			}
		}
		return res;
	}
}mcmf;
int a[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		int src = n+n+1, ssrc = n+n+2;
		int des = n+n+4, ddes = n+n+3;
		mcmf.init(des);
		mcmf.addnode(src, ssrc, m, 0);
		mcmf.addnode(ddes, des, m, 0);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		for(int i=1; i<=n; i++) {
			mcmf.addnode(ssrc, i, 1, -a[i]);
			mcmf.addnode(i, i+n, 1, 0);
			for(int j=i+1; j<=n; j++) {
				if(a[i] <= a[j]) {
					mcmf.addnode(i+n, j, 1, -a[j]);
				}
			}
			mcmf.addnode(i+n, ddes, 1, 0);
		}
		int flow;
		int ans = mcmf.MCMF(src, des, inf, flow);
		printf("%d\n", -ans);
	}
    return 0;
}

