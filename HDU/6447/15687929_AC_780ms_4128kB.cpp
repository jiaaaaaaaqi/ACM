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
const int maxn = 1e5+50;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
struct Node {
    int x, y;
    ll w;
    bool operator < (Node a) const {
        if(y == a.y)    return x > a.x;
        return y < a.y;
    }
};
Node node[maxn];
int X[maxn];
ll mx[maxn];

void update(int pos, ll w) {
	for(int i=pos; i<=n; i+=lowbit(i)) {
		mx[i] = max(mx[i], w);
	}
}

ll query(int pos) {
	ll ans = 0;
	for(int i=pos; i>0; i-=lowbit(i)) {
		ans = max(ans, mx[i]);
	}
	return ans;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(mx, 0, sizeof mx);
        for(int i=1; i<=n; i++) {
			scanf("%d%d%lld", &node[i].x, &node[i].y, &node[i].w);
			X[i] = node[i].x;
        }
        sort(X+1, X+n+1);
        sort(node+1, node+n+1);
        ll ans = -inf;
		for(int i=1; i<=n; i++) {
			int x = lower_bound(X+1, X+n+1, node[i].x) - X;
			ll tmp = query(node[i].x-1);
			update(node[i].x, tmp + node[i].w);
			ans = max(ans, node[i].w + tmp);
		}
		printf("%lld\n", ans);
    }
    return 0;
}
