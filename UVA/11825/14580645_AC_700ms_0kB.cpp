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
const int maxn = 1 << 17;
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
int dp[maxn];
int state[maxn];
int num[20];

void init() {
    memset(dp, 0, sizeof dp);
    memset(num, 0, sizeof num);
    memset(state, 0, sizeof state);
}

int main() {
    int cas = 1;
    while(scanf("%d", &n), n) {
        init();
        for(int i=0; i<n; i++) {
            num[i] = 1 << i;
            scanf("%d", &m);
            while(m--) {
                int tmp;
                scanf("%d", &tmp);
				num[i] |= (1 << tmp);
            }
        }
        tol = 1 << n;
        for(int i=0; i<tol; i++) {
            state[i] = 0;
            for(int j=0; j<n; j++) {
                if(i & (1 << j)) {
                    state[i] |= num[j];
                }
            }
        }
        for(int i=0; i<tol; i++) {
            for(int j=i; j; j=(j-1) & i) {
                if(state[j] == tol - 1) {
                    dp[i] = max(dp[i], dp[i^j] + 1);
                }
            }
        }
        printf("Case %d: %d\n", cas++, dp[tol-1]);
    }
    return 0;
}
