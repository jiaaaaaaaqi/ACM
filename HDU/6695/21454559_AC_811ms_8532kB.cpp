/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月21日 星期三 13时08分06秒
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
const ll     INF  = 2e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

ll sufmax[maxn];
struct QAQ {
    ll a, b;
    bool operator < (QAQ aa) const {
        return b<aa.b;
    }
} qaq[maxn];
set<ll> st;

ll solve(ll x) {
    if(st.empty())    return INF;
    set<ll>::iterator it=st.upper_bound(x);
    ll ans = INF;
    if(it != st.end())    ans = min(ans, abs((*it)-x));
    if(it != st.begin()) {
        it--;
        ans = min(ans, abs((*it)-x));
    }
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        st.clear();
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%lld%lld", &qaq[i].a, &qaq[i].b);
        }
        sort(qaq+1, qaq+1+n);
        sufmax[n+1] = 0;
        for(int i=n; i>=1; i--) {
            sufmax[i] = max(sufmax[i+1], qaq[i].a);
        }
        ll ans = INF;
        for(int i=1; i<=n; i++) {
            if(i!=n) {
                if(sufmax[i+1] >= qaq[i].b) {
                    ans = min(ans, abs(sufmax[i+1]-qaq[i].b));
                } else {
                    ll ans1 = abs(sufmax[i+1]-qaq[i].b);
                    ll ans2 = solve(qaq[i].b);
                    ll ans3 = min(ans1, ans2);
                    ans = min(ans, ans3);
                }
            } else {
                ll ans3 = solve(qaq[i].b);
                ans = min(ans, ans3);
            }
            st.insert(qaq[i].a);
        }
        printf("%lld\n", ans);
    }
    return 0;
}