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
const int maxn = 105;
const int maxm = 100005;
using namespace std;

int n, m;
int maps[maxn][maxn];
int flow[maxn];
int pre[maxn];
int tmp[maxn][maxn];
int inp[maxn][maxn];
int oup[maxn][maxn];
int res[maxm][3];
queue<int> q;

void init() {
	memset(inp, 0, sizeof(inp));
	memset(oup, 0, sizeof(oup));
	memset(tmp, 0, sizeof(tmp));
	memset(res, 0, sizeof(res));
	memset(maps, 0, sizeof(maps));
	memset(flow, 0, sizeof(flow));
}

void getmap() {
	int src = 0;
	int des = 2 * m + 1;
	int val;
	for(int i=1; i<=m; i++) {
		scanf("%d", &val);
		maps[i][i+m] = val;
		bool flag = true;
		for(int j=1; j<=n; j++) {
			scanf("%d", &inp[i][j]);
			if(inp[i][j] == 1)	flag = false;
		}
		if(flag)
			maps[src][i] = inf;
		flag = true;
		for(int j=1; j<=n; j++) {
			scanf("%d", &oup[i][j]);
			if(oup[i][j] == 0)	flag = false;
		}
		if(flag)
			maps[i + m][des] = inf;
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			if(i == j)	continue;
			int flag = true;
			for(int k=1; k<=n; k++) {
				if(oup[i][k] == 1 && inp[j][k] == 0)	flag = false;
				if(oup[i][k] == 0 && inp[j][k] == 1)	flag = false;
			}
			if(flag)
				maps[i+m][j] = inf;
		}
	}
}

int bfs(int src, int des) {
	while(!q.empty())	q.pop();
	memset(pre, -1, sizeof(pre));
	q.push(src);
	pre[src] = 0;
	flow[src] = inf;
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

int solve() {
	int ans = 0;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			if(tmp[i + m][j] - maps[i + m][j] > 0) {
				res[ans][0] = i;
				res[ans][1] = j;
				res[ans][2] = tmp[i + m][j] - maps[i + m][j];
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		getmap();
		int src = 0;
		int des = 2 * m + 1;
		/*
		for(int i=src; i<=des; i++) {
			for(int j=src; j<=des; j++) {
				printf("%d%c", maps[i][j], j==des ? '\n' : '\t');
			}
		}
		*/
		memcpy(tmp, maps, sizeof(maps));
		int ans = EK(src, des);
		int tol = solve();
		printf("%d %d\n", ans, tol);
		for(int i=0; i<tol; i++) {
			printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
		}
	}
	return 0;
}
