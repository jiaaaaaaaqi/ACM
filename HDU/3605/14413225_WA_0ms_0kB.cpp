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
const int maxn = 2000;
const int maxm = 200000;
using namespace std;

int n, m, tol;
struct Node{
	int v;
	int w;
	int next;
};
Node node[maxm];
int num[maxn];
int dep[maxm];
int head[maxm];
map<int, int> mp;

void init() {
	tol = 0;
	mp.clear();
	memset(num, 0, sizeof(num));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool bfs(int src, int des) {
	queue<int > q;
	memset(dep, -1, sizeof(dep));
	dep[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == des)	return true;
		for(int i = head[u]; ~i; i = node[i].next) {
			int v = node[i].v;
			if(dep[v] == -1 && node[i].w) {
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
	for(int i = head[src]; ~i; i = node[i].next) {
		int v = node[i].v;
		if(dep[v] == dep[src] + 1 && node[i].w) {
			int tmp = dfs(v, des, min(node[i].w, flow - ans));
			node[i].w -= tmp;
			node[i^1].w += tmp;
			ans += tmp;
			if(ans == flow)	return ans;
		}
	}
	if(!ans)	dep[src] = -2;
	return ans;
}

int dinic(int src, int des) {
	int ans = 0;
	int tmp;
	while(bfs(src, des)) {
		while((tmp = dfs(src, des, inf)) > 0)
			ans += tmp;
	}
	return ans;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i=1; i<=n; i++) {
			int ans = 0;
			int val;
			for(int j=1; j<=m; j++) {
				ans <<= 1;
				scanf("%d", &val);
				ans |= 1;
			}
			mp[ans]++;
		}
		for(int i=0; i<m; i++) {
			scanf("%d", &num[i]);
		}
		int src = 0;
		int des = (1 << m) + m + 1;
		int mx = 1 << m;
		for(int i=1; i<=mx; i++) {
			if(!mp[i])	continue;
			int val = i;
			addnode(src, i, mp[i]);
			int pos = 0;
			while(val) {
				if(val & 1)
					addnode(i, mx + pos, mp[i]);
				val >>= 1;
				pos++;
			}
		}
		for(int i=0; i<m; i++) {
			addnode(mx + i, des, num[i]);
		}
		if(dinic(src, des) == n)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
