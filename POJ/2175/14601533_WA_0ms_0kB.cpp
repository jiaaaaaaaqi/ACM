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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 25000;
const int maxm = 205;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
struct Node {
    int u;
    int v;
    int w;
    int val;
    int next;
};
int head[maxn];
Node node[maxn * 10];
struct Edge {
    int x;
    int y;
    int num;
};
Edge edge1[105];
Edge edge2[105];
int maps[maxm][maxm];
int cnt[maxm];
int pre[maxm];
int vis[maxm];
int dis[maxm];
int num[maxm];

void init() {
    tol = 0;
    memset(maps, 0, sizeof maps);
    memset(node, 0, sizeof node);
    memset(head, -1, sizeof head);
    memset(edge1, 0, sizeof edge1);
    memset(edge2, 0, sizeof edge2);
}

void addnode(int u, int v, int w, int val) {
    node[tol].u = u;
    node[tol].v = v;
    node[tol].w = w;
    node[tol].val = val;
    node[tol].next = head[u];
    head[u] = tol++;
}

int calcdis(int i, int j) {
    int x1 = edge1[i].x;
    int x2 = edge2[j].x;
    int y1 = edge1[i].y;
    int y2 = edge2[j].y;
    int ans = abs(x1 - x2) + abs(y1 - y2);
    return ans;
}

int spfa(int src, int tolnum) {
    memset(dis, inf, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    memset(pre, -1, sizeof pre);
    memset(vis, 0, sizeof vis);
    queue<int > q;
    dis[src] = 0;
    cnt[src] = 1;
    vis[src] = true;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i=head[u]; ~i; i=node[i].next) {
            int v = node[i].v;
            if(node[i].w && dis[v] > dis[u] + node[i].val) {
                dis[v] = dis[u] + node[i].val;
                pre[v] = i;
                if(!vis[v]) {
                    cnt[v]++;
                    vis[v] = true;
                    q.push(v);
                    if(cnt[v] > tolnum)	return v;
                }
            }
        }
    }
    return -1;
}

int find(int i) {
	int x;
    memset(vis, false, sizeof vis);
    while(1) {
        x = node[i].v;
        if(vis[x])	break;
        vis[x] = true;
        x = pre[node[i].u];
    }
    return x;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i=1; i<=n; i++) scanf("%d%d%d", &edge1[i].x, &edge1[i].y, &edge1[i].num);
        for(int i=1; i<=m; i++) scanf("%d%d%d", &edge2[i].x, &edge2[i].y, &edge2[i].num);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d", &maps[i][j]);
                num[j] += maps[i][j];
            }
        }
        int src = 0;
        int des = n + m + 1;
        for(int i=1; i<=n; i++) {
            addnode(src, i, 0, 0);
            addnode(i, src, edge1[i].num, 0);
        }
        for(int i=1; i<=m; i++) {
            addnode(i + n, des, edge2[i].num - num[i], 0);
            addnode(des, i + n, num[i], 0);
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                addnode(i, j + n, inf, calcdis(i, j));
                addnode(j + n, i, maps[i][j], -calcdis(i, j));
            }
        }
        int x = spfa(des, des);
        if(x == -1) {
            printf("OPTIMAL\n");
            continue;
        }
        x = find(pre[x]);
        memset(vis, false, sizeof vis);
        for(int i=pre[x]; ~i; i = pre[node[i].u]) {
            int u = node[i].u;
            int v = node[i].v;
            if(u > v)	swap(u, v);
            if(u >= 1 && u <= n && v >= n + 1 && v <= n + m) {
                maps[u][v - n]++;
            }
            if(vis[u] && vis[v])	break;
            vis[u] = vis[v] = true;
        }
        printf("SUBOPTIMAL\n");
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                printf("%d%c", maps[i][j], j==m ? '\n' : ' ');
            }
        }
    }
    return 0;
}
