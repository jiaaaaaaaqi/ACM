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
const int maxn = 1e5+50;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
bool pri[maxn];
vector<int> vec[maxn];

void handle() {
    memset(pri, true, sizeof pri);
    for(int i=2; i<maxn; i++) {
        if(pri[i]) {
            vec[i].push_back(i);
            for(int j=2; i*j<maxn; j++) {
                vec[i*j].push_back(i);
                pri[i*j] = false;
            }
        }
    }
}

ll solve(ll x, int k) {
    ll ans = 0;
    int len = vec[k].size();
    for(int i=1; i<(1<<len); i++) {
        int cnt = 0;
        ll tmp = 1;
        for(int j=0; j<len; j++) {
            if(i & (1<<j)) {
                cnt++;
                tmp *= vec[k][j];
            }
        }
        if(cnt & 1)	ans += x / tmp;
        else		ans -= x / tmp;
    }
    return ans;
}

int main() {
    handle();
    int cas = 1;
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b, k;
        scanf("%d%d%d%d%d", &a, &n, &b, &m, &k);
        if(k == 0) {
            printf("Case %d: 0", cas++);
            continue;
        }
        n /= k, m /= k, k = 1;
        if(n > m)	swap(n, m);
        ll ans = 0;
        //[i, m]
        for(int i=1; i<=n; i++) {
            ans += 1ll * (m-i+1) - 1ll * (solve(m, i) - solve(1ll * (i-1), i));
        }
        printf("Case %d: %I64d\n", cas++, ans);
    }
    return 0;
}
