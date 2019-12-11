#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 22
using namespace std;

int ans = 0;
int w, h;
int x, y;
int to[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
char c[maxn][maxn];
int vis[maxn][maxn];

void queen(int x, int y) {
//    if (vis[x][y] == 1 || c[x][y] == '#')
//        return;
//    vis[x][y] = 1;
//    ans++;
    for (int v = 0; v < 4; v++) {
        int yy = y + to[v][0];
        int xx = x + to[v][1];
        if (vis[xx][yy] != 1 && c[xx][yy] != '#') {
            if (xx >= 0 && xx < h&&yy >= 0 && yy < w) {
			    vis[xx][yy] = 1;
                ans++;
                queen(xx, yy);
            }
        }
    }
}
int main() {
    while (scanf("%d%d", &w, &h) != EOF) {
        if (w == 0 && h == 0)
            break;
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < h; i++) {
            scanf("%s", c[i],22);
            for (int j = 0; j < w; j++) {
                if (c[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        queen(x, y);
        printf("%d\n", ans);

    }
}
