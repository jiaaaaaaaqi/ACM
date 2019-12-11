#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
ll mod, n;
ll fastmul(ll a, ll b){
    ll ans = 0;
    while(b){
        if(b%2)
            ans = (ans + a)%mod;
        a = (a + a)%mod;
        b = (b + mod)%mod;
        b /= 2;
    }
    return ans;
}

ll pow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b%2)
            ans = fastmul(ans, a);
        a = fastmul(a, a);
        b /= 2;
    }
    return ans;
}

int main(){
    while(scanf("%lld%lld",&n,&mod)!=EOF){
        ll ans = pow(2, n) - 2;
        if(n == 1)
            printf("%lld\n", 1%mod);
        else
            printf("%lld\n", (ans%mod + mod)%mod);
    }
    return 0;
}

