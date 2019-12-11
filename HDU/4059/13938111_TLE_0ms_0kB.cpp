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

const int maxn = 1e6;
int mod = 1000000007;

bool vis[maxn*10];
int tol;
bool ispri[maxn + 10];
int pri[maxn + 10];

void handle() {
	memset(ispri, true, sizeof(ispri));
	memset(pri, 0, sizeof(pri));
	tol = 1;
	for(int i=2; i<maxn; i++) {
		if(ispri[i]) {
			pri[tol++] = i;
			for(int j=2; i*j<maxn; j++) {
				ispri[i*j] = false;
			}
		}
	}
}

void getnum(ll n) {
	ll num = n;
	memset(vis, 0, sizeof(vis));
	for(int i=1; i<tol && pri[i] * pri[i] < n; i++) {
		bool flag = false;
		while(n % pri[i] == 0) {
			n /= pri[i];
			flag = true;
		}
		if(flag) {
			for(int j=1; pri[i]*j<=num; j++) {
//			printf("x = %d \n", pri[i] * j);
				vis[pri[i]*j] = true;
			}
		}
	}
}

int main() {
	int T;
	handle();
	scanf("%d", &T);
	while(T--) {
		ll n;
		scanf("%lld", &n);
		getnum(n);
		ll ans = 0;
		for(int i=1; i<n; i++) {
//			printf("vis%d = %d\n", i, vis[i]);
			if(!vis[i]) {
				ll j = i * i % mod;
				ans += j * j % mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}