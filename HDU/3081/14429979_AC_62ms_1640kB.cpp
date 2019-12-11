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
const int maxn = 250;
const int maxm = 20050;
using namespace std;

int n, m, tol;
struct Node {
    int v;
    int w;
    int next;
};
Node node[maxm];
int head[maxn];
int dep[maxn];
int fath[maxn];
bool vis[maxn][maxn];

void init1() {
    memset(vis, false, sizeof vis);
    for(int i=0; i<=n; i++)
        fath[i] = i;
}

void init2() {
    tol = 0;
    memset(head, -1, sizeof head);
}

int find(int x) {
    return fath[x] == x ? x : fath[x] = find(fath[x]);
}

void bind(int u, int v) {
    int x = find(u);
    int y = find(v);
    if(x == y)	return ;
    else	fath[x] = y;
}

void addnode(int u, int v, int w) {
    node[tol].v = v;
    node[tol].w = w;
    node[tol].next = head[u];
    head[u] = tol++;
}

void getmap(int src, int des, int k) {
	init2();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
			if(vis[i][j]) {
				addnode(i, n + j, 1);
				addnode(n + j, i, 0);
			}
        }
        addnode(src, i, k);
        addnode(i, src, 0);
        addnode(n + i, des, k);
        addnode(des, n + i, 0);
    }
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
    scanf("%d", &T);
    while(T--) {
        int f;
        scanf("%d%d%d", &n, &m, &f);
        init1();
        for(int i=1; i<=m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            vis[u][v] = true;
        }
        for(int i=1; i<=f; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            bind(u, v);
        }
        for(int i=1; i<=n; i++) {
			find(i);
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j)	continue;
                if(fath[i] == fath[j]) {
                    for(int k=1; k<=n; k++) {
                        if(vis[i][k])	vis[j][k] = true;
                        if(vis[j][k])	vis[i][k] = true;
                    }
                }
            }
        }
        int ans = 0;
        int left = 0;
        int right = n;
        int src = 0;
        int des = n + n + 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            getmap(src, des, mid);
            int res = dinic(src, des);
            if(mid * n == res) {
				ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
