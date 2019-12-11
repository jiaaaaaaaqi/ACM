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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1030;
const int maxm = 1<<11;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
ll mul[maxn];
int cnt[maxn];

void handle() {
    mul[1] = 1;
    for(int i=2; i<=1000; i++) {
        mul[i] = mul[i - 1] * i;
        mul[i] %= mod;
    }
}

void init() {
	memset(cnt, 0, sizeof cnt);
}

int main() {
    handle();
    int T;
    scanf("%d", &T);
    while(T--) {
		init();
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cnt[i^j]++;
            }
        }
        ll ans = 1;
        for(int i=0; i<maxn; i++) {
            if(cnt[i]) {
                ans *= mul[cnt[i]];
                ans %= mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
