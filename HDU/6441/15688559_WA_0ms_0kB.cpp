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
const ll INF = 1e18+100;
const int maxn = 4e4+10;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;

int main() {
    scanf("%d", &T);
    while(T--) {
        ll n, a;
        scanf("%lld%lld", &n, &a);
        if(n == 0 || n > 2) {
            printf("-1 -1\n");
            break;
        } else if (n == 1) {
            ll b = 1;
            ll c = a+1;
            printf("%lld %lld\n", b, c);
        } else {
        	ll b, c;
			if(a & 1) {
				b = (a*a-1) / 2;
				c = b + 1;
			} else {
				b = (a*a-4) / 4;
				c = b + 2;
			}
			printf("%lld %lld\n", b, c);
        }
    }
    return 0;
}
