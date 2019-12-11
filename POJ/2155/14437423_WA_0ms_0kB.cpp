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
const int maxn = 1005;
const int maxm = 555000;
using namespace std;

int n, m, tol;
int ans = 0;
int node[maxn << 2][maxn << 2];

void init() {
	memset(node, 0, sizeof node);
}

void updatey(int yleft, int yright, int yprel, int yprer, int xroot, int yroot) {
	if(yprel <= yleft && yright <= yprer) {
		node[xroot][yroot]++;
		return ;
	}
	int ymid = (yleft + yright) >> 1;
	if(yprel <= ymid)	updatey(yleft, ymid, yprel, yprer, xroot, yroot << 1);
	if(yprer > ymid)	updatey(ymid + 1, yright, yprel, yprer, xroot, yroot << 1 | 1);
}

void updatex(int xleft, int xright, int xprel, int xprer, int yprel, int yprer, int xroot) {
	if(xprel <= xleft && xright <= xprer) {
		updatey(1, n, yprel, yprer, xroot, 1);
		return ;
	}
	int xmid = (xleft + xright) >> 1;
	if(xprel <= xmid)	updatex(xleft, xmid, xprel, xprer, yprel, yprer, xroot << 1);
	if(xprer > xmid)	updatex(xmid + 1, xright, xprel, xprer, yprel, yprer, xroot << 1 | 1);
}

void queryy(int yleft, int yright, int y, int xroot, int yroot) {
	ans += node[xroot][yroot];
	if(yleft == yright)	return ;
	int ymid = (yleft + yright) >> 1;
	if(y <= ymid)	queryy(yleft, ymid, y, xroot, yroot << 1);
	else	queryy(ymid + 1, yright, y, xroot, yroot << 1 | 1);
}

void queryx(int xleft, int xright, int x, int y, int xroot) {
	if(xleft == xright)	{
		queryy(1, n, y, xroot, 1);
		return ;
	}
	int xmid = (xleft + xright) >> 1;
	if(x <= xmid)	queryx(xleft, xmid, x, y, xroot << 1);
	else	queryx(xmid + 1, xright, x, y, xroot << 1 | 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		char str[4];
		for(int i=1; i<=m; i++) {
			scanf("%s", str);
			if(str[0] == 'C') {
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				updatex(1, n, x1, x2, y1, y2, 1);
			} else if(str[0] == 'Q') {
				int x, y;
				scanf("%d%d", &x, &y);
				ans = 0;
				queryx(1, n, x, y, 1);
				if(ans & 1)		printf("1\n");
				else 	printf("0\n");
			}
		}
		if(T)	printf("\n");
	}
	return 0;
}
