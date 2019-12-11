/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月13日 星期六 19时50分11秒
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

int n, m, K;
int cas, tol, T;

vector< pii > vv[maxn];
vector< pii > vvv[maxn];
bool vis[maxn];

/*************************************/
ll dis[maxn];
void spfa() {
	mes(vis, 0);
	queue<int> q;
	while(!q.empty())	q.pop();
	vis[1] = true;
	dis[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(auto it : vvv[u]) {
			int v = it.fi;
			int w = it.se;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u]+w;
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		} 
	}
}

void getmap(int u) {
	for(auto it : vvv[u]) {
		int v = it.fi;
		int w = it.se;
		if(dis[v]!=dis[u]+w || vis[v])	continue;
		vis[v] = true;
		vv[u].push_back(make_pair(v, w));
		vv[v].push_back(make_pair(u, w));
		getmap(v);
	}
}
/*************************************/

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &K);
		for(int i=1; i<=n; i++) {
			vv[i].clear();
			vvv[i].clear();
		}
		for(int i=1, u, v, w; i<=m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			vvv[u].push_back(make_pair(v, w));
			vvv[v].push_back(make_pair(u, w));
		}
		for(int i=1; i<=n; i++) {
			sort(vvv[i].begin(), vvv[i].end());
			dis[i] = INF;
		}
		spfa();
		mes(vis, 0);
		getmap(1);
	}
    return 0;
}

