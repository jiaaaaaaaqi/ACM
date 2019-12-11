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
const int maxn = 200005;
const int maxm = 1 << 29;
using namespace std;

int n, m, tol;
int num[maxn];
map<int, ll> cnt;

int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(num, 0, sizeof num);
		cnt.clear();
		cnt[0] = 1;
		int pos;
		for(int i=1; i<=n; i++) {
			scanf("%d", &num[i]);
			if(num[i] == m) {
				pos = i;
			}
		}
		ll x = 0;
		for(int i=pos-1; i>=1; i--) {
			if(num[i] < m)	x--;
			else if(num[i] > m)	x++;
			cnt[x]++;
		}
		x = 0;
		ll ans = 0;
		for(int i=pos; i<=n; i++) {
			if(num[i] < m)	x--;
			else if(num[i] > m)	x++;
			ans += cnt[-x];
			ans += cnt[1-x];
		}
		printf("%lld\n", ans);
	}
	return 0;
}