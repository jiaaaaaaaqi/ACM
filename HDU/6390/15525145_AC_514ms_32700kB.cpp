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
const int maxn = 1000005;
const int maxm = 2010;
const int mod = 1e9+7;
using namespace std;

ll n, m, p;
int T, tol;
ll phi[maxn];
ll inv[maxn];
ll f[maxn];
ll g[maxn];

void init() {
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(inv, 0, sizeof inv);
}

void handle() {
    for(int i=0; i<maxn; i++)	phi[i] = i;
    for(int i=2; i<maxn; i++) {
        if(phi[i] == i) {
            for(int j=i; j<maxn; j+=i) {
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
}

ll num_pow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    handle();
    cin >> T;
    while(T--) {
        init();
        scanf("%I64d%I64d%I64d", &n, &m, &p);
        if(n > m)	swap(n, m);
        inv[1] = 1;
        for(int i=2; i<=n; i++) inv[i] = (p - p/i) * inv[p%i] % p;
        for(int i=1; i<=n; i++)	f[i] = (n/i) * (m/i) % p;
        for(int i=n; i>=1; i--) {
            g[i] = f[i];
            for(int j=2; i*j<=n; j++) {
                g[i] -= g[i*j];
                if(g[i] < 0)	g[i] += p;
            }
        }
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            ans += i * g[i] % p * inv[phi[i]] % p;
            ans %= p;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
