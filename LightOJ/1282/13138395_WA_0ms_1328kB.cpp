#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int mod = 1000;

double getleading(long long int a, long long int b) {
	long long int k = (b * log10(a));
	double ans = pow(10, 1.0*b*log10(a)-k);
	while(ans < 100.0)
		ans *= 10;
	return ans;
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
		double pre = getleading(a, b);
		long long int ans1 = pre;
		long long int ans2 = gettrailing(a, b);
		printf("Case %d: %lld %lld\n", cas++, ans1, ans2);
	}
	return 0;
} 