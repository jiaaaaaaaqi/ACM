#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mx = 50+5;
char mp[mx][mx];
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
char a[5] = {'R', 'L', 'D', 'U'};
char ans[50005];
int len = 0;
bool vis[mx][mx];

int n, m;
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == '1';
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if (check(nx,ny) && !vis[nx][ny]) {
            //printf("%c", a[i]);
            ans[len++] = a[i];
            dfs(nx, ny);
            //printf("%c", a[i^1]);
            ans[len++] = a[i^1];
        }
    }
}

int main() {
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", mp[i]+1);
    }
    int x = -1, y = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '1') {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    if (check(i+dir[k][0], j+dir[k][1])) cnt++;
                }
                if (cnt == 1) {
                    x = i; y = j;
                    break;
                }
            }
        }
    }
    //printf("%d %d\n", x, y);
    if (x != -1 && y != -1) {
        int pos = 0;
        dfs(x, y);
        for (int i = 1; i <= 50000; i++) {
            printf("%c", ans[pos]);
            pos++;
            if (pos == len) pos = 0;
        }
    }
    printf("\n");
    return 0;
}