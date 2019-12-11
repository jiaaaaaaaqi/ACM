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
const int maxn = 205;
using namespace std;

int n, m;
int maps[maxn][maxn];
int flow[maxn];
int pre[maxn];
queue<int> q;

void init() {
	memset(maps, 0, sizeof(maps));
	memset(flow, 0, sizeof(flow));
}

int bfs(int src, int des) {
	while(!q.empty())	q.pop();
	memset(pre, -1, sizeof(pre));
	flow[src] = inf;
	pre[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int index = q.front();
		q.pop();
		if(index == des)	break;
		for(int i=1; i<=des; i++) {
			if(maps[index][i] && pre[i] == -1 && i != index) {
				pre[i] = index;
				flow[i] = min(flow[index], maps[index][i]);
				q.push(i);
			}
		}
	}
	if(pre[des] == -1)	return -1;
	else	return flow[des];
}

int ek(int src, int des) {
	int maxflow = 0;
	int val = 0;
	while((val = bfs(src, des)) != -1) {
		int k = des;
		while(k != src) {
			int last = pre[k];
			maps[k][last] += val;
			maps[last][k] -= val;
			k = last;
		}
		maxflow += val;
	}
	return maxflow;
}

int main() {
	int mp, mc;
	int src, des;
	while(~scanf("%d%d%d%d", &n, &mp, &mc, &m)) {
		init();
		src = 0;
		des = n + 1;
		char str[100];
		for(int i=0; i<m; i++) {
			scanf("%s", str);
			int u, v, val;
			sscanf(str, "(%d,%d)%d", &u, &v, &val);
			if(u == v)	continue;
			maps[u + 1][v + 1] += val;
		}
		for(int i=0; i<mp; i++) {
			scanf("%s", str);
			int v, val;
			sscanf(str, "(%d)%d", &v, &val);
			maps[src][v + 1] += val;
		}
		for(int i=0; i<mc; i++) {
			scanf("%s", str);
			int u, val;
			sscanf(str, "(%d)%d", &u, &val);
			maps[u + 1][des] += val;
		}
		/*
		for(int i=src; i<=des; i++) {
			for(int j=src; j<=des; j++) {
				printf("%d%c", maps[i][j], j == des ? '\n' : ' ');
			}
		}
		*/
		int ans = ek(src, des);
		printf("%d\n", ans);
	}
	return 0;
}