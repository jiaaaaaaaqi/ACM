#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mx = 1e6+5;
int prime[mx], a[mx], pos[mx];

void getPrime() {
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < mx; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] < mx/i; j++) {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
vector <int> p;
int main() {
    memset(pos, 0, sizeof(pos));
    getPrime();
    //for (int i = 1; i <= 10; i++) printf("prime[%d] = %d\n", i, prime[i]);
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = a[i];
        p.clear();
        for (int j = 1; j < prime[0] && 1LL*prime[j]*prime[j] <= tmp; j++) {
            if (tmp % prime[j] == 0) {
                p.push_back(prime[j]);
                while (tmp % prime[j] == 0) tmp /= prime[j];
            }
        }
        if (tmp > 1) p.push_back(tmp);
        //printf("p.size = %d\n", p.size());
        for (int j = 0; j < p.size(); j++) {
            ans += 1LL * (i-pos[p[j]]) * (n-i+1);
            //printf("i = %d %d*%d\n", i, (i-pos[p[j]]), (n-i+1));
            pos[p[j]] = i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}