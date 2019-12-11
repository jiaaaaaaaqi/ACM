#include<stdio.h>
#include<string.h>
const int mx = 1e6 + 10;
bool num[mx + 5];
int p[mx + 5];
int k;
void prime() {
	int i, j;
	k = 0;
	memset(num, true, sizeof(num));
	num[0] = num[1] = false;
	for (int i = 2; i*i < mx; i++) {
		if (num[i]) {
			p[k++] = i;
			for (j = i * i; j < mx; j += i) {
				num[j] = false;
			}
		}
	}
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
		return true;
	}
}


int main() {
	long long int n, m,i;
	long long int ans;
	prime();
	while (scanf("%lld", &n) != EOF) {
		if (n <= 1) {
			printf("0\n");
			continue;
		}
		if(calc(n)) {
			printf("1\n");
			continue;
		}
		ans = 1;
		m = n;
		for (i = 0; i < k; i++) {
			if (n <=p[i]) {
				break;
			}
			while (n%p[i] == 0) {
				n = n / p[i];
				ans *= p[i];
			}
		}
		if (n == m) {
			printf("1\n");
			continue;
		}
		if (n == 1) {
			printf("%lld\n", ans / p[i - 1]);
		} else {
			printf("%lld\n", ans);
		}
	}
	return 0;
}