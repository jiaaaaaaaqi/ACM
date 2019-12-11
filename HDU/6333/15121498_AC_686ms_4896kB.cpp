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
const int maxn = 1e5+10;
const int maxm = 10000007;
const int mod = 1e9+7;
using namespace std;

int n, m, tol, T;
int block;
struct Node {
    int l;
    int r;
    int id;
    bool operator < (Node a) const {
    	/*
        if(l/block != a.l/block)	return l < a.l;
        if((l/block) & 1)	return r < a.r;
        else	return r > a.r;
		*/
		return l/block != a.l/block ? l/block < a.l/block : r < a.r;
    }
};
Node node[maxn];
ll res[maxn];
ll fac[maxn];
ll inv[maxn];
ll ans;

void init() {
    ans = 1;
    memset(res, 0, sizeof res);
    memset(node, 0, sizeof node);
}

ll fa_pow(ll a, ll b) {
    ll ans = 1;
    a %= mod;
    while(b) {
        if(b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}

void handle() {
    fac[0] = 1;
    inv[0] = 1;
    for(int i=1; i<=100000; i++) {
        fac[i] = fac[i-1] * i;
        fac[i] %= mod;
        inv[i] = fa_pow(fac[i], mod-2);
    }
}

ll C(int n1, int m1) {
    if(m1 > n1)	return 0;
    ll ans = fac[n1] * inv[m1] % mod * inv[n1-m1] % mod;
    return ans;
}

int main() {
    init();
    handle();
    scanf("%d", &n);
    block = sqrt(n);
    for(int i=1; i<=n; i++)	scanf("%d%d", &node[i].l, &node[i].r), node[i].id = i;
    sort(node+1, node+1+n);
    int L = 1;
    int R = 0;
    for(int i=1; i<=n; i++) {
        while(L > node[i].l) {
            L--;
            ans = (ans + C(L, R)) % mod * inv[2] % mod;
        }
        while(L < node[i].l) {
            ans = (ans * 2 % mod - C(L, R)) % mod + mod;
            ans %= mod;
            L++;
        }
        while(R < node[i].r) {
            R++;
            ans = (ans + C(L, R)) % mod;
        }
        while(R > node[i].r) {
            ans = (ans - C(L, R) % mod) + mod;
            ans %= mod;
            R--;
        }
        res[node[i].id] = ans;
    }
    for(int i=1; i<=n; i++)	printf("%I64d\n", res[i]);
    return 0;
}
