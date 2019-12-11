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

stack<pair<int, int> > s;

int main() {
    while(scanf("%d",&n), n) {
        while(!s.empty())	s.pop();
        ll ans = 0;
        int x;
        ll y = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &x);
            y = 0;
            while(!s.empty() && s.top().first >= x) {
                ll preans = (s.top().first * (s.top().second + y));
                ans = max(preans, ans);
                y += s.top().second;
                s.pop();
            }
            s.push(make_pair(x, y + 1));
        }
        y = 0;
        while(!s.empty()) {
            ll preans = s.top().first * (s.top().second + y);
            ans = max(ans, preans);
            y += s.top().second;
            s.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
