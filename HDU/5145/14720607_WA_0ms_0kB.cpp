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
const int maxn = 30005;
const int maxm = 10000;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int block;
struct Node {
    int l, r, id;
    bool operator < (Node a) const{
        return l/block == a.l/block ? r < a.r : l/block < a.l/block;
    }
};
Node node[maxn];
ll ans;
int a[maxn];
ll fac[maxn];
ll res[maxn];
int cnt[maxn];

void init() {
    ans = 1;
    memset(a, 0, sizeof a);
    memset(cnt, 0, sizeof cnt);
    memset(node, 0, sizeof node);
}

void handle() {
    fac[1] = 1;
    for(int i=2; i<=30000; i++)
        fac[i] = fac[i-1] * (ll)i % mod;
}

ll getinv(ll x) {
	ll b = mod - 2;
	ll ans = 1;
	while(b) {
		if(b & 1) 
			ans = (ans * x) % mod;
		x = (x * x) % mod;
		b >>= 1;
	}
	return ans;
}

void add(int x) {
	cnt[a[x]]++;
	ans = ans * getinv(cnt[a[x]]) % mod;
}

void del(int x) {
	ans = ans * cnt[a[x]] % mod;
	cnt[a[x]]--;
}

int main() {
    int T;
    handle();
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        block = sqrt(n);
        for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
        for(int i=1; i<=m; i++) {
            scanf("%d%d", &node[i].l, &node[i].r);
            node[i].id = i;
        }
        sort(node+1, node+1+m);
        int L = 1;
        int R = 0;
        for(int i=1; i<=m; i++) {
            while(L < node[i].l) 
				del(L++);
            while(L > node[i].l) 
				add(--L);
			while(R < node[i].r)
				add(++R);
			while(R > node[i].r) 
				del(R--);
			int x = node[i].r - node[i].l + 1;
			res[node[i].id] = fac[x] * ans % mod;
        }
        for(int i=1; i<=m; i++)	printf("%lld\n", res[i]);
    }
    return 0;
}
