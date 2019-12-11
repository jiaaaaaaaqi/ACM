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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 5e4 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, T;

struct Node {
    int x, y, z;
    Node (int a, int b, int c) {
        x = a, y = b, z = c;
    }
    bool operator < (Node a) const {
        if(x != a.x)	return x<a.x;
        else if(y != a.y)	return y<a.y;
        else	return z<a.z;
    }
};
map<Node, int> mp[2];
vector<int> vv[2][maxn];
int tol[2], cc[maxn];
bool vis[maxn];
int dfn[maxn], low[maxn], sta[maxn], maps[maxn];
int top, stacksz, cnt;

int getid(Node a, int id) {
    if(!mp[id].count(a)) {
        mp[id][a] = ++tol[id];
        return tol[id];
    } else {
        return mp[id][a];
    }
}

void dfs(int id, int u, int fa) {
	int chong = 0;
	int v;
	dfn[u] = low[u] = ++cnt;
	vis[u] = true;
	sta[stacksz++] = u;
	for(auto v : vv[id][u]) {
		if(!dfn[v]) {
			dfs(id, v, u);
			low[u] = min(low[u], low[v]);
		} else if(v == fa) {
			if(chong)	low[u] = min(low[u], dfn[v]);
			chong++;
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		top++;
		do {
			v = sta[--stacksz];
			maps[v] = top;
			vis[v] = false;
		} while(v != u);
	}
}

bool solve(int id) {
	mes(dfn, 0);
	mes(low, 0);
	mes(vis, 0);
	mes(sta, 0);
	mes(maps, 0);
	top = stacksz = cnt = 0;
	n = tol[id];
	for(int u=1; u<=n; u++) {
		if(!dfn[u]) {
			dfs(id, u, u);
		}
	}
	mes(cc, 0);
	for(int i=1; i<=n; i++) {
		cc[maps[i]]++;
		if(cc[maps[i]] >= 3)	return true;
	}
	return false;
}

int main() {
	tol[0] = tol[1] = 0;
	mp[0].clear();
	mp[1].clear();
    scanf("%d", &n);
	for(int i=0; i<=n; i++) {
		vv[0][i].clear();
		vv[1][i].clear();
	}
    int x1, y1, z1, x2, y2, z2;
    bool f1, f2;
    f1 = false;
    f2 = false;
    Node node(0, 0, 0);
    for(int i=1; i<=n; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        int id1 = getid(Node(x1, y1, z1), 0);
        int id2 = getid(Node(x2, y2, z2), 0);
        if(id1 != id2) {
            vv[0][id1].push_back(id2);
            vv[0][id2].push_back(id1);
        }
        id1 = getid(Node(x1, y1, 0), 1);
        id2 = getid(Node(x2, y2, 0), 1);
        if(id1 != id2) {
            vv[1][id1].push_back(id2);
            vv[1][id2].push_back(id1);
        }
    }
    f1 = solve(0);
    f2 = solve(1);
    if(f1) {
        printf("True closed chains\n");
    } else {
        printf("No true closed chains\n");
    }
    if(f2) {
        printf("Floor closed chains\n");
    } else {
        printf("No floor closed chains\n");
    }
    return 0;
}
