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
const int maxn = 1035;
const int maxm = 1005;
using namespace std;

int n, m, tol;
int node[maxn << 2][maxn << 2];

void pushupy(int xroot, int yroot) {
	node[xroot][yroot] = node[xroot][yroot << 1] + node[xroot][yroot << 1 | 1];
}

void updatey(int yleft, int yright, int y, int val, int xroot, int yroot) {
	node[xroot][yroot] += val;
	if(yleft == yright)	return ;
	int ymid = (yleft + yright) >> 1;
	if(y <= ymid)	updatey(yleft, ymid, y, val, xroot, yroot << 1);
	else	updatey(ymid + 1, yright, y, val, xroot, yroot <<  1 | 1);
	pushupy(xroot, yroot);
}

void updatex(int xleft, int xright, int x, int y, int val, int xroot) {
	updatey(1, n, y, val, xroot, 1);
	if(xleft == xright)	return ;
	int xmid = (xleft + xright) >> 1;
	if(x <= xmid)	updatex(xleft, xmid, x, y, val, xroot << 1);
	else	updatex(xmid + 1, xright, x, y, val, xroot << 1 | 1);
}

int queryy(int yleft, int yright, int yprel, int yprer, int xroot, int yroot) {
	if(yprel <= yleft && yright <= yprer) {
		return node[xroot][yroot];
	}
	int ans = 0;
	int ymid = (yleft + yright) >> 1;
	if(yprel <= ymid)	ans += queryy(yleft, ymid, yprel, yprer, xroot, yroot << 1);
	if(yprer > ymid)	ans += queryy(ymid + 1, yright, yprel, yprer, xroot, yroot << 1 | 1);
	return ans;
}

int queryx(int xleft, int xright, int xprel, int xprer, int yprel, int yprer, int xroot) {
	if(xleft == xright) {
		return queryy(1, n, yprel, yprer, xroot, 1);
	}
	int ans = 0;
	int xmid = (xleft + xright) >> 1;
	if(xprel <= xmid)	ans += queryx(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1);
	if(xprer > xmid)	ans += queryx(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1);
	return ans;
}

int main() {
	int op;
	while(scanf("%d", &op) != EOF) {
		if(op == 0) {
			scanf("%d", &n);
			memset(node, 0, sizeof node);
		} else if(op == 1) {
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			x++, y++;
			updatex(1, n, x, y, w, 1);
		} else if(op == 2) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1++, x2++, y1++, y2++;
			int ans = queryx(1, n, x1, x2, y1, y2, 1);
			printf("%d\n", ans);
		} else if(op == 3) {
			break;
		}
	}
	return 0;
}
