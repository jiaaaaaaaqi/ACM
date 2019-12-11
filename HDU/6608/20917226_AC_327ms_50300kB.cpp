/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年07月29日 星期一 12时54分32秒
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
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e7 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int pri[maxn];
bool ispri[maxn];

void handle() {
    int mx = 1e7;
    tol = 0;
    mes(pri, 0), mes(ispri, 1);
    ispri[1] = 0;
    for(int i=2; i<=mx; i++) {
        if(ispri[i])    pri[++tol] = i;
        for(int j=1; j<=tol&&i*pri[j]<=mx; j++) {
            ispri[i*pri[j]] = false;
            if(i%pri[j] == 0)    break;
        }
    }
}

ll fmul(ll a, ll b, ll mod) {
    ll ans = 0;
    while(b) {
        if(b&1) {
            ans = ans+a;
            if(ans>=mod)    ans-=mod;
        }
        a = a+a;
        if(a >= mod)    a -= mod;
        b >>= 1;
    }
    return ans;
}

ll fpow(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b) {
        if(b&1)    ans = fmul(ans, a, mod);;
        a = fmul(a, a, mod);
        b >>= 1;
    }
    return ans;
}

bool check(ll x) {
    for(int i=1; i<=tol && pri[i]*pri[i]<=x; i++) {
        if(x%pri[i] == 0)    return false;
    }
    return true;
}

int main() {
    // freopen("in", "r", stdin);
    handle();
    ll p;
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &p);
        ll ans = p-1;
        for(ll i=p-1; ; i--) {
            if(check(i)) {
                break;
            }
            ans = fmul(ans, fpow(i, p-2, p), p);
        }
        printf("%lld\n", ans);
    }
    return 0;
}