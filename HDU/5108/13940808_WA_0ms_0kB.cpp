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
	if(n < mx) {
		if(num[n])
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
		m = n;
		long long int x = 1;
		for (i = 0; i<k && p[i] * p[i] < n; i++) {
			while (n%p[i] == 0) {
				x = p[i];
				n = n / p[i];
			}
		}
		if(n != 1) {
			printf("%lld\n", m / n);
		} else {
			printf("%lld\n", m / x);
		}
	}
	return 0;
}