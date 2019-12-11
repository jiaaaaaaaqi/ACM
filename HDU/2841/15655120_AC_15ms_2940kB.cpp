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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 1005000;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
ll f[maxn];
ll g[maxn];

void init() {
	memset(f, 0, sizeof f);
	memset(g, 0, sizeof g);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		if(n > m)	swap(n, m);
		for(int i=1; i<=n; i++)	f[i] = 1ll * (n/i) * (m/i);
		for(int i=n; i>=1; i--) {
			g[i] = f[i];
			for(int j=2; i*j<=n; j++) {
				g[i] -= g[i*j];
			}
		}
		printf("%lld\n", g[1]);
	}
	return 0;
}
