#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mx = 1e5+5;
ll num[mx];
int main() {
	int T;
	scanf("%d", &T);
	
	while (T--) {
		ll n;
		scanf("%lld", &n);
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld",&num[i]);
			sum += num[i];
		}
		if (sum % n) printf("%lld\n",n-1);
		else printf("%lld\n",n);
	}
	return 0;
}