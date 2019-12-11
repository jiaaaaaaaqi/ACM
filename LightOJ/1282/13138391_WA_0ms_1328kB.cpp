#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int mod = 1000;

long long int getleading(long long int a, long long int b) {
	long long int k = (int) (b * log10(a));
	double ans = pow(10, b*log10(a)-k);
	long long int res = int(ans * 100);
	return res;
}

long long int gettrailing(long long int a, long long int b) {
	long long int ans = 1;
	while(b) {
		if(b&1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1; 
	}
	return ans;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		long long int a, b;
		scanf("%lld%lld", &a, &b);
		long long int pre = getleading(a, b);
		long long int nex = gettrailing(a, b);
		printf("Case %d: %lld %lld", cas++, pre, nex);
	}
	return 0;
} 