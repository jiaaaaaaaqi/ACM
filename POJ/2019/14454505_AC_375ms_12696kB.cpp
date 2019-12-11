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
const int maxn = 310;
const int maxm = 310;
using namespace std;

int n, m, tol;
int maxans, minans;
int nodemax[maxn << 2][maxn << 2];
int nodemin[maxn << 2][maxn << 2];

void pushupy(int xroot, int yroot) {
	nodemax[xroot][yroot] = max(nodemax[xroot][yroot << 1], nodemax[xroot][yroot << 1 | 1]);
	nodemin[xroot][yroot] = min(nodemin[xroot][yroot << 1], nodemin[xroot][yroot << 1 | 1]);
}

void pushupx(int xroot, int yroot) {
	nodemax[xroot][yroot] = max(nodemax[xroot << 1][yroot], nodemax[xroot << 1 | 1][yroot]);
	nodemin[xroot][yroot] = min(nodemin[xroot << 1][yroot], nodemin[xroot << 1 | 1][yroot]);
}

void buildy(int yleft, int yright, int xroot, int flag, int yroot) {
	if(yleft == yright)	{
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

void queryy(int yleft, int yright, int yprel, int yprer, int xroot, int yroot) {
	if(yprel <= yleft && yright <= yprer) {
		maxans = max(maxans, nodemax[xroot][yroot]);
		minans = min(minans, nodemin[xroot][yroot]);
		return ;
	}
	int ymid = (yleft + yright) >> 1;
	if(yprel <= ymid)	queryy(yleft, ymid, yprel, yprer, xroot, yroot << 1);
	if(yprer > ymid)	queryy(ymid + 1, yright, yprel, yprer, xroot, yroot << 1 | 1);
}

void queryx(int xleft, int xright, int xprel, int xprer, int yprel, int yprer, int xroot) {
	if(xprel <= xleft && xright <= xprer) {
		queryy(1, n, yprel, yprer, xroot, 1);
		return ;
	}
	int xmid = (xleft + xright) >> 1;
	if(xprel <= xmid)	queryx(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1);
	if(xprer > xmid)	queryx(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1);
}

int main() {
	int k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		memset(nodemax, 0, sizeof nodemax);
		memset(nodemin, inf, sizeof nodemin);
		buildx(1, n, 1);
		for(int i=1; i<=k; i++) {
			int x1, y1;
			scanf("%d%d", &x1, &y1);
			int x2 = x1 + m - 1;
			int y2 = y1 + m - 1;
			maxans = -inf;
			minans = inf;
			queryx(1, n, x1, x2, y1, y2, 1);
			printf("%d\n", maxans - minans);
		}
	}
	return 0;
}
