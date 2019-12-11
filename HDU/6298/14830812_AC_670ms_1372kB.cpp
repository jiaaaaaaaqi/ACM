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
const int maxn = 1005;
const int maxm = 30005;
const int mod = 1000000007;
using namespace std;

ll n, m, tol;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        ll ans = -1;
        scanf("%lld", &n);
        if(n % 3 == 0) {
            m = n / 3;
            ans = m * m * m;
        } else if (n % 2 == 0) {
            m = n / 2;
            if(m % 2 == 0) {
                ll z = m / 2;
                ans = m * z * z;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}