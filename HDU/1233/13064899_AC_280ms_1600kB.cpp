#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct Node{
	int u;
	int v;
	int w;
}node[5000];
int tol;
int n;
int fa[5000];

void init() {
	memset(fa, -1, sizeof(fa));
	memset(node, 0, sizeof(node));
}

void addnode(int u, int v, int w) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol++].w = w;
}

bool cmp(Node a, Node b) {
	return a.w < b.w;
}

int find(int x) {
	return fa[x]==-1 ? x : fa[x]=find(fa[x]);
}

int Kruskal() {
	int ans=0;
	int cnt=0;
	for(int i=1; i<tol; i++) {
		int x = find(node[i].u);
		int y = find(node[i].v);
		int w = node[i].w;
		if(x != y) {
			ans += w;
			fa[x] = y;
			cnt++;
		}
		if(cnt == n-1)
			break;
	}
	return ans;
}

int main() {
	while(scanf("%d", &n), n) {
		init();
		int m = (n*(n-1)) / 2;
		tol=1;
		for(int i=1; i<=m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addnode(u, v, w);
		}
		sort(node, node+tol, cmp);
		int ans = Kruskal();
		printf("%d\n", ans);
	}
	return 0;
}