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
const int maxn = 1050;
const int maxm = 1005;
using namespace std;

int n, m, tol;
int node[maxn * 3][maxn * 3];

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int y, int w) {
	for(int i=x; i<=n; i+=lowbit(x)) {
		for(int j=y; j<=n; j+=lowbit(y)) {
			node[i][j] += w;
		}
	}
}

int query(int x, int y) {
	int ans = 0;
	for(int i=x; i>0; i-=lowbit(x)) {
		for(int j=y; j>0; j-=lowbit(y)) {
			ans += node[i][j];
		}
	}
	return ans;
}

int main() {
	int op;
	while(scanf("%d", &op) != EOF) {
		if(op == 0) {
			scanf("%d", &n);
		} else if(op == 1) {
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			x++, y++;
			update(x, y, w);
		} else if(op == 2) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1++, x2++, y1++, y2++;
			int ans = 0;
			ans += query(x2, y2);
			ans -= query(x1 - 1, y2);
			ans -= query(x2, y1 - 1);
			ans += query(x1 - 1, y1 - 1);
			printf("%d\n", ans);
		} else if(op == 3) {
			break;
		}
	}
	return 0;
}
