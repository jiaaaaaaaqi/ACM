#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const int mx = 1e6+10;

ll fac[mx];

ll pow_mod(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}



int main() {
    //freopen("out.txt", "w+", stdout);
    ll ans = 1;
    for (ll i = 1; i <= 1e6+3; i++) {
        ans = ans * i % mod;
        fac[i] = ans;
    }

    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) printf("0\n");
        else if (n >= mod) printf("0\n");
        else printf("%lld\n", fac[n]);
    }
    return 0;
}