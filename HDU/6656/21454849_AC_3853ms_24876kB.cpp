/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月12日 星期一 13时08分58秒
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

ll n, m;
int cas, tol, T;

void read(ll &x) {
    static char ch;static bool neg;
    for(ch=neg=0;ch<'0' || '9'<ch;neg|=ch=='-',ch=getchar());
    for(x=0;'0'<=ch && ch<='9';(x*=10)+=ch-'0',ch=getchar());
    x=neg?-x:x;
}

ll fpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

struct Node {
    ll ri, si;
    ll pi, ai;
    ll xi;
} node[maxn];
ll dp[maxn];
ll sum[maxn];

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        read(n), read(m);
        for(int i=1; i<=n; i++) {
            read(node[i].ri), read(node[i].si), read(node[i].xi), read(node[i].ai);
            node[i].pi = node[i].ri * fpow(node[i].si, mod-2) % mod; 
        }
        if(node[2].xi == 1) {
            dp[1] = (node[1].pi*node[2].ai + node[1].ai)%mod * fpow(node[1].pi*node[2].pi%mod, mod-2)%mod; 
            dp[2] = (node[2].si-node[2].ri)*fpow(node[2].si, mod-2)%mod*dp[1]%mod + node[2].ai;
            dp[2] %= mod;
        } else {
            dp[2] = node[2].ai * fpow(node[2].pi, mod-2)%mod;
            dp[1] = (node[2].ai*node[1].pi%mod+node[1].ai*node[2].pi%mod)%mod * fpow(node[1].pi*node[2].pi%mod, mod-2)%mod;
        }
        sum[1] = sum[0] = 0;
        sum[2] = dp[1]-dp[2];
        sum[2] = (sum[2]%mod+mod)%mod;
        sum[3] = sum[2]+dp[2];
        sum[3] %= mod;
        for(int i=3; i<=n; i++) {
            ll tmp = sum[i] - sum[node[i].xi];
            tmp = (tmp%mod+mod)%mod;
            tmp = tmp*(node[i].si-node[i].ri)%mod*fpow(node[i].si, mod-2)%mod;
            tmp = (tmp+node[i].ai)*fpow(node[i].pi, mod-2)%mod;
            sum[i+1] = (sum[i] + tmp) % mod;
        }
        ll l, r;
        while(m--) {
            read(l), read(r);
            ll ans = sum[r] - sum[l];
            printf("%lld\n", (ans%mod+mod)%mod);
        }
    }
    return 0;
}
