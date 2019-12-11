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
const ll INF = 1e18+100;
const int maxn = 1e5+10;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
ll fac[maxn];
struct Node{
	int u, v;
	ll w;
	int next;
};
Node node[maxn << 1];
int head[maxn];
int sz[maxn];
ll ans = 0;

void handle() {
	fac[0] = fac[1] = 1;
	for(int i=2; i<=1e5; i++) {
		fac[i] = fac[i-1] * i;
		fac[i] %= mod;
	}
}

void init() {
	tol = 0;
	memset(sz, 0, sizeof sz);
	memset(head, -1, sizeof head);
}

void addnode(int u, int v, ll w) {
	node[tol].u = u;
	node[tol].v = v;
	node[tol].w = w;
	node[tol].next = head[u];
	head[u] = tol++;
}

void dfs(int u, int fa) {
	sz[u] = 1;
	for(int i=head[u]; ~i; i=node[i].next) {
		int v = node[i].v;
		int w = node[i].w;
		if(v == fa)	continue;
		dfs(v, u);
		sz[u] += sz[v];
		ans += 1ll * (n-sz[v]) * sz[v] % mod * w % mod * 2 * fac[n-1] % mod;
		ans %= mod;
	}
}

int main() {
	handle();
	while(~scanf("%d", &n)) {
		init();
		for(int i=2; i<=n; i++) {
			int u, v;
			ll w;
			scanf("%d%d%lld", &u, &v, &w);
			addnode(u, v, w);
			addnode(v, u, w);
		}
		ans = 0;
		dfs(1, 0);
		printf("%lld\n", ans % mod);
	}
    return 0;
}
