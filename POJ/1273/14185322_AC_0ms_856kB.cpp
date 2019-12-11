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
	pre[src] = 0;
	flow[src] = inf;
	q.push(src);
	while(!q.empty()) {
		int index = q.front();
		q.pop();
		if(index == des)	break;
		for(int i=1; i<=n; i++) {
			if(i != src && pre[i] == -1 && maps[index][i]) {
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
	int val;
	while(1) {
		val = bfs(src, des);
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
	while(~scanf("%d%d", &m, &n)) {
		init();
		int u, v, val;
		while(m--) {
			scanf("%d%d%d", &u, &v, &val);
			maps[u][v] += val;
		}
		printf("%d\n", EK(1, n));
	}
	return 0;
}
