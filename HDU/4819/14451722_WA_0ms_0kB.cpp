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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 805;
const int maxm = 1005;
using namespace std;

int n, m, tol;
int maxans, minans;
int nodemax[maxn << 2][maxn << 2];
int nodemin[maxn << 2][maxn << 2];

void pushupx(int xroot, int yroot) {
    nodemax[xroot][yroot] = max(nodemax[xroot << 1][yroot], nodemax[xroot << 1 | 1][yroot]);
    nodemin[xroot][yroot] = min(nodemin[xroot << 1][yroot], nodemin[xroot << 1 | 1][yroot]);
    return ;
}

void pushupy(int xroot, int yroot) {
    nodemax[xroot][yroot] = max(nodemax[xroot][yroot << 1], nodemax[xroot][yroot << 1 | 1]);
    nodemin[xroot][yroot] = min(nodemin[xroot][yroot << 1], nodemin[xroot][yroot << 1 | 1]);
    return ;
}

void buildy(int yleft, int yright, int xroot, int flag, int yroot) {
    if(yleft == yright) {
        if(flag) {
            scanf("%d", &nodemax[xroot][yroot]);
            nodemin[xroot][yroot] = nodemax[xroot][yroot];
        } else {
            pushupx(xroot, yroot);
        }
        return ;
    }
    int ymid = (yleft + yright) >> 1;
    buildy(yleft, ymid, xroot, flag, yroot << 1);
    buildy(ymid + 1, yright, xroot, flag, yroot << 1 | 1);
    pushupy(xroot, yroot);
}

void buildx(int xleft, int xright, int xroot) {
    if(xleft == xright) {
        buildy(1, n, xroot, 1, 1);
        return ;
    }
    int xmid = (xleft + xright) >> 1;
    buildx(xleft, xmid, xroot << 1);
    buildx(xmid + 1, xright, xroot << 1 | 1);
    buildy(1, n, xroot, 0, 1);
}

void updatey(int yleft, int yright, int y, int val, int xroot, int yroot) {
    if(yleft == yright) {
        nodemax[xroot][yroot] = nodemin[xroot][yroot] = val;
        return ;
    }
    int ymid = (yleft + yright) >> 1;
    if(y <= ymid)	updatey(yleft, ymid, y, val, xroot, yroot << 1);
    else	updatey(ymid + 1, yright, y, val, xroot, yroot << 1 | 1);
    pushupy(xroot, yroot);
}

void updatex(int xleft, int xright, int x, int y, int val, int xroot) {
    updatey(1, n, y, val, xroot, 1);
    if(xleft == xright)	return ;
    int xmid = (xleft + xright) >> 1;
    if(x <= xmid)	updatex(xleft, xmid, x, y, val, xroot << 1);
    else	updatex(xmid + 1, xright, x, y, val, xroot << 1 | 1);
}

void queryy(int yleft, int yright, int yprel, int yprer, int xroot, int yroot) {
    if(yprel <= yleft && yright <= yprer) {
        maxans = max(maxans, nodemax[xroot][yroot]);
        minans = min(minans, nodemin[xroot][yroot]);
        return ;
    }
    int ymid = (yleft + yright) >> 1;
    if(yprel <= ymid)	queryy(yleft, ymid, yprel, yprer, xroot, yroot << 1);
    if(yprer > ymid)	queryy(ymid + 1, yright, yprel, yprer, xroot, yroot << 1 | 1);
    return ;
}

void queryx(int xleft, int xright, int xprel, int xprer, int yprel, int yprer, int xroot) {
    if(xprel <= xleft && xright <= xprer) {
        queryy(1, n, yprel, yprer, xroot, 1);
        return ;
    }
    int xmid = (xleft + xright) >> 1;
    if(xprel <= xmid)	queryx(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1);
    if(xprer > xmid)	queryx(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1);
    return ;
}

int main() {
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        scanf("%d", &n);
        buildx(1, n, 1);
        scanf("%d", &m);
        printf("Case #%d:\n", cas++);
        while(m--) {
            maxans = -inf, minans = inf;
            int x, y, r;
            scanf("%d%d%d", &x, &y, &r);
            int x1 = x - (r - 1) / 2;
            x1 = max(x1, 1);
            int x2 = x + (r - 1) / 2;
            x2 = min(x2, n);
            int y1 = y - (r - 1) / 2;
            y1 = max(y1, 1);
            int y2 = y + (r - 1) / 2;
            y2 = min(y2, n);
            queryx(1, n, x1, x2, y1, y2, 1);
            int ans = (maxans + minans) >> 1;
            printf("%d\n", ans);
            updatex(1, n, x, y, ans, 1);
        }
    }
    return 0;
}
