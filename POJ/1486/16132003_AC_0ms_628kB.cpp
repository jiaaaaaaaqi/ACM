#include<stdio.h>
#include<string.h>
#include <queue>
#include<iostream>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int, int> P;
const int MAXN = 30;
int uN, vN;
int g[MAXN][MAXN], linker[MAXN], tmp[MAXN];
bool used[MAXN];
// bool dfs(int u) {
//     for (int v = 0; v < vN; v++)
//         if (g[u][v] && !used[v]) {
//             used[v] = 1;
//             if (linker[v] == -1 || dfs(linker[v])) {
//                 linker[v] = u;
//                 return 1;
//             }
//         }
//     return 0;
// }
// int hungary() {
//     int res = 0;
//     memset(linker, -1, sizeof(linker));
//     for (int u = 0; u < uN; u++) {
//         memset(used, 0, sizeof used);
//         if (dfs(u)) res++;
//     }
//     return res;
// }

bool dfs(int u) {
    for (int v = 0; v < vN; v++) {
        if (g[u][v] && !used[v]) {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    memset(linker, -1, sizeof linker);
    int ans = 0;
    for (int i = 0; i < uN; i++) {
        memset(used, 0, sizeof used);
        if (dfs(i))
            ans++;
    }
    return ans;
}

struct node {
    int x1, x2, y1, y2;
} p[30];
bool inside(P &u, node &v) {
    if (u.first > v.x1 && u.first < v.x2 && u.second > v.y1 && u.second < v.y2) return true;
    return false;
}
struct Edge {
    int u, v;
    bool operator < (Edge a) const {
        return u > a.u;
    }
    Edge () {

    }
    Edge (int a, int b) {
        u = a, v = b;
    }
};

int main() {
    int Heap = 1;
    while (scanf("%d", &uN), uN) {
        memset(g, 0, sizeof g);
        vN = uN;
        for (int i = 0; i < uN; i++)
            scanf("%d %d %d %d", &p[i].x1, &p[i].x2, &p[i].y1, &p[i].y2);
        P t;
        for (int i = 0; i < uN; i++) {
            scanf("%d %d", &t.first, &t.second);
            for (int j = 0; j < uN; j++)
                if (inside(t, p[j]))
                    g[j][i] = 1;
        }
        printf("Heap %d\n", Heap++);
        int ans = hungary();
        if (ans != vN) {
            puts("none\n");
            continue;
        }
        bool flag = 0;
        memcpy(tmp, linker, sizeof(tmp));
        priority_queue<Edge> q;
        for (int i = 0; i < vN; i++) {
            g[tmp[i]][i] = 0;
            if (ans != hungary()) {
                q.push(Edge(tmp[i], i));
                flag = 1;
            }
            g[tmp[i]][i] = 1;
        }
        if (!flag) puts("none\n");
        else {
            while (!q.empty()) {
                Edge e = q.top();
                q.pop();
                printf("(%c,%d) ", e.u + 'A', e.v + 1);
            }
            puts("\n");
        }
    }
    return 0;
}
