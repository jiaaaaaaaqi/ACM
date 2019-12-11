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
int node[maxn << 2][maxn << 2];

void pushupx(int xroot, int yroot) {
	node[xroot][yroot] = min(node[xroot << 1][yroot], node[xroot << 1 | 1][yroot]);
}

void pushupy(int xroot, int yroot) {
	node[xroot][yroot] = min(node[xroot][yroot << 1], node[xroot][yroot << 1 | 1]);
}

void buildy(int yleft, int yright, int xroot, int flag, int yroot) {
	if(yleft == yright) {
		if(flag)	scanf("%d", &node[xroot][yroot]);
		else	pushupx(xroot, yroot);
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

int queryy(int yleft, int yright, int yprel, int yprer, int xroot, int yroot) {
	if(yprel <= yleft && yright <= yprer) {
		return node[xroot][yroot];
	}
	int ans = inf;
	int ymid = (yleft + yright) >> 1;
	if(yprel <= ymid)	ans = min(ans, queryy(yleft, ymid, yprel, yprer, xroot, yroot << 1));
	if(yprer > ymid)	ans = min(ans, queryy(ymid + 1, yright, yprel, yprer, xroot, yroot << 1 | 1));
	return ans;
	/*
	if(yprel <= yleft && yright <= yprer) {
		return node[xroot][yroot];
	}
	int ans = inf;
	int ymid = (yleft + yright) >> 1;
	if(yprel <= ymid)	ans = min(ans, queryy(yleft, ymid, yprel, yprer, xroot, yroot << 1));
	if(yprer > ymid)	ans = min(ans, queryy(ymid + 1, yright, yprel, yprer, xroot, yroot << 1 | 1));
	return ans;
	*/
}

int queryx(int xleft, int xright, int xprel, int xprer, int yprel, int yprer, int xroot) {
	if(xprel <= xleft && xright <= xprer) {
		return queryy(1, n, yprel, yprer, xroot, 1);
	}
	int xmid = (xleft + xright) >> 1;
	int ans = inf;
	if(xprel <= xmid)	ans = min(ans, queryx(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1));
	if(xprer < xmid)	ans = min(ans, queryx(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1));
	return ans;
	/*
	if(xprel <= xleft && xright <= xprer) {
		return queryy(1, n, yprel, yprer, xroot, 1);
	}
	int ans = inf;
	int xmid = (xleft + xright) >> 1;
	if(xprel <= xmid)	ans = min(ans, queryx(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1));
	if(xprer > xmid)	ans = min(ans, queryx(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1));
	return ans;
	*/
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		buildx(1, n, 1);
		scanf("%d", &m);
		while(m--) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			int ans = queryx(1, n, x1, x2, y1, y2, 1);
			printf("%d\n", ans);
		}
	}
	return 0;
}
