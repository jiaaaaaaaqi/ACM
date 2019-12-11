/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Fri 20 Sep 2019 09:45:43 PM CST
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
#include <unordered_map>
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

int d;
ll n, m;
int cas, tol, T;

ll count(ll n, int d) {
    ll k, ans = 0;
    for(ll i=1; k=n/i; i*=10) {
        ans += (k/10)*i;
        int cur = k%10;
        if(cur > d) {
            ans += i;
        } else if(cur == d) {
            ans += n-k*i+1;
        }
    }
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%lld", &d, &n);
        ll ans = count(n, d);
        while(1) {
            if(ans == n) {
                break;
            } else {
                n -= max(1ll, abs(n-ans) / ((int)log10(1.0*n)+1));
                ans = count(n, d);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}