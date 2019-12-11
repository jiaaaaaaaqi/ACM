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
const int maxn = 120;
const int maxm = 10000007;
const int mod = 1e9+7;
using namespace std;

int n, m, tol, T;

ll num[maxn];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    scanf("%d", &T);
    getchar();
    while(T--) {
        memset(num, 0, sizeof num);
        char ch;
        ll x = 0;
		n = 0;
		while(1) {
            scanf("%c", &ch);
			if(ch == '\n')	break;
			if(ch == ' ') {
				x = 0;
				continue;
			}
			x = x*10 + ch - '0';
			num[++n] = x;
        }
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                ans = max(ans, gcd(num[i], num[j]));
            }
        }
        printf("%I64d\n", ans);
    }
}
