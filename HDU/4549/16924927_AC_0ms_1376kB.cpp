#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn = 10;
const ll mod = 1e9+6;
struct mat {
    ll m[maxn][maxn];
};

mat msub(mat a, mat b) {
    mat ans;
    memset(ans.m, 0, sizeof(ans.m));
    ll x;
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            x = 0;
            for(int k = 1; k <= 2; k++) {
                x += a.m[i][k]*b.m[k][j]%mod;
            }
            ans.m[i][j] = x%mod;
        }
    }
    return ans;
}

mat mpow(mat a, ll b) {
    mat ans;
    memset(ans.m, 0, sizeof(ans.m));
    for(int i = 1; i <= 2; i++)
        ans.m[i][i] = 1;
    while(b) {
        if(b%2)
            ans = msub(ans, a);
        a = msub(a, a);
        b /= 2;
    }
    return ans;
}


ll pow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b%2)
            ans = a*ans%(mod+1);
        a = a*a%(mod+1);
        b /= 2;
    }
    return ans%(mod+1);
}

int main() {
    ll x, y, n;
    mat f, g;
    g.m[1][1] = 1;
    g.m[1][2] = 1;
    g.m[2][1] = 1;
    g.m[2][2] = 0;
    while(scanf("%lld%lld%lld",&x,&y,&n)!=EOF) {
        f = g;
        ll a, b, ans;
        if(n == 0) {
            a = 1;
            b = 0;
        } else if(n == 1) {
            a = 0;
            b = 1;
        } else {
            a = mpow(f, n-2).m[1][1];
            b = mpow(f, n-1).m[1][1];
            //  printf("a == %lld, b = %lld\n", a, b);
        }
        ans = pow(x, a)*pow(y, b)%(mod+1);
        printf("%lld\n", ans);
    }
    return 0;
}
