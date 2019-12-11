#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e6;

int tol;
long long int pri[maxn+10];
bool ispri[maxn+10];

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

long long int getnum(int n) {
	long long int ans=1;
	for(int i=1; i<tol && pri[i] <= n; i++) {
		int cnt = 0;
		while(n % pri[i] == 0) {
			cnt++;
			n /= pri[i];
		}
		ans *= (1 + cnt);
	}
	if(n > 1) {
		ans *= 2;
	}
	return ans;
}

int main() {
	handle();
	int T;
	int cas=1;
	scanf("%d", &T);
	while(T--) {
		long long int a, b;
		long long int ans;
		scanf("%lld%lld", &a, &b);
		if(b*b > a) {
			ans = 0;
		} else {
			ans = getnum(a) / 2;
			for(int i=1; i<b; i++) {
				if(a % b == 0)
					ans--;
			}
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}