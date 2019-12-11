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

struct edge {
	int to, capacity, cost, rev;
	edge() {}
	edge(int to, int _capacity, int _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
struct Mcmf {
	int V, H[maxn + 5], dis[maxn + 5], PreV[maxn + 5], PreE[maxn + 5];
	vector<edge> G[maxn + 5];
	//调用前初始化
	void init(int n) {
		V = n;
		for (int i = 0; i <= V; ++i)G[i].clear();
	}
	//加边
	void addnode(int from, int to, int cap, int cost) {
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}
	//flow是自己传进去的变量，就是最后的最大流，返回的是最小费用
	int MCMF(int s, int t, int f, int& flow) {
		int res = 0; fill(H, H + 1 + V, 0);
		while (f) {
			priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
			fill(dis, dis + 1 + V, inf);
			dis[s] = 0; q.push(pair<int, int>(0, s));
			while (!q.empty()) {
				pair<int, int> now = q.top(); q.pop();
				int v = now.second;
				if (dis[v] < now.first)continue;
				for (int i = 0; i < G[v].size(); ++i) {
					edge& e = G[v][i];
					if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
						dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
						PreV[e.to] = v;
						PreE[e.to] = i;
						q.push(pair<int, int>(dis[e.to], e.to));
					}
				}
			}
			if (dis[t] == inf)break;
			for (int i = 0; i <= V; ++i)H[i] += dis[i];
			int d = f;
			for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
			f -= d; flow += d; res += d*H[t];
			for (int v = t; v != s; v = PreV[v]) {
				edge& e = G[PreV[v]][PreE[v]];
				e.capacity -= d;
				G[v][e.rev].capacity += d;
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

