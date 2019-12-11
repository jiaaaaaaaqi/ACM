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
int node[maxn][maxn];

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int y) {
	for(int i=x; i<=n; i+=lowbit(i)) {
		for(int j=y; j<=m; j+=lowbit(j)) {
			node[i][j] += 1;
		}
	}
}

int query(int x, int y) {
	int ans = 0;
	for(int i=x; i>0; i-=lowbit(i)) {
		for(int j=y; j>0; j-=lowbit(j)) {
			ans += node[i][j];
		}
	}
	return ans;
}

int main() {
	int k;
	while(scanf("%d", &k), k) {
		memset(node, 0, sizeof node);
		scanf("%d%d", &m, &n);
		int x, y;
		for(int i=1; i<=k; i++) {
			scanf("%d%d", &y, &x);
			update(x, y);
		}
		scanf("%d%d", &y, &x);
		int ans = 0;
		for(int i=1; i+x-1<=n; i++) {
			for(int j=1; j+y-1<=m; j++) {
				int preans = 0;
				preans += query(i + x - 1, j + y - 1);
				preans += query(i - 1, j - 1);
				preans -= query(i - 1, j + y - 1);
				preans -= query(i + x - 1, j - 1);
				ans = max(ans, preans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
