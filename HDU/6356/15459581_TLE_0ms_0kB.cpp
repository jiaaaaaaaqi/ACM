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
typedef unsigned int ui;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 20;
const int maxm = 2e5+10;
const int mod = 1<<30;
const double eps = 1e-8;
using namespace std;

int n, m;
int T, tol;
ui X, Y, Z;

int st[maxm][20];

ui RNG61() {
	X = X ^ (X<<11);
	X = X ^ (X>>4);
	X = X ^ (X<<5);
	X = X ^ (X>>14);
	ll W = X ^ (Y ^ Z);
	X = Y;
	Y = Z;
	Z = W;
	return Z;
}

void init() {
	memset(st, 0, sizeof st);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d%d%d%d", &n, &m, &X, &Y, &Z);
		for(int i=1; i<=m; i++) {
			ui f1 = RNG61();
			ui f2 = RNG61();
			ui f3 = RNG61();
			cout << f1<< " " << f2 << " " << f3 << endl;
			int l = min(f1%n+1, f2%n+1);
			int r = max(f1%n+1, f2%n+1);
			int v = f3 % mod;
			int k = log(r-l+1) / log(2.0);
			st[l][k] = max(st[l][k], v);
			st[r-(1<<k)+1][k] = max(st[r-(1<<k)+1][k], v);
		}
		int len = log(n) / log(2.0);
		for(int j=len; j>=1; j--) {
			for(int i=1; i<=n; i++) {
				st[i][j-1] = max(st[i][j-1], st[i][j]);
				st[i+(1<<(j-1))][j-1] = max(st[i+(1<<(j-1))][j-1], st[i][j]);
				st[i][j] = 0;
			}
		}
		ll ans = 0;
		for(int i=1; i<=n; i++)		ans = ans ^ (1ll * i * st[i][0]);
		printf("%I64d\n", ans);
	}
	return 0;
}
