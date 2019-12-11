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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

ll n, m;
int T, tol;
vector<ll> vec;

void init() {
    vec.clear();
    for(int i=2; i<=n; i++) {
        if(n % i == 0) {
            vec.push_back(i);
            while(n % i == 0)	n /= i;
        }
    }
    if(n > 1)	vec.push_back(n);
}

ll solve(ll x) {
    ll ans = 0;
    int len = vec.size();
    for(int i=1; i<(1<<len); i++) {
        ll tmp = 1;
        int cnt = 0;
        for(int j=0; j<len; j++) {
            if(i & (1<<j)) {
                cnt++;
                tmp *= vec[j];
            }
        }
        if(cnt & 1)	ans += x / tmp;
        else	ans -= x / tmp;
    }
    return ans;
}

int main() {
    int cas = 1;
    scanf("%d", &T);
    while(T--) {
        ll l, r;
        scanf("%lld%lld%lld", &l, &r, &n);
        init();
        ll ans = 0;
        int len = vec.size();
//		for(int i=0; i<len; i++)	printf("%d%c", vec[i], i==len-1 ? '\n' : ' ');
		ans = solve(r) - solve(l-1);
        ans = (r-l+1) - ans;
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
