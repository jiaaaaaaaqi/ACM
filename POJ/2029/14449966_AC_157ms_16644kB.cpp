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
const int maxn = 505;
const int maxm = 1005;
using namespace std;

int n, m, tol;
int node[maxn << 2][maxn << 2];

void pushup(int xroot, int yroot) {
	node[xroot][yroot] = node[xroot][yroot << 1] + node[xroot][yroot << 1 | 1];
}

void updatey(int yleft, int yright, int y, int val, int xroot, int yroot) {
	if(yleft == yright) {
		node[xroot][yroot] += val;
		return ;
	}
	int ymid = (yleft + yright) >> 1;
	if(y <= ymid)	updatey(yleft, ymid, y, val, xroot, yroot << 1);
	else	updatey(ymid + 1, yright, y, val, xroot, yroot << 1 | 1);
	pushup(xroot, yroot);
}

void updatex(int xleft, int xright, int x, int y, int val, int xroot) {
	updatey(1, m, y, val, xroot, 1);
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
	if(xprel <= xleft && xright <= xprer) {
		return queryy(1, m, yprel, yprer, xroot, 1);
	}
	int ans = 0;
	int xmid = (xleft + xright) >> 1;
	if(xprel <= xmid)	ans += queryx(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1);
	if(xprer > xmid)	ans += queryx(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1);
	return ans;
}

int main() {
	int k;
	while(scanf("%d", &k), k) {
		memset(node, 0, sizeof node);
		scanf("%d%d", &m, &n);
		for(int i=1; i<=k; i++) {
			int x, y;
			scanf("%d%d", &y, &x);
			updatex(1, n, x, y, 1, 1);
		}
		int x, y;
		scanf("%d%d", &y, &x);
		int ans = 0;
		for(int i=1; i+x-1<=n; i++) {
			for(int j=1; j+y-1<=m; j++) {
				int preans = queryx(1, n, i, i + x - 1, j, j + y - 1, 1);
				ans = max(ans, preans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
