#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int mod = 1000000007;


ll gcd(ll a,ll b) {
	return a == 0 ? b : gcd(b%a,a);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ll n;
		scanf("%lld", &n);
		ll ans = 0;
		for(int i=1; i<n; i++) {
			if (gcd(i, n) == 1) {
				ll sum = i * i % mod;
				ans += sum * sum % mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}