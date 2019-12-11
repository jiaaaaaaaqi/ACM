#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const long long int maxn = 1e5;

bool prime[maxn+10];
int pri[maxn+10];

void ispri() {
	memset(pri, 0, sizeof(pri));
	memset(prime, true, sizeof(prime));
	int tol=0;
	pri[tol++] = 1;
	for(int i=2; i<=maxn; i++) {
		if(prime[i]) {
			pri[tol++] = i;
			for(int j=2; i*j<=maxn; j++) {
				prime[i*j] = false;
			}
		}
	}
}

int gcd(int a, int b) {
	return b==0 ? a : gcd(b, a%b);
}

int main() {
	ispri();
	int T;
	scanf("%d", &T);
	while(T--) {
		long long int n;
		bool flag = false;
		scanf("%d", &n);
		if(n < 0) {
			n = -1 * n;
			flag = true;
		}
		int ans=0;
		for(int i=1; pri[i]*pri[i]<=n; i++) {
			int cnt=0;
			while(n % pri[i] == 0) {
				cnt++;
				n /= pri[i];
			}
			if(ans == 0)
				ans = cnt;
			else
				ans = gcd(cnt, ans);
		}
		if(n > 1)
			ans = 1;
		if(flag) {
			if(ans % 2 == 0) {
				ans = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}