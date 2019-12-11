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
const int maxn = 250;
const int maxm = 250;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
struct Node {
    int x1, y1;
    int x2, y2;
    int w;
};
Node node[maxn];
int X[maxn];
int Y[maxn];
int maps[maxn][maxn];
int ans[maxn];

void init() {
	memset(X, 0, sizeof X);
	memset(Y, 0, sizeof Y);
	memset(ans, 0, sizeof ans);
	memset(node, 0, sizeof node);
	memset(maps, 0, sizeof maps);
}

int main() {
	int cas = 1;
    while(scanf("%d%d", &n, &m), n||m) {
		init();
        int q;
        scanf("%d", &q);
        int cx = 0, cy = 0;
        int x1, y1, x2, y2, w;
        int mw = 0;
        for(int i=1; i<=q; i++) {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &w);
            X[cx++] = x1, Y[cy++] = y1;
            X[cx++] = x2, Y[cy++] = y2;
            node[i].x1 = x1, node[i].y1 = y1;
            node[i].x2 = x2, node[i].y2 = y2;
            node[i].w = w;
            mw = max(mw, w);
        }
        sort(X, X+cx);
        sort(Y, Y+cy);
        cx = unique(X, X+cx) - X;
        cy = unique(Y, Y+cy) - Y;
//        for(int i=0; i<cx; i++)	printf("%d%c", X[i], i==cx-1 ? '\n' : ' ');
//        for(int i=0; i<cy; i++)	printf("%d%c", Y[i], i==cy-1 ? '\n' : ' ');
//        printf("\n");
		for(int i=1; i<=q; i++) {
			x1 = lower_bound(X, X+cx, node[i].x1) - X;
			x2 = lower_bound(X, X+cx, node[i].x2) - X;
			y1 = lower_bound(Y, Y+cy, node[i].y1) - Y;
			y2 = lower_bound(Y, Y+cy, node[i].y2) - Y;
//			printf("%d %d %d %d\n", x1, y1, x2, y2);
			for(int x=x1; x<x2; x++) {
				for(int y=y1; y<y2; y++) {
					maps[x][y] = node[i].w;
				}
			}
		}
//		printf("\n");
//		for(int i=0; i<cx; i++)	for(int j=0; j<cy; j++)	printf("%d%c", maps[i][j], j==cy-1 ? '\n' : ' ');
		for(int i=0; i<cx; i++) {
			for(int j=0; j<cy; j++) {
				if(!maps[i][j])	continue;
				w = maps[i][j];
				int area = (X[i+1] - X[i]) * (Y[j+1] - Y[j]);
				ans[w] += area;
			}
		}
		tol = 0;
		printf("Case %d:\n", cas++);
		for(int i=0; i<=mw; i++) {
			if(ans[i]) {
				printf("%d %d\n", i, ans[i]);
				tol++;
			}
		}
		if(tol == 1)	printf("There is 1 color left on the wall.\n");
		else	printf("There are %d colors left on the wall.\n", tol);
    }
    return 0;
}
