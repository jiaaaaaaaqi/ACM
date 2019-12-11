#include<map>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 500;
const int maxm = 1005;
using namespace std;

int n, f, d;
int maps[maxn][maxn];
int flow[maxn];
int pre[maxn];
//int dep[maxn];

void init() {
	memset(maps, 0, sizeof(maps));
	memset(flow, 0, sizeof(flow)); 
//	memset(dep, 0, sizeof(dep));
}
/*
bool bfs(int src, int des) {
	queue<int > q;
	while(!q.empty())	q.pop();
	q.push(src);
	memset(dep, 0, sizeof(dep));
	dep[src] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int v=src; v<=des; v++) {
			if(!dep[v] && maps[u][v]) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

int dfs(int src, int des, int flow) {
	if(src == des)	return flow;
	int ans = 0;
	for(int v=src; v<=des; v++) {
		if(dep[v] == dep[src] + 1 && maps[src][v]) {
			int val = dfs(v, des, min(flow - ans, maps[src][v]));
			maps[src][v] -= val;
			maps[v][src] += val;
			ans += val;
			if(ans == flow)	return ans;
		}
	}
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	int val;
	while(bfs(src, des)) {
		val = dfs(src, des, inf);
		ans += val;
	}
	return ans;
}
*/

queue<int> q;
int bfs(int src, int des) {
	while(!q.empty())	q.pop();
	memset(pre, -1, sizeof(pre));
	pre[src] = 0;
	flow[src] = inf;
	q.push(src);
	while(!q.empty()) {
		int index = q.front();
		q.pop();
		if(index == des)	break;
		for(int i=src; i<=des; i++) {
			if(i != src && maps[index][i] && pre[i] == -1) {
				pre[i] = index;
				flow[i] = min(flow[index], maps[index][i]);
				q.push(i);
			}
		}
	}
	if(pre[des] == -1)	return -1;
	else	return flow[des];
}

int EK(int src, int des) {
	int ans = 0;
	while(1) {
		int val = bfs(src, des);
		if(val == -1)	break;
		int last = des;
		while(last != src) {
			maps[pre[last]][last] -= val;
			maps[last][pre[last]] += val;
			last = pre[last];
		}
		ans += val;
	}
	return ans;
}

int main() {
	while(~scanf("%d%d%d", &n, &f, &d)) {
		int src = 0, des = 2 * n + f + d + 1;
		for(int i=1; i<=f; i++)	maps[src][i] = 1;
		for(int i=1; i<=d; i++)	maps[f + 2 * n + i][des] = 1;
		for(int i=1; i<=n; i++)	maps[f + i][f + n + i] = 1;
		for(int i=1; i<=n; i++) {
			int d1, d2;
			scanf("%d%d", &d1, &d2);
			while(d1--) {
				int v;
				scanf("%d", &v);
				maps[v][f + i] = 1;
			}
			while(d2--) {
				int v;
				scanf("%d", &v);
				maps[f + n + i][f + 2 * n + v] = 1;
			}
		}
		/*
		for(int i=src; i<=des; i++) {
			for(int j=src; j<=des; j++) {
				printf("%d%c", maps[i][j], j==des ? '\n' : ' ');
			}
		}
		*/
		int ans = EK(src, des);
		printf("%d\n", ans);
	}
	return 0;
}
