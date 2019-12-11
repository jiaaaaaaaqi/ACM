/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月19日 星期五 16时41分22秒
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

int ind[maxn];
int vis[maxn], res[maxn];
vector<int> vv[maxn];

struct cmp {
	bool operator ()(int &a, int &b) {
		return vis[a]==vis[b] ? a<b : vis[a] < vis[b];
	}
};

void topu() {
	priority_queue<int, vector<int>, cmp> q;
	for(int i=1; i<=n; i++) {
		if(ind[i] == 0)	q.push(i);
	}
	int cnt = 1;
	while(!q.empty()) {
		int u = q.top();
		res[u] = cnt++;
		q.pop();
		for(auto v : vv[u]) {
			vis[v] = min(vis[v], vis[u]);
			ind[v]--;
			if(ind[v] == 0)	q.push(v);
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d%c", n-res[i]+1, i==n ? '\n' : ' ');
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		vv[i].clear();
		vis[i] = i;
		res[i] = ind[i] = 0;	
	}
	for(int i=1, u, v; i<=m; i++) {
		scanf("%d%d", &u, &v);
		vv[v].push_back(u);
		ind[u]++;
	}
	topu();
	return 0;
}

