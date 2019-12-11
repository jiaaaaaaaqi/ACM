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
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef __int64 ll;
const int    maxn = 1e5+5;
const int    maxm = 1e9+10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

ll n, m;
ll T, tol;
vector<int> vec;
int path[maxn];
ll ans = 0;

void init(ll n) {
	vec.clear();
	for(int i=2; i*i<=n; i++) {
		if(n % i == 0) {
			vec.push_back(i);
			while(n % i == 0) {
				n /= i;
			}
		}
	}
	if(n != 1)	vec.push_back(n);
}

ll fpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ans;
}

ll solve() {
	ll ans = 0;
	int len = vec.size();
	for(int i=1; i<(1<<len); i++) {
		int cnt = 0;
		ll tmp = 1;
		for(int j=0; j<len; j++) {
			if(i & (1<<j)) {
				cnt++;
				tmp *= 1ll * vec[j];
			}
		}
		ll b = m / tmp;
		if(cnt & 1)	ans += fpow(b, n);
		else		ans -= fpow(b, n);
	}
	return ans;
}

int main() {
	cin >> n >> m;
	init(m);
	ans = fpow(m, n) - solve();
	cout << ans << endl;
	return 0;
}
