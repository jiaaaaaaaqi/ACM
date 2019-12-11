#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int v;
    int next;
} node[maxm];
int fa[maxn];
int cnt[maxn];
bool vis[maxn];
int head[maxn];
vector<int> vec[maxn];

void init() {
    tol = 1;
    mes(vis, 0);
    mes(cnt, 0);
    mes(head, -1);
	for(int i=1; i<=n; i++) {
		fa[i] = i;
		vec[i].clear();
	}
}

void addnode(int u, int v) {
    node[tol].v = v;
    node[tol].next = head[u];
    head[u] = tol++;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void bind(int u, int v) {
	int x = find(u);
	int y = find(v);
	if(x != y) {
		fa[y] = x;
	}
}

void lca(int u) {
	fa[u] = u;
	vis[u] = 1;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		if(vis[v])	continue;
		lca(v);
		bind(u, v);
	}
	int len = vec[u].size();
	for(int i=0; i<len; i++) {
		int v = vec[u][i];
		if(vis[v]) {
			cnt[find(v)]++;
		}
	}
}

int main() {
	while(~scanf("%d", &n)) {
		init();
        int u, v;
        for(int i=1; i<=n; i++) {
            scanf("%d:(%d)", &u, &m);
            while(m--) {
                scanf("%d", &v);
                addnode(u, v);
                vis[v] = true;
            }
        }
        scanf("%d", &m);
        while(m--) {
            scanf(" (%d %d)", &u, &v);
			vec[u].push_back(v);
        }
        for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				mes(vis, 0);
				lca(i);
			}
        }
        for(int i=1; i<=n; i++) {
			if(cnt[i]) {
				printf("%d:%d\n", i, cnt[i]);
			}
        }
	}
	return 0;
}
