#include<map>
#include<set>
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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
const int maxm = 1000020;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
struct Node {
    int u, v, w, next;
    bool operator < (Node a) const {
        return w > a.w;
    }
};
Node node[maxm];
int cnt[maxn];
int dis[maxn];
bool vis[maxn];
int head[maxn];
int maps[50][50];

void init() {
    tol = 0;
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    memset(dis, inf, sizeof dis);
    memset(maps, 0, sizeof maps);
    memset(head, -1, sizeof head);
}

int getnum(int i, int j) {
    return (i-1)*m + j;
}

void addnode(int u, int v, int w) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].w = w;
    node[tol].next = head[u];
    head[u] = tol++;
}

int spfa(int st, int ed) {
    int all = ed;
    queue<int> q;
    vis[st] = true;
    dis[st] = 0;
    cnt[st]++;
    q.push(st);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        if(u==ed)
			continue;
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            int w = node[i].w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    vis[v] = true;
                    cnt[v]++;
                    if(cnt[v] >= all)	return -inf;
                    q.push(v);
                }
            }
        }
    }
    return dis[ed];
}

int main() {
    while(scanf("%d%d",  &m, &n), n||m) {
        init();
        int q;
        scanf("%d", &q);
        int x, y;
        while(q--) {
            scanf("%d%d", &x, &y);
            x++, y++;
            maps[y][x] = 1;
        }
        scanf("%d", &q);
        int x2, y2, t;
        while(q--) {
            scanf("%d%d%d%d%d", &x, &y, &x2, &y2, &t);
            x++, y++;
            x2++, y2++;
            maps[y][x] = 2;
            
            addnode(getnum(y, x), getnum(y2, x2), t);
        }
//		for(int i=1; i<=n; i++)	for(int j=1; j<=m; j++)	printf("%d%c", maps[i][j], j==m ? '\n' : ' ');
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(i == n && j == m)	continue;
                if(maps[i][j] == 0) {
                    if(i-1 >= 1 && maps[i-1][j] != 1)
                        addnode(getnum(i, j), getnum(i-1, j), 1);
                    if(j-1 >= 1 && maps[i][j-1] != 1)
                        addnode(getnum(i, j), getnum(i, j-1), 1);
                    if(i+1 <= n && maps[i+1][j] != 1)
                        addnode(getnum(i, j), getnum(i+1, j), 1);
                    if(j+1 <= m && maps[i][j+1] != 1)
                        addnode(getnum(i, j), getnum(i, j+1), 1);
                }

            }
        }
        int ans = spfa(getnum(1, 1), getnum(n, m));
        if(ans == -inf)	printf("Never\n");
        else if(ans == inf)	printf("Impossible\n");
        else	printf("%d\n", ans);
    }
    return 0;
}
