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
int node[maxn][maxn];

void init() {
	memset(node, 0, sizeof node);
}

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int y) {
	for(int i=x; i<=n; i += lowbit(i)) {
		for(int j=y; j<=n; j += lowbit(j)) {
			node[i][j]++;
		}
	}
}

int query(int x, int y) {
	int ans = 0;
	for(int i=x; i>0; i -= lowbit(i)) {
		for(int j=y; j>0; j -= lowbit(j)) {
			ans += node[i][j];
		}
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		char str[5];
		while(m--) {
			scanf("%s", str);
			if(str[0] == 'C') {
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				update(x1, y1);
				update(x2 + 1, y2 + 1);
				update(x1, y2 + 1);
				update(x2 + 1, y1);
			} else if(str[0] == 'Q') {
				int x, y;
				scanf("%d%d", &x, &y);
				int ans = query(x, y);
				if(ans & 1)		printf("1\n");
				else	printf("0\n");
			}
		}
		if(T)	printf("\n");
	}
	return 0;
}
