#include <bits/stdc++.h>
using namespace std;
const int mx = 200005;
vector <int> mat[mx];
int son[mx], u[mx], v[mx];

int dfs(int u, int fa) {
    son[u] = 1;
    for (auto v: mat[u]) {
        if (v != fa) {
            son[u] += dfs(v, u);
        }
    }
    return son[u];
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            mat[i].clear();
            son[i] = 0;
        }
        for (int i = 1; i <= n-1; i++) {
            scanf("%d%d", &u[i], &v[i]);
            mat[u[i]].push_back(v[i]);
            mat[v[i]].push_back(u[i]);
        }
        dfs(1, 1);
        int ans = 0;
        for (int i = 1; i <= n-1; i++) {
            if (son[u[i]] > son[v[i]]) {
                int tot = n-son[v[i]];
                if (tot >= k && son[v[i]] >= k) ans++;
            } else {
                int tot = n-son[u[i]];
                if (tot >= k && son[u[i]] >= k) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
