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
const int    maxn = 1e5 + 10;
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
int ind[2][maxn];
int vis[maxn];

int getid(Node a, int id) {
    if(!mp[id].count(a)) {
        mp[id][a] = ++tol[id];
        return tol[id];
    } else {
        return mp[id][a];
    }
}
int cnt[maxn];
bool dfs(int id, int u, int fa, int x) {
	int tmp = cnt[fa]-cnt[u];
	if(tmp >= 2 && vis[u]==x)	return true;
	if(vis[u] == x)	return false;
	vis[u] = x;
	cnt[u] = cnt[fa]+1;
	for(auto v : vv[id][u]) {
		if(vis[v] && vis[u]!=x)	continue;
		if(v == fa)	continue;
		if(dfs(id, v, u, x))
			return true;
	}
	return false;
}

bool solve(int id) {
    mes(vis, 0);
    mes(cnt, 0);
    n = tol[id];
    for(int i=1; i<=n; i++) {
		if(vis[i] == 0) {
			cnt[i] = 0;
			if(dfs(id, i, i, i))
				return true;
		}
    }
    return false;
}

int main() {
    tol[0] = tol[1] = 0;
    mp[0].clear();
    mp[1].clear();
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        vv[0][i].clear();
        vv[1][i].clear();
    }
    int x1, y1, z1, x2, y2, z2;
    bool f1, f2;
    f1 = false;
    f2 = false;
    Node node(0, 0, 0);
    mes(ind, 0);
    for(int i=1; i<=n; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        int id1 = getid(Node(x1, y1, z1), 0);
        int id2 = getid(Node(x2, y2, z2), 0);
        if(id1 != id2) {
			vv[0][id1].push_back(id2);
			vv[0][id2].push_back(id1);
//			printf("%d %d\n", id1, id2);
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
