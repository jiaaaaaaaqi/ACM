#include<map>
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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 1 << 29;
using namespace std;

int n, m, tol;

stack<pair<ll, ll> > s;

int main() {
    while(scanf("%d",&n) != EOF) {
        if(n == 0)	break;
        while(!s.empty())	s.pop();
        ll ans = 0;
        ll x;
        ll y = 0;
        for(int i=1; i<=n; i++) {
            scanf("%lld", &x);
            y = 0;
            while(!s.empty() && s.top().first >= x) {
                s.top().second += y;
                ll preans = (s.top().first * s.top().second);
                ans = max(preans, ans);
                y = s.top().second;
                s.pop();
            }
            s.push(make_pair(x, y + 1));
        }
        y = 0;
        while(!s.empty()) {
            s.top().second += y;
            ll preans = s.top().first * s.top().second;
            ans = max(ans, preans);
            y = s.top().second;
            s.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
