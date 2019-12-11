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
#define fi		first
#define	se		second
#define INOPEM  freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi   = 4.0*atan(1.0);
const int    inf  = 0x3f3f3f3f;
const ll     INF  = 1e18+100;
const int    maxn = 1e5;
const int    maxm = 1e9+10;
const int    mod  = 1e9+7;
using namespace std;

int n, m;
int T, tol;

int main() {
    int a, b;
    while(~scanf("%d%d%d", &n, &a, &b)) {
		ll ans = 0;
		ll sum = 1;
		ll tmp = 1;
		for(int i=1; i<=a; i++) {
			tmp = tmp * (n+i-1) / i;
			sum += tmp;			
		}
		ans = sum;
		sum = 1;
		tmp = 1;
		for(int i=1; i<=b; i++) {
			tmp = tmp * (n+i-1) / i;
			sum += tmp;			
		}
		ans *= sum;
		cout << ans << endl;
    }
    return 0;
}
