#include <bits/stdc++.h>

using namespace std;
vector <int> vx, vy;

int mp[12][12];
bool vis[12][12];
int dir[4][2] = {{0,1},{0,-1}, {1,0}, {-1,0}};
int getidx(int x) {
    return lower_bound(vx.begin(), vx.end(), x) - vx.begin() + 1;
}
int getidy(int x) {
    return lower_bound(vy.begin(), vy.end(), x) - vy.begin() + 1;
}
bool judge(int x, int y) {
    return x >= 1 && y >= 1 && x <= 6 && y <= 6;
}

void dfs(int x, int y, int val) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (judge(nx, ny) && !vis[nx][ny] && mp[nx][ny] == val) {
            dfs(nx, ny, val);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        vx.clear(), vy.clear();
        memset(mp, 0, sizeof(mp));
        memset(vis, false, sizeof(vis));
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d%d%d%d", &x3, &y3, &x4, &y4);

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x3 > x4) swap(x3, x4);
        if (y3 > y4) swap(y3, y4);

        vx.push_back(x1); vy.push_back(y1); vx.push_back(x2); vy.push_back(y2);
        vx.push_back(x3); vy.push_back(y3); vx.push_back(x4); vy.push_back(y4);
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());

        vx.erase(unique(vx.begin(), vx.end()), vx.end());
        vy.erase(unique(vy.begin(), vy.end()), vy.end());

        x1 = getidx(x1); y1 = getidy(y1); x2 = getidx(x2); y2 = getidy(y2);
        x3 = getidx(x3); y3 = getidy(y3); x4 = getidx(x4); y4 = getidy(y4);

        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                mp[i][j] += 1;
            }
        }

        for (int i = x3; i < x4; i++) {
            for (int j = y3; j < y4; j++) {
                mp[i][j] += 2;
            }
        }
        // for (int i = 1; i <= 6; i++) {
        //     for (int j = 1; j <= 6; j++) {
        //         printf("%d%c", mp[i][j], j == 6 ?'\n':' ');
        //     }
        // }
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                if (!vis[i][j] && mp[i][j] != 0) {
                    dfs(i, j, mp[i][j]);
                    ans++;
                }
            }
        }
        printf("%d\n", ans+1);
    }
    return 0;
}