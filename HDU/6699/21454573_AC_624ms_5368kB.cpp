/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月21日 星期三 12时30分12秒
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
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 2e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    int x, y;
    Node() {}
    Node(int xx, int yy) {
        x = xx, y = yy;
    }
};
int dir[4][2] = {
    -1, 0, 1, 0, 0, 1, 0 ,-1
};
bool vis[maxn][maxn];

bool ok(int x, int y) {
    if(vis[x-1][y]==0 && vis[x+1][y]==0)    return 0;
    if(vis[x][y-1]==0 && vis[x][y+1]==0)    return 0;
    return 1;
}

int bfs(int x, int y) {
    if(vis[x][y] == 1)    return 0;
    vis[x][y] = 1;
    int ans = 1;
    queue<Node> q;
    q.push(Node(x, y));
    while(!q.empty()) {
        Node now = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = now.x+dir[i][0];
            int ny = now.y+dir[i][1];
            if(nx<=0 || ny<=0 || nx>n || ny>m || vis[nx][ny])    continue;
            if(ok(nx, ny)) {
                ans++;
                vis[nx][ny] = 1;
                q.push(Node(nx, ny));
            }
        }
    }
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        int q;
        scanf("%d%d%d", &n, &m, &q);
        mes(vis, 0);
        while(q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int ans = bfs(x, y);
            printf("%d\n", ans);
        }
    }
    return 0;
}