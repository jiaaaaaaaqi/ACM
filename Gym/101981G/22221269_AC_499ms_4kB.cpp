#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mx = 1e6+5;
const int mod = 1e9+7;

ll pow_mod(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a %mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll inv2 = pow_mod(2, mod-2);
    ll inv3 = pow_mod(3, mod-2);
    ll inv6 = pow_mod(6, mod-2);

    int T;
    scanf("%d", &T);

    while (T--) {
        ll n;
        scanf("%lld", &n);
        n++;
        ll sum = (n*n + n) / 2;
        sum %= mod;

        ll ans = (sum * (sum-1) % mod + mod) % mod * inv6 % mod;
        printf("%lld\n", ans);
    }
    return 0;
}