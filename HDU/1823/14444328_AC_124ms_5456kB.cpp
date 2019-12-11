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
const int maxn = 105;
const int maxm = 1005;
using namespace std;

int n, m, tol;
double node[maxn << 2][maxm << 2];

void buildy(int yleft, int yright, int xroot, int yroot) {
	node[xroot][yroot] = -1.0;
	if(yleft == yright)	return ;
	int ymid = (yleft + yright) >> 1;
	buildy(yleft, ymid, xroot, yroot << 1);
	buildy(ymid + 1, yright, xroot, yroot << 1 | 1);
}

void buildx(int xleft, int xright, int xroot) {
	buildy(1, 1001, xroot, 1);
	if(xleft == xright) {
		return ;
	}
	int xmid = (xleft + xright) >> 1;
	buildx(xleft, xmid, xroot << 1);
	buildx(xmid + 1, xright, xroot << 1 | 1);
}

void pushupy(int xroot, int yroot) {
	node[xroot][yroot] = max(node[xroot][yroot << 1], node[xroot][yroot << 1 | 1]);
}

void updatey(int yleft, int yright, int y, double val, int xroot, int yroot) {
	if(yleft == yright) {
		node[xroot][yroot] = max(node[xroot][yroot], val);
		return ;
	}
	int ymid = (yleft + yright) >> 1;
	if(y <= ymid)	updatey(yleft, ymid, y, val, xroot, yroot << 1);
	else	updatey(ymid + 1, yright, y, val, xroot, yroot << 1 | 1);
	pushupy(xroot, yroot);
}

void updatex(int xleft, int xright, int x, int y, double val, int xroot) {
	updatey(1, 1001, y, val, xroot, 1);
	if(xleft == xright)	return ;
	int xmid = (xleft + xright) >> 1;
	if(x <= xmid)	updatex(xleft, xmid, x, y, val, xroot << 1);
	else	updatex(xmid + 1, xright, x, y, val, xroot << 1 | 1);
}

double queryy(int yleft, int yright, int yprel, int yprer, int xroot, int yroot) {
	if(yprel <= yleft && yright <= yprer) {
		return node[xroot][yroot];
	}
	double ans = -1.0;
	int ymid = (yleft + yright) >> 1;
	if(yprel <= ymid)	ans = max(ans, queryy(yleft, ymid, yprel, yprer, xroot, yroot << 1));
	if(yprer > ymid)	ans = max(ans, queryy(ymid + 1, yright, yprel, yprer, xroot, yroot << 1 | 1));
	return ans;
}

double queryx(int xleft, int xright, int xprel, int xprer, int yprel, int yprer, int xroot) {
	if(xprel <= xleft && xright <= xprer) {
		return queryy(1, 1001, yprel, yprer, xroot, 1);
	}
	double ans = -1.0;
	int xmid = (xleft + xright) >> 1;
	if(xprel <= xmid)	ans = max(ans, queryx(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1));
	if(xprer > xmid)	ans = max(ans, queryx(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1));
	return ans;
}

int main() {
	while(scanf("%d", &m), m) {
		char str[5];
		buildx(1, 101, 1);
		while(m--) {
			scanf("%s", str);
			if(str[0] == 'I') {
				int x;
				double y, w;
				scanf("%d%lf%lf", &x, &y, &w);
				updatex(1, 101, x - 99, (int)(y * 10) + 1, w, 1);
			} else if(str[0] == 'Q') {
				int x1, x2;
				double y1, y2;
				scanf("%d%d%lf%lf", &x1, &x2, &y1, &y2);
				if(x1 > x2)		swap(x1, x2);
				if(y1 > y2)		swap(y1, y2);
				double ans = queryx(1, 101, x1 - 99, x2 - 99, (int)(y1 * 10) + 1, (int)(y2 * 10) + 1, 1);
				if(ans == -1.0)		printf("-1\n");
				else	printf("%.1lf\n", ans);
			}
		}
	}
	return 0;
}