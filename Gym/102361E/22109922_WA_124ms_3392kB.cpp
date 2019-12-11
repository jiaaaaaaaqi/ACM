/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 07 Oct 2019 04:15:01 PM CST
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn][maxn];
int be[maxn], ed[maxn];

struct Node {
    int v, w;
    int next;
};
Node node[maxm << 1];
int head[maxm];
int dep[maxm];

void init() {
    tol = 0;
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
        if(u == des)    return true;
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
    if(src == des)  return flow;
    int ans = 0;
    for(int i = head[src]; ~i; i = node[i].next) {
        int v = node[i].v;
        if(dep[v] == dep[src] + 1 && node[i].w) {
            int tmp = dfs(v, des, min(node[i].w, flow - ans));
            node[i].w -= tmp;
            node[i^1].w += tmp;
            ans += tmp;
            if(ans == flow) return ans;
        }
    }
    if(!ans)    dep[src] = -2;
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

int ok(int i, int j) {
	if(s[i][j] == '1')	return 0;
	if(i<1 || j<1)	return 0;
	if(i>n || j>m)	return 0;
	return 1;
}

int id(int i, int j) {
	return (i-1)*m+j;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		init();
		int c1, c2;
		scanf("%d%d%d%d", &n, &m, &c1, &c2);
		for(int i=1; i<=n; i++) {
			scanf("%s", s[i]+1);
		}
		for(int i=1; i<=c1; i++)	scanf("%d", &be[i]);
		for(int i=1; i<=c2; i++)	scanf("%d", &ed[i]);
		int src = 0, des = n*m*2+1;
		for(int i=1; i<=c1; i++) {
			addnode(src, id(1, be[i]), 1);
			addnode(id(1, be[i]), src, 0);
		}
		for(int i=1; i<=c2; i++) {
			addnode(id(n, ed[i]), des, 1);
			addnode(des, id(n, ed[i]), 0);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(s[i][j] == '1')	continue;
				addnode(id(i, j), id(i, j)+n*m, 1);
				addnode(id(i, j)+n*m, id(i, j), 0);

				addnode(id(i, j)+n*m, id(i, j), 1);
				addnode(id(i, j), id(i, j)+n*m, 0);
				if(ok(i-1, j)) {
					addnode(id(i, j), id(i-1, j), 1);
					addnode(id(i-1, j), id(i, j), 0);
				}
				if(ok(i+1, j)) {
					addnode(id(i, j), id(i+1, j), 1);
					addnode(id(i+1, j), id(i, j), 0);
				}
				if(ok(i, j-1)) {
					addnode(id(i, j)+n*m, id(i, j-1)+n*m, 1);
					addnode(id(i, j-1)+n*m, id(i, j)+n*m, 0);
				}
				if(ok(i, j+1)) {
					addnode(id(i, j)+n*m, id(i, j+1)+n*m, 1);
					addnode(id(i, j+1)+n*m, id(i, j)+n*m, 0);
				}
			}
		}
		dinic(src, des)==c2 ? puts("Yes") : puts("No");
	}
	return 0;
}

