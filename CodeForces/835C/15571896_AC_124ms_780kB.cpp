#include<map>
#include<set>
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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 128;
const int maxm = 1000020;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
int cnt[maxn][maxn][maxn/10];

void init() {
	memset(cnt, 0, sizeof cnt);
}

int main() {
	init();
	int q, c;
	scanf("%d%d%d", &n, &q, &c);
	int mx=0, my=0;
	int x, y, s;
	for(int i=1; i<=n; i++) {
		scanf("%d%d%d", &x, &y, &s);
		cnt[x][y][s]++;
		mx = max(mx, x);
		my = max(my, y);
	}
	for(int i=1; i<=100; i++) {
		for(int j=1; j<=100; j++) {
			for(int k=0; k<=c; k++) {
				cnt[i][j][k] = cnt[i][j][k] + cnt[i-1][j][k] + cnt[i][j-1][k] - cnt[i-1][j-1][k];
			}
		}
	}
	int t, x1, y1, x2, y2;
	while(q--) {
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		int ans = 0;
		for(int k=0; k<=c; k++) {
			int tmp = (k+t) % (c+1);
			int cx = cnt[x2][y2][k] - cnt[x1-1][y2][k] - cnt[x2][y1-1][k] + cnt[x1-1][y1-1][k];
			ans += tmp * cx;
		}
		printf("%d\n", ans);
	}
	return 0;
}
