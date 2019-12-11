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
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 1e18+100;
const int maxn = 1e5;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;

multiset< pair<ll, int> > se;

int main() {
    scanf("%d", &T);
    while(T--) {
		se.clear();
		scanf("%d", &n);
		ll ans, cnt;
		ans = cnt = 0;
		ll a;
		for(int i=1; i<=n; i++) {
			scanf("%lld", &a);
			if(!se.empty() && se.begin()->first < a) {
				ans += a - se.begin()->first;
				cnt += se.begin()->second;
				se.erase(se.begin());
				se.insert(make_pair(a, 0));
			}
			se.insert(make_pair(a, 2));
		}
		printf("%lld %lld\n", ans, cnt);
    }
    return 0;
}
