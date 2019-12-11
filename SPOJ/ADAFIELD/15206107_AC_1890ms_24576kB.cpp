#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e7;
const int maxm = 1e11;
const int mod = 1e9+7;
using namespace std;

int n, m, T, tol;
multiset<ll> X;
multiset<ll> Y;
multiset<ll> CX;
multiset<ll> CY;
multiset<ll> :: iterator it;

int main() {
    scanf("%d", &T);
    while(T--) {
        ll n, m;
        int q;
        scanf("%lld%lld%d", &n, &m, &q);
        X.clear(), Y.clear(), CX.clear(), CY.clear();
        X.insert(0), X.insert(n);
        Y.insert(0), Y.insert(m);
        CX.insert(n), CY.insert(m);
        while(q--) {
            int op;
            scanf("%d", &op);
            if(op == 0) {
                ll x;
                scanf("%lld", &x);
                X.insert(x);
                it = X.find(x);
                ll lx = 0, rx = n;
                if(x != 0) {
                    it--;
                    lx = *it;
                }
                if(x != n) {
                    it++, it++;
                    rx = *it;
                }
                ll cx = (rx - lx);
                it = CX.find(cx);
                CX.erase(it);
                CX.insert(x - lx);
                CX.insert(rx - x);
                ll ans = (*(--CX.end())) * (*(--CY.end()));
                printf("%lld\n", ans);
            } else {
                ll y;
                scanf("%lld", &y);
                Y.insert(y);
                it = Y.find(y);
                ll ly = 0, ry = m;
                if(y != 0) {
                    it--;
                    ly = *it;
                }
                if(y != m) {
                    it++, it++;
                    ry = *it;
                }
                ll cy = (ry - ly);
                it = CY.find(cy);
                CY.erase(it);
                CY.insert(y-ly);
                CY.insert(ry-y);
                ll ans = (*(--CX.end())) * (*(--CY.end()));
                printf("%lld\n", ans);
            }
            //    printf("!!!%lld %lld\n", (*(--CX.end())), (*(--CY.end())));
        }
    }
    return 0;
}