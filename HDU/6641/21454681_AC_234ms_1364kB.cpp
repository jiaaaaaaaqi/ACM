/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月07日 星期三 12时39分44秒
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
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int cas, tol, T;

ll gcd(ll a, ll b) {
    return b==0 ? a : gcd(b, a%b);
}

ll f(ll n, ll m) {
    int cnt = 0;
    for(ll i=n+1; ; i++) {
        if(__gcd(i, n) == 1) {
            cnt++;
            if(cnt == m)    return i;
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        ll k, m;
        ll ans = INF;
        scanf("%lld%lld", &k, &m);
        for(int i=1; i<=1000; i++) {
            ll n = (k^i);
            if(n>1 || (n == 0 && m==1)) {
                if(((f(n, m) - n)^n) == k) {
                    ans = min(ans, n);
                }
            }
        }
        if(ans == INF)  printf("-1\n");
        else    printf("%lld\n", ans);
    }
    return 0;
}