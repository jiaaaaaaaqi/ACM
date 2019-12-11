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
const int maxm = 205;
using namespace std;

int n, m, tol;
struct Node{
	int u;
	int v;
	int w;
	bool used;
	bool del;
	bool operator < (Node a) const {
		return w < a.w;
	}
};
Node node[maxm];
int fa[maxn];
bool flag;

void init() {
	memset(node, 0, sizeof node);
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int kruskal() {
	int ans = 0;
	int cnt = 0;
	for(int i=1; i<=m; i++) {
		if(node[i].del)	continue;
		int x = find(node[i].u);
		int y = find(node[i].v);
		if(x != y) {
			fa[x] = y;
			ans += node[i].w;
			cnt++;
			if(flag)	node[i].used = true;
		}
		if(cnt == n - 1)	break;
	}
	return cnt == n - 1 ? ans : inf;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d", &node[i].u, &node[i].v, &node[i].w);
			node[i].used = node[i].del = false;
		}
		sort(node + 1, node + 1 + m);
		flag = true;
		for(int i=1; i<=n; i++)	fa[i] = i;
		int mst = kruskal();
		flag = false;
		if(mst == inf) {
			printf("Case #%d : No way\n", cas++);
			continue;
		}
		int smst = inf;
		for(int i=1; i<=m; i++) {
			if(node[i].used) {
				for(int i=1; i<=n; i++)	fa[i] = i;
				node[i].del = true;
				int preans = kruskal();
				smst = min(smst, preans);
				node[i].del = false;
			}
		}
		if(smst == inf || smst == mst) {
			printf("Case #%d : No second way\n", cas++);
		} else {
			printf("Case #%d : %d\n", cas++, smst);
		}
	}
	return 0;
}
