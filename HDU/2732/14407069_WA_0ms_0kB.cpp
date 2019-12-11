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
const int maxn = 100;
const int maxm = 1000100;
using namespace std;

int n, m, tol;
struct Node {
	int u;
	int v;
	int w;
	int next;
};
Node node[maxm];
int d;
int dep[maxm];
int head[maxm];
char str[maxn][maxn];
char str1[maxn][maxn];

void init() {
	tol = 0;
	memset(dep, 0, sizeof(dep));
	memset(str, 0, sizeof(str));
	memset(str1, 0, sizeof(str1));
	memset(head, -1, sizeof(head));
}

void addnode(int u, int v, int w) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

bool isok(int i, int j) {
	if(i <= d || i+d > n || j <= d || j + d > m)
		return true;
	return false;
}

int dis(int x1, int y1, int x2, int y2) {
	int d1 = sqrt((x1 - x2) * (x1 * x2) + (y1 - y2) * (y1 - y2));
	int d2 = (float)d;
	if(d1 > d2)	return true;
	else	return false;
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
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		int ans1 = 0;
		int ans2 = 0;
		init();
		scanf("%d%d", &n, &d);
		for(int i=1; i<=n; i++) {
			if(i == 1) {
				scanf("%s", str[i]);
				m = strlen(str[1]);
				strcpy(str[i] + 1, str[i]);
			} else {
				scanf("%s", str[i] + 1);
			}
		}
		int src = 0;
		int des = n * m * 2 + 1;
		for(int i=1; i<=n; i++) {
			scanf("%s", str1[i]+1);
			for(int j=1; j<=m; j++) {
				if(str1[i][j] == 'L') {
					ans1 ++;
					addnode(src, (i-1)*m+j, 1);
					addnode((i-1)*m+j, src, 0);
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(str[i][j] == '0')	continue;
				addnode((i-1)*m+j, (i-1)*m+j+n*m, str[i][j] - '0');
				addnode((i-1)*m+j+n*m, (i-1)*m+j, 0);
				if(isok(i, j)) {
					addnode((i-1)*m+j+n*m, des, inf);
					addnode(des, (i-1)*m+j+n*m, 0);
				} else {
					for(int ii=-d; ii<=d; ii++) {
						for(int jj=-d; jj<=d; jj++) {
							int x = i + ii;
							int y = j + jj;
							if(x == i && y == j)	continue;
							if(dis(i, j, x, y))	continue;
							if(str[x][y] == '0')	continue;
							addnode((i-1)*m+j+n*m, (x-1)*m+y, inf);
							addnode((x-1)*m+y, +n*m, 0);
						}
					}
				}
			}
		}
		ans2 = dinic(src, des);
		int ans = ans1 - ans2;
		printf("Case #%d: ",cas++);
        if(ans > 1) printf("%d lizards were left behind.\n",ans);
        else if (ans == 1) printf("1 lizard was left behind.\n");
        else if (ans == 0) printf("no lizard was left behind.\n");
	}
	return 0;
}
