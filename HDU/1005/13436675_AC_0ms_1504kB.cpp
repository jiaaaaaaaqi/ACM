#include<stdio.h>
#include<string.h>

int mod = 7;

long long int fac[100];

int main() {
	int a, b, n;
	while(scanf("%d%d%d", &a, &b, &n), a||b||n) {
		if(n == 1 && n == 2)
			printf("1\n");
		else {
			memset(fac, 0, sizeof(fac));
			fac[1] = fac[2] = 1;
			int T;
			T = 100;
			for(int i=3; i<100; i++) {
				fac[i] = a * fac[i-1] + b * fac[i - 2];
				fac[i] %= mod;
				if(fac[i] == 1 && fac[i-1] == 1) {
					T = i;
					break;
				}
			}
			T -= 2;
			fac[0] = fac[T];
			printf("%d\n", fac[n % T]);			
		}
	}
	return 0;
}