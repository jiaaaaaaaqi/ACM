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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 10000005;
const int maxm = 1 << 29;
using namespace std;

int n, m, tol;
deque<pair<int, ll> > q;

void init() {
	q.clear();
}

int main() {
	ll n, A, mod;
    while(~scanf("%lld%lld%lld", &n, &A, &mod)) {
		init();
		ll ans = 1;
		ll tmp = 1;
		for(int i=1; i<=n; i++) {
			int left = max((int)(i - A), 1);
			int right = n;
			tmp = tmp * A % mod;
			while(!q.empty() && q.back().second > tmp)
				q.pop_back();
			while(!q.empty() && q.front().first < left)
				q.pop_front();
			q.push_back(make_pair(i, tmp));
			ans = ans * q.front().second % mod;
		}
		printf("%lld\n", ans);
    }
    return 0;
}
