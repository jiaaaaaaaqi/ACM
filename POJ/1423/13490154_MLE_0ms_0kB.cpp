#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

typedef long long int ll;
using namespace std;

const int maxn = 10000005;

ll num[maxn];

int main() {
	memset(num, 0, sizeof(num));
	double d = 0.0;
	for(ll i=1; i<=maxn; i++) {
		d += log10((double)i);
		num[i] = (int)d + 1;
	}
	int T;
	scanf("%d", &T);
	while(T--) {
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", num[n]);
	}
	return 0; 
}