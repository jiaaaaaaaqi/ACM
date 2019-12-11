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
const int maxn = 110;
const int maxm = 1000000;
using namespace std;

int n, m, tol;
struct Node {
	int v;
	int w;
	int next;
};
Node node[maxm];
struct Edge {
	int rsum, rindex;
	int psum, pindex;
	int windex;
	bool white;
	int index;
	Edge() {
		rsum = psum = 0;
		white = false;
	}
};
Edge edge[maxn][maxn];
int dep[maxm];
int head[maxm];
int rnum, pnum, wnum;

void init() {
	tol = 0;
	rnum = pnum = wnum = 0;
	memset(node, 0, sizeof(node));
	memset(edge, 0, sizeof(edge));
	memset(head, -1, sizeof(head));
}

void change(char *str, Edge &e) {
	if(strcmp(str, "XXXXXXX") == 0) {
		return ;
	} else if(strcmp(str, ".......") == 0) {
		e.white = true;
		e.windex = ++wnum;
		return ;
	}
	if(isdigit(str[0])) {
		int num = (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0');
		e.psum = num;
		e.pindex = ++pnum;
	}
	if(isdigit(str[4])) {
		int num = (str[4] - '0') * 100 + (str[5] - '0') * 10 + (str[6] - '0');
		e.rsum = num;
		e.rindex = ++rnum;
	}
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
		char str[100];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%s", str);
				change(str, edge[i][j]);
			}
		}
		int src = pnum + rnum + wnum + wnum + 1;
		int des = src + 1;
		int rst = wnum + wnum;
		int pst = rst + rnum;
		for(int i=1; i<=n; i++) {
			int pos;
			int k;
			for(int j=1; j<=m; j++) {
				if(edge[i][j].rsum > 0) {
					k = edge[i][j].rindex;
					addnode(src, rst + k, edge[i][j].rsum);
					addnode(rst + k, src, 0);
					pos = tol - 2;
				}
				if(edge[i][j].white) {
					int t = edge[i][j].windex;
					node[pos].w -= 1;
					addnode(rst + k, t, 8);
					addnode(t, rst + k, 0);
					addnode(t, t + wnum, 8);
					addnode(t + wnum, t, 0);
					edge[i][j].index = tol - 1;
				}
			}
		}
		for(int j=1; j<=m; j++) {
			int pos;
			int k;
			for(int i=1; i<=n; i++) {
				if(edge[i][j].psum > 0) {
					k = edge[i][j].pindex;
					addnode(pst + k, des, edge[i][j].psum);
					addnode(des, pst + k, 0);
					pos = tol - 2;
				}
				if(edge[i][j].white) {
					int t = edge[i][j].windex;
					node[pos].w -= 1;
					addnode(wnum + t, pst + k, 8);
					addnode(pst + k, wnum + t, 0);
				}
			}
		}
		dinic(src, des);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(edge[i][j].white) {
					printf("%d", node[edge[i][j].index].w + 1);
				} else {
					printf("_");
				}
				printf("%c", j == m ? '\n' : ' ');
			}
		}
	}
	return 0;
}
