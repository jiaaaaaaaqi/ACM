#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>

typedef long long int ll;
using namespace std;

ll gcd(ll a, ll b) {
	return a%b==0 ? b:gcd(b, a%b);
}

ll LCM(ll a, ll b) {
	ll d = gcd(a, b);
	return a * b / d;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ll n;
		scanf("%d", &n);
		ll ans = 1;
		for(ll i=0; i<n; i++) {
			ll a;
			scanf("%lld", &a);
			ans = LCM(a, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}