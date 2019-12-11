#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e7;

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

long long int getnum(long long int n) {
	long long int ans=1;
	long long int num =1;
	for(int i=1; i<tol && pri[i] <= n; i++) {
		while(n % pri[i] == 0) {
//			printf("n = %lld pri = %lld\n", n, pri[i]);
			num = pri[i];
			n /= pri[i];
		}
	}
	return num;
}

bool calc(long long int n) {
	if(n < maxn) {
		if(ispri[n])
			return true;
		else
			return false;
	} else {
		for(int i=2; i*i<=n; i++) {
			if(n % i == 0)
				return false;
		}
	}
	return true;
}

int main() {
	handle();
	long long int n;
	while(~scanf("%lld", &n)) {
		if(n == 0 || n == 1) {
			printf("0\n");
			continue;
		}
		if(calc(n)) {
			printf("1\n");
		} else {
			long long int ans = n/getnum(n);
			printf("%lld\n", ans);
		}
	}
	return 0;
}