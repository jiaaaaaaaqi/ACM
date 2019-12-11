#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int mod = 1000;

int getleading(int a, int b) {
	int k = (b * log10((double)a)) + 1;
	double ans = pow(10.0, 1.0*b*log10((double)a) - k + 1);
	while(ans < 100.0)
		ans *= 10.0;
	return ans;
}

int gettrailing(int a, int b) {
	int ans = 1;
	a %= mod; 
	while(b) {
		if(b&1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1; 
	}
	return ans%mod;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int ans1 = getleading(a, b);
		int ans2 = gettrailing(a, b);
		printf("Case %d: %d %03d\n", cas++, ans1, ans2);
	}
	return 0;
} 